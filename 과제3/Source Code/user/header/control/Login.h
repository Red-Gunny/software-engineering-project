#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include "../../../entity/header/UserCollection.h"

class LoginUI;

/*
��� �������̽� : �α���
���׷��� Ÿ�� : Control
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