#ifndef PURCHASABLEPRODUCTUI_H
#define PURCHASABLEPRODUCTUI_H

#include <iostream>
#include "../../../entity/header/Product.h"
//#include "../control/PurchasableProduct.h"
using namespace std;

#define MAX_STRING 100

class PurchasableProduct;		// ��ȣ���� ���� ���� ����

/*
��� �������̽� :  ���� ���� ��ǰ ��� ��ȸ
���׷��� Ÿ�� : Boundary
*/
class PurchasableProductUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	PurchasableProduct* purchasableProduct;
	Product searchedProduct;
public:
	// ������
	PurchasableProductUI() {};
	PurchasableProductUI(FILE* inFilePtr, FILE* outFilePtr, PurchasableProduct* purchasableProduct) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->purchasableProduct = purchasableProduct;
	}

	// ����
	Product getSearchedProduct() { return searchedProduct; }

	void displaySearchUi();
	void searchProduct(char productName[]);

};

#endif