#include "../header/control/AddNewProduct.h"

/*
��� �������̽� : �Ǹ� ��ǰ ���
���� : Collection�� ȣ���� ���� ����Ʈ�� �ν��Ͻ��� ����� �����
�Ķ���� : Product �ν��Ͻ��� �����ϴµ� �ʿ��� �ּ� ���� (string productName, string madeCompany, int price, int initialQuantity)
���� : ����� Product (Product)
*/
Product AddNewProduct::createNewProduct(string productName, string madeCompany, int price, int initialQuantity) {
	return productList->createNewProduct(
		currentUser.getId(),		// seller id
		productName,				// ��ǰ��
		madeCompany,				// ����ȸ���
		price,						// ����
		initialQuantity				// �ʱ����
	);
}