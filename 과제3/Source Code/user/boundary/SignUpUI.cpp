#include "../header/boundary/SignUpUI.h"
#include "../header/control/SignUp.h"

/*
��� �������̽� : ȸ������
���� : ����ڷκ��� ȸ������ ���� �Է� ������ ���� (UI �Լ�)
�Ķ���� : ���� (void)
���� : �Է¿� ���� ���� ��� �������̸� true (bool)
*/
bool SignUpUI::displaySignUpForm() {
	char userName[MAX_STRING], socialNumber[MAX_STRING], id[MAX_STRING], password[MAX_STRING];
	fscanf(inFilePtr, "%s %s %s %s", userName, socialNumber, id, password);		// ������� �Է�
	return requestSignUpUi(userName, socialNumber, id, password);				// �Է¿� �����ϴ� ó���Լ�
}

/*
��� �������̽� : ȸ������
���� : ����� �Է� �̺�Ʈ�� ó���ϴ� �Լ�(�ݹ� �Լ�)
	   control���� ������.
�Ķ���� : ����� �Է°��� (char userName[], char socialNumber[], char id[], char password[])
���� : �Է¿� ���� ���� ��� �������̸� true (bool)
*/
bool SignUpUI::requestSignUpUi(char userName[], char socialNumber[], char id[], char password[]) {
	string castedUserName(userName);					// String ��ü�� Type Casting	
	string castedSocialNumber(socialNumber);
	string castedId(id);
	string castedPassword(password);
	bool signUpResult = signUp->signUp(castedId, castedPassword, castedUserName, castedSocialNumber);	// control���� ����.
	fprintf(outFilePtr, "1.1. ȸ������\n");		// ��� ���
	if (signUpResult) {		// ID�� ȸ�������� �������� ��쿡��
		fprintf(outFilePtr, "> %s %s %s %s\n", userName, socialNumber, id, password);	// ȸ������ ������
	}
	fprintf(outFilePtr, "\n");					// ������ ��� ���� ���ÿ� ���߱� ����.
	return signUpResult;
}