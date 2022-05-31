#include "../header/boundary/ProductSalesStatisticsUI.h"
#include "../header/control/ProductSalesStatistics.h"

/*
사용 유즈케이스 : 판매 통계 조회
내용 : UI함수. 사용자로부터 입력받는 메소드
파라미터 : void
리턴 : void
*/
void ProductSalesStatisticsUI::displayStatisticsButton() {
	requestProductSalesStatistics();
}

/*
사용 유즈케이스 : 판매 통계 조회
내용 : control을 호출하고 이후 받은 결과를 출력함.
파라미터 : void
리턴 : void
*/
void ProductSalesStatisticsUI::requestProductSalesStatistics() {
	auto result = statisticsControl->productSalesStatistics();	// boundary to control
	// 결과 출력
	fprintf(outFilePtr, "5.1. 판매 상품 통계\n");
	for (auto element : result) {
		fprintf(outFilePtr, "> %s %d %.0f\n",
			element.first.c_str(),				// 상품명 출력
			element.second.first,				// 가격 출력
			element.second.second				// 평균 구매만족도 출력
		);
	}
	fprintf(outFilePtr, "\n");
}