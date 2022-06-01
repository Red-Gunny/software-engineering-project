#include "../header/boundary/PurchaseUI.h"
#include "../header/control/Purchase.h"

void PurchaseUI::displayPurchaseButton() {
	clickPurchaseButton();
}

void PurchaseUI::clickPurchaseButton() {
	Product purchaseProduct = purchase->purchaseProduct();
	fprintf(outFilePtr, "4.2. 상품 구매\n");	// 이하 결과 기록
	if (purchaseProduct.getSellerId().empty()) {		// 구매실패  - 예외처리
		fprintf(outFilePtr, "\n");
		return;
	}
	fprintf(outFilePtr, "> %s %s \n",
		purchaseProduct.getSellerId().c_str(),	// 판매자 ID
		purchaseProduct.getProductName().c_str());	// 상품명
	fprintf(outFilePtr, "\n");
}