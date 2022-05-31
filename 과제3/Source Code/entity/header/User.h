#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
using namespace std;

/*
* ���� Entity
* ���׷��� Ÿ�� : Entity
*/
class User {
	string id;
	string password;
	string userName;
	string socialNumber;

	vector<string> purchasedHistoryList;
public:

	// ������
	User() {};
	User(string id, string password, string userName = "", string socialNumber = "") {
		if (id.empty() || password.empty()) {		
			exit(0);							// id�� password�� null�̸� ���� �Ұ�
		}
		this->id = id;
		this->password = password;
		this->userName = userName;
		this->socialNumber = socialNumber;
	}

	// ����
	string getId() { return id; }
	string getPassword() { return password; }
	string getUserName() { return userName; }
	string getSocailName() { return socialNumber; }
	vector<string>& getPurchaseHistoryList() { return purchasedHistoryList; }


	// ����
	void setId(string id) { this->id = id; }
	void setPassword(string password) { this->password = password; }
	void setUserName(string userName) { this->userName = userName; }
	void setSocialNumber(string socialNumber) { this->socialNumber = socialNumber; }
};
#endif