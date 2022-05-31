#include "../header/boundary/SignUpUI.h"
#include "../header/control/SignUp.h"

/*
사용 유즈케이스 : 회원가입
내용 : 사용자로부터 회원가입 관련 입력 정보를 받음 (UI 함수)
파라미터 : 없음 (void)
리턴 : 입력에 대한 응답 결과 성공적이면 true (bool)
*/
bool SignUpUI::displaySignUpForm() {
	char userName[MAX_STRING], socialNumber[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
	fscanf(inFilePtr, "%s %s %s %s", userName, socialNumber, id, password);		// 사용자의 입력
	return requestSignUpUi(userName, socialNumber, id, password);				// 입력에 대응하는 처리함수
}

/*
사용 유즈케이스 : 회원가입
내용 : 사용자 입력 이벤트를 처리하는 함수(콜백 함수)
	   control한테 전달함.
파라미터 : 사용자 입력값들 (char userName[], char socialNumber[], char id[], char password[])
리턴 : 입력에 대한 응답 결과 성공적이면 true (bool)
*/
bool SignUpUI::requestSignUpUi(char userName[], char socialNumber[], char id[], char password[]) {
	string castedUserName(userName);					// String 객체로 Type Casting	
	string castedSocialNumber(socialNumber);
	string castedId(id);
	string castedPassword(password);
	bool signUpResult = signUp->signUp(castedId, castedPassword, castedUserName, castedSocialNumber);	// control한테 전달.
	fprintf(outFilePtr, "1.1. 회원가입\n");		// 결과 기록
	if (signUpResult) {		// ID등 회원가입이 성공적인 경우에만
		fprintf(outFilePtr, "> %s %s %s %s\n", userName, socialNumber, id, password);	// 회원가입 성공적
	}
	fprintf(outFilePtr, "\n");					// 교수님 출력 형식 예시에 맞추기 위함.
	return signUpResult;
}