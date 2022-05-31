#define _CRT_SECURE_NO_WARNINGS
#include "../header/boundary/SignOutUI.h"
#include "../header/control/SignOut.h"


/*
사용 유즈케이스 : 회원탈퇴
내용 : 사용자에게 UI를 제시하고 입력 받을 때까지 대기함
	   사용자 입력 시 requestSignOut() 실행
파라미터 : void
리턴 : void
*/
void SignOutUI::displaySignOutButton() {		// 사용자가 버튼을 누를 수 있게
	requestSignOut();							// 버튼을 눌렀으므로 이벤트 처리
}

/*
사용 유즈케이스 : 회원탈퇴
내용 : 사용자가 입력한 이벤트를 바탕으로 회원탈퇴하도록 control한테 전달함
파라미터 : void
리턴 : void
*/
void SignOutUI::requestSignOut() {
	User signOutUser = signOut->signOut();			// Control한테 전달
	fprintf(outFilePtr, "1.2. 회원탈퇴\n");			// 이하 받은 결과 기록
	fprintf(outFilePtr, "> %s\n\n", signOutUser.getId().c_str());
}