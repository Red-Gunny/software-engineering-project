#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include "../../../entity/header/ProductCollection.h"
#include "../../../entity/header/UserCollection.h"
#include "../boundary/PurchaseUI.h"
using namespace std;

/*
��� �������̽� : ��ǰ ����
���׷��� Ÿ�� : Control
*/
class Purchase {
	User currentUser;
	UserCollection* userList;
	Product searchedProduct;			// ����ڰ� ������ ��ǰ
	ProductCollection* productList;
	PurchaseUI* purchaseUi;
public:
	// ������
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
	// ����
	User& getCurrentUser() { return currentUser; }
	
	Product purchaseProduct();
};

#endif