#pragma once
#ifndef SIGNOUTUI_H
#define SIGNOUTUI_H

#include <iostream>
using namespace std;

class SignOut;		// Ŭ���� ��ȣ���� ���� ������

/*
��� �������̽� : ȸ��Ż��
���׷��� Ÿ�� : Boundary
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