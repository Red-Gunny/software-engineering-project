#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/EvaluateProductUI.h"
#include "../header/control/EvaluateProduct.h"

/*
��� �������̽� : ���� ������ ��
���� : Boundary ������. �ʵ� �ʱ�ȭ
�Ķ���� : ���������� / Control Ŭ���� ������. (FILE* inFilePtr, FILE* outFilePtr, EvaluateProduct* evaluateProduct)
���� : -
*/
EvaluateProductUI::EvaluateProductUI(FILE* inFilePtr, FILE* outFilePtr, EvaluateProduct* evaluateProduct) {
	this->inFilePtr = inFilePtr;
	this->outFilePtr = outFilePtr;
	this->evaluateProduct = evaluateProduct;
}

/*
��� �������̽� : ���� ������ ��
���� : UI�Լ�. ����ڷκ��� �Է¹���
�Ķ���� : void
���� : void
*/
void EvaluateProductUI::displayEvaluateForm() {	// ��ư�� ������
	int ratingValue;
	char productName[MAX_STRING];
	fscanf(inFilePtr, "%s %d ", productName, &ratingValue);				// ����ڰ� �Է�������
	fillRatingValue(productName, ratingValue);							// �̺�Ʈ ó�� �Լ�
}

/*
��� �������̽� : ���� ������ ��
���� : ���� �Է°��� control���� �����ϰ� ���� ���� ������� �����
�Ķ���� : ��ǰ�� / ����. (char productName[], int ratingValue)
���� : void
*/
void EvaluateProductUI::fillRatingValue(char productName[], int ratingValue) {
	string castedProductName(productName);	// ��ǰ�� typeCasting
	if (1 <= ratingValue && ratingValue <= 5) {	// ���� �̳�
		Product evaluatedProduct = evaluateProduct->evaluateProduct(castedProductName, ratingValue);
		fprintf(outFilePtr, "4.4. ��ǰ ���Ÿ����� ��\n");			// ���� ���� ��� ���
		if (evaluatedProduct.getPrice() == -1) {	// ����ó�� - ��ϵ��� ���� ��ǰ�̶�簡..
			fprintf(outFilePtr, "> \n\n");
			return;
		}
		fprintf(outFilePtr, "> %s %s %d\n",
			evaluatedProduct.getSellerId().c_str(),			// �Ǹ��� id ���
			evaluatedProduct.getProductName().c_str(),		// ��ǰ�� ���
			ratingValue										// ���Ÿ����� ���
		);
	}
	else {
		fprintf(outFilePtr, "4.4. ��ǰ ���Ÿ����� ��\n >\n");		// ���� ��Ȳ - ������ ���� ����
	}
	fprintf(outFilePtr, "\n");		// ������ ������Ŀ� ���߱�
}