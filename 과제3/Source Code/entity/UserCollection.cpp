#include <iostream>
#include <vector>
#include <algorithm>
#include "./header/UserCollection.h"
using namespace std;

/*
사용 유즈케이스 : 회원가입
내용 : userList에 User 객체를 만들어 추가함.
파라미터 : User Class의 전체 Atrribute. (string id, string password, string userName, string socialName)
리턴 타입 : 회원이 정상적으로 추가됐으면 true 반환 (bool)
*/
bool UserCollection::createUser(string id, string password, string userName, string socialName) {
	if (id.empty() || password.empty()) {		// ID나 비밀번호가 비어있으면 경고문을 발생시킴
		cout << "UserCollection::addUser() 오류 - 아이디나 비밀번호를 확인해주세요." << endl;
		return false;														// 실패 시 False
	}
	User createdUser(id, password, userName, socialName);
	userList.push_back(createdUser);			// User 인스턴스를 만들어 벡터에 삽입
	return true;															// 성공 시 True
}

/*
사용 유즈케이스 : 회원탈퇴
내용 : userList에 User 객체를 삭제함. 사이즈 차이로 제대로 삭제 됐는지 검증함.
파라미터 : User Class의 id (string id)
리턴 : 삭제가 정상적으로 이뤄졌으면 true반환 (bool)
*/
bool UserCollection::destroyUser(string id) {
	if (id.empty()) {	// 예외처리
		return false;
	}
	int beforeSize = userList.size();			// 검증 목적의 벡터 사이즈 담는 변수
	userList.erase(										// vector에서 삭제해주는함수
		remove_if(											// vector에서 가장 뒤로 보내는 함수
			userList.begin(),										// 처음부터
			userList.end(),											// 끝까지 순회하면서
			[id](auto user) -> bool {								// (파라미터 id에 맞는 User를 찾는 함수)이 참이 되는 걸 뒤로 보냄
				return (user.getId() == id);
			}
		),
		userList.end());
	int afterSize = userList.size();				// 삭제 후 벡터 사이즈
	return (beforeSize - afterSize == 1);			// 벡터 사이즈 차이로 제대로 삭제됐는지 확인
}

/*
사용 유즈케이스 : 로그인
내용 : User객체가 userList에 존재하는 객체인지 확인함
파라미터 : User의 id와 password (string id, string password)
리턴 타입 : 유효한 회원이면 true 반환 아니면 false (bool)
*/
bool UserCollection::isValidUser(string id, string password) {
	for (User user : userList) {				// userList 내 모든 User 원소들에 대하여 반복문 실행
		if (user.getId() == id && user.getPassword() == password) {			// id와 비밀번호 모두 같으면
			return true;														// true 반환
		}
	}
	return false;									// 루프 동안 if문으로 못 빠져나갔으므로 해당 유저는 존재하지 않음.
}

/*
사용 유즈케이스 : 회원가입
내용 : 회원가입 시 만들고자하는 ID가 먼저 가입한 유저들에 존재하는지 확인함.
파라미터 : User의 아이디. (string id)
리턴 타입 : 중복되면 True 반환 / 중복 안되면 False 반환 (bool)
*/
bool UserCollection::isIdDuplicated(string id) {
	for (User& user : userList) {				// userList 내 모든 User 원소들에 대하여 반복문 실행
		if (user.getId() == id) {				// id 비교
			return true;							// 비번 비교
		}
	}
	return false;
}

/*
사용 유즈케이스 : 상품구매  
내용 :   상품 구매 시 User Class의 purchaseHistoryList에 구매한 상품을 추가함.
		UserCollection에 보관되어있는 유저와 현재 시스템 내 로그인된 유저 인스턴스 state update
파라미터 : User Class의 전체 Atrribute. (string id, string password, string userName, string socialName)
리턴 타입 : (bool)
유의 사항 : 루프 내 User& user는 반드시 지켜져야함. (수정작업이 일어나기 때문에)
*/
bool UserCollection::purchaseProduct(User& currentUser, string productName) {
	for (User& user : userList) {				// userList 내 모든 User 원소들에 대하여 반복문 실행
		if (user.getId() == currentUser.getId()) {		// userList에서 현재 시스템 내 로그인 되어있는 유저를 찾아냄
			user.getPurchaseHistoryList().push_back(productName);			// 유저리스트에 보관 중인 정보 업데이트
			currentUser.getPurchaseHistoryList().push_back(productName);	// main에서 활용되는 User객체 업데이트
			return true;
		}
	}
	return false;
}