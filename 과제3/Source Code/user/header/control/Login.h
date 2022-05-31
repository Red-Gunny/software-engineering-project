#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include "../../../entity/header/UserCollection.h"

class LoginUI;

/*
사용 유즈케이스 : 로그인
스테레오 타입 : Control
*/
class Login {
	UserCollection *userList;
	LoginUI* loginUi;
	User currentUser;
public:
	Login() {};
	Login(FILE* inFilePt, FILE* outFilePtr, UserCollection* userList);
	bool login(string id, string password);
	User getCurrentUser();
};
#endif