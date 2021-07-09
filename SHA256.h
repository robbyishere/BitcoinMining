#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

void populateShiftValues();
void computeConstants();
void computeInitialHashValues();
string binaryToHex(string output[]);
string hexToBinary(char input[], int characterCount);
void convertToBinary(int current);
void rightShift(int RightShiftValue, int Order, int equationNumber, int wordNumber, int blockNumber);
void shift(int ShiftValue, int Order, int wordNumber, int blockNumber);
void xortest();
void equationCompute(int equationNumber, int wordNumber, int blockNumber);
void binaryAdditionFunction(int equationsCount);
void majority();
void choice();
string SHA256(char minerInput[]);