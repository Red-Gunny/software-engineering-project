#include "../header/control/Purchase.h"

Product Purchase::purchaseProduct() {
	if (productList->purchaseProduct(searchedProduct.getProductName())) {	// Control -> ProductList
		userList->purchaseProduct(currentUser, searchedProduct.getProductName());	
		return searchedProduct;
	}
	else {
		return Product("", "", "", -1, -1);	// 구매 실패
	}
}