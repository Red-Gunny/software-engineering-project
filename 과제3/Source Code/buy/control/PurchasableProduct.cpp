#include "../header/control/PurchasableProduct.h"

/*
��� �������̽� : ���� ���� ��ǰ ����Ʈ ��ȸ
���� : ��ǰ�� ���� ������ ������
�Ķ���� : void
���� : void
*/
Product PurchasableProduct::showProduct(string productName) {
	vector<Product> resultProductList = productList->getPurchasableProduct(productName);	// proudctList���� ������
	if (resultProductList.size() == 0) {
		return Product(" ", " ", " ", -1, -1);	// ���� ó��
	}
	return resultProductList.front();		// ����� ��ȯ��
}

/*
��� �������̽� : ���� ���� ��ǰ ����Ʈ ��ȸ
���� : �ý��ۿ��� main������ Ȱ��Ǳ� ���� ����
�Ķ���� : void
���� : ���Ű����� ��ǰ (Product)
*/
Product PurchasableProduct::getSearchProduct() {
	return purchasableProductUi->getSearchedProduct();	// ���� ��ǰ ���ſ� �����.
}