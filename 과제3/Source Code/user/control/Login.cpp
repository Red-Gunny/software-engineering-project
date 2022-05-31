#include "../header/control/Login.h"
#include "../header/boundary/LoginUI.h"

/*
��� �������̽� : �α���
���� : �α��� �� ���� ���� ����Ǵ� control ������
�Ķ���� : ���� ������ / �ý��� ��ü ���� ����Ʈ (FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList)
���� : -
*/
Login::Login(FILE* inFilePtr, FILE* outFilePtr, UserCollection* userList) {
	if (inFilePtr == NULL || outFilePtr == NULL) {
		cout << "LoginŬ���� ���� ����" << endl;
	}
	else {
		this->userList = userList;
		this->loginUi = new LoginUI(inFilePtr, outFilePtr, this);		// Control Ŭ������ Boundary�� ����
		currentUser = loginUi->displayLoginForm();						// Boundary���� �Է¹޴´�.
	}
}

/*
��� �������̽� : �α���
���� : �α��� �� control���� ������.
�Ķ���� : �α��� ���� (string id, string password)
���� : �α��� ��� (bool)
*/
bool Login::login(string id, string password) {
	return userList->isValidUser(id, password);
}

/*
��� �������̽� : �α���
���� : �ý��� ��ü ���� �α��� ���� �������� ��ȯ ����
�Ķ���� : void
���� : User
*/
User Login::getCurrentUser() {
	return currentUser;
}