#ifndef CHECKPRODUCTSONSALEUI_H
#define CHECKPRODUCTSONSALEUI_H

#include <iostream>
using namespace std;

class CheckProductsOnSale;

/*
사용 유즈케이스 : 판매 중인 상품 조회
스테레오 타입 : Boundary
*/
class CheckProductsOnSaleUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	CheckProductsOnSale* onSaleControl;
public:
	CheckProductsOnSaleUI() {};
	CheckProductsOnSaleUI(FILE* inFilePtr, FILE* outFilePtr, CheckProductsOnSale* onSaleControl) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->onSaleControl = onSaleControl;
	}

	void displayCheckProductsOnSaleUI();
	void checkProductsOnSale();
};

#endif