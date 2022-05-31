#include "../header/control/ProductSalesStatistics.h"

/*
사용 유즈케이스 : 판매 통계 조회
내용 : 가장 먼저 실행되는 control 생성자. bonudary하고 참조를 교환함. 이후 boundary의 UI함수를 호출함.
파라미터 : 파일포인터 / 현재 접속중인 유저 정보 / 상품리스트 (FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList)
리턴 : -
*/
ProductSalesStatistics::ProductSalesStatistics(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	this->statisticsBoundary = new ProductSalesStatisticsUI(inFilePtr, outFilePtr, this);
	statisticsBoundary->displayStatisticsButton();
}

/*
사용 유즈케이스 : 판매 통계 조회
내용 : 현재 접속중인 사용자의 ID를 바탕으로  ProductCollection를 호출해 각종 통계정보를 받아냄.
파라미터 : void
리턴 : 필요한 통계정보를 STL형태 (map <상품명, pair<가격, 평균 구매만족도>>)
*/
map<string, pair<int, double>> ProductSalesStatistics::productSalesStatistics() {
	return productList->getSoldStatistics(currentUser.getId());		// 컬렉션 클래스 호출
}