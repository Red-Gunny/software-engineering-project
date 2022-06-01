#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/AddNewProductUI.h"
#include "../header/control/AddNewProduct.h"

/*
사용 유즈케이스 : 판매 상품 등록
내용 : Boundary 생성자
파라미터 :파일포인터 / Control 포인터 (FILE* inFilePtr, FILE* outFilePtr, AddNewProduct* addNewProduct)
리턴 : -
*/
AddNewProductUI::AddNewProductUI(FILE* inFilePtr, FILE* outFilePtr, AddNewProduct* addNewProduct) {
	this->inFilePtr = inFilePtr;
	this->outFilePtr = outFilePtr;
	this->addNewProduct = addNewProduct;
}

/*
사용 유즈케이스 : 판매 상품 등록
내용 : 사용자로부터 입력을 받는 함수 
파라미터 : void
리턴 : void
*/
void AddNewProductUI::displayAddNewProductForm() {
	char productName[MAX_STRING], madeCompany[MAX_STRING];
	int price, initialQuantity;
	fscanf(inFilePtr, "%s %s %d %d", productName, madeCompany, &price, &initialQuantity);
	createNewProduct(productName, madeCompany, price, initialQuantity);
}

/*
사용 유즈케이스 : 판매 상품 등록
내용 : 입력받은 내용은 control한테 전달하고 이후 받은 결과를 출력함.
파라미터 : 입력받은 상품 정보 (char productName[], char madeCompany[], int price, int initialQuantity)
리턴 : void
*/
void AddNewProductUI::createNewProduct(char productName[], char madeCompany[], int price, int initialQuantity) {
	string castedProductName(productName);
	string castedMadeCompany(madeCompany);
	Product createdProduct = addNewProduct->createNewProduct(castedProductName, castedMadeCompany, price, initialQuantity);	// boundary -> control
	fprintf(outFilePtr, "3.1. 판매 의류 등록\n");
	fprintf(outFilePtr, "> %s %s %d %d\n",
		createdProduct.getProductName().c_str(),		// 상품 정보
		createdProduct.getMadeCompany().c_str(),		// 제조 회사
		createdProduct.getPrice(),						// 가격
		createdProduct.getRemainQuantity()				// 수량
	);
	fprintf(outFilePtr, "\n");
}