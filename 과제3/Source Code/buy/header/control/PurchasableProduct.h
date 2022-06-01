#ifndef PURCHASABLEPRODUCT_H
#define PURCHASABLEPRODUCT_H

#include "../../../entity/header/ProductCollection.h"
#include "../boundary/PurchasableProductUI.h"

#include <iostream>
using namespace std;

/*
사용 유즈케이스 : 구매 가능 상품 조회
스테레오 타입 : Control
*/
class PurchasableProduct {
	ProductCollection* productList;
	PurchasableProductUI* purchasableProductUi;
public:
	// 생성자
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