#define _CRT_SECURE_NO_WARNINGS 1

#include "terminal.h"
#include <stdio.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

	printf("enter the transaction date in the format DD/MM/YYYY\n");
	gets(termData->transactionDate);

	if ((strlen(termData->transactionDate)>10) || (strlen(termData->transactionDate)<10) || (termData->transactionDate[0]=='\0')) {
		return WRONG_DATE;
	}

	for (uint32_t i = 0;i<2; i++) {

		if ((termData->transactionDate[i]<48) || (termData->transactionDate[i]>57)) {
			return WRONG_DATE;
		}

	}

	for (uint32_t i = 3; i < 5; i++) {

		if ((termData->transactionDate[i] < 48) || (termData->transactionDate[i]>57)) {
			return WRONG_DATE;
		}

	}

	for (uint32_t i = 6; i < 10; i++) {

		if ((termData->transactionDate[i] < 48) || (termData->transactionDate[i]>57)) {
			return WRONG_DATE;
		}

	}

	if ((termData->transactionDate[2] != 47) || (termData->transactionDate[5] != 47)) {
		return WRONG_DATE;

	}
	if (termData->transactionDate[0] > '3') {
		return WRONG_DATE;
	}
	if ((termData->transactionDate[0] == '3') && (termData->transactionDate[1]>'1')) {
		return WRONG_DATE;
	}
	if (termData->transactionDate[3] > '1') {
		return WRONG_DATE;
	}
	if ((termData->transactionDate[3] == 1) && (termData->transactionDate[4]>2)) {
		return WRONG_DATE;
	}
	else {
		return oK;
	}

}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	
	if (cardData.cardExpirationDate[3] > termData.transactionDate[8]) {
		return oK;
	}
	else if (( cardData.cardExpirationDate[3] == termData.transactionDate[8] ) && ( cardData.cardExpirationDate[4] > termData.transactionDate[9])) {
		return oK;
	}
	else if (cardData.cardExpirationDate[0] > termData.transactionDate[3]) {
		return oK;

	}
	else if ((cardData.cardExpirationDate[0] == termData.transactionDate[3]) && (cardData.cardExpirationDate[1] > termData.transactionDate[4])) {
		return oK;

	}
	else if ((cardData.cardExpirationDate[0] == termData.transactionDate[3]) && (cardData.cardExpirationDate[1] == termData.transactionDate[4])) {
		return oK;

	}
	else {
		return EXPIRED_CARD;
	}
	

}


EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {

	printf("enter the transaction amount\n");
	scanf("%f", &(termData->transAmount));
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;

	}
	else {
		return oK;
	}

}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	
	printf("enter the max amount of the terminal\n");
	scanf("%f", &(termData->maxTransAmount));

	if (termData->maxTransAmount<=0) {
		return INVALID_MAX_AMOUNT;
	}
	else {
		return oK;
	}


}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {

	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else {
		return oK;
	}

}