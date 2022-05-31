#pragma once
#ifndef SIGNOUT_H
#define SIGNOUT_H

#include "../../../entity/header/UserCollection.h"
#include "../boundary/SignOutUI.h"

/*
사용 유즈케이스 : 회원탈퇴
스테레오 타입 : Control
*/
class SignOut {
	UserCollection *userList;
	SignOutUI* signOutUi;
	User *currentUser;
public:
	SignOut() {};
	SignOut(FILE* inFilePtr, FILE* outFilePtr, User *currentUser, UserCollection* userList) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "SignOut 생성 에러" << endl;
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


