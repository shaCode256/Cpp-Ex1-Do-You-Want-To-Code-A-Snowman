 /* 

 *
 * TEST FOR SNOWMAN.CPP
 *
 * AUTHOR: Shavit Luzon
 *
 * Date: 2021-03
 *

*/

#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "doctest.h"
#include "snowman.hpp"
//using namespace ariel;
#include <string>
using namespace std;
using namespace ariel; 

/* 11114411
 length: 8 areas
 options: 4 for each one 
 options are 1,2,3,4
 charcaters that are not integers won't be accepted, as the snowman function gets integers only.
 so problems that can occur: wrong amount of digits | 
 */

TEST_CASE("Too many digits: given wrong number of choices- an input out of range") {

    CHECK_THROWS(snowman(121212121));  // there are 9 digits in the input, while needs to have 8 exactly. check that some exception is thrown. 
    CHECK_THROWS_AS(snowman(123456789), std::out_of_range);  // check that the specific exception of out of range is thrown. there are 9 digits,while needs to have 8 exactly.
    CHECK_THROWS_AS(snowman(1234123412), std::out_of_range);  // check that a specific exception type is thrown. there are 10 digits, while needs to have 8 exactly.
    // CHECK_THROWS_AS(snowman(12341234123), std::out_of_range); // check that a specific exception type is thrown. there are 11 digits,while needs to have 8 exactly..
    // CHECK_THROWS_AS(snowman(123412341234), out_of_range); // check that a specific exception type is thrown. there are 12 digits, while needs to have 8 exactly.
    // CHECK_THROWS_AS(snowman(2323141324122), out_of_range); // there are 13 digits, while there should be 8. check that a out of range exception is thrown.
    // CHECK_THROWS_AS(snowman(22222224141442), out_of_range); // there are 14 digits, while there should be 8. check that a out of range exception is thrown.

}

TEST_CASE("Not enough digits: given wrong number of choices- an input out of range") {
    CHECK_THROWS_AS(snowman(2222222), out_of_range); // // there are 7 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(123412), out_of_range); // there are 6 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(44421), out_of_range); // there are 5 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(3334), out_of_range); // there are 4 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(111), out_of_range); // there are 3 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(21), out_of_range); // there are 2 digits, while there should be 8. check that a out of range exception is thrown.
    CHECK_THROWS_AS(snowman(1), out_of_range);// there is 1 digit, while there should be 8. check that a out of range exception is thrown.
//  CHECK_THROWS_AS(snowman(), out_of_range);// there are no digits, while there should be 8. check that a out of range exception is thrown.

}


TEST_CASE("Given unvalid options- wrong input: includes digits that are not 1,2,3,4") {
    CHECK_THROWS(snowman(44312346));
    CHECK_THROWS_AS(snowman(12923102), std::invalid_argument);
    CHECK_THROWS_AS(snowman(14645678), std::invalid_argument);
    CHECK_THROWS_AS(snowman(12345678), std::invalid_argument);
    CHECK_THROWS_AS(snowman(22227222), std::invalid_argument);
    CHECK_THROWS_AS(snowman(12323991), std::invalid_argument);

}

TEST_CASE("Good inputs- check the outputs") {

    CHECK(snowman(11114411) == string(" _===_\n (.,.)\n ( : )\n ( : )"));
    CHECK(snowman(33232124) == string("   _\n  /_\\ \n\\(o_O)\n (] [)>\n (   )"));
    CHECK(snowman(12222212) == string(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));
    CHECK(snowman(32443333) == string("   _\n  /_\\ \n (-.-)\n/(> <)\\ \n (___)"));
    CHECK(snowman(12341234) == string(" _===_\n (O.-)/\n<(> <)\n (   )"));
    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(44444432) == string("  ___\n (_*_)\n (- -)\n (> <)\n (\" \")"));

}



        //  HHHHH
        //  HHHHH
        // X(LNR)Y
        // X(TTT)Y
        //  (BBB)

TEST_CASE("Bad inputs- look for exceptions") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(55543453));
    CHECK_THROWS(snowman(528723855));
    CHECK_THROWS(snowman(22191232));
    CHECK_THROWS(snowman(55329435));
    CHECK_THROWS(snowman(124329436));

}

    /* 30 tests */