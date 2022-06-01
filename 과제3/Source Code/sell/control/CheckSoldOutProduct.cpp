#include "../header/control/CheckSoldOutProduct.h"

/*
��� �������̽� : �Ǹ� �Ϸ� ��ǰ ��ȸ
���� : Control ������. Boundary�� ������ ��ȯ�ϰ� UI�Լ��� ȣ����.
�Ķ���� : ���������� / �������� / productList (FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList)
���� : -
*/
CheckSoldOutProduct::CheckSoldOutProduct(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	soldOutBoundary = new CheckSoldOutProductUI(inFilePtr, outFilePtr, this);		// boundary �ν��Ͻ� ����
	soldOutBoundary->displayCheckSoldOutProductUi();								// UI�Լ� ȣ��
}

/*
��� �������̽� : �Ǹ� �Ϸ� ��ǰ ��ȸ
���� : productList�� ���� �Ǹ� �Ϸ�� ��ǰ����Ʈ�� �޾ƿ�
�Ķ���� : ���� (void)
���� : �Ǹ� �Ϸ�� ��ǰ��� (vector<Product>)
*/
vector<Product> CheckSoldOutProduct::showSoldOutProduct() {
	return productList->checkSoldOutList(currentUser.getId());				// Collection Ŭ���� ȣ��;
}