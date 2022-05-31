#include "../header/boundary/LogoutUI.h"
#include "../header/control/Logout.h"

/*
��� �������̽� : �α׾ƿ�
���� : ����ڷκ��� �Է¹���
�Ķ���� : void
���� : void
*/
void LogoutUI::displayLogoutButton() {
	requestLogout();			// ����ڰ� ��ư�� �������Ƿ� �ݹ��Լ�.
}

/*
��� �������̽� : �α׾ƿ�
���� : control���� �����ϰ� ���� ���� ����� �����
�Ķ���� : void
���� : void
���ǻ��� : �α��� ���ߴµ��� �α׾ƿ� �õ� �ÿ� ���� ����
*/
void LogoutUI::requestLogout() {
	User logoutUser = logout->logout();		// boundary to control
	fprintf(outFilePtr, "2.2. �α׾ƿ�\n");
	fprintf(outFilePtr, "> %s\n", logoutUser.getId().c_str());
	fprintf(outFilePtr, "\n");
	return;
}
