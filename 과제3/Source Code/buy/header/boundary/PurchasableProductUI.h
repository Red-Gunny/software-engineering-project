#ifndef PURCHASABLEPRODUCTUI_H
#define PURCHASABLEPRODUCTUI_H

#include <iostream>
#include "../../../entity/header/Product.h"
//#include "../control/PurchasableProduct.h"
using namespace std;

#define MAX_STRING 100

class PurchasableProduct;		// 상호참조 오류 방지 목적

/*
사용 유즈케이스 :  구매 가능 상품 목록 조회
스테레오 타입 : Boundary
*/
class PurchasableProductUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	PurchasableProduct* purchasableProduct;
	Product searchedProduct;
public:
	// 생성자
	PurchasableProductUI() {};
	PurchasableProductUI(FILE* inFilePtr, FILE* outFilePtr, PurchasableProduct* purchasableProduct) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->purchasableProduct = purchasableProduct;
	}

	// 게터
	Product getSearchedProduct() { return searchedProduct; }

	void displaySearchUi();
	void searchProduct(char productName[]);

};

#endif