#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

/*
* ��ǰ Entity
* ���׷��� Ÿ�� : Entity
*/
class Product {
	string sellerId;					// �Ǹ��� ���̵�
	string productName;					// ��ǰ��
	string madeCompany;					// ����ȸ��
	int price;							// ����
	int initialQuantity;				// �ʱ� ����� ��ü ����
	int remainQuantity;					// ���� ����
	double averageRating;				// ��� ���� ������
	int ratingUserCount;				// ��� ���Ÿ������� ������ ��� ��
public:

	// ������
	Product() {};
	Product(
		string sellerId,
		string productName,
		string madeCompany,
		int price,
		int initialQuantity,
		int remainQuantity = 0,
		double averageRating = 0.0,
		int ratingUserCount = 0)
	{
		if (productName.empty()) {
			exit(0);		
		}

		this->sellerId = sellerId;
		this->productName = productName;
		this->madeCompany = madeCompany;
		this->price = price;
		this->initialQuantity = initialQuantity;
		this->remainQuantity = initialQuantity;		// �ڡڡڡڡڡڡڡڡ� initial�� ������ ���� �ڡڡڡڡڡڡڡڡڡ�
		this->averageRating = averageRating;
		this->ratingUserCount = ratingUserCount;
	}

	//����
	string getSellerId() { return sellerId; }
	string getProductName() { return productName; }
	string getMadeCompany() { return madeCompany; }
	int getPrice() { return price; }
	int getInitialQuantity() { return initialQuantity; }
	int getRemainQuantity() { return remainQuantity; }
	double getAverageRating() { return averageRating; }
	int getRatingUserCount() { return ratingUserCount; }

	//����
	void setRemainQuantity(int remainQuantity) { this->remainQuantity = remainQuantity; }
	void setAverageRating(double averageRating) { this->averageRating = averageRating; }
	void setRatingUserCount(int ratingUserCount) { this->ratingUserCount = ratingUserCount; }
};

#endif