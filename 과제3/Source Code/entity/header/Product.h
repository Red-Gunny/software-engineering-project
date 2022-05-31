#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

/*
* 상품 Entity
* 스테레오 타입 : Entity
*/
class Product {
	string sellerId;					// 판매자 아이디
	string productName;					// 상품명
	string madeCompany;					// 제조회사
	int price;							// 가격
	int initialQuantity;				// 초기 등록한 전체 수량
	int remainQuantity;					// 남은 수량
	double averageRating;				// 평균 구매 만족도
	int ratingUserCount;				// 평균 구매만족도에 참여한 사람 수
public:

	// 생성자
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
		this->remainQuantity = initialQuantity;		// ★★★★★★★★★ initial과 같음에 주의 ★★★★★★★★★★
		this->averageRating = averageRating;
		this->ratingUserCount = ratingUserCount;
	}

	//게터
	string getSellerId() { return sellerId; }
	string getProductName() { return productName; }
	string getMadeCompany() { return madeCompany; }
	int getPrice() { return price; }
	int getInitialQuantity() { return initialQuantity; }
	int getRemainQuantity() { return remainQuantity; }
	double getAverageRating() { return averageRating; }
	int getRatingUserCount() { return ratingUserCount; }

	//세터
	void setRemainQuantity(int remainQuantity) { this->remainQuantity = remainQuantity; }
	void setAverageRating(double averageRating) { this->averageRating = averageRating; }
	void setRatingUserCount(int ratingUserCount) { this->ratingUserCount = ratingUserCount; }
};

#endif