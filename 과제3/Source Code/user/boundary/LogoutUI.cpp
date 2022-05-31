#include "../header/boundary/LogoutUI.h"
#include "../header/control/Logout.h"

/*
사용 유즈케이스 : 로그아웃
내용 : 사용자로부터 입력받음
파라미터 : void
리턴 : void
*/
void LogoutUI::displayLogoutButton() {
	requestLogout();			// 사용자가 버튼을 눌렀으므로 콜백함수.
}

/*
사용 유즈케이스 : 로그아웃
내용 : control한테 전달하고 이후 받은 결과를 출력함
파라미터 : void
리턴 : void
유의사항 : 로그인 안했는데도 로그아웃 시도 시에 문제 없음
*/
void LogoutUI::requestLogout() {
	User logoutUser = logout->logout();		// boundary to control
	fprintf(outFilePtr, "2.2. 로그아웃\n");
	fprintf(outFilePtr, "> %s\n", logoutUser.getId().c_str());
	fprintf(outFilePtr, "\n");
	return;
}
