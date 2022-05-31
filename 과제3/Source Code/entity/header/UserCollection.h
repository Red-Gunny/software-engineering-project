#pragma once
#ifndef USERCOLLECTION_H
#define USERCOLLECTION_H

#include "./User.h"

/*
* 유저 관리 클래스
* 스테레오 타입 : Entity (Collection)
*/
class UserCollection {
	vector<User> userList;
public:
	bool createUser(string id, string password, string userName = "", string socialName = "");		// 유저 등록 함수 (회원가입)
	bool destroyUser(string id);						// 유저 삭제 함수 (회원탈퇴)
	bool isValidUser(string id, string password);		// 로그인 시 검사 함수 
	bool isIdDuplicated(string id);						// ID 중복검사 함수

	bool purchaseProduct(User& user, string productName);	// 구입 기록 함수 (상품 구매)
};

#endif