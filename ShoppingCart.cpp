#include <iostream>
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
  customerName = "none";
  currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
  customerName = name;
  currentDate = date;
}

string ShoppingCart::GetCustomerName() const{
  return customerName;
}

string ShoppingCart::GetDate() const{
  return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
  cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name){
  bool found = false;
  for(unsigned int i = 0; i<cartItems.size(); i++){
    if(cartItems.at(i).GetName() == name){
      cartItems.erase(cartItems.begin()+i);
      found = true;
    }  
  }
  if(found == false){
    cout << "Item not found in cart. Nothing removed." << endl;
  }
}

void ShoppingCart::ModifyItem(ItemToPurchase item){
  bool found = false;
  for(unsigned int i = 0; i<cartItems.size(); i++){
    if(cartItems.at(i).GetName() == item.GetName()){
      if(item.GetDescription() != "none"){
        cartItems.at(i).SetDescription(item.GetDescription());
      }
      if(item.GetPrice() != 0){
        cartItems.at(i).SetPrice(item.GetPrice());
      }
      if(item.GetQuantity() != 0){
        cartItems.at(i).SetQuantity(item.GetQuantity());
      }
    }
  }
  if(found == false){
    cout << "Item not found in cart. Nothing modified." << endl;
  }
}

int ShoppingCart::GetNumItemsInCart(){
  return cartItems.size();
}

double ShoppingCart::GetCostOfCart(){
  int sum = 0;
  for(ItemToPurchase item : cartItems){
    sum += item.GetPrice() * item.GetQuantity();
  }

  return sum;
}

void ShoppingCart::PrintTotal(){
  cout << customerName << "'s Shopping Cart - " << currentDate << endl;
  cout << "Number of items: " << cartItems.size() << endl << endl;
  for(ItemToPurchase item : cartItems){
    item.PrintItemCost();
  }
  if(cartItems.empty()){
    cout << endl << "SHOPPING CART IS EMPTY" << endl;
  }
  cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions(){
  cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
  cout << "Item Descriptions" << endl;
  for(ItemToPurchase item : cartItems){
    item.PrintItemCost();
  }
  if(cartItems.empty()){
    cout << "SHOPPING CART IS EMPTY" << endl;
  }
}
  
