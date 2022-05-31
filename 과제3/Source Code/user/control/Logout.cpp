#include "../header/control/Logout.h"

/*
사용 유즈케이스 : 로그아웃
내용 : 로그아웃 진행. 현재 시스템에서 접속 중인 유저(currentUser) 정보를 초기화 시킴
파라미터 : void
리턴 : 현재 로그아웃하려는 유저 정보 (User)
*/
User Logout::logout() {
	User logoutUser = *currentUser;
	currentUser->setId(" ");			// 유저 정보 초기화
	currentUser->setPassword(" ");		// 유저 정보 초기화
	return logoutUser;
}