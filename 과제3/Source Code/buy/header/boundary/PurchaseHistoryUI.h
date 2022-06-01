#ifndef PURCHASEHISTORYUI_H
#define PURCHASEHISTORYUI_H

#include "../control/PurchaseHistory.h"
#include <iostream>
using namespace std;

//class PurchasHistory;

/*
��� �������̽� : ���� ��� ��ȸ
���׷��� Ÿ�� : Boundary
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