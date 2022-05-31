#ifndef PRODUCTSALESSTATISTICSUI_H
#define PRODUCTSALESSTATISTICSUI_H

#include <iostream>
using namespace std;


class ProductSalesStatistics;

/*
사용 유즈케이스 : 판매상품 통계조회
스테레오 타입 : Boundary
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