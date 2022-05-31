#pragma once
#ifndef SIGNUPUI_H
#define SIGNUPUI_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define MAX_STRING 100

class SignUp;

/*
��� �������̽� : ȸ������
���׷��� Ÿ�� : Boundary
*/
class SignUpUI {
	SignUp* signUp;
	FILE* inFilePtr; 
	FILE* outFilePtr;
public:
	SignUpUI() {};
	SignUpUI(FILE* inFilePtr, FILE* outFilePtr, SignUp* signUp = NULL) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->signUp = signUp;
	}

	// �Է� UI
	bool displaySignUpForm();
	bool requestSignUpUi(char userName[], char socialNumber[], char id[], char password[]);
};

#endif