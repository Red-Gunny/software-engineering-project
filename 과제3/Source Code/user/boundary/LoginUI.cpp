#define _CRT_SECURE_NO_WARNINGS

#include "../header/boundary/LoginUI.h"

/*
��� �������̽� : �α���
���� : ����ڷκ��� �α��� ������ �Է¹���
�Ķ���� : void
���� : �α��� �õ��� ���� ���� (User)
*/
User LoginUI::displayLoginForm() {
	char id[MAX_STRING], password[MAX_STRING];
	fscanf(inFilePtr, "%s %s", id, password);				// ����ڰ� �Է�������
	return requestLogin(id, password);						// �̺�Ʈ �ڵ鷯 ȣ��.
}

/*
��� �������̽� : �α���
���� : �α��� ������ control���� �����ϰ� ���� ����� �����
�Ķ���� : ��������  (char id[] , char password[])
���� : �α��� �õ��� ���� ���� (User)
*/
User LoginUI::requestLogin(char id[], char password[]) {
	string castedId(id);							// String ��ü�� Ÿ�� ĳ����
	string castedPassword(password);				// String ��ü�� Ÿ�� ĳ����
	bool loginResult = login->login(castedId, castedPassword);		// Control���� ����.
	// ���� ��� ���
	fprintf(outFilePtr, "2.1. �α���\n");
	if (loginResult) {
		fprintf(outFilePtr, "> %s %s\n\n", id, password);
		return User(castedId, castedPassword);
	}
	else {
		fprintf(outFilePtr, "\n");
		return User(" ", " ");
	}
	
}