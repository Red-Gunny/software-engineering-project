#ifndef LOGOUT_H
#define LOGOUT_H

#include "../boundary/LogoutUI.h"
#include "../../../entity/header/User.h"

/*
��� �������̽� : �α׾ƿ�
���׷��� Ÿ�� : Control
*/
class Logout {
	LogoutUI* logoutUi=NULL;
	User* currentUser;
public: 
	Logout() {};
	Logout(FILE* inFilePtr, FILE* outFilePtr, User* currentUser) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "Logout ���� ����" << endl;
		}
		else {
			this->currentUser = currentUser;
			this->logoutUi = new LogoutUI(inFilePtr, outFilePtr, this);
			this->logoutUi->displayLogoutButton();							// UI
		}
	}

	User logout();
};
#endif