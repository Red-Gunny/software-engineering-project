#ifndef PURCHASABLEPRODUCT_H
#define PURCHASABLEPRODUCT_H

#include "../../../entity/header/ProductCollection.h"
#include "../boundary/PurchasableProductUI.h"

#include <iostream>
using namespace std;

/*
��� �������̽� : ���� ���� ��ǰ ��ȸ
���׷��� Ÿ�� : Control
*/
class PurchasableProduct {
	ProductCollection* productList;
	PurchasableProductUI* purchasableProductUi;
public:
	// ������
	PurchasableProduct() {};
	PurchasableProduct(FILE* inFilePtr, FILE* outFilePtr, ProductCollection* productList) {
		this->productList = productList;
		purchasableProductUi = new PurchasableProductUI(inFilePtr, outFilePtr, this);
		purchasableProductUi->displaySearchUi();
	}

	~PurchasableProduct() {
		delete purchasableProductUi;
	};

	Product showProduct(string productName);
	Product getSearchProduct();
};

#endif