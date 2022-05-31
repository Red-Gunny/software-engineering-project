#include "../header/control/Login.h"
#include "../header/boundary/LoginUI.h"

/*
사용 유즈케이스 : 로그인
내용 : 로그인 시 가장 먼저 실행되는 control 생성자
파라미터 : 파일 포인터 / 시스템 전체 유저 리스트 (FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList)
리턴 : -
*/
Login::Login(FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList) {
	if (inFilePtr == NULL || outFilePtr == NULL) {
		cout << "Login클래스 생성 에러" << endl;
	}
	else {
		this->userList = userList;
		this->loginUi = new LoginUI(inFilePtr, outFilePtr, this);		// Control 클래스가 Boundary를 만듬
		currentUser = loginUi->displayLoginForm();						// Boundary에서 입력받는다.
	}
}

/*
사용 유즈케이스 : 로그인
내용 : 로그인 시 control한테 전달함.
파라미터 : 로그인 정보 (string id, string password)
리턴 : 로그인 결과 (bool)
*/
bool Login::login(string id, string password) {
	return userList->isValidUser(id, password);
}

/*
사용 유즈케이스 : 로그인
내용 : 시스템 전체 현재 로그인 중인 유저정보 반환 목적
파라미터 : void
리턴 : User
*/
User Login::getCurrentUser() {
	return currentUser;
}