#include "./header/ProductCollection.h"

//#include <conio.h>

/*
��� �������̽� : ���Ű��� ��ǰ����Ʈ ��ȸ
���� : productList���� ���Ű����� ������ ��� ���Ϳ� ��� ��ȯ��.
�Ķ���� : ��ǰ�� �̸�. (string productName)
���� : ���Ű����� ��ǰ ��� (vector<Product>)
*/
vector<Product> ProductCollection::getPurchasableProduct(string productName) {
	vector<Product> purchasableProductList;
	for (Product& product : productList) {
		if (product.getProductName() == productName) {				// ��ǰ���� ��ġ
			if (product.getInitialQuantity() >= product.getRemainQuantity()) {				// ���� ������ �����ϴ��� Ȯ��
				purchasableProductList.push_back(product);										// ���Ű����̹Ƿ� ���Ϳ� ����
			}
		}
	}
	return purchasableProductList;
}

/*
��� �������̽� : ��ǰ ����
���� : ��ǰ�� ����. ���� ������ ���ҽ�Ŵ. (������ ����ϴ°� userList�� �ش� control�� �ٸ� �޼ҵ忡�� �����)
�Ķ���� : ��ǰ�� �̸�. (string productName)
���� : ��ǰ ���� ���� �� true ��ȯ (bool)
���ǻ��� : �ڡڡڡڡ� for�� �� Product& product�� �ݵ�� ���� ���¿��� ��.�ڡڡڡڡ�
*/
bool ProductCollection::purchaseProduct(string productName) {
	for (Product& product : productList) {
		if (product.getProductName() == productName) {			// productList���� ��ǰ�� �´� ��ǰ�� ã�Ƴ�
			int currentQuantity = product.getRemainQuantity();			// ���� �����ִ� ����
			if (currentQuantity > 0) {									// ���� ������ �����ִ� ��쿡��
				product.setRemainQuantity(--currentQuantity);			// 1�� ���ҽ�Ų ���� product ����.
				return true;
			}
			return false;		// ������ 0�̹Ƿ� ���� ����
		}
	}
	return false;			//  productList�� �ش� ��ǰ�� �������� ����.
}

/*
��� �������̽� : ���Ÿ����� ��
���� : ������ ��ǰ�� ���Ͽ� ���Ÿ������� ������Ʈ��.
�Ķ���� : (1) ���Ÿ����� ��  (2) ��ǰ�� �̸�. (int rating, string productName)
���� : ��ǰ ���Ÿ����� ������Ʈ ���� �� true ��ȯ (bool)
���ǻ��� : (1) �ڡڡڡڡ� for�� �� Product& product�� �ݵ�� ���� ���¿��� ��. �ڡڡڡڡ�
		   (2) rating ��ȿ�� �˻�� boundary���� �̷����.
		   (3) ��հ� ���ϴ� �������� �и�(�򰡿� ������ ��� ��) getRatingCount() + 1 �Ǿ������� ����
*/
bool ProductCollection::evaluateSatisfactionRating(int rating, string productName) {
	for (Product& product : productList) {
		if (product.getProductName() == productName) {					// productList���� ��ǰ���� ��ġ�ϴ� ���� ã���� ��
			double currentAverageRating = product.getAverageRating();			// ���� ���ڰ� (���� ��� �� ����)
			int ratingUserCount = product.getRatingUserCount();					// ���� �и� (������ �򰡿� ������ ��� ��)
			double currentAverageRatingSum = (double)currentAverageRating * ratingUserCount;	// ���ڰ� (���� ������ �� ����� * ���� ��� �� ����)
			ratingUserCount += 1;																// �и� 1 ���� (������ ��� ��)
			double updatedAverageRating = (double)(currentAverageRatingSum + rating) / ratingUserCount;		// �������� ��� ��� ���� �κ�
			product.setAverageRating(updatedAverageRating);						// ���� ���� ���Ÿ����� ����.
			product.setRatingUserCount(ratingUserCount);						// �߰��� �򰡿� ������ ��� �� ����
			return true;
		}
	}
	return false;		// productList�� �ش� ��ǰ���� ��ǰ�� �������� �ʴ� ��� �� ����
}

