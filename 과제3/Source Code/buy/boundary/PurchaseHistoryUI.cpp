#include "../header/boundary/PurchaseHistoryUI.h"
#include "../header/control/PurchaseHistory.h"

/*
사용 유즈케이스 : 구매내역 조회
내용 : 사용자로부터 입력받는 UI함수.
파라미터 : void
리턴 : void
*/
void PurchaseHistoryUI::displayPurchaseHistoryUi() {
	checkPurchaseHistory();
}

/*
사용 유즈케이스 : 구매내역 조회
내용 : 입력을 control로 전달하고, 이후 받은 결과를 출력함.
파라미터 : void
리턴 : void
*/
void PurchaseHistoryUI::checkPurchaseHistory() {
	vector<Product> purchaseHistoryList = purchaseHistory->showPurchaseHistory();	// 컨트롤
	fprintf(outFilePtr, "4.3. 상품 구매 내역 조회\n");			// 이하 받은 결과 기록
	if (purchaseHistoryList.size() == 0) {
		fprintf(outFilePtr, "> \n\n");
		return;
	}
	for (Product product : purchaseHistoryList) {		// 리스트 없으면 루프 안 돌게 됨
		fprintf(outFilePtr, "> %s %s %s %d %d %.0f\n",
			product.getSellerId().c_str(),					// 판매자 ID 출력
			product.getProductName().c_str(),				// 상품명 출력
			product.getMadeCompany().c_str(),				// 제조회사 출력
			product.getPrice(),								// 가격 출력
			product.getRemainQuantity(),					// 남은 수량 출력
			product.getAverageRating()						// 평균 구매 만족도 출력
		);
	}
	fprintf(outFilePtr, "\n");		// 교수님 출력형식 맞추기
}

void printResult(vector<Product> purchaseHistoryList);