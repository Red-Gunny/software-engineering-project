#include "../header/control/SignOut.h"

/*
��� �������̽� : ȸ��Ż��
���� : ���� ���� ���� ȸ���� �������� ��Ż��.
�Ķ���� : void
���� : ���� Ż���Ϸ��� ���� ���� (���������� ��쿡 ���̵� " "�� ä�� ��ȯ��)
*/
User SignOut::signOut() {
	bool signOutResult = userList->destroyUser(currentUser->getId());		// ȸ��Ż�� ó��.
	User inform = *currentUser;
	currentUser->setId(" ");			// �ý��ۿ��� �ٸ� �޴� ���ϰ� ���� ����
	currentUser->setPassword(" ");		// �ý��ۿ��� �ٸ� �޴� ���ϰ� ���� ����
	return inform;			// ���� Ż���Ϸ��� ���� ������ ��ȯ
}


    