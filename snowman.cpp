#include "snowman.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

const int decimalBase = 10;
const int hatIndex = 0;
const int noseMouthIndex = 1;
const int leftEyeIndex = 2;
const int rightEyeIndex = 3;
const int leftArmIndex = 4;
const int rightArmIndex = 5;
const int torsoIndex = 6;
const int baseIndex = 7;
const int minSnowman = 11111111;
const int maxSnowman = 55555555;
const int snowmanLen = 8;
const int optionsOfEachFeature = 4;
using namespace std;

namespace ariel
{
    //filling the array with the compatible strings:
    // 8 digits, as the place of the digits, and 4 options to each place

    int count_digits(int number)
    {
        return int(log10(number) + 1);
    }

    void check_and_take_each_digit(int number, int digitsArray[]) //checks if the digits are valid, and puts them in an array
    {
        int count = snowmanLen;
        int digit = 0;
        while (number >= decimalBase)
        {
            count--;
            digit = number % decimalBase;
            number = number / decimalBase;
            if (digit != 1 && digit != 2 && digit != 3 && digit != 4)
            {
                std::cout << "invalid digit '" << digit << "'\n"; //to print
                throw std::out_of_range("out_of_range");
            }
            digitsArray[count]= digit;
            //  std::cout << digit << '\n'; //to print
        }

        //aaaaand to the last digit:
        digit = number % decimalBase;
        if (digit != 1 && digit != 2 && digit != 3 && digit != 4)
        {
            std::cout << "invalid digit '" << digit << "'\n"; //to print
            throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");
            //"The input is invalid! make sure enter a number that contains only the digits 1-4"
        }
        digitsArray[0]= digit;
    }

    void collect_snowman_parts(int number, string snowmanBody[], int digitsArray[]) //collects the chosen snowman's body parts
    {
        string snowmanBodyParts[snowmanLen][optionsOfEachFeature] = {
        {" _===_", "  ___\n .....", "   _\n  /_\\ ", "  ___\n (_*_)"},
        {",", ".", "_", " "},
        {".", "o", "O", "-"},
        {".", "o", "O", "-"},
        {"\n<", "\\", "\n/", " "},
        {"\n>", "/", "\n\\", " "},
        {" : ", "] [", "> <", "   "},
        {" : ", "\" \"", "___", "   "}} ;

        for(int i=0; i< snowmanLen; i++){
            snowmanBody[i]= snowmanBodyParts[i][digitsArray[i]-1];
        }

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
        int digitsArray[snowmanLen]= {0, 0, 0, 0, 0, 0, 0, 0};
        check_and_take_each_digit(number, digitsArray); // will throw an exception if the number is invalid
                                  //    string snowman="";

        //reaching here means the input is valid. so, let's start printing the snowman!
        string snowmanBody[snowmanLen] = {" ", " ", " ", " ", " ", " ", " ", " "};
        collect_snowman_parts(number, snowmanBody, digitsArray);
        string H = snowmanBody[hatIndex];     //Hat
        string N = snowmanBody[noseMouthIndex];     //Nose/mouth
        string L = snowmanBody[leftEyeIndex];     //Left eye
        string R = snowmanBody[rightEyeIndex];     //Right eye
        string X = snowmanBody[leftArmIndex];  //Left arm
        string Y = snowmanBody[rightArmIndex];  //Right arm
        string T = snowmanBody[torsoIndex];   //Torso
        string B = snowmanBody[baseIndex]; //Base

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

        // std::cout << "THE SNOWMAN IS: \n"
        //           << snowman << "\n"; //to print
        //                            //       std::cout << "THE B IS: \n" << "("+B+")" << "\n"; //to print
        return snowman;
    }

}

        //  HHHHH
        //  HHHHH
        // X(LNR)Y
        // X(TTT)Y
        //  (BBB)