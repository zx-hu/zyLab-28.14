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
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   switch(option){
      case 'a': {
         break;
      }
      case 'd': {
         break;
      }
      case 'c': {
         break;
      }
      case 'i': {
         break;
      }
      case 'o': {
         break;
      }
      case 'q': 
         break;
      default: 
         cout << "Invalid option. Re-enter.";
}

int main() {
   /* Type your code here */
   
   return 0;
}
