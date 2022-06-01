#ifndef ADDNEWPRODUCT_H
#define ADDNEWPRODUCT_H

#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"

#include "../boundary/AddNewProductUI.h"

/*
사용 유즈케이스 : 판매상품 등록
스테레오 타입 : control
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