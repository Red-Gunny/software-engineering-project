#pragma once
#ifndef SIGNOUT_H
#define SIGNOUT_H

#include "../../../entity/header/UserCollection.h"
#include "../boundary/SignOutUI.h"

/*
��� �������̽� : ȸ��Ż��
���׷��� Ÿ�� : Control
*/
class SignOut {
	UserCollection *userList;
	SignOutUI* signOutUi;
	User *currentUser;
public:
	SignOut() {};
	SignOut(FILE* inFilePtr, FILE* outFilePtr, User *currentUser, UserCollection* userList) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "SignOut ���� ����" << endl;
		}
		else {
			this->userList = userList;
			this->currentUser = currentUser;
			signOutUi = new SignOutUI(inFilePtr, outFilePtr, this);
			signOutUi->displaySignOutButton();
		}
	}

	~SignOut() {
		delete signOutUi;
	}

	User signOut();
};

#endif 


