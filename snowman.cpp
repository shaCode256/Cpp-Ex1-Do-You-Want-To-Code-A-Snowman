#include "snowman.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

const int ten = 10;
const int snowmanLen = 8;
const int five = 5;
const int six = 6;
const int seven = 7;
const int eight = 8;
const int nine = 9;
const int four = 4;
const int minSnowman = 11111111;
const int maxSnowman = 55555555;
using namespace std;

int count_digits(int number);
void check_each_digit(int number);
void collect_snowman_parts(int number);
void remove_newline(std::string s);

namespace ariel
{
    //filling the array with the compatible strings:
    // 8 digits, as the place of the digits, and 4 options to each place

    int count_digits(int number)
    {
        return int(log10(number) + 1);
    }

    void check_each_digit(int number) //checks if the digits are valid
    {
        int digit = 0;
        while (number >= ten)
        {
            digit = number % ten;
            number = number / ten;
            if (digit != 1 && digit != 2 && digit != 3 && digit != 4)
            {
                std::cout << "invalid digit '" << digit << "'\n"; //to print
                throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");
            }
            //  std::cout << digit << '\n'; //to print
        }

        //aaaaand to the last digit:
        digit = number % ten;
        if (digit != 1 && digit != 2 && digit != 3 && digit != 4)
        {
            std::cout << "invalid digit '" << digit << "'\n"; //to print
            throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");
            //"The input is invalid! make sure enter a number that contains only the digits 1-4"
        }
    }

    void collect_snowman_parts(int number, string snowmanBody[]) //collects the chosen snowman's body parts
    {
        string snowmanBodyParts[snowmanLen][four] = {
        {" _===_", "  ___\n .....", "   _\n  /_\\ ", "  ___\n (_*_)"},
        {",", ".", "_", " "},
        {".", "o", "O", "-"},
        {".", "o", "O", "-"},
        {"\n<", "\\", "\n/", " "},
        {"\n>", "/", "\n\\", " "},
        {" : ", "] [", "> <", "   "},
        {" : ", "\" \"", "___", "   "}} ;


        //       std::cout << "NUM IS " << number << '\n'; //to print
        int digit = 0;
        int whichFeature = nine;
        int placeInBody = 0;
        while (number >= ten)
        {
            whichFeature--;
            digit = number % ten;
            number = number / ten;
            placeInBody = whichFeature - 1;
            // std::cout << "the digit is " << digit << '\n'; //to print
            // std::cout << "the feature is " << whichFeature << '\n'; //to print

            //range of (digit-1) is 0-3 because it's a valid number, so range of digit is (1-4).
            snowmanBody[placeInBody] = snowmanBodyParts[placeInBody][digit - 1];
        }

        ///////////and to the last digit- which is the first feature:
        digit = number % ten;
        snowmanBody[0] = snowmanBodyParts[0][digit - 1];

        //"The input is invalid! make sure enter a number that contains only the digits 1-4"
        //  cout << "digits are" << digit << '\n'; //to print
    }

    string snowman(int number) //returns the string of the snowman
    {
        if (count_digits(number) != snowmanLen)
        {
            std::cout << "invalid code '" << number << "'\n"; //to print
            throw std::out_of_range("The input is out of range! make sure you enter exactly 8 digits");
        }
        if (number < minSnowman || number > maxSnowman)
        {                                                       //to avoid getting an input with conversion fro long to int
            std::cout << "invalid number '" << number << "'\n"; //to print
            throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");
        }
        check_each_digit(number); // will throw an exception if the number is invalid
                                  //    string snowman="";

        //reaching here means the input is valid. so, let's start printing the snowman!
        string snowmanBody[snowmanLen] = {" ", " ", " ", " ", " ", " ", " ", " "};
        collect_snowman_parts( number, snowmanBody);
        string H = snowmanBody[0];     //Hat
        string N = snowmanBody[1];     //Nose/mouth
        string L = snowmanBody[2];     //Left eye
        string R = snowmanBody[3];     //Right eye
        string X = snowmanBody[four];  //Left arm
        string Y = snowmanBody[five];  //Right arm
        string T = snowmanBody[six];   //Torso
        string B = snowmanBody[seven]; //Base

        // std::cout << "H IS " << H << "\n"; //to print
        // std::cout << "N IS " << N << "\n"; //to print
        // std::cout << "L IS " << L << "\n"; //to print
        // std::cout << "R IS " << R << "\n"; //to print
        // std::cout << "X IS " << X << "\n"; //to print
        // std::cout << "Y IS " << Y << "\n"; //to print
        // std::cout << "T IS " << T << "\n"; //to print
        // std::cout << "B IS " << B << "\n"; //to print

        if(X== " "){ //fixing special cases spaces.
            X= "  ";
        }
        if(Y == " "){ //fixing special cases spaces.
            Y= "  ";
        }
        string snowman = " ";
        if (X.find('\n') != std::string::npos)
        { //if you can find '\n' in this string. the difference in the hands (X&Y)
                    X.erase(0, 1);
            if (Y.find('\n') != std::string::npos)
            {
                Y.erase(0, 1);
                //  std::cout << "Y IS " << Y << "\n"; //to print
                snowman = H + "\n"  + " (" + L + N + R + ")" + "\n" + X + "(" + T + ")" + Y + "\n" + " (" + B + ")"; //cuz X contains \n and than goes down, and also Y
            }
            else
            {
                snowman = H + "\n" + " (" + L + N + R + ")" + Y + "\n" + X + "(" + T + ")" + "\n" + " (" + B + ")"; //cuz X contains \n and Y doesn't
            }
        }
        else
        {
            if (Y.find('\n') != std::string::npos)
            {      
                Y.erase(0, 1);
                snowman = H + "\n" + X + "(" + L + N + R + ")" + "\n" + " (" + T + ")" + Y + "\n" + " (" + B + ")"; //cuz Y contains \n and than goes down, and X doesn't
            }
            else
            {
                if(X== "  "){
                    X=" ";
                }
                snowman = H + "\n" + X + "(" + L + N + R + ")" + Y + "\n" + " (" + T + ")" + "\n" + " (" + B + ")"; //cuz X doesn't contain \n and so does Y
            }
        }
        //string realsnowman= H+"\n"+XS+"("+L+N+R+")"+YS+XS+"("+T+")"+YS+"("+B+")";

        //       std::cout << "X IS: \n" << "-"+X+"-"   ;

        std::cout << "THE SNOWMAN IS: \n"
                  << snowman << "\n"; //to print
                                   //       std::cout << "THE B IS: \n" << "("+B+")" << "\n"; //to print
        return snowman;
    }

}

        //  HHHHH
        //  HHHHH
        // X(LNR)Y
        // X(TTT)Y
        //  (BBB)