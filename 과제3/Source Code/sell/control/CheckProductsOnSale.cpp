#include "../header/control/CheckProductsOnSale.h"

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���� : productList�� ���� ���� �Ǹ� ���� ��ǰ���� �޾� ��.
�Ķ���� : ���� (void)
���� : �Ǹ����� Product����Ʈ (vector<Product>)
*/
vector<Product> CheckProductsOnSale::showProductsOnSale() {
	return productList->checkOnSaleList(currentUser.getId());
}