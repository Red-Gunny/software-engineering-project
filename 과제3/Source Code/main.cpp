#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "./user/header/control/Login.h"
#include "./user/header/control/Logout.h"
#include "./user/header/control/SignUp.h"
#include "./user/header/control/SignOut.h"
#include "./user/header/control/ProductSalesStatistics.h"

#include "./sell/header/control/AddNewProduct.h"
#include "./sell/header/control/CheckProductsOnSale.h"
#include "./sell/header/control/CheckSoldOutProduct.h"

#include "./buy/header/control/PurchasableProduct.h"
#include "./buy/header/control/Purchase.h"
#include "./buy/header/control/PurchaseHistory.h"
#include "./buy/header/control/EvaluateProduct.h"

#include "./entity/header/ProductCollection.h"
#include "./entity/header/UserCollection.h"


//#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

//함수 선언
void doTask();
bool isLogined(User currentUser);
void notLoginAlert(int menu_level_1, int menu_level_2);
void program_exit();

// 변수 선언
FILE* inFilePtr, * outFilePtr;

int main() {


	// 파일 입출력을 위한 초기화
	inFilePtr = fopen(INPUT_FILE_NAME, "r+");
	outFilePtr = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	fclose(inFilePtr);
	fclose(outFilePtr);
	return 0;
}


