#include "../header/control/PurchaseHistory.h"
#include "../header/boundary/PurchaseHistoryUI.h"

/*
사용 유즈케이스 : 구매내역 조회
내용 : 가장 먼저 실행되는 control 생성자. boundary와 참조를 교환하고 UI함수를 호출함.
파라미터 : 파일포인터 / 현재 접속한 유저 정보 / product컬렉션 (FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList)
리턴 : -
*/
PurchaseHistory::PurchaseHistory(FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	purchaseHistoryUi = new PurchaseHistoryUI(inFilePtr, outFilePtr, this);		// boundary 객체 생성
	purchaseHistoryUi->displayPurchaseHistoryUi();								// UI 함수 호출
}

/*
사용 유즈케이스 : 구매내역 조회
내용 : .
파라미터 : void
리턴 : 사용자가 구매한 Product리스트 (vector<Product>)
*/
vector<Product> PurchaseHistory::showPurchaseHistory() {
	vector<string> purchaseHistoryList = currentUser.getPurchaseHistoryList();	// 접속중인 회원의 상품 구매 상품명 목록
	vector<Product> purchaseProductList;
	for (string productName : purchaseHistoryList) {			
		Product purchaseProduct = productList->getProductDetails(productName);		// 상품 정보를 가져옴.
		purchaseProductList.push_back(purchaseProduct);								// 결과를 반환할 벡터에 담음
	}
	return purchaseProductList;
}