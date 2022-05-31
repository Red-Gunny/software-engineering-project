#pragma once
#ifndef SIGNUP_H
#define SIGNUP_H

#include <iostream>
#include "../../../entity/header/UserCollection.h"
#include "../boundary/SignUpUI.h"
using namespace std;

/*
사용 유즈케이스 : 회원가입
스테레오 타입 : Control
*/
class SignUp {
	UserCollection *userList;
	SignUpUI* signUpUi;
public:
	SignUp() {};
	SignUp(FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "SignUp 생성 에러" << endl;
		}
		else {
			this->userList = userList;
			signUpUi = new SignUpUI(inFilePtr, outFilePtr, this);
			signUpUi->displaySignUpForm();
		}
	}

	~SignUp() {
		delete signUpUi;
	}

	bool signUp(string id, string password, string userName, string socialNumber);
};

#endif