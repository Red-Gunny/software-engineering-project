#include "../header/control/SignOut.h"

/*
사용 유즈케이스 : 회원탈퇴
내용 : 현재 접속 중인 회원이 사용권한을 박탈함.
파라미터 : void
리턴 : 현재 탈퇴하려는 유저 정보 (비정상적인 경우에 아이디가 " "인 채로 반환함)
*/
User SignOut::signOut() {
	bool signOutResult = userList->destroyUser(currentUser->getId());		// 회원탈퇴 처리.
	User inform = *currentUser;
	currentUser->setId(" ");			// 시스템에서 다른 메뉴 못하게 막는 목적
	currentUser->setPassword(" ");		// 시스템에서 다른 메뉴 못하게 막는 목적
	return inform;			// 현재 탈퇴하려는 유저 정보만 반환
}


    