// 여긴 컨트롤 갖고있다고 가정.
void doTask() {
	int menu_level_1 = 0, menu_level_2 = 0;		// 메뉴 파싱을 위한 level 구분을 위한 변수.
	int is_program_exit = 0;

	// 제일 중요한 거.
	UserCollection *userList = new UserCollection();
	ProductCollection* productList = new ProductCollection();

	User currentUser(" ", " ", " ", " ");	// 현재 로그인 로그아웃 정보를 가짐.
	Product searchProduct;

	while (!is_program_exit) {
		fscanf(inFilePtr, "%d %d ", &menu_level_1, &menu_level_2);
		switch(menu_level_1) {
		case 1:
			switch (menu_level_2) {		
			case 1:			// 1.1 회원가입 (큰 예외랄게 없음. 유저리스트 변경 확인 완료)
			{
				SignUp* signUp = new SignUp(inFilePtr, outFilePtr, userList);	// Control 생성
				delete signUp;											// Control 삭제
				break;
			}
			case 2:			// 1.2 회원탈퇴 - 접속 안 되어도 탈퇴 시도해도 이후 진행 확인완료
			{							// 로그인 안하면 회원탈퇴 불가능
				SignOut* signOut = new SignOut(inFilePtr, outFilePtr, &currentUser, userList);	// Control 생성
				delete signOut;															// Control 삭제
				break;
			}
			}
			break;
		case 2:
			switch (menu_level_2) {
			case 1:			// 2.1 로그인 - 로그인 실패해도 이후로 넘어가는건 확인 완료
			{
				Login* login = new Login(inFilePtr, outFilePtr, userList);
				currentUser = login->getCurrentUser();
				delete login;
				break;
			}
			case 2:			// 2.2 로그아웃	- 로그인 안 했는데 시도 시 예외처리 확인완료.
			{
				Logout* logout = new Logout(inFilePtr, outFilePtr, &currentUser);
				delete logout;
				break;
			}
			}
			break;
		case 3:
			switch (menu_level_2) {
			case 1:							// 3.1 판매 의류 등록
			{
				if (isLogined(currentUser)) {
					AddNewProduct* addNewProduct = new AddNewProduct(inFilePtr, outFilePtr, currentUser, productList);
					delete addNewProduct;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}				
				break;
			}
			case 2:							// 3.2 등록 상품 조회
			{
				if (isLogined(currentUser)) {
					CheckProductsOnSale* checkProductsOnSale = new CheckProductsOnSale(inFilePtr, outFilePtr, currentUser, productList);
					delete checkProductsOnSale;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			case 3:							// 3.3 판매 완료 상품 조회
			{
				if (isLogined(currentUser)) {
					CheckSoldOutProduct* checkSoldOutProduct = new CheckSoldOutProduct(inFilePtr, outFilePtr, currentUser, productList);
					delete checkSoldOutProduct;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			}
			break;
		case 4:
			switch (menu_level_2) {
			case 1:		  // 4.1 상품 정보 검색  - 유저 정보 - 구매 시 활용되므로 주의 필요
			{				
				if (isLogined(currentUser)) {
					PurchasableProduct* purchasableProduct = new PurchasableProduct(inFilePtr, outFilePtr, productList);
					searchProduct = purchasableProduct->getSearchProduct();
					delete purchasableProduct;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			case 2:			// 4.2 상품 구매    - WRITE 이므로 주의 필요
			{
				if (isLogined(currentUser)) {
					Purchase* purchase = new Purchase(inFilePtr, outFilePtr, currentUser, userList, searchProduct, productList);
					currentUser = purchase->getCurrentUser();	// 현재 유저 정보 업데이트
					delete purchase;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			case 3:			// 4.3 상품 구매 내역 조회  -  READ 이므로 큰 예외 x
			{
				if (isLogined(currentUser)) {
					PurchaseHistory* purchaseHistory = new PurchaseHistory(inFilePtr, outFilePtr, currentUser, productList);
					delete purchaseHistory;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			case 4:			// 4.4 상품 구매 만족도 평가 - WRITE 이므로 주의 필요
			{
				if (isLogined(currentUser)) {
					EvaluateProduct* evaluateProduct = new EvaluateProduct(inFilePtr, outFilePtr, productList);
					delete evaluateProduct;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			}
			break;
		case 5:
			switch (menu_level_2) {
			case 1:			// 5.1 판매 상품 통계
			{
				ProductSalesStatistics* statisticsControl = new ProductSalesStatistics(inFilePtr, outFilePtr, currentUser, productList);
				delete statisticsControl;
				break;
			}
			}
			break;
		case 6:
			switch (menu_level_2) {
			case 1:							// 6.1 종료
			{
				program_exit();
				is_program_exit = 1;
				break;
			}
			}
			break;
		default:
			break;
		}
	}
	delete userList;
	delete productList;
	return;
}

void program_exit() {
	fprintf(outFilePtr, "6.1 종료\n");
}

bool isLogined(User currentUser) {
	return (currentUser.getId() != " ");
}

void notLoginAlert(int menu_level_1, int menu_level_2) {
	switch (menu_level_1) {
	case 3:
		switch (menu_level_2) {
		case 1:							// 3.1 판매 의류 등록
		{
			char productName[MAX_STRING], madeCompany[MAX_STRING];
			int price, initialQuantity;
			fscanf(inFilePtr, "%s %s %d %d", productName, madeCompany, &price, &initialQuantity);
			fprintf(outFilePtr, "3.1. 판매 의류 등록\n");
			break;
		}
		case 2:							// 3.2 등록 상품 조회
		{
			fprintf(outFilePtr, "3.2. 등록 상품 조회\n");
			break;
		}
		case 3:							// 3.3 판매 완료 상품 조회
		{
			fprintf(outFilePtr, "3.3. 판매 완료 상품 조회\n");
			break;
		}
		}
		break;
	case 4:
		switch (menu_level_2) {
		case 1:							// 4.1 상품 정보 검색
		{
			char productName[MAX_STRING];
			fscanf(inFilePtr, "%s", productName);
			fprintf(outFilePtr, "4.1. 상품 정보 검색\n");
			break;
		}
		case 2:							// 4.2 상품 구매
		{
			fprintf(outFilePtr, "4.2. 상품 구매\n");
			break;
		}
		case 3:							// 4.3 상품 구매 내역 조회
		{
			fprintf(outFilePtr, "4.3. 상품 구매 내역 조회\n");
			break;
		}
		case 4:							// 4.4 상품 구매 만족도 평가
		{
			int ratingValue;
			char productName[MAX_STRING];
			fscanf(inFilePtr, "%s %d", productName, &ratingValue);
			fprintf(outFilePtr, "4.4. 상품 구매만족도 평가\n");
			break;
		}
		}
		break;
	case 5:
		switch (menu_level_2) {
		case 1:							// 5.1 판매 상품 통계
		{
			fprintf(outFilePtr, " 5.1. 판매 상품 통계\n");
			break;
		}
		}
		break;
	default:
		break;
	}
	fprintf(outFilePtr, "> Login Please ! \n\n");
}