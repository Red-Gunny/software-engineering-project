#include "./header/ProductCollection.h"

//#include <conio.h>

/*
사용 유즈케이스 : 구매가능 상품리스트 조회
내용 : productList에서 구매가능한 조건일 경우 벡터에 담아 반환함.
파라미터 : 상품의 이름. (string productName)
리턴 : 구매가능한 상품 목록 (vector<Product>)
*/
vector<Product> ProductCollection::getPurchasableProduct(string productName) {
	vector<Product> purchasableProductList;
	for (Product& product : productList) {
		if (product.getProductName() == productName) {				// 상품명이 일치
			if (product.getInitialQuantity() >= product.getRemainQuantity()) {				// 남은 수량이 존재하는지 확인
				purchasableProductList.push_back(product);										// 구매가능이므로 벡터에 담음
			}
		}
	}
	return purchasableProductList;
}

/*
사용 유즈케이스 : 상품 구매
내용 : 상품을 구매. 남은 수량을 감소시킴. (구매자 등록하는건 userList와 해당 control의 다른 메소드에서 수행됨)
파라미터 : 상품의 이름. (string productName)
리턴 : 상품 구매 성공 시 true 반환 (bool)
유의사항 : ★★★★★ for문 내 Product& product는 반드시 참조 형태여야 함.★★★★★
*/
bool ProductCollection::purchaseProduct(string productName) {
	for (Product& product : productList) {
		if (product.getProductName() == productName) {			// productList에서 상품명에 맞는 상품을 찾아냄
			int currentQuantity = product.getRemainQuantity();			// 현재 남아있는 수량
			if (currentQuantity > 0) {									// 현재 수량이 남아있는 경우에만
				product.setRemainQuantity(--currentQuantity);			// 1개 감소시킨 값을 product 저장.
				return true;
			}
			return false;		// 수량이 0이므로 구매 실패
		}
	}
	return false;			//  productList에 해당 상품이 존재하지 않음.
}

/*
사용 유즈케이스 : 구매만족도 평가
내용 : 구매한 상품에 대하여 구매만족도를 업데이트함.
파라미터 : (1) 구매만족도 값  (2) 상품의 이름. (int rating, string productName)
리턴 : 상품 구매만족도 업데이트 성공 시 true 반환 (bool)
유의사항 : (1) ★★★★★ for문 내 Product& product는 반드시 참조 형태여야 함. ★★★★★
		   (2) rating 유효성 검사는 boundary에서 이루어짐.
		   (3) 평균값 구하는 로직에서 분모(평가에 참여한 사람 수) getRatingCount() + 1 되어있음에 주의
*/
bool ProductCollection::evaluateSatisfactionRating(int rating, string productName) {
	for (Product& product : productList) {
		if (product.getProductName() == productName) {					// productList에서 상품명이 일치하는 것을 찾았을 때
			double currentAverageRating = product.getAverageRating();			// 기존 분자값 (기존 평균 평가 점수)
			int ratingUserCount = product.getRatingUserCount();					// 기존 분모값 (만족도 평가에 참여한 사람 수)
			double currentAverageRatingSum = (double)currentAverageRating * ratingUserCount;	// 분자값 (기존 만족도 평가 사람수 * 기존 평균 평가 점수)
			ratingUserCount += 1;																// 분모값 1 증가 (참여한 사람 수)
			double updatedAverageRating = (double)(currentAverageRatingSum + rating) / ratingUserCount;		// 실질적인 평균 계산 로직 부분
			product.setAverageRating(updatedAverageRating);						// 새로 계산된 구매만족도 저장.
			product.setRatingUserCount(ratingUserCount);						// 추가된 평가에 참여한 사람 수 저장
			return true;
		}
	}
	return false;		// productList에 해당 상품명의 상품이 존재하지 않는 경우 평가 실패
}

/*
사용 유즈케이스 : 판매 상품 등록
내용 : 판매자가 상품을 등록함.
파라미터 : Product에서 판매자 아이디 / 상품명 / 제조회사 / 가격 / 초기수량 (string sellerId, string proudctName, string madeCompany, int price, int initialQuantity)
리턴 : 등록한 상품 (Product)
유의사항 : (1) 사용 시 파라미터 순서 엇갈리거나 empty 값 들어오지 않게 주의 필요
*/
Product ProductCollection::createNewProduct(string sellerId, string proudctName, string madeCompany, int price, int initialQuantity) {
	Product createdProduct(sellerId, proudctName, madeCompany, price, initialQuantity);	// Product 생성
	productList.push_back(createdProduct);												// 벡터에 삽입
	return createdProduct;																// 만든 Product 반환
}

/*
사용 유즈케이스 : 판매 중인 상품 조회
내용 : 판매자가 올린 상품 중 수량이 남아있는 것들만 반환함.
파라미터 : 판매자 아이디 (string sellerId)
리턴 : 판매 중인 상품 리스트 (vector<Product>)
*/
vector<Product> ProductCollection::checkOnSaleList(string sellerId) {
	vector<Product> onSaleProductList;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId && product.getRemainQuantity() > 0) {			// 판매자 아이디 일치 && 남은 수량 존재.
			onSaleProductList.push_back(product);											// 벡터에 추가
		}
	}
	return onSaleProductList;
}

/*
사용 유즈케이스 : 판매 완료된 상품 조회
내용 : 판매자가 올린 상품 중 없는 것들만 반환함.
파라미터 : 판매자 아이디 (string sellerId)
리턴 : 판매 완료된 상품 리스트 (vector<Product>)
*/
vector<Product> ProductCollection::checkSoldOutList(string sellerId) {
	vector<Product> soldOutProductList;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId && product.getRemainQuantity() <= 0) {	// 판매자 일치 && 남은 수량 확인.
			soldOutProductList.push_back(product);											// 벡터에 추가
		}
	}
	return soldOutProductList;
}

/*
	상품 구매 시 였나
*/
Product ProductCollection::getProductDetails(string productName) {
	for (Product product : productList) {
		if (product.getProductName() == productName) {
			return product;
		}
	}
	return Product(" ", " ", " ", -1, -1);	// 예외처리
}

/*
사용 유즈케이스 : 판매 상품 통계 출력  (그냥 회원)
내용 : 판매자가 올린 상품들에 대하여 통계 내용을 출력함. 
	   통계 내용은 상품 별로 판매 총액과 평균 구매만족도가 됨.
파라미터 : 판매자 아이디 (string sellerId)
리턴 : 상품명 / 상품 판매 총액 / 평균 구매 만족도 (map<string, pair<int, double>>)
유의 사항 : 리턴 시 map<상품명, pair<상품 판매 총액, 평균 구매만족도>> 가 되며
			꺼내 쓸 때는  상품명 = map.first	/  상품 판매 총액 = map.second.first  / 구매만족도 = map.second.second 로 사용.
*/
map<string, pair<int, double>> ProductCollection::getSoldStatistics(string sellerId) {
	map<string, pair<int, double>> resultMap;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId) {
			int soldMoney = product.getPrice() * (product.getInitialQuantity() - product.getRemainQuantity());	// 가격 * (초기 - 남은)
			double averageRating = product.getAverageRating();									// 평균 구매만족도
			resultMap.insert({ product.getProductName(), { soldMoney, averageRating} });		// map에 집어 넣음
		}
	}
	return resultMap;
}