#ifndef ADDNEWPRODUCTUI_H
#define ADDNEWPRODUCTUI_H

#include <iostream>
using namespace std;

#define MAX_STRING 100

class AddNewProduct;

/*
��� �������̽� : �ǸŻ�ǰ ���
���׷��� Ÿ�� : Boundary
*/
class AddNewProductUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	AddNewProduct* addNewProduct;
public:
	AddNewProductUI() {};
	AddNewProductUI(FILE* inFilePtr, FILE* outFilPtr, AddNewProduct* addNewProduct);
	void displayAddNewProductForm();

	void createNewProduct(char productName[], char madeCompany[], int price, int initialQuantity);
};

#endif