#define _CRT_SECURE_NO_WARNINGS 1

#include "server.h"
#include <string.h>

uint32_t k;
static uint32_t j = 0;


ST_accountsDB_t side_accounts_DB[255] = {

	{1500,"652134879652145864"},

	{5608.45,"139782645971394568"},

	{9999.99,"59713524682136497"},

	{5859864,"19826459783214598"}

};

ST_transaction_t side_transactions_DB[255];



EN_serverError_t isValidAccount(ST_cardData_t* cardData) {

	uint32_t x;
	for (k = 0; k < 255; ++k)
	{
		x = strcmp(side_accounts_DB[k].primaryAccountNumber, cardData->primaryAccountNumber);
		if (x == 0)
		{
			return ok;
		}



	}
	return ACCOUNT_NOT_FOUND;


}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	
	if ((termData->transAmount) > side_accounts_DB[k].balance) {
		return LOW_BALANCE;

	}
	else {
		return ok;
	}
	
	}
EN_serverError_t saveTransaction(ST_transaction_t* transData) {


	if (j >= 255)
	{
		return SAVING_FAILED;
	}

	strcpy(side_transactions_DB[j].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate);
	strcpy(side_transactions_DB[j].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName);
	strcpy(side_transactions_DB[j].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber);

	strcpy(side_transactions_DB[j].terminalData.transactionDate, transData->terminalData.transactionDate);
	side_transactions_DB[j].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
	side_transactions_DB[j].terminalData.transAmount = transData->terminalData.transAmount;

	side_transactions_DB[j].transState = transData->transState;

	side_transactions_DB[j].transactionSequenceNumber = j + 1;

	side_accounts_DB[k].balance = side_accounts_DB[k].balance - transData->terminalData.transAmount;

	j++;
	return ok;
	
}


EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

	if (isValidAccount(&(transData->cardHolderData)) == ACCOUNT_NOT_FOUND) {
		return DECLINED_STOLEN_CARD;

	}

	if (isAmountAvailable(&(transData->terminalData)) == LOW_BALANCE) {
		return DECLINED_INSUFFECIENT_FUND;

	}
	if (saveTransaction(transData) == SAVING_FAILED ) {
		return INTERNAL_SERVER_ERROR;

	}
	else {
		return APPROVED;
	}

}
	


