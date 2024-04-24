//GitHub Repository: https://github.com/zx-hu/zyLab-28.14
//Team Members: Ryan Hiltz, Gloria Hu

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   /* Type your code here */
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   /* Type your code here */
   
}

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
