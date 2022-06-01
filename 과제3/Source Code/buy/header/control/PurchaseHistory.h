#ifndef PURCHASEHISTORY_H
#define PURCHASEHISTORY_H

#include <iostream>
#include <vector>
//#include "../boundary/PurchaseHistoryUI.h"
#include "../../../entity/header/ProductCollection.h"
#include "../../../entity/header/User.h"

class PurchaseHistoryUI;

using namespace std;

/*
��� �������̽� : ���� ��� ��ȸ
���׷��� Ÿ�� : Control
*/
class PurchaseHistory {
	User currentUser;
	ProductCollection* productList;
	PurchaseHistoryUI* purchaseHistoryUi;
public:
	PurchaseHistory() {};
	PurchaseHistory(FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList);

	vector<Product> showPurchaseHistory();
};

#endif