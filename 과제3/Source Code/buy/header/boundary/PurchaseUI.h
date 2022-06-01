#ifndef PURCHASEUI_H
#define PURCHASEUI_H

#include <iostream>
using namespace std;

class Purchase;

/*
사용 유즈케이스 : 상품 구매
스테레오 타입 : Boundary
*/
class PurchaseUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	Purchase* purchase;
	
public:
	// 생성자
	PurchaseUI() {};
	PurchaseUI(FILE* inFilePtr, FILE* outFilePtr, Purchase *purchase) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->purchase = purchase;
	}

	void displayPurchaseButton();	// UI 함수
	void clickPurchaseButton();		// 콜백함수
};

#endif