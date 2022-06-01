#ifndef ADDNEWPRODUCT_H
#define ADDNEWPRODUCT_H

#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"

#include "../boundary/AddNewProductUI.h"

/*
��� �������̽� : �ǸŻ�ǰ ���
���׷��� Ÿ�� : control
*/
class AddNewProduct {
	User currentUser;
	ProductCollection* productList;
	AddNewProductUI* addNewProductUi;
public:
	AddNewProduct() {};
	AddNewProduct(FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList) {
		this->currentUser = currentUser;
		this->productList = productList;
		addNewProductUi = new AddNewProductUI(inFilePtr, outFilePtr, this);
		addNewProductUi->displayAddNewProductForm();
	}
	Product createNewProduct(string productName, string madeCompany, int price, int initialQuantity);
};

#endif