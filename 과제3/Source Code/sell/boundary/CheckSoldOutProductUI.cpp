#include "../header/boundary/CheckSoldOutProductUI.h"
#include "../header/control/CheckSoldOutProduct.h"


/*
사용 유즈케이스 : 판매 완료 상품 조회
내용 : UI함수. 사용자로부터 입력을 받음
파라미터 : 없음 (void)
리턴 : void
*/
void CheckSoldOutProductUI::displayCheckSoldOutProductUi() {
	checkSoldOutProduct();									// 이벤트 핸들러 호출
}

/*
사용 유즈케이스 : 판매 중인 상품 조회
내용 : 사용자 입력을 control한테 전달하고 이후 결과를 출력함.
파라미터 : 없음 (void)
리턴 : void
*/
void CheckSoldOutProductUI::checkSoldOutProduct() {
	vector<Product> soldOutList = soldOutControl->showSoldOutProduct();		// boundary to control
	fprintf(outFilePtr, "3.3. 판매 완료 상품 조회\n");
	for (Product product : soldOutList) {
		fprintf(outFilePtr, "> %s %s %d %d %.0lf\n",
			product.getProductName().c_str(),				// 상품명
			product.getMadeCompany().c_str(),				// 제조회사
			product.getPrice(),								// 가격
			product.getInitialQuantity() - product.getRemainQuantity(),										// 판매된 수량.
			product.getAverageRating()						// 평균 구매 만족도
		);
	}
	fprintf(outFilePtr, "\n");
}