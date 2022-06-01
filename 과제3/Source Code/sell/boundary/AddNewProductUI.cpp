#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/AddNewProductUI.h"
#include "../header/control/AddNewProduct.h"

/*
��� �������̽� : �Ǹ� ��ǰ ���
���� : Boundary ������
�Ķ���� :���������� / Control ������ (FILE* inFilePtr, FILE* outFilePtr, AddNewProduct* addNewProduct)
���� : -
*/
AddNewProductUI::AddNewProductUI(FILE* inFilePtr, FILE* outFilePtr, AddNewProduct* addNewProduct) {
	this->inFilePtr = inFilePtr;
	this->outFilePtr = outFilePtr;
	this->addNewProduct = addNewProduct;
}

/*
��� �������̽� : �Ǹ� ��ǰ ���
���� : ����ڷκ��� �Է��� �޴� �Լ� 
�Ķ���� : void
���� : void
*/
void AddNewProductUI::displayAddNewProductForm() {
	char productName[MAX_STRING], madeCompany[MAX_STRING];
	int price, initialQuantity;
	fscanf(inFilePtr, "%s %s %d %d", productName, madeCompany, &price, &initialQuantity);
	createNewProduct(productName, madeCompany, price, initialQuantity);
}

/*
��� �������̽� : �Ǹ� ��ǰ ���
���� : �Է¹��� ������ control���� �����ϰ� ���� ���� ����� �����.
�Ķ���� : �Է¹��� ��ǰ ���� (char productName[], char madeCompany[], int price, int initialQuantity)
���� : void
*/
void AddNewProductUI::createNewProduct(char productName[], char madeCompany[], int price, int initialQuantity) {
	string castedProductName(productName);
	string castedMadeCompany(madeCompany);
	Product createdProduct = addNewProduct->createNewProduct(castedProductName, castedMadeCompany, price, initialQuantity);	// boundary -> control
	fprintf(outFilePtr, "3.1. �Ǹ� �Ƿ� ���\n");
	fprintf(outFilePtr, "> %s %s %d %d\n",
		createdProduct.getProductName().c_str(),		// ��ǰ ����
		createdProduct.getMadeCompany().c_str(),		// ���� ȸ��
		createdProduct.getPrice(),						// ����
		createdProduct.getRemainQuantity()				// ����
	);
	fprintf(outFilePtr, "\n");
}