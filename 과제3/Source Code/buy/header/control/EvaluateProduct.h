#ifndef EVALUATEPRODUCT_H
#define EVALUATEPRODUCT_H

#include "../../../entity/header/ProductCollection.h"
//#include "../boundary/EvaluateProductUI.h"

#include <iostream>
using namespace std;

class EvaluateProductUI;

/*
사용 유즈케이스 : 구매만족도 평가
스테레오 타입 : Control
*/
class EvaluateProduct {
	EvaluateProductUI* evaluateProductUi;
	ProductCollection* prouductList;
public:
	EvaluateProduct() {};
	EvaluateProduct(FILE* inFilePtr, FILE* outFilePtr, ProductCollection* productList);
	~EvaluateProduct() { delete evaluateProductUi; }
	Product evaluateProduct(string productName, int ratingValue);
};

/*
[예외상황]
1. 상품이 등록되지 않은 상품에 대하여 평가하려고 시도할 경우	=>   productCollection의 getProductDetails()에서 처리.
2. 만족도 점수가 범위 밖			=> boundary 클래스의 fillRatingValue에서 처리
3. 로그인이 안 되었을 때			=> main문에서 처리.
*/
#endif