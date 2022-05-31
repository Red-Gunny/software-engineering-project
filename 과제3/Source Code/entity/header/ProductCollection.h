#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H

#include <vector>
#include <map>
#include "./product.h"

/*
* ��ǰ ���� Ŭ����
* ���׷��� Ÿ�� : Entity (Collection)
*/
class ProductCollection {
	vector<Product> productList;
public:
	vector<Product> getPurchasableProduct(string productName);// ���Ű��� ��ǰ ����Ʈ ��ȸ
	bool purchaseProduct(string productName);					// ��ǰ ���� - remainQuantity�� 0���� Ŭ ���� 1 ���ҽ�Ų��. 
	bool evaluateSatisfactionRating(int rating, string productName);	// ���Ÿ����� ��
	Product createNewProduct(string sellerId, string proudctName, string madeCompany, int price, int initialQuantity);	// �ǸŻ�ǰ���
	vector<Product> checkOnSaleList(string sellerId);		// �Ǹ� ���� ��ǰ  ��ȸ
	vector<Product> checkSoldOutList(string sellerId);		// �Ǹ� �Ϸ� ��ǰ ��ȸ
	Product getProductDetails(string productName);

	map<string, pair<int, double>> getSoldStatistics(string sellerId);		// �Ǹ� ��ǰ ��� ��ȸ

};

#endif