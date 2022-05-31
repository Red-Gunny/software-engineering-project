#ifndef PRODUCTSALESSTATISTICS_H
#define PRODUCTSALESSTATISTICS_H

#include <iostream>
using namespace std;

#include "../../../entity/header/User.h"
#include "../../../entity/header/ProductCollection.h"

#include "../../header/boundary/ProductSalesStatisticsUI.h"

/*
��� �������̽� : �ǸŻ�ǰ �����ȸ
���׷��� Ÿ�� : Control
*/
class ProductSalesStatistics {
	User currentUser;
	ProductCollection* productList;
	ProductSalesStatisticsUI* statisticsBoundary;
public:
	ProductSalesStatistics() {};
	ProductSalesStatistics(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList);
	map<string, pair<int, double>> productSalesStatistics();
};

#endif