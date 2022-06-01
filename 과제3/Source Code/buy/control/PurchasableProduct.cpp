#include "../header/control/PurchasableProduct.h"

/*
사용 유즈케이스 : 구매 가능 상품 리스트 조회
내용 : 상품명에 따른 정보를 보여줌
파라미터 : void
리턴 : void
*/
Product PurchasableProduct::showProduct(string productName) {
	vector<Product> resultProductList = productList->getPurchasableProduct(productName);	// proudctList에서 가져옴
	if (resultProductList.size() == 0) {
		return Product(" ", " ", " ", -1, -1);	// 예외 처리
	}
	return resultProductList.front();		// 결과를 반환함
}

/*
사용 유즈케이스 : 구매 가능 상품 리스트 조회
내용 : 시스템에서 main문에서 활용되기 위한 목적
파라미터 : void
리턴 : 구매가능한 상품 (Product)
*/
Product PurchasableProduct::getSearchProduct() {
	return purchasableProductUi->getSearchedProduct();	// 이후 상품 구매와 연결됨.
}