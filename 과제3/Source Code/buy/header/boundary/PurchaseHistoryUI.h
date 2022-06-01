#ifndef PURCHASEHISTORYUI_H
#define PURCHASEHISTORYUI_H

#include "../control/PurchaseHistory.h"
#include <iostream>
using namespace std;

//class PurchasHistory;

/*
사용 유즈케이스 : 구매 목록 조회
스테레오 타입 : Boundary
*/
class PurchaseHistoryUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	PurchaseHistory* purchaseHistory;
public:
	PurchaseHistoryUI() {};
	PurchaseHistoryUI(FILE* inFilePtr, FILE* outFilePtr, PurchaseHistory* purchaseHistory) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->purchaseHistory = purchaseHistory;
	}

	void displayPurchaseHistoryUi();
	void checkPurchaseHistory();
};

#endif