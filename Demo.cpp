/**
 * Main Demo program for snowman exercise.
 * 
 * Author: Shavit Luzon
 * Since : 2021-03
 */

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

int main() {
int number; 
cout << "Type a number which represent a snowman: "; // Type a number and press enter
cin >> number; // Get user input from the keyboard
cout << "Your snowman is: \n" << snowman(number) << endl; // Display the input value

}