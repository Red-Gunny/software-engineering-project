#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
using namespace std;

/*
* 유저 Entity
* 스테레오 타입 : Entity
*/
class User {
	string id;
	string password;
	string userName;
	string socialNumber;

	vector<string> purchasedHistoryList;
public:

	// 생성자
	User() {};
	User(string id, string password, string userName = "", string socialNumber = "") {
		if (id.empty() || password.empty()) {		
			exit(0);							// id와 password의 null이면 생성 불가
		}
		this->id = id;
		this->password = password;
		this->userName = userName;
		this->socialNumber = socialNumber;
	}

	// 게터
	string getId() { return id; }
	string getPassword() { return password; }
	string getUserName() { return userName; }
	string getSocailName() { return socialNumber; }
	vector<string>& getPurchaseHistoryList() { return purchasedHistoryList; }


	// 세터
	void setId(string id) { this->id = id; }
	void setPassword(string password) { this->password = password; }
	void setUserName(string userName) { this->userName = userName; }
	void setSocialNumber(string socialNumber) { this->socialNumber = socialNumber; }
};
#endif