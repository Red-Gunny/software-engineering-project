#include "../header/control/AddNewProduct.h"

/*
사용 유즈케이스 : 판매 상품 등록
내용 : Collection을 호출해 실제 리스트에 인스턴스를 만들어 등록함
파라미터 : Product 인스턴스를 생성하는데 필요한 최소 정보 (string productName, string madeCompany, int price, int initialQuantity)
리턴 : 등록한 Product (Product)
*/
Product AddNewProduct::createNewProduct(string productName, string madeCompany, int price, int initialQuantity) {
	return productList->createNewProduct(
		currentUser.getId(),		// seller id
		productName,				// 상품명
		madeCompany,				// 제조회사명
		price,						// 가격
		initialQuantity				// 초기수량
	);
}