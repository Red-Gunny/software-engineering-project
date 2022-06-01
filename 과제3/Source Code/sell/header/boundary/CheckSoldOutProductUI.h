#ifndef CHECKSOLDOUTPRODUCTUI_H
#define CHECKSOLDOUTPRODUCTUI_H

#include <iostream>
using namespace std;

class CheckSoldOutProduct;

/*
��� �������̽� : �Ǹ� �Ϸ� ��ǰ ��ȸ
���׷��� Ÿ�� : Boundary
*/
class CheckSoldOutProductUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	CheckSoldOutProduct* soldOutControl;
public:
	CheckSoldOutProductUI() {};
	CheckSoldOutProductUI(FILE* inFilePtr, FILE* outFilePtr, CheckSoldOutProduct* soldOutControl) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->soldOutControl = soldOutControl;
	}
	void displayCheckSoldOutProductUi(); 
	void checkSoldOutProduct();
};

#endif // !CHECKSOLDOUTPRODUCTUI_H
