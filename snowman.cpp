#include "snowman.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

const int ten= 10;
const int snowmanLen= 8;
const int five= 5;
const int six= 6;
const int seven= 7;
const int eight= 8;
const int minSnowman= 11111111;
const int maxSnowman= 55555555;

using namespace std;

namespace ariel
{ 
    int numFeaturesRecursive=-1;
    int whichFeature=1;
    string H=" ";
    string N=" ";
    string L=" ";
    string R=" ";
    string X=" ";
    string T=" ";
    string B=" ";
    string Y=" ";
    //filling the array with the compatible strings:
   // 8 digits, as the place of the digits, and 4 options to each place
    
    int count_digits(int number) {
        return int(log10(number) + 1);
    } 

    void check_each_digit(int number){
        int digit=0;
        if(number >= ten){
            check_each_digit(number/ten);
        }
        digit = number % ten;
        if(digit!=1 && digit!=2 && digit!=3 && digit!=4){
            std::cout << "invalid digit '" << digit << "'\n"; //to print
            throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");

            //"The input is invalid! make sure enter a number that contains only the digits 1-4"
        }
      //  std::cout << digit << '\n'; //to print
    }

        void create_the_snowman(int number){
 //       std::cout << "NUM IS " << number << '\n'; //to print
        int digit=0;
        if(number >= ten){
 //       std::cout << "yo, i'm here " << '\n'; //to print
            numFeaturesRecursive++;
            create_the_snowman(number/ten);
        }

        digit = number % ten;
        whichFeature= snowmanLen-numFeaturesRecursive;
        // std::cout << "the digit is " << digit << '\n'; //to print
        // std::cout << "the feature is " << whichFeature << '\n'; //to print
        // std::cout << "the recursive is " << numFeaturesRecursive << '\n'; //to print

            //because it's a valid number, its digits are only in range of 1-4
            if(digit==1){  
                if(whichFeature==1){
                    H= "_===_";
                }
                if(whichFeature==2){
                    N= ",";
                }
                if(whichFeature==3){
                    L=".";
                }
                if(whichFeature==4){
                    R=".";

                }
                if(whichFeature==five){
                    X="\n<";
                }
                if(whichFeature==seven){
                    T=" : ";
                }
                if(whichFeature==eight){
                    B=" : ";
                }
                if(whichFeature==six){
                    Y="\n>";   
                }
            }
            else if(digit==2){
                if(whichFeature==1){
                    H= " ___\n.....";
                }
                if(whichFeature==2){
                    N=".";
                }
                if(whichFeature==3){
                    L="o";
                }
                if(whichFeature==4){
                    R="o";
                }
                if(whichFeature==five){
                    X="\\";
                }
                if(whichFeature==seven){
                    T="] [";
                }
                if(whichFeature==eight){
                    B="" "";
                }
                if(whichFeature==six){
                    Y="/";
                }
            }
            else if(digit==3){ 
                if(whichFeature==1){
                    H= " _\n/_\\ ";
                }
                if(whichFeature==2){
                    N="_";
                }
                if(whichFeature==3){
                    L="O";
                }
                if(whichFeature==4){
                    R="O";

                }
                if(whichFeature==five){
                    X="\n/";
                }
                if(whichFeature==seven){
                    T="> <";
                }
                if(whichFeature==eight){
                    B="___";
                }
                if(whichFeature==six){
                    Y="\n\"";
                }
            }
            else if(digit==4){ //
                if(whichFeature==1){
                    H= " ___(_*_)";
                }
                if(whichFeature==2){
                    N="\n";
                }
                if(whichFeature==3){
                    L="-";
                }
                if(whichFeature==4){
                    R="-";

                }
                if(whichFeature==five){
                    X="";
                }
                if(whichFeature==seven){
                    T="";
                }
                if(whichFeature==eight){
                    B="";
                }
                if(whichFeature==six){
                    Y="";
                }
        }
        numFeaturesRecursive--;
        
  //     whichFeature= whichFeature+1;
      //  cout << "digits are" << digit << '\n'; //to print
    }

    string snowman(int number) {
        if(count_digits(number)!= snowmanLen){
            std::cout << "invalid code '" << number << "'\n"; //to print
            throw std::out_of_range( "The input is out of range! make sure you enter exactly 8 digits" );
        }
        if(number < minSnowman || number > maxSnowman){ //to avoid getting an input with conversion fro long to int
             std::cout << "invalid number '" << number << "'\n"; //to print
            throw std::invalid_argument("The input is invalid! make sure enter a number that contains only the digits 1-4");           
        }
        check_each_digit(number); // will throw an exception if the number is invalid
    //    string snowman="";
        H=" "; //Hats
        N=" "; //Nose/mouth
        L=" "; //Left eye
        R=" "; //Right eye
        X=" "; //Left arm
        T=" "; //Torso
        B=" "; //Base
        Y=" "; //Right arm
        //reaching here means the input is valid. so, let's start printing the snowman!
        whichFeature=1;
        numFeaturesRecursive=0;
        create_the_snowman(number);
        // std::cout << "N IS " << N << "'\n"; //to print
        // std::cout << "L IS " << L << "'\n"; //to print
        // std::cout << "R IS " << R << "\n"; //to print
        // std::cout << "X IS " << X << "'\n"; //to print
        // std::cout << "T IS " << T << "'\n"; //to print
        // std::cout << "B IS " << B << "'\n"; //to print
        // std::cout << "Y IS " << Y << "'\n"; //to print

        string real=" ";
        if(X.find('\n')!=std::string::npos){
            if(Y.find('\n')!=std::string::npos){
                real= H+"\n"+" "+"("+L+N+R+")"+X+"("+T+")"+Y+"("+B+")"; //cuz X contains \n and than goes down, and also Y
            }
            else{
                real= H+"\n"+" "+"("+L+N+R+")"+X+"("+T+")"+Y+"\n"+"("+B+")"; //cuz X contains \n and Y doesn't
            }
        }
        else{
            if(Y.find('\n')!=std::string::npos){
                real= H+"\n"+" "+"("+L+N+R+")"+X+"\n"+"("+T+")"+Y+"("+B+")"; //cuz Y contains \n and than goes down, and X doesn't
            }
            else{
                real= H+"\n"+" "+"("+L+N+R+")"+X+"\n"+"("+T+")"+Y+"\n"+"("+B+")"; //cuz X doesn't contain \n and so does Y
            }
        }
        //string realsnowman= H+"\n"+XS+"("+L+N+R+")"+YS+XS+"("+T+")"+YS+"("+B+")";

//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)
        string snowman= "123";
        snowman= real;
        std::cout << "THE SNOWMAN IS " << real << "'\n"; //to print
        return snowman;
    }
   


}

