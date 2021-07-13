#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

struct ConstantValueStruct{
	string WorkingValues;
};

void populateShiftValues();
void computeConstants(struct ConstantValueStruct ConstantValues[]);
void computeInitialHashValues();
string binaryToHex(string output[]);
string hexToBinary(char input[], int characterCount);
void convertToBinary(int current);
void rightShift(int RightShiftValue, int Order, int equationNumber, int wordNumber, int blockNumber);
void shift(int ShiftValue, int Order, int wordNumber, int blockNumber);
void xortest();
void equationCompute(int equationNumber, int wordNumber, int blockNumber);
void binaryAdditionFunction(int wordCount);
void majority();
void choice();
string SHA256(string message, struct ConstantValueStruct ConstantValues[]);