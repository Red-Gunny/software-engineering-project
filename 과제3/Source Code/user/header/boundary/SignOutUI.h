#pragma once
#ifndef SIGNOUTUI_H
#define SIGNOUTUI_H

#include <iostream>
using namespace std;

class SignOut;		// 클래스 상호참조 오류 방지용

/*
사용 유즈케이스 : 회원탈퇴
스테레오 타입 : Boundary
*/
class SignOutUI {
	SignOut* signOut;
	FILE* inFilePtr;
	FILE* outFilePtr;
public:
	SignOutUI() {};
	SignOutUI(FILE* inFilePtr, FILE* outFilePtr, SignOut* signOut) {
		this->inFilePtr = inFilePtr;
		this->outFilePtr = outFilePtr;
		this->signOut = signOut;
	}

	void displaySignOutButton();
	void requestSignOut();
};
#endif