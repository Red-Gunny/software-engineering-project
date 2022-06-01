#ifndef EVALUATEPRODUCT_H
#define EVALUATEPRODUCT_H

#include "../../../entity/header/ProductCollection.h"
//#include "../boundary/EvaluateProductUI.h"

#include <iostream>
using namespace std;

class EvaluateProductUI;

/*
��� �������̽� : ���Ÿ����� ��
���׷��� Ÿ�� : Control
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
[���ܻ�Ȳ]
1. ��ǰ�� ��ϵ��� ���� ��ǰ�� ���Ͽ� ���Ϸ��� �õ��� ���	=>   productCollection�� getProductDetails()���� ó��.
2. ������ ������ ���� ��			=> boundary Ŭ������ fillRatingValue���� ó��
3. �α����� �� �Ǿ��� ��			=> main������ ó��.
*/
#endif