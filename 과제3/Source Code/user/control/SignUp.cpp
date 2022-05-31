#include "../header/control/SignUp.h"

/*
사용 유즈케이스 : 회원가입
내용 : 회원가입 해도 되면(ID 중복 x) 회원 객체를 생성 후 list에 추가함.
파라미터 : 유저 정보. (string id, string password, string userName, string socialNumber)
리턴 : 회원 가입 성공했으면 true (bool)
*/
bool SignUp::signUp(string id, string password, string userName, string socialNumber) {
	if (userList->isIdDuplicated(id)) {	// 아이디가 중복
		return false;					// 실패
	}
	return userList->createUser(id, password, userName, socialNumber);	// list에 추가(반환타입 bool)
}