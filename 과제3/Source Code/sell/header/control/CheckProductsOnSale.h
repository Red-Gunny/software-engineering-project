#ifndef CHECKPRODUCTSONSALE_H
#define CHECKPRODUCTSONSALE_H

#include <iostream>
#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"
#include "../../header/boundary/CheckProductsOnSaleUI.h"

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���׷��� Ÿ�� : control
*/
class CheckProductsOnSale {
	User currentUser;
	ProductCollection* productList;
	CheckProductsOnSaleUI* checkProductsOnSaleUi;
public:
	CheckProductsOnSale() {};
	CheckProductsOnSale(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList) {
		this->currentUser = currentUser;
		this->productList = productList;
		checkProductsOnSaleUi = new CheckProductsOnSaleUI(inFilePtr, outFilePtr, this);
		checkProductsOnSaleUi->displayCheckProductsOnSaleUI();
	}
	vector<Product> showProductsOnSale();
};

#endif // !CHECKPRODUCTSONSALE_H
