#define _CRT_SECURE_NO_WARNINGS 1

#include "app.h"
#include "card.h"
#include "terminal.h"
#include "server.h"

#include <stdio.h>
#include <string.h>


void appStart(void) {

	
		ST_transaction_t test_object3;


		if (getCardHolderName(&test_object3.cardHolderData) == WRONG_NAME) {

			printf("you entered a wrong name\n");
			return 0;
		}
		if (getCardExpiryDate(&test_object3.cardHolderData) == WRONG_EXP_DATE) {
			printf("you entered a wrong expiry date\n");
			return 0;
		}
		if (getCardPAN(&test_object3.cardHolderData) == WRONG_PAN) {
			printf("you entered a wrong PAN\n");
			return 0;

		}
		

		if (getTransactionDate(&test_object3.terminalData) == WRONG_DATE) {
			printf("you entered a wrong date\n");
			return 0;
		}
		if (isCardExpired(test_object3.cardHolderData , test_object3.terminalData) == EXPIRED_CARD) {
			printf("card is expired\n");
			return 0;
		}
		if (getTransactionAmount(&test_object3.terminalData) == INVALID_AMOUNT) {
			printf("you entered an invalid amount of money\n");
			return 0;
		}
		if (setMaxAmount(&test_object3.terminalData) == INVALID_MAX_AMOUNT) {
			printf("you entered an invalid max amount \n");

			return 0;
		}
		if (isBelowMaxAmount(&test_object3.terminalData) == EXCEED_MAX_AMOUNT) {
			printf("you exceeded the max amount \n");
			return 0;

		}
		


		if ((recieveTransactionData(&test_object3) == DECLINED_STOLEN_CARD)) {
			printf("this is a stolen card \n");
			return 0;
		}

		if ((recieveTransactionData(&test_object3) == DECLINED_INSUFFECIENT_FUND)) {
			printf("sorry insuffecient fund\n");
			return 0;
		}

		if ((recieveTransactionData(&test_object3) == INTERNAL_SERVER_ERROR)) {
			printf("sorry the transaction can't be saved due to an internal server error\n");
			return 0;
		}
		else {
			printf("successful transaction\n");
		}

		
}