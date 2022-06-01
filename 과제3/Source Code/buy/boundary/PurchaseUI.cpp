#include "../header/boundary/PurchaseUI.h"
#include "../header/control/Purchase.h"

void PurchaseUI::displayPurchaseButton() {
	clickPurchaseButton();
}

void PurchaseUI::clickPurchaseButton() {
	Product purchaseProduct = purchase->purchaseProduct();
	fprintf(outFilePtr, "4.2. ��ǰ ����\n");	// ���� ��� ���
	if (purchaseProduct.getSellerId().empty()) {		// ���Ž���  - ����ó��
		fprintf(outFilePtr, "\n");
		return;
	}
	fprintf(outFilePtr, "> %s %s \n",
		purchaseProduct.getSellerId().c_str(),	// �Ǹ��� ID
		purchaseProduct.getProductName().c_str());	// ��ǰ��
	fprintf(outFilePtr, "\n");
}