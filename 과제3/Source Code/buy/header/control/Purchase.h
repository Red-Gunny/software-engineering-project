#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include "../../../entity/header/ProductCollection.h"
#include "../../../entity/header/UserCollection.h"
#include "../boundary/PurchaseUI.h"
using namespace std;

/*
사용 유즈케이스 : 상품 구매
스테레오 타입 : Control
*/
class Purchase {
	User currentUser;
	UserCollection* userList;
	Product searchedProduct;			// 사용자가 선택한 상품
	ProductCollection* productList;
	PurchaseUI* purchaseUi;
public:
	// 생성자
	Purchase() {};
	Purchase(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, UserCollection *userList, Product product, ProductCollection* productList) {
		this->currentUser = currentUser;
		this->userList = userList;
		this->searchedProduct = product;
		this->productList = productList;
		purchaseUi = new PurchaseUI(inFilePtr, outFilePtr, this);
		purchaseUi->displayPurchaseButton();
	}
	~Purchase() {
		delete purchaseUi;
	};
	// 게터
	User& getCurrentUser() { return currentUser; }
	
	Product purchaseProduct();
};

#endif