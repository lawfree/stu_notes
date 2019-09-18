package cn.lowfree.entity;

import cn.lowfree.entity.cn.lowfree.entity.Product;

public class ShoppingItem {
    private Product product;
    private  int quantity;

    public  ShoppingItem(Product product , int quantity){
        this.product = product ;
        this.quantity = quantity;
    }

    public void setProduct(Product product) {
        this.product = product;
    }

    public Product getProduct() {
        return product;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public int getQuantity() {
        return quantity;
    }
}
