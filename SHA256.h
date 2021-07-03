//cmath library can be removed when using shortcut
#include <iostream>
#include <cmath> //Needed for calculating constants and initial hash values

using std::endl;
using std::cout;
using std::cin;
using std::string;

void populateShiftValues();
void computeConstants();
void computeInitialHashValues();
string hexToBinary(char input[], int characterCount);
void convertToBinary(int current);
void rightShift(int RightShiftValue, int Order, int wordNumber, int equationNumber);
void shift(int ShiftValue, int Order, int wordNumber);
void xortest();
void equationCompute(int equationNumber, int wordNumber);
void binaryAdditionFunction(int inc);