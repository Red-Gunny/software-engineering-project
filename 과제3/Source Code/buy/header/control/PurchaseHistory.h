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
사용 유즈케이스 : 구매 목록 조회
스테레오 타입 : Control
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