#include "../header/boundary/PurchaseHistoryUI.h"
#include "../header/control/PurchaseHistory.h"

/*
��� �������̽� : ���ų��� ��ȸ
���� : ����ڷκ��� �Է¹޴� UI�Լ�.
�Ķ���� : void
���� : void
*/
void PurchaseHistoryUI::displayPurchaseHistoryUi() {
	checkPurchaseHistory();
}

/*
��� �������̽� : ���ų��� ��ȸ
���� : �Է��� control�� �����ϰ�, ���� ���� ����� �����.
�Ķ���� : void
���� : void
*/
void PurchaseHistoryUI::checkPurchaseHistory() {
	vector<Product> purchaseHistoryList = purchaseHistory->showPurchaseHistory();	// ��Ʈ��
	fprintf(outFilePtr, "4.3. ��ǰ ���� ���� ��ȸ\n");			// ���� ���� ��� ���
	if (purchaseHistoryList.size() == 0) {
		fprintf(outFilePtr, "> \n\n");
		return;
	}
	for (Product product : purchaseHistoryList) {		// ����Ʈ ������ ���� �� ���� ��
		fprintf(outFilePtr, "> %s %s %s %d %d %.0f\n",
			product.getSellerId().c_str(),					// �Ǹ��� ID ���
			product.getProductName().c_str(),				// ��ǰ�� ���
			product.getMadeCompany().c_str(),				// ����ȸ�� ���
			product.getPrice(),								// ���� ���
			product.getRemainQuantity(),					// ���� ���� ���
			product.getAverageRating()						// ��� ���� ������ ���
		);
	}
	fprintf(outFilePtr, "\n");		// ������ ������� ���߱�
}

void printResult(vector<Product> purchaseHistoryList);