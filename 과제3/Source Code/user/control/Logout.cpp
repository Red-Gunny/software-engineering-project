#include "../header/control/Logout.h"

/*
��� �������̽� : �α׾ƿ�
���� : �α׾ƿ� ����. ���� �ý��ۿ��� ���� ���� ����(currentUser) ������ �ʱ�ȭ ��Ŵ
�Ķ���� : void
���� : ���� �α׾ƿ��Ϸ��� ���� ���� (User)
*/
User Logout::logout() {
	User logoutUser = *currentUser;
	currentUser->setId(" ");			// ���� ���� �ʱ�ȭ
	currentUser->setPassword(" ");		// ���� ���� �ʱ�ȭ
	return logoutUser;
}