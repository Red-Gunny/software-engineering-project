#include "../header/control/PurchaseHistory.h"
#include "../header/boundary/PurchaseHistoryUI.h"

/*
��� �������̽� : ���ų��� ��ȸ
���� : ���� ���� ����Ǵ� control ������. boundary�� ������ ��ȯ�ϰ� UI�Լ��� ȣ����.
�Ķ���� : ���������� / ���� ������ ���� ���� / product�÷��� (FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList)
���� : -
*/
PurchaseHistory::PurchaseHistory(FILE* inFilePtr, FILE* outFilePtr, User &currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	purchaseHistoryUi = new PurchaseHistoryUI(inFilePtr, outFilePtr, this);		// boundary ��ü ����
	purchaseHistoryUi->displayPurchaseHistoryUi();								// UI �Լ� ȣ��
}

/*
��� �������̽� : ���ų��� ��ȸ
���� : .
�Ķ���� : void
���� : ����ڰ� ������ Product����Ʈ (vector<Product>)
*/
vector<Product> PurchaseHistory::showPurchaseHistory() {
	vector<string> purchaseHistoryList = currentUser.getPurchaseHistoryList();	// �������� ȸ���� ��ǰ ���� ��ǰ�� ���
	vector<Product> purchaseProductList;
	for (string productName : purchaseHistoryList) {			
		Product purchaseProduct = productList->getProductDetails(productName);		// ��ǰ ������ ������.
		purchaseProductList.push_back(purchaseProduct);								// ����� ��ȯ�� ���Ϳ� ����
	}
	return purchaseProductList;
}