#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/EvaluateProductUI.h"
#include "../header/control/EvaluateProduct.h"

/*
사용 유즈케이스 : 구매 만족도 평가
내용 : Boundary 생성자. 필드 초기화
파라미터 : 파일포인터 / Control 클래스 포인터. (FILE* inFilePtr, FILE* outFilePtr, EvaluateProduct* evaluateProduct)
리턴 : -
*/
EvaluateProductUI::EvaluateProductUI(FILE* inFilePtr, FILE* outFilePtr, EvaluateProduct* evaluateProduct) {
	this->inFilePtr = inFilePtr;
	this->outFilePtr = outFilePtr;
	this->evaluateProduct = evaluateProduct;
}

/*
사용 유즈케이스 : 구매 만족도 평가
내용 : UI함수. 사용자로부터 입력받음
파라미터 : void
리턴 : void
*/
void EvaluateProductUI::displayEvaluateForm() {	// 버튼이 눌렸음
	int ratingValue;
	char productName[MAX_STRING];
	fscanf(inFilePtr, "%s %d ", productName, &ratingValue);				// 사용자가 입력했으면
	fillRatingValue(productName, ratingValue);							// 이벤트 처리 함수
}

/*
사용 유즈케이스 : 구매 만족도 평가
내용 : 받은 입력값을 control한테 전달하고 이후 받은 결과값을 출력함
파라미터 : 상품명 / 점수. (char productName[], int ratingValue)
리턴 : void
*/
void EvaluateProductUI::fillRatingValue(char productName[], int ratingValue) {
	string castedProductName(productName);	// 상품명 typeCasting
	if (1 <= ratingValue && ratingValue <= 5) {	// 범위 이내
		Product evaluatedProduct = evaluateProduct->evaluateProduct(castedProductName, ratingValue);
		fprintf(outFilePtr, "4.4. 상품 구매만족도 평가\n");			// 이하 받은 결과 기록
		if (evaluatedProduct.getPrice() == -1) {	// 예외처리 - 등록되지 않은 상품이라든가..
			fprintf(outFilePtr, "> \n\n");
			return;
		}
		fprintf(outFilePtr, "> %s %s %d\n",
			evaluatedProduct.getSellerId().c_str(),			// 판매자 id 출력
			evaluatedProduct.getProductName().c_str(),		// 상품명 출력
			ratingValue										// 구매만족도 출력
		);
	}
	else {
		fprintf(outFilePtr, "4.4. 상품 구매만족도 평가\n >\n");		// 예외 상황 - 점수가 범위 밖임
	}
	fprintf(outFilePtr, "\n");		// 교수님 출력형식에 맞추기
}