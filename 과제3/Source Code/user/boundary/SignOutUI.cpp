#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/SignOutUI.h"
#include "../header/control/SignOut.h"


/*
��� �������̽� : ȸ��Ż��
���� : ����ڿ��� UI�� �����ϰ� �Է� ���� ������ �����
	   ����� �Է� �� requestSignOut() ����
�Ķ���� : void
���� : void
*/
void SignOutUI::displaySignOutButton() {		// ����ڰ� ��ư�� ���� �� �ְ�
	requestSignOut();							// ��ư�� �������Ƿ� �̺�Ʈ ó��
}

/*
��� �������̽� : ȸ��Ż��
���� : ����ڰ� �Է��� �̺�Ʈ�� �������� ȸ��Ż���ϵ��� control���� ������
�Ķ���� : void
���� : void
*/
void SignOutUI::requestSignOut() {
	User signOutUser = signOut->signOut();			// Control���� ����
	fprintf(outFilePtr, "1.2. ȸ��Ż��\n");			// ���� ���� ��� ���
	fprintf(outFilePtr, "> %s\n\n", signOutUser.getId().c_str());
}