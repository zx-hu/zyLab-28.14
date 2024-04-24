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
         cout << "ADD ITEM TO CART" << endl;
         cout <<  "Enter the item name:" << endl;
         getline(cin,name);
         cout << "Enter the item description:" << endl;
         getline(cin, description);
         cout << "Enter the item price:" << endl;
         cin >> price;
         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         ItemToPurchase item = new ItemToPurchase(name, description, price, quantity);
         theCart.AddItem(item);
         break;
      }
      case 'd': {
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove" << endl;
         getline(cin, name);
         theCart.RemoveItem(name);
         break;
      }
      case 'c': {
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter item name:" << endl;
         getline(cin, name);
         cout << "Enter the new quantity" << endl;
         cin >> quantity;
         ItemToPurchase item = new ItemToPurchase();
         item.SetName(name);
         item.SetQuantity(quantity);
         theCart.ModifyItem(item);
         break;
      }
      case 'i': {
         cout << "OUTPUT ITEM DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         break;
      }
      case 'o': {
         cout << "OUTPUT SHOPPPING CART" << endl;
         theCart.PrintTotal();
         break;
      }
      case 'q': 
         break;
      default: 
         cout << "Invalid option. Re-enter.";
};

int main() {
   char option = '';
   string name, date;
   cout << "Enter customer's name:" << endl;
   cin >> name;
   cout << "Enter today's date:" << endl;
   cin >> date;
   
   ShoppingCart userCart = new ShoppingCart(name, date);

   cout << endl;
   cout << "Customer name: " << userCart.GetCustomerName() << end;
   cout << "Today's date: " << userCart.GetDate() << endl;
   
   while(option != 'q'){
      PrintMenu();
      cout << endl;
      cout << "Choose an option:" <<endl;
      cin >> option;
      ExecuteMenu(option, userCart);
   }
   
   return 0;
}
