#ifndef LOGOUTUI_H
#define LOGOUTUI_H

#define MAX_STRING 100

#include <iostream>
using namespace std;

class Logout;

/*
��� �������̽� : �α׾ƿ�
���׷��� Ÿ�� : Boundary
*/
class LogoutUI {
	FILE* inFilePtr, * outFilePtr;
	Logout* logout;
public:
	LogoutUI() {};
	LogoutUI(FILE* inFilePtr, FILE* outFilePtr, Logout* logout) {
		if (logout == NULL) {
			cout << "[ERROR] logout is NULL" << endl;
		}
		else {
			this->inFilePtr = inFilePtr;
			this->outFilePtr = outFilePtr;
			this->logout = logout;
		}
	}

	void displayLogoutButton();
	void requestLogout();
};

#endif