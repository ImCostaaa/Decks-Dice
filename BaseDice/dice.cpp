using namespace std;
#include "dice.h" 

//CS3307 - Group 5
//Date:         8 November, 2018
//Description:  Randomly generates a variable sided dice a variable amount of times

dice::dice()
{
    //empty constructor
}

int dice::roll (int sides, int rolls) {
    srand(time(NULL));                              //can't run this class back-to-back t0o quickly
    int sum = 0;
    for (int i = 1; i <= rolls; i++) {              //generate a random number, modulo by the number of sides, this results in a number from (0, sides-1), add 1 for (1, sides), then add this amount to total
            sum = sum + ((rand() % sides) + 1);     //example:      sides = 6, rolls = 2        |Roll1                   |Roll2                     |Sum;
    }                                               //                                          |(12345 % 6) + 1 = 4     |(67890 % 6) + 1 = 1       |4 + 1 = 5

    return sum;
};
