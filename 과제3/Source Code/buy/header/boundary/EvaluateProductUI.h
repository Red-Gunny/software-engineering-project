#ifndef EVALUATEPRODUCTUI_H
#define EVALUATEPRODUCTUI_H

#include "../control/EvaluateProduct.h"

#include <iostream>
using namespace std;

#define MAX_STRING 100

class EvaluateProduct;

/*
사용 유즈케이스 : 구매만족도 평가
스테레오 타입 : Boundary
*/
class EvaluateProductUI {
	FILE* inFilePtr;
	FILE* outFilePtr;
	EvaluateProduct* evaluateProduct;
public :
	EvaluateProductUI() {};
	EvaluateProductUI(FILE* inFilePtr, FILE* outFilePtr, EvaluateProduct* evaluateProduct);

	void displayEvaluateForm();
	void fillRatingValue(char productName[], int ratingValue);
};

#endif