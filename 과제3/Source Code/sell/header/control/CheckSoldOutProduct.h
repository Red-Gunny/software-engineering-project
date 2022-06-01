#ifndef CHECKSOLDOUTPRODUCT_H
#define CHECKSOLDOUTPRODUCT_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"
#include "../boundary/CheckSoldOutProductUI.h"

/*
��� �������̽� : �Ǹ� �Ϸ� ��ǰ ��ȸ
���׷��� Ÿ�� : control
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
