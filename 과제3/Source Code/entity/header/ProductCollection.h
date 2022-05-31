#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H

#include <vector>
#include <map>
#include "./product.h"

/*
* 상품 관리 클래스
* 스테레오 타입 : Entity (Collection)
*/
class ProductCollection {
	vector<Product> productList;
public:
	vector<Product> getPurchasableProduct(string productName);// 구매가능 상품 리스트 조회
	bool purchaseProduct(string productName);					// 상품 구매 - remainQuantity가 0보다 클 때만 1 감소시킨다. 
	bool evaluateSatisfactionRating(int rating, string productName);	// 구매만족도 평가
	Product createNewProduct(string sellerId, string proudctName, string madeCompany, int price, int initialQuantity);	// 판매상품등록
	vector<Product> checkOnSaleList(string sellerId);		// 판매 중인 상품  조회
	vector<Product> checkSoldOutList(string sellerId);		// 판매 완료 상품 조회
	Product getProductDetails(string productName);

	map<string, pair<int, double>> getSoldStatistics(string sellerId);		// 판매 상품 통계 조회

};

#endif