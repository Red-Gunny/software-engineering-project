#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/LoginUI.h"

/*
사용 유즈케이스 : 로그인
내용 : 사용자로부터 로그인 정보를 입력받음
파라미터 : void
리턴 : 로그인 시도한 유저 정보 (User)
*/
User LoginUI::displayLoginForm() {
	char id[MAX_STRING], password[MAX_STRING];
	fscanf(inFilePtr, "%s %s", id, password);				// 사용자가 입력했으면
	return requestLogin(id, password);						// 이벤트 핸들러 호출.
}

/*
사용 유즈케이스 : 로그인
내용 : 로그인 정보를 control한테 전달하고 이후 결과를 출력함
파라미터 : 유저정보  (char id[] , char password[])
리턴 : 로그인 시도한 유저 정보 (User)
*/
User LoginUI::requestLogin(char id[], char password[]) {
	string castedId(id);							// String 객체로 타입 캐스팅
	string castedPassword(password);				// String 객체로 타입 캐스팅
	bool loginResult = login->login(castedId, castedPassword);		// Control한테 전달.
	// 이하 결과 기록
	fprintf(outFilePtr, "2.1. 로그인\n");
	if (loginResult) {
		fprintf(outFilePtr, "> %s %s\n\n", id, password);
		return User(castedId, castedPassword);
	}
	else {
		fprintf(outFilePtr, "\n");
		return User(" ", " ");
	}
	
}