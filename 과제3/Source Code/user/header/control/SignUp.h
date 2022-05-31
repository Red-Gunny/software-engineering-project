#pragma once
#ifndef SIGNUP_H
#define SIGNUP_H

#include <iostream>
#include "../../../entity/header/UserCollection.h"
#include "../boundary/SignUpUI.h"
using namespace std;

/*
��� �������̽� : ȸ������
���׷��� Ÿ�� : Control
*/
class SignUp {
	UserCollection *userList;
	SignUpUI* signUpUi;
public:
	SignUp() {};
	SignUp(FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "SignUp ���� ����" << endl;
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