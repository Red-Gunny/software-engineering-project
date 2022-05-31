#include <iostream>
#include <vector>
#include <algorithm>
#include "./header/UserCollection.h"
using namespace std;

/*
��� �������̽� : ȸ������
���� : userList�� User ��ü�� ����� �߰���.
�Ķ���� : User Class�� ��ü Atrribute. (string id, string password, string userName, string socialName)
���� Ÿ�� : ȸ���� ���������� �߰������� true ��ȯ (bool)
*/
bool UserCollection::createUser(string id, string password, string userName, string socialName) {
	if (id.empty() || password.empty()) {		// ID�� ��й�ȣ�� ��������� ����� �߻���Ŵ
		cout << "UserCollection::addUser() ���� - ���̵� ��й�ȣ�� Ȯ�����ּ���." << endl;
		return false;														// ���� �� False
	}
	User createdUser(id, password, userName, socialName);
	userList.push_back(createdUser);			// User �ν��Ͻ��� ����� ���Ϳ� ����
	return true;															// ���� �� True
}

/*
��� �������̽� : ȸ��Ż��
���� : userList�� User ��ü�� ������. ������ ���̷� ����� ���� �ƴ��� ������.
�Ķ���� : User Class�� id (string id)
���� : ������ ���������� �̷������� true��ȯ (bool)
*/
bool UserCollection::destroyUser(string id) {
	if (id.empty()) {	// ����ó��
		return false;
	}
	int beforeSize = userList.size();			// ���� ������ ���� ������ ��� ����
	userList.erase(										// vector���� �������ִ��Լ�
		remove_if(											// vector���� ���� �ڷ� ������ �Լ�
			userList.begin(),										// ó������
			userList.end(),											// ������ ��ȸ�ϸ鼭
			[id](auto user) -> bool {								// (�Ķ���� id�� �´� User�� ã�� �Լ�)�� ���� �Ǵ� �� �ڷ� ����
				return (user.getId() == id);
			}
		),
		userList.end());
	int afterSize = userList.size();				// ���� �� ���� ������
	return (beforeSize - afterSize == 1);			// ���� ������ ���̷� ����� �����ƴ��� Ȯ��
}

/*
��� �������̽� : �α���
���� : User��ü�� userList�� �����ϴ� ��ü���� Ȯ����
�Ķ���� : User�� id�� password (string id, string password)
���� Ÿ�� : ��ȿ�� ȸ���̸� true ��ȯ �ƴϸ� false (bool)
*/
bool UserCollection::isValidUser(string id, string password) {
	for (User user : userList) {				// userList �� ��� User ���ҵ鿡 ���Ͽ� �ݺ��� ����
		if (user.getId() == id && user.getPassword() == password) {			// id�� ��й�ȣ ��� ������
			return true;														// true ��ȯ
		}
	}
	return false;									// ���� ���� if������ �� �����������Ƿ� �ش� ������ �������� ����.
}

/*
��� �������̽� : ȸ������
���� : ȸ������ �� ��������ϴ� ID�� ���� ������ �����鿡 �����ϴ��� Ȯ����.
�Ķ���� : User�� ���̵�. (string id)
���� Ÿ�� : �ߺ��Ǹ� True ��ȯ / �ߺ� �ȵǸ� False ��ȯ (bool)
*/
bool UserCollection::isIdDuplicated(string id) {
	for (User& user : userList) {				// userList �� ��� User ���ҵ鿡 ���Ͽ� �ݺ��� ����
		if (user.getId() == id) {				// id ��
			return true;							// ��� ��
		}
	}
	return false;
}

/*
��� �������̽� : ��ǰ����  
���� :   ��ǰ ���� �� User Class�� purchaseHistoryList�� ������ ��ǰ�� �߰���.
		UserCollection�� �����Ǿ��ִ� ������ ���� �ý��� �� �α��ε� ���� �ν��Ͻ� state update
�Ķ���� : User Class�� ��ü Atrribute. (string id, string password, string userName, string socialName)
���� Ÿ�� : (bool)
���� ���� : ���� �� User& user�� �ݵ�� ����������. (�����۾��� �Ͼ�� ������)
*/
bool UserCollection::purchaseProduct(User& currentUser, string productName) {
	for (User& user : userList) {				// userList �� ��� User ���ҵ鿡 ���Ͽ� �ݺ��� ����
		if (user.getId() == currentUser.getId()) {		// userList���� ���� �ý��� �� �α��� �Ǿ��ִ� ������ ã�Ƴ�
			user.getPurchaseHistoryList().push_back(productName);			// ��������Ʈ�� ���� ���� ���� ������Ʈ
			currentUser.getPurchaseHistoryList().push_back(productName);	// main���� Ȱ��Ǵ� User��ü ������Ʈ
			return true;
		}
	}
	return false;
}