/*
��� �������̽� : �Ǹ� ��ǰ ���
���� : �Ǹ��ڰ� ��ǰ�� �����.
�Ķ���� : Product���� �Ǹ��� ���̵� / ��ǰ�� / ����ȸ�� / ���� / �ʱ���� (string sellerId, string proudctName, string madeCompany, int price, int initialQuantity)
���� : ����� ��ǰ (Product)
���ǻ��� : (1) ��� �� �Ķ���� ���� �������ų� empty �� ������ �ʰ� ���� �ʿ�
*/
Product ProductCollection::createNewProduct(string sellerId, string proudctName, string madeCompany, int price, int initialQuantity) {
	Product createdProduct(sellerId, proudctName, madeCompany, price, initialQuantity);	// Product ����
	productList.push_back(createdProduct);												// ���Ϳ� ����
	return createdProduct;																// ���� Product ��ȯ
}

/*
��� �������̽� : �Ǹ� ���� ��ǰ ��ȸ
���� : �Ǹ��ڰ� �ø� ��ǰ �� ������ �����ִ� �͵鸸 ��ȯ��.
�Ķ���� : �Ǹ��� ���̵� (string sellerId)
���� : �Ǹ� ���� ��ǰ ����Ʈ (vector<Product>)
*/
vector<Product> ProductCollection::checkOnSaleList(string sellerId) {
	vector<Product> onSaleProductList;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId && product.getRemainQuantity() > 0) {			// �Ǹ��� ���̵� ��ġ && ���� ���� ����.
			onSaleProductList.push_back(product);											// ���Ϳ� �߰�
		}
	}
	return onSaleProductList;
}

/*
��� �������̽� : �Ǹ� �Ϸ�� ��ǰ ��ȸ
���� : �Ǹ��ڰ� �ø� ��ǰ �� ���� �͵鸸 ��ȯ��.
�Ķ���� : �Ǹ��� ���̵� (string sellerId)
���� : �Ǹ� �Ϸ�� ��ǰ ����Ʈ (vector<Product>)
*/
vector<Product> ProductCollection::checkSoldOutList(string sellerId) {
	vector<Product> soldOutProductList;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId && product.getRemainQuantity() <= 0) {	// �Ǹ��� ��ġ && ���� ���� Ȯ��.
			soldOutProductList.push_back(product);											// ���Ϳ� �߰�
		}
	}
	return soldOutProductList;
}

/*
	��ǰ ���� �� ����
*/
Product ProductCollection::getProductDetails(string productName) {
	for (Product product : productList) {
		if (product.getProductName() == productName) {
			return product;
		}
	}
	return Product(" ", " ", " ", -1, -1);	// ����ó��
}

/*
��� �������̽� : �Ǹ� ��ǰ ��� ���  (�׳� ȸ��)
���� : �Ǹ��ڰ� �ø� ��ǰ�鿡 ���Ͽ� ��� ������ �����. 
	   ��� ������ ��ǰ ���� �Ǹ� �Ѿװ� ��� ���Ÿ������� ��.
�Ķ���� : �Ǹ��� ���̵� (string sellerId)
���� : ��ǰ�� / ��ǰ �Ǹ� �Ѿ� / ��� ���� ������ (map<string, pair<int, double>>)
���� ���� : ���� �� map<��ǰ��, pair<��ǰ �Ǹ� �Ѿ�, ��� ���Ÿ�����>> �� �Ǹ�
			���� �� ����  ��ǰ�� = map.first	/  ��ǰ �Ǹ� �Ѿ� = map.second.first  / ���Ÿ����� = map.second.second �� ���.
*/
map<string, pair<int, double>> ProductCollection::getSoldStatistics(string sellerId) {
	map<string, pair<int, double>> resultMap;
	for (Product product : productList) {
		if (product.getSellerId() == sellerId) {
			int soldMoney = product.getPrice() * (product.getInitialQuantity() - product.getRemainQuantity());	// ���� * (�ʱ� - ����)
			double averageRating = product.getAverageRating();									// ��� ���Ÿ�����
			resultMap.insert({ product.getProductName(), { soldMoney, averageRating} });		// map�� ���� ����
		}
	}
	return resultMap;
}