#include "../header/control/EvaluateProduct.h"
#include "../header/boundary/EvaluateProductUI.h"

/*
사용 유즈케이스 : 구매 만족도 평가
내용 :가장 먼저 실행되는 Control 생성자
파라미터 : 파일포인터 / 상품 리스트. (FILE* inFilePtr, FILE* outFilePtr, Product& purchaseProduct, ProductCollection* productList)
리턴 : -
*/
EvaluateProduct::EvaluateProduct(FILE* inFilePtr, FILE* outFilePtr, ProductCollection* productList) {
	this->prouductList = productList;
	evaluateProductUi = new EvaluateProductUI(inFilePtr, outFilePtr, this);	// boundary 객체 생성
	evaluateProductUi->displayEvaluateForm();		// UI 함수 호출
}

/*
사용 유즈케이스 : 구매 만족도 평가
내용 : 구매만족도를 평가함. productcollection 호출
파라미터 : 구매 만족도 값 (string productName, int ratingValue)
리턴 : 수정된 Product 인스턴스 (Product)
*/
Product EvaluateProduct::evaluateProduct(string productName, int ratingValue) {
	prouductList->evaluateSatisfactionRating(ratingValue, productName);	// productCollection 호출
	Product updatedProduct = prouductList->getProductDetails(productName);	// product의 각 정보를 받음
	return updatedProduct;
}