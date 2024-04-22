#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

//Default Constructor
ItemToPurchase::ItemToPurchase(){
  itemName = "none";
  itemPrice = 0;
  itemQuantity = 0;
  itemDescription = "none";
}

//Constructor
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
  itemName = name;
  itemPrice = price;
  itemQuantity = quantity;
  itemDescription = description;
}

//Set Name
void ItemToPurchase::SetName(string n){
  itemName = n;
}

//Get Name
string ItemToPurchase::GetName() const{
  return itemName;
}

//Set Price
void ItemToPurchase::SetPrice(int p){
  itemPrice = p;
}

//Get Price
int ItemToPurchase::GetPrice() const{
  return itemPrice;
}

//Set Quantity
void ItemToPurchase::SetQuantity(int q){
  itemQuantity = q;
}

//Get Quantity
int ItemToPurchase::GetQuantity() const{
  return itemQuantity;
}

//Set Description
void ItemToPurchase::SetDescription(string d){
  itemDescription = d;
}

//Get Description
string ItemToPurchase::GetDescription() const{
  return itemDescription;
}

void ItemToPurchase::PrintItemCost(){
  int subtotal = itemQuantity*itemPrice;
  cout << itemName << "  " << itemQuantity << " @ $" << itemPrice << " = $" << subtotal << endl;
}

void ItemToPurchase::PrintItemDescrition(){
  cout << itemName << ": " << itemDescription << endl;
}


