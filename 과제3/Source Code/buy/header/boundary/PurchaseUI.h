#ifndef PURCHASEUI_H
#define PURCHASEUI_H

#include <iostream>
using namespace std;

class Purchase;

/*
��� �������̽� : ��ǰ ����
���׷��� Ÿ�� : Boundary
*/
class PurchaseUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	Purchase* purchase;
	
public:
	// ������
	PurchaseUI() {};
	PurchaseUI(FILE* inFilePtr, FILE* outFilePtr, Purchase *purchase) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->purchase = purchase;
	}

	void displayPurchaseButton();	// UI �Լ�
	void clickPurchaseButton();		// �ݹ��Լ�
};

#endif