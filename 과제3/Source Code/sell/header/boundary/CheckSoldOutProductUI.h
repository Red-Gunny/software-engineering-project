#ifndef CHECKSOLDOUTPRODUCTUI_H
#define CHECKSOLDOUTPRODUCTUI_H

#include <iostream>
using namespace std;

class CheckSoldOutProduct;

/*
사용 유즈케이스 : 판매 완료 상품 조회
스테레오 타입 : Boundary
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
