#include "../header/control/ProductSalesStatistics.h"

/*
��� �������̽� : �Ǹ� ��� ��ȸ
���� : ���� ���� ����Ǵ� control ������. bonudary�ϰ� ������ ��ȯ��. ���� boundary�� UI�Լ��� ȣ����.
�Ķ���� : ���������� / ���� �������� ���� ���� / ��ǰ����Ʈ (FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList)
���� : -
*/
ProductSalesStatistics::ProductSalesStatistics(FILE* inFilePtr, FILE* outFilePtr, User& currentUser, ProductCollection* productList) {
	this->currentUser = currentUser;
	this->productList = productList;
	this->statisticsBoundary = new ProductSalesStatisticsUI(inFilePtr, outFilePtr, this);
	statisticsBoundary->displayStatisticsButton();
}

/*
��� �������̽� : �Ǹ� ��� ��ȸ
���� : ���� �������� ������� ID�� ��������  ProductCollection�� ȣ���� ���� ��������� �޾Ƴ�.
�Ķ���� : void
���� : �ʿ��� ��������� STL���� (map <��ǰ��, pair<����, ��� ���Ÿ�����>>)
*/
map<string, pair<int, double>> ProductSalesStatistics::productSalesStatistics() {
	return productList->getSoldStatistics(currentUser.getId());		// �÷��� Ŭ���� ȣ��
}