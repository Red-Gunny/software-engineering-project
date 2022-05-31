#include "../header/control/SignUp.h"

/*
��� �������̽� : ȸ������
���� : ȸ������ �ص� �Ǹ�(ID �ߺ� x) ȸ�� ��ü�� ���� �� list�� �߰���.
�Ķ���� : ���� ����. (string id, string password, string userName, string socialNumber)
���� : ȸ�� ���� ���������� true (bool)
*/
bool SignUp::signUp(string id, string password, string userName, string socialNumber) {
	if (userList->isIdDuplicated(id)) {	// ���̵� �ߺ�
		return false;					// ����
	}
	return userList->createUser(id, password, userName, socialNumber);	// list�� �߰�(��ȯŸ�� bool)
}