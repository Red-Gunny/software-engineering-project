#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/CheckProductsOnSaleUI.h"
#include "../header/control/CheckProductsOnSale.h"

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���� : UI�Լ�. ����ڷκ��� ��ȣ�� ����
�Ķ���� : ���� (void)
���� : void
*/
void CheckProductsOnSaleUI::displayCheckProductsOnSaleUI() {
	checkProductsOnSale();		// ����� �Է¿� ���� �̺�Ʈ ó��
}

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���� : UI�Լ�. ����ڷκ��� ��ȣ�� ����
�Ķ���� : ���� (void)
���� : void
*/
void CheckProductsOnSaleUI::checkProductsOnSale() {
	vector<Product> saleList = onSaleControl->showProductsOnSale();		// boundary to control
	fprintf(outFilePtr, "3.2. ��� ��ǰ ��ȸ\n");
	for (Product product : saleList) {			// result print
		fprintf(outFilePtr, "> %s %s %d %d\n",
			product.getProductName().c_str(),		// ��ǰ�� ���
			product.getMadeCompany().c_str(),		// ����ȸ�� ���
			product.getPrice(),						// ���� ���
			product.getRemainQuantity()				// ���� ���� ���
		);
	}
	fprintf(outFilePtr, "\n");
}