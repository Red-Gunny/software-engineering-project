#ifndef CHECKPRODUCTSONSALEUI_H
#define CHECKPRODUCTSONSALEUI_H

#include <iostream>
using namespace std;

class CheckProductsOnSale;

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���׷��� Ÿ�� : Boundary
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