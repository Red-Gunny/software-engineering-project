#ifndef LOGOUT_H
#define LOGOUT_H

#include "../boundary/LogoutUI.h"
#include "../../../entity/header/User.h"

/*
사용 유즈케이스 : 로그아웃
스테레오 타입 : Control
*/
class Logout {
	LogoutUI* logoutUi=NULL;
	User* currentUser;
public: 
	Logout() {};
	Logout(FILE* inFilePtr, FILE* outFilePtr, User* currentUser) {
		if (inFilePtr == NULL || outFilePtr == NULL) {
			cout << "Logout 생성 에러" << endl;
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