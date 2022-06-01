#ifndef CHECKSOLDOUTPRODUCT_H
#define CHECKSOLDOUTPRODUCT_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"
#include "../boundary/CheckSoldOutProductUI.h"

/*
사용 유즈케이스 : 판매 완료 상품 조회
스테레오 타입 : control
*/
class CheckSoldOutProduct {
	User currentUser;
	ProductCollection* productList;
	CheckSoldOutProductUI* soldOutBoundary;
public:
	CheckSoldOutProduct() {};
	CheckSoldOutProduct(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList);
	vector<Product> showSoldOutProduct();
};

#endif // !CHECKSOLDOUTPRODUCT_H
