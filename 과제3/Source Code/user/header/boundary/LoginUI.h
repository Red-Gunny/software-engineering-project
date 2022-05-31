#pragma once
#ifndef LOGINUI_H
#define LOGINUI_H

#define MAX_STRING 100
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "../control/Login.h"
using namespace std;

//class Login;

/*
사용 유즈케이스 : 로그인
스테레오 타입 : Boundary
*/
class LoginUI {
	Login* login;
	FILE* inFilePtr;
	FILE* outFilePtr;
public:
	LoginUI() {};
	LoginUI(FILE* inFilePtr, FILE* outFilePtr, Login* login) {
		this->login = login;
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
	}

	User displayLoginForm();
	User requestLogin(char id[], char password[]);
};
#endif