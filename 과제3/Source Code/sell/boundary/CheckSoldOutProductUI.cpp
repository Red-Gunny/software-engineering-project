#include "../header/boundary/CheckSoldOutProductUI.h"
#include "../header/control/CheckSoldOutProduct.h"


/*
��� �������̽� : �Ǹ� �Ϸ� ��ǰ ��ȸ
���� : UI�Լ�. ����ڷκ��� �Է��� ����
�Ķ���� : ���� (void)
���� : void
*/
void CheckSoldOutProductUI::displayCheckSoldOutProductUi() {
	checkSoldOutProduct();									// �̺�Ʈ �ڵ鷯 ȣ��
}

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���� : ����� �Է��� control���� �����ϰ� ���� ����� �����.
�Ķ���� : ���� (void)
���� : void
*/
void CheckSoldOutProductUI::checkSoldOutProduct() {
	vector<Product> soldOutList = soldOutControl->showSoldOutProduct();		// boundary to control
	fprintf(outFilePtr, "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n");
	for (Product product : soldOutList) {
		fprintf(outFilePtr, "> %s %s %d %d %.0lf\n",
			product.getProductName().c_str(),				// ��ǰ��
			product.getMadeCompany().c_str(),				// ����ȸ��
			product.getPrice(),								// ����
			product.getInitialQuantity() - product.getRemainQuantity(),										// �Ǹŵ� ����.
			product.getAverageRating()						// ��� ���� ������
		);
	}
	fprintf(outFilePtr, "\n");
}