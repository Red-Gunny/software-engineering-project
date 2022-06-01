#include "../header/control/CheckSoldOutProduct.h"

/*
사용 유즈케이스 : 판매 완료 상품 조회
내용 : Control 생성자. Boundary랑 참조를 교환하고 UI함수를 호출함.
파라미터 : 파일포인터 / 유저정보 / productList (FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList)
리턴 : -
*/
CheckSoldOutProduct::CheckSoldOutProduct(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	soldOutBoundary = new CheckSoldOutProductUI(inFilePtr, outFilePtr, this);		// boundary 인스턴스 생성
	soldOutBoundary->displayCheckSoldOutProductUi();								// UI함수 호출
}

/*
사용 유즈케이스 : 판매 완료 상품 조회
내용 : productList로 부터 판매 완료된 상품리스트를 받아옴
파라미터 : 없음 (void)
리턴 : 판매 완료된 상품목록 (vector<Product>)
*/
vector<Product> CheckSoldOutProduct::showSoldOutProduct() {
	return productList->checkSoldOutList(currentUser.getId());				// Collection 클래스 호출;
}