#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/PurchasableProductUI.h"
#include "../header/control/PurchasableProduct.h"

/*
��� �������̽� : ���� ���� ��ǰ ����Ʈ ��ȸ
���� : ����ڷκ��� ��ǰ���� �Է¹���.
�Ķ���� : void
���� : void
*/
void PurchasableProductUI::displaySearchUi() {
	char productName[MAX_STRING];
	fscanf(inFilePtr, "%s ", productName);		// ������� �Է�
	searchProduct(productName);					// �Է¿� �����ϴ� �Լ�
}

/*
��� �������̽� : ���� ���� ��ǰ ����Ʈ ��ȸ
���� : �Է¹��� ������ control���� �ѱ�� ���� ���� ����� ��½�Ŵ.
�Ķ���� : void
���� : void
*/
void PurchasableProductUI::searchProduct(char productName[]) {
	string castedProductName(productName);		// type casting
	Product resultProduct = purchasableProduct->showProduct(castedProductName);		// control�� ȣ��
	searchedProduct = resultProduct;
	fprintf(outFilePtr, "4.1. ��ǰ ���� �˻�\n");			// ���� ���� ��� ���
	fprintf(outFilePtr, "> %s %s %s %d %d %.0f\n", 
		resultProduct.getSellerId().c_str(),				// �Ǹ��� id
		resultProduct.getProductName().c_str(),				// ��ǰ��
		resultProduct.getMadeCompany().c_str(),				// ����ȸ��
		resultProduct.getPrice(),							// ����
		resultProduct.getRemainQuantity(),					// ���� ����
		resultProduct.getAverageRating()					// ��� ���Ÿ�����
	);
	fprintf(outFilePtr, "\n");								// ��� ���� ���߱�
}