#include "../header/control/EvaluateProduct.h"
#include "../header/boundary/EvaluateProductUI.h"

/*
��� �������̽� : ���� ������ ��
���� :���� ���� ����Ǵ� Control ������
�Ķ���� : ���������� / ��ǰ ����Ʈ. (FILE* inFilePtr, FILE* outFilePtr, Product& purchaseProduct, ProductCollection* productList)
���� : -
*/
EvaluateProduct::EvaluateProduct(FILE* inFilePtr, FILE* outFilePtr, ProductCollection* productList) {
	this->prouductList = productList;
	evaluateProductUi = new EvaluateProductUI(inFilePtr, outFilePtr, this);	// boundary ��ü ����
	evaluateProductUi->displayEvaluateForm();		// UI �Լ� ȣ��
}

/*
��� �������̽� : ���� ������ ��
���� : ���Ÿ������� ����. productcollection ȣ��
�Ķ���� : ���� ������ �� (string productName, int ratingValue)
���� : ������ Product �ν��Ͻ� (Product)
*/
Product EvaluateProduct::evaluateProduct(string productName, int ratingValue) {
	prouductList->evaluateSatisfactionRating(ratingValue, productName);	// productCollection ȣ��
	Product updatedProduct = prouductList->getProductDetails(productName);	// product�� �� ������ ����
	return updatedProduct;
}