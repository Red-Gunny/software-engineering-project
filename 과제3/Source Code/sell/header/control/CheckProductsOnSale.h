#ifndef CHECKPRODUCTSONSALE_H
#define CHECKPRODUCTSONSALE_H

#include <iostream>
#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"
#include "../../header/boundary/CheckProductsOnSaleUI.h"

/*
사용 유즈케이스 : 판매 중인 상품 조회
스테레오 타입 : control
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
