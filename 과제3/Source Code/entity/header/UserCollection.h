#pragma once
#ifndef USERCOLLECTION_H
#define USERCOLLECTION_H

#include "./User.h"

/*
* ���� ���� Ŭ����
* ���׷��� Ÿ�� : Entity (Collection)
*/
class UserCollection {
	vector<User> userList;
public:
	bool createUser(string id, string password, string userName = "", string socialName = "");		// ���� ��� �Լ� (ȸ������)
	bool destroyUser(string id);						// ���� ���� �Լ� (ȸ��Ż��)
	bool isValidUser(string id, string password);		// �α��� �� �˻� �Լ� 
	bool isIdDuplicated(string id);						// ID �ߺ��˻� �Լ�

	bool purchaseProduct(User& user, string productName);	// ���� ��� �Լ� (��ǰ ����)
};

#endif