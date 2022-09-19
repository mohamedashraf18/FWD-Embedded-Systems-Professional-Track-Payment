#define _CRT_SECURE_NO_WARNINGS 1
#include "card.h"
#include <string.h>



EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("enter the cardholder's name(20 to 24 characters)\n");
	gets(cardData->cardHolderName);

	if (strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20 || cardData->cardHolderName[0] == '\0') {
		return WRONG_NAME;
	}
	for (uint32_t i = 0; i < 2; i++) {
		if (cardData->cardHolderName[i] > 122 || cardData->cardHolderName[i]<65) {
			return WRONG_NAME;
		}

	}
	for (uint32_t i = 0; i < 2; i++) {
		if (cardData->cardHolderName[i] < 97 && cardData->cardHolderName[i]>90) {
			return WRONG_NAME;
		}

	}
	return OK;


}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("enter the expiry date in the format MM/YY\n");
	gets(cardData->cardExpirationDate);

	if (strlen(cardData->cardExpirationDate) > 5 || strlen(cardData->cardExpirationDate) < 5 || cardData->cardExpirationDate[0] == '\0') {
		return WRONG_EXP_DATE;

	}

	for (uint32_t i = 0; i < 2; i++) {
		if (cardData->cardExpirationDate[i] < 48 || cardData->cardExpirationDate[i]>57) {
			return WRONG_EXP_DATE;
		}

	}
	if (cardData->cardExpirationDate[0]>'1') {
		return WRONG_EXP_DATE;

	}
	if (cardData->cardExpirationDate[0]=='1' && cardData->cardExpirationDate[1]>'2' ) {
		return WRONG_EXP_DATE;

	}

	for (uint32_t i = 3; i < 5; i++) {
		if (cardData->cardExpirationDate[i] < 48 || cardData->cardExpirationDate[i]>57) {
			return WRONG_EXP_DATE;
		}

	}
	if (cardData->cardExpirationDate[2] != 47) {
		return WRONG_EXP_DATE;
			
	}
	else {
		return OK;

	}
	
		
	


}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("enter the card's primary account number\n");
	gets(cardData->primaryAccountNumber);

	for (uint32_t i = 0;i<strlen(cardData->primaryAccountNumber); i++) {
		if (cardData->primaryAccountNumber[i] < 48 || cardData->primaryAccountNumber[i]>57) {
			return WRONG_PAN;
		}
	}
	if (strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16 || cardData->primaryAccountNumber[0] == '\0') {
		return WRONG_PAN;
	}
	else {
		return OK;
	}


}