#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/PurchasableProductUI.h"
#include "../header/control/PurchasableProduct.h"

/*
사용 유즈케이스 : 구매 가능 상품 리스트 조회
내용 : 사용자로부터 상품명을 입력받음.
파라미터 : void
리턴 : void
*/
void PurchasableProductUI::displaySearchUi() {
	char productName[MAX_STRING];
	fscanf(inFilePtr, "%s ", productName);		// 사용자의 입력
	searchProduct(productName);					// 입력에 대응하는 함수
}

/*
사용 유즈케이스 : 구매 가능 상품 리스트 조회
내용 : 입력받은 정보를 control한테 넘기고 이후 받은 결과를 출력시킴.
파라미터 : void
리턴 : void
*/
void PurchasableProductUI::searchProduct(char productName[]) {
	string castedProductName(productName);		// type casting
	Product resultProduct = purchasableProduct->showProduct(castedProductName);		// control을 호출
	searchedProduct = resultProduct;
	fprintf(outFilePtr, "4.1. 상품 정보 검색\n");			// 이하 받은 결과 기록
	fprintf(outFilePtr, "> %s %s %s %d %d %.0f\n", 
		resultProduct.getSellerId().c_str(),				// 판매자 id
		resultProduct.getProductName().c_str(),				// 상품명
		resultProduct.getMadeCompany().c_str(),				// 제조회사
		resultProduct.getPrice(),							// 가격
		resultProduct.getRemainQuantity(),					// 남은 수량
		resultProduct.getAverageRating()					// 평균 구매만족도
	);
	fprintf(outFilePtr, "\n");								// 출력 형식 맞추기
}