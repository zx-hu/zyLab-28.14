//GitHub Repository: https://github.com/zx-hu/zyLab-28.14
//Team Members: Ryan Hiltz, Gloria Hu

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" <<  endl;
   
};

void ExecuteMenu(char option, ShoppingCart& theCart) {
   string name, description;
   int price, quantity;
   switch(option){
      case 'a': {
         cin.ignore();
         cout << "ADD ITEM TO CART" << endl;
         cout <<  "Enter the item name:" << endl;
         getline(cin, name);
         cout << "Enter the item description:" << endl;
         getline(cin, description);
         cout << "Enter the item price:" << endl;
         cin >> price;
         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         ItemToPurchase item = ItemToPurchase(name, description, price, quantity);
         theCart.AddItem(item);
         break;
      }
      case 'd': {
         cin.ignore();
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         getline(cin, name);
         theCart.RemoveItem(name);
         break;
      }
      case 'c': {
         cin.ignore();
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter item name:" << endl;
         getline(cin, name);
         cout << "Enter the new quantity:" << endl;
         cin >> quantity;
         ItemToPurchase item;
         item.SetName(name);
         item.SetQuantity(quantity);
         theCart.ModifyItem(item);
         break;
      }
      case 'i': {
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         break;
      }
      case 'o': {
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         break;
      }
      case 'q': 
         break;
      default: 
         break;
   }
};

int main() {
   char option;
   string name, date;
   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   getline(cin, date);
   
   ShoppingCart userCart = ShoppingCart(name, date);

   cout << endl;
   cout << "Customer name: " << userCart.GetCustomerName() << endl;
   cout << "Today's date: " << userCart.GetDate() << endl << endl;
   
   PrintMenu();
   cout << endl;
   
   cout << "Choose an option:" << endl;
   cin >> option;
   ExecuteMenu(option, userCart);
   
   while(option != 'q'){
      if(option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o'){
         cout << endl;
         PrintMenu();
         cout << endl;
      }
      cout << "Choose an option:" << endl;
      cin >> option;
      ExecuteMenu(option, userCart);
   }
   
   return 0;
}
