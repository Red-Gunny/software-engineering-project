#ifndef PRODUCTSALESSTATISTICSUI_H
#define PRODUCTSALESSTATISTICSUI_H

#include <iostream>
using namespace std;


class ProductSalesStatistics;

/*
��� �������̽� : �ǸŻ�ǰ �����ȸ
���׷��� Ÿ�� : Boundary
*/
class ProductSalesStatisticsUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	ProductSalesStatistics* statisticsControl;
public:
	ProductSalesStatisticsUI() {};
	ProductSalesStatisticsUI(FILE* inFilePtr, FILE* outFilePtr, ProductSalesStatistics* statisticsControl) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->statisticsControl = statisticsControl;
	}
	void displayStatisticsButton();
	void requestProductSalesStatistics();
};

#endif