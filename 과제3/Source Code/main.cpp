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

//�Լ� ����
void doTask();
bool isLogined(User currentUser);
void notLoginAlert(int menu_level_1, int menu_level_2);
void program_exit();

// ���� ����
FILE* inFilePtr, * outFilePtr;

int main() {


	// ���� ������� ���� �ʱ�ȭ
	inFilePtr = fopen(INPUT_FILE_NAME, "r+");
	outFilePtr = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	fclose(inFilePtr);
	fclose(outFilePtr);
	return 0;
}


// ���� ��Ʈ�� �����ִٰ� ����.
void doTask() {
	int menu_level_1 = 0, menu_level_2 = 0;		// �޴� �Ľ��� ���� level ������ ���� ����.
	int is_program_exit = 0;

	// ���� �߿��� ��.
	UserCollection *userList = new UserCollection();
	ProductCollection* productList = new ProductCollection();

	User currentUser(" ", " ", " ", " ");	// ���� �α��� �α׾ƿ� ������ ����.
	Product searchProduct;

	while (!is_program_exit) {
		fscanf(inFilePtr, "%d %d ", &menu_level_1, &menu_level_2);
		switch(menu_level_1) {
		case 1:
			switch (menu_level_2) {		
			case 1:			// 1.1 ȸ������ (ū ���ܶ��� ����. ��������Ʈ ���� Ȯ�� �Ϸ�)
			{
				SignUp* signUp = new SignUp(inFilePtr, outFilePtr, userList);	// Control ����
				delete signUp;											// Control ����
				break;
			}
			case 2:			// 1.2 ȸ��Ż�� - ���� �� �Ǿ Ż�� �õ��ص� ���� ���� Ȯ�οϷ�
			{							// �α��� ���ϸ� ȸ��Ż�� �Ұ���
				SignOut* signOut = new SignOut(inFilePtr, outFilePtr, &currentUser, userList);	// Control ����
				delete signOut;															// Control ����
				break;
			}
			}
			break;
		case 2:
			switch (menu_level_2) {
			case 1:			// 2.1 �α��� - �α��� �����ص� ���ķ� �Ѿ�°� Ȯ�� �Ϸ�
			{
				Login* login = new Login(inFilePtr, outFilePtr, userList);
				currentUser = login->getCurrentUser();
				delete login;
				break;
			}
			case 2:			// 2.2 �α׾ƿ�	- �α��� �� �ߴµ� �õ� �� ����ó�� Ȯ�οϷ�.
			{
				Logout* logout = new Logout(inFilePtr, outFilePtr, &currentUser);
				delete logout;
				break;
			}
			}
			break;
		case 3:
			switch (menu_level_2) {
			case 1:							// 3.1 �Ǹ� �Ƿ� ���
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
			case 2:							// 3.2 ��� ��ǰ ��ȸ
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
			case 3:							// 3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
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
			case 1:		  // 4.1 ��ǰ ���� �˻�  - ���� ���� - ���� �� Ȱ��ǹǷ� ���� �ʿ�
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
			case 2:			// 4.2 ��ǰ ����    - WRITE �̹Ƿ� ���� �ʿ�
			{
				if (isLogined(currentUser)) {
					Purchase* purchase = new Purchase(inFilePtr, outFilePtr, currentUser, userList, searchProduct, productList);
					currentUser = purchase->getCurrentUser();	// ���� ���� ���� ������Ʈ
					delete purchase;
				}
				else {
					notLoginAlert(menu_level_1, menu_level_2);
				}
				break;
			}
			case 3:			// 4.3 ��ǰ ���� ���� ��ȸ  -  READ �̹Ƿ� ū ���� x
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
			case 4:			// 4.4 ��ǰ ���� ������ �� - WRITE �̹Ƿ� ���� �ʿ�
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
			case 1:			// 5.1 �Ǹ� ��ǰ ���
			{
				ProductSalesStatistics* statisticsControl = new ProductSalesStatistics(inFilePtr, outFilePtr, currentUser, productList);
				delete statisticsControl;
				break;
			}
			}
			break;
		case 6:
			switch (menu_level_2) {
			case 1:							// 6.1 ����
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
	fprintf(outFilePtr, "6.1 ����\n");
}

bool isLogined(User currentUser) {
	return (currentUser.getId() != " ");
}

void notLoginAlert(int menu_level_1, int menu_level_2) {
	switch (menu_level_1) {
	case 3:
		switch (menu_level_2) {
		case 1:							// 3.1 �Ǹ� �Ƿ� ���
		{
			char productName[MAX_STRING], madeCompany[MAX_STRING];
			int price, initialQuantity;
			fscanf(inFilePtr, "%s %s %d %d", productName, madeCompany, &price, &initialQuantity);
			fprintf(outFilePtr, "3.1. �Ǹ� �Ƿ� ���\n");
			break;
		}
		case 2:							// 3.2 ��� ��ǰ ��ȸ
		{
			fprintf(outFilePtr, "3.2. ��� ��ǰ ��ȸ\n");
			break;
		}
		case 3:							// 3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
		{
			fprintf(outFilePtr, "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n");
			break;
		}
		}
		break;
	case 4:
		switch (menu_level_2) {
		case 1:							// 4.1 ��ǰ ���� �˻�
		{
			char productName[MAX_STRING];
			fscanf(inFilePtr, "%s", productName);
			fprintf(outFilePtr, "4.1. ��ǰ ���� �˻�\n");
			break;
		}
		case 2:							// 4.2 ��ǰ ����
		{
			fprintf(outFilePtr, "4.2. ��ǰ ����\n");
			break;
		}
		case 3:							// 4.3 ��ǰ ���� ���� ��ȸ
		{
			fprintf(outFilePtr, "4.3. ��ǰ ���� ���� ��ȸ\n");
			break;
		}
		case 4:							// 4.4 ��ǰ ���� ������ ��
		{
			int ratingValue;
			char productName[MAX_STRING];
			fscanf(inFilePtr, "%s %d", productName, &ratingValue);
			fprintf(outFilePtr, "4.4. ��ǰ ���Ÿ����� ��\n");
			break;
		}
		}
		break;
	case 5:
		switch (menu_level_2) {
		case 1:							// 5.1 �Ǹ� ��ǰ ���
		{
			fprintf(outFilePtr, " 5.1. �Ǹ� ��ǰ ���\n");
			break;
		}
		}
		break;
	default:
		break;
	}
	fprintf(outFilePtr, "> Login Please ! \n\n");
}