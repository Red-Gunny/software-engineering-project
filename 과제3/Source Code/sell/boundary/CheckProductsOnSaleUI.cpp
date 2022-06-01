#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/CheckProductsOnSaleUI.h"
#include "../header/control/CheckProductsOnSale.h"

/*
사용 유즈케이스 : 판매 중인 상품 조회
내용 : UI함수. 사용자로부터 신호를 받음
파라미터 : 없음 (void)
리턴 : void
*/
void CheckProductsOnSaleUI::displayCheckProductsOnSaleUI() {
	checkProductsOnSale();		// 사용자 입력에 따른 이벤트 처리
}

/*
사용 유즈케이스 : 판매 중인 상품 조회
내용 : UI함수. 사용자로부터 신호를 받음
파라미터 : 없음 (void)
리턴 : void
*/
void CheckProductsOnSaleUI::checkProductsOnSale() {
	vector<Product> saleList = onSaleControl->showProductsOnSale();		// boundary to control
	fprintf(outFilePtr, "3.2. 등록 상품 조회\n");
	for (Product product : saleList) {			// result print
		fprintf(outFilePtr, "> %s %s %d %d\n",
			product.getProductName().c_str(),		// 상품명 기록
			product.getMadeCompany().c_str(),		// 제조회사 기록
			product.getPrice(),						// 가격 기록
			product.getRemainQuantity()				// 남은 수량 기록
		);
	}
	fprintf(outFilePtr, "\n");
}