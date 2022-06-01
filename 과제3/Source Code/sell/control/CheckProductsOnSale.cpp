#include "../header/control/CheckProductsOnSale.h"

/*
사용 유즈케이스 : 판매 중인 상품 조회
내용 : productList로 부터 현재 판매 중인 상품들을 받아 옴.
파라미터 : 없음 (void)
리턴 : 판매자의 Product리스트 (vector<Product>)
*/
vector<Product> CheckProductsOnSale::showProductsOnSale() {
	return productList->checkOnSaleList(currentUser.getId());
}