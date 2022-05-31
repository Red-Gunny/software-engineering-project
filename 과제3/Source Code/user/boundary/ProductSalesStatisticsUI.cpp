#include "../header/boundary/ProductSalesStatisticsUI.h"
#include "../header/control/ProductSalesStatistics.h"

/*
��� �������̽� : �Ǹ� ��� ��ȸ
���� : UI�Լ�. ����ڷκ��� �Է¹޴� �޼ҵ�
�Ķ���� : void
���� : void
*/
void ProductSalesStatisticsUI::displayStatisticsButton() {
	requestProductSalesStatistics();
}

/*
��� �������̽� : �Ǹ� ��� ��ȸ
���� : control�� ȣ���ϰ� ���� ���� ����� �����.
�Ķ���� : void
���� : void
*/
void ProductSalesStatisticsUI::requestProductSalesStatistics() {
	auto result = statisticsControl->productSalesStatistics();	// boundary to control
	// ��� ���
	fprintf(outFilePtr, "5.1. �Ǹ� ��ǰ ���\n");
	for (auto element : result) {
		fprintf(outFilePtr, "> %s %d %.0f\n",
			element.first.c_str(),				// ��ǰ�� ���
			element.second.first,				// ���� ���
			element.second.second				// ��� ���Ÿ����� ���
		);
	}
	fprintf(outFilePtr, "\n");
}