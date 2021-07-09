/* TODO:
Cut down struct array values?
*/

/* Ideas for optimization:
Use Right Shift operator
Use XOR operator
bool instead of int (Might not increase speed but saves memory)
Target Check before computing rest of hash values
*/
#include "SHA256.h"

struct messageSchedule{
	int word[32];
} schedule[2][64];

struct equationData{
	int result[32];
} Data[4];

struct equationShiftValues{
	int Value[3];
} Shift[4];
struct ConstantValues{
	string WorkingValues;
}ConstantValues[64];
struct HashValues{
	string InitialValues;
	int OriginalValues[32];
	int WorkingValues[32];
}HashValues[8];
struct binaryAddition{
	int Data[32];
}binaryAddition[8];

void populateShiftValues(){
	Shift[0].Value[0] = 7;
	Shift[0].Value[1] = 18;
	Shift[0].Value[2] = 3;
	Shift[1].Value[0] = 17;
	Shift[1].Value[1] = 19;
	Shift[1].Value[2] = 10;
	Shift[2].Value[0] = 2;
	Shift[2].Value[1] = 13;
	Shift[2].Value[2] = 22;
	Shift[3].Value[0] = 6;
	Shift[3].Value[1] = 11;
	Shift[3].Value[2] = 25;
}
void computeConstants(){
	ConstantValues[0].WorkingValues = "01000010100010100010111110011000";
	ConstantValues[1].WorkingValues = "01110001001101110100010010010001";
	ConstantValues[2].WorkingValues = "10110101110000001111101111001111";
	ConstantValues[3].WorkingValues = "11101001101101011101101110100101";
	ConstantValues[4].WorkingValues = "00111001010101101100001001011011"; 
	ConstantValues[5].WorkingValues = "01011001111100010001000111110001";
	ConstantValues[6].WorkingValues = "10010010001111111000001010100100";
	ConstantValues[7].WorkingValues = "10101011000111000101111011010101";
	ConstantValues[8].WorkingValues = "11011000000001111010101010011000";
	ConstantValues[9].WorkingValues = "00010010100000110101101100000001";
	ConstantValues[10].WorkingValues = "00100100001100011000010110111110";
	ConstantValues[11].WorkingValues = "01010101000011000111110111000011";
	ConstantValues[12].WorkingValues = "01110010101111100101110101110100";
	ConstantValues[13].WorkingValues = "10000000110111101011000111111110";
	ConstantValues[14].WorkingValues = "10011011110111000000011010100111";
	ConstantValues[15].WorkingValues = "11000001100110111111000101110100";
	ConstantValues[16].WorkingValues = "11100100100110110110100111000001";
	ConstantValues[17].WorkingValues = "11101111101111100100011110000110";
	ConstantValues[18].WorkingValues = "00001111110000011001110111000110";
	ConstantValues[19].WorkingValues = "00100100000011001010000111001100";
	ConstantValues[20].WorkingValues = "00101101111010010010110001101111";
	ConstantValues[21].WorkingValues = "01001010011101001000010010101010";
	ConstantValues[22].WorkingValues = "01011100101100001010100111011100";
	ConstantValues[23].WorkingValues = "01110110111110011000100011011010";
	ConstantValues[24].WorkingValues = "10011000001111100101000101010010";
	ConstantValues[25].WorkingValues = "10101000001100011100011001101101";
	ConstantValues[26].WorkingValues = "10110000000000110010011111001000";
	ConstantValues[27].WorkingValues = "10111111010110010111111111000111";
	ConstantValues[28].WorkingValues = "11000110111000000000101111110011";
	ConstantValues[29].WorkingValues = "11010101101001111001000101000111";
	ConstantValues[30].WorkingValues = "00000110110010100110001101010001";
	ConstantValues[31].WorkingValues = "00010100001010010010100101100111";
	ConstantValues[32].WorkingValues = "00100111101101110000101010000101";
	ConstantValues[33].WorkingValues = "00101110000110110010000100111000";
	ConstantValues[34].WorkingValues = "01001101001011000110110111111100";
	ConstantValues[35].WorkingValues = "01010011001110000000110100010011";
	ConstantValues[36].WorkingValues = "01100101000010100111001101010100";
	ConstantValues[37].WorkingValues = "01110110011010100000101010111011";
	ConstantValues[38].WorkingValues = "10000001110000101100100100101110";
	ConstantValues[39].WorkingValues = "10010010011100100010110010000101";
	ConstantValues[40].WorkingValues = "10100010101111111110100010100001";
	ConstantValues[41].WorkingValues = "10101000000110100110011001001011";
	ConstantValues[42].WorkingValues = "11000010010010111000101101110000";
	ConstantValues[43].WorkingValues = "11000111011011000101000110100011";
	ConstantValues[44].WorkingValues = "11010001100100101110100000011001";
	ConstantValues[45].WorkingValues = "11010110100110010000011000100100";
	ConstantValues[46].WorkingValues = "11110100000011100011010110000101";
	ConstantValues[47].WorkingValues = "00010000011010101010000001110000";
	ConstantValues[48].WorkingValues = "00011001101001001100000100010110";
	ConstantValues[49].WorkingValues = "00011110001101110110110000001000";
	ConstantValues[50].WorkingValues = "00100111010010000111011101001100";
	ConstantValues[51].WorkingValues = "00110100101100001011110010110101";
	ConstantValues[52].WorkingValues = "00111001000111000000110010110011";
	ConstantValues[53].WorkingValues = "01001110110110001010101001001010";
	ConstantValues[54].WorkingValues = "01011011100111001100101001001111";
	ConstantValues[55].WorkingValues = "01101000001011100110111111110011";
	ConstantValues[56].WorkingValues = "01110100100011111000001011101110";
	ConstantValues[57].WorkingValues = "01111000101001010110001101101111";
	ConstantValues[58].WorkingValues = "10000100110010000111100000010100";
	ConstantValues[59].WorkingValues = "10001100110001110000001000001000";
	ConstantValues[60].WorkingValues = "10010000101111101111111111111010";
	ConstantValues[61].WorkingValues = "10100100010100000110110011101011";
	ConstantValues[62].WorkingValues = "10111110111110011010001111110111";
	ConstantValues[63].WorkingValues = "11000110011100010111100011110010";
}
void computeInitialHashValues(){
	HashValues[0].InitialValues = "01101010000010011110011001100111";
	HashValues[1].InitialValues = "10111011011001111010111010000101";
	HashValues[2].InitialValues = "00111100011011101111001101110010";
	HashValues[3].InitialValues = "10100101010011111111010100111010";
	HashValues[4].InitialValues = "01010001000011100101001001111111";
	HashValues[5].InitialValues = "10011011000001010110100010001100";
	HashValues[6].InitialValues = "00011111100000111101100110101011";
	HashValues[7].InitialValues = "01011011111000001100110100011001";
	//Duplicate values
	for(int i=0; i<8; i++){
		for(int j=0; j<32; j++){
			if(HashValues[i].InitialValues[j] == '1'){
				HashValues[i].OriginalValues[j] = 1;
				HashValues[i].WorkingValues[j] = 1;
			}
			if(HashValues[i].InitialValues[j] == '0'){
				HashValues[i].OriginalValues[j] = 0;
				HashValues[i].WorkingValues[j] = 0;
			}
		}
	}
}
string binaryToHex(string output[]){
	string result;
	for(int i=0; i<64; i++){
		if(output[i] == "0000"){
			result = result + '0';
		}
		if(output[i] == "0001"){
				result = result + '1';
		}
		if(output[i] == "0010"){
				result = result + '2';
		}
		if(output[i] == "0011"){
				result = result + '3';
		}
		if(output[i] == "0100"){
				result = result + '4';
		}
		if(output[i] == "0101"){
				result = result + '5';
		}
		if(output[i] == "0110"){
				result = result + '6';
		}
		if(output[i] == "0111"){
				result = result + '7';
		}
		if(output[i] == "1000"){
				result = result + '8';
		}
		if(output[i] == "1001"){
				result = result + '9';
		}
		if(output[i] == "1010"){
				result = result + 'a';
		}
		if(output[i] == "1011"){
				result = result + 'b';
		}
		if(output[i] == "1100"){
				result = result + 'c';
		}
		if(output[i] == "1101"){
				result = result + 'd';
		}
		if(output[i] == "1110"){
				result = result + 'e';
		}
		if(output[i] == "1111"){
				result = result + 'f';
		}
	}
	return result;
}
string hexToBinary(char input[], int characterCount){
	string result;
	for(int i=0; i<characterCount; i++){
		switch(input[i]){ 
			case 'a':
				result = result + "1010";
				break;
			case 'b':
				result = result + "1011";
				break;
			case 'c':
				result = result + "1100";
				break;
			case 'd':
				result = result + "1101";
				break;
			case 'e':
				result = result + "1110";
				break;
			case 'f':
				result = result + "1111";
				break;
			case '0':
				result = result + "0000";	
				break;
			case '1':
				result = result + "0001";	
				break;
			case '2':
				result = result + "0010";	
				break;
			case '3':
				result = result + "0011";	
				break;
			case '4':
				result = result + "0100";	
				break;
			case '5':
				result = result + "0101";	
				break;
			case '6':
				result = result + "0110";	
				break;
			case '7':
				result = result + "0111";	
				break;
			case '8':
				result = result + "1000";	
				break;
			case '9':
				result = result + "1001";	
				break;
		}
	}
	return result;
}

string SHA256(char minerInput[]){
	populateShiftValues();
	computeConstants();
	string result;
	for(int i=0; i<2; i++){ //Loops twice to compute SHA256 twice for correct block hash
		computeInitialHashValues(); //Needs to be recalculated every hash
		//Convert input to binary
		string message = hexToBinary(minerInput, 160);
		
		//Pad message to 1024 (512*2) characters or 512 characters
		int padStart;
		int padEnd;
		if(i==0){
			padStart = 640;
			padEnd = 1024;
		}
		if(i==1){
			padStart = 256;
			padEnd = 512;
		}
		for(int j=padStart; j<padEnd; j++){
			message = message + '0';
		}

		//Add padding separator and define message length
		if(i==0){
			message[640] = '1'; //Separator
			//Message length
			message[1016] = '1';
			message[1014] = '1';
		}
		if(i==1){
			message[256] = '1'; //Separator
			message[503] = '1'; //Message length
		}

		//Splitting message into 512 bit message blocks and convert from string to int
		int blockCount;
		if(i==0){
			blockCount = 2;
		}
		if(i==1){
			blockCount = 1;
		}
		
		//Loop for every block
		for(int j=0; j<blockCount; j++){
			int temp[32];
			int temp1[32];
			int equationNumber;
			//Initialize message schedule
			int wordCount = 0;
			for(int k=(512*j); k<512+(j*512); k++){ //Blocks are 512 bits long, fills schedule with 16, 32 bit words
				for(int m=0; m<32; m++){
					if(message[k+m] == '1'){
						schedule[j][wordCount].word[m] = 1;
					}
					else{
						schedule[j][wordCount].word[m] = 0;
					}
				}
				wordCount++;
				k=k+31;
			}
			//Fill out rest of message schedule (i<64)
			for(int k=16; k<64; k++){
				for(int m=0; m<32; m++){
					binaryAddition[1].Data[m] = schedule[j][k-7].word[m];
					binaryAddition[3].Data[m] = schedule[j][k-16].word[m];
				}
				int wordNumber = k-2;
				equationNumber = 1;
				equationCompute(equationNumber, wordNumber, j);
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = Data[3].result[m];
				}
				wordNumber = k-15;
				equationNumber = 0;
				equationCompute(equationNumber, wordNumber, j);
				for(int m=0; m<32; m++){
					binaryAddition[2].Data[m] = Data[3].result[m];
				}
				binaryAdditionFunction(1);
				for(int m=0; m<32; m++){
					schedule[j][k].word[m] = binaryAddition[6].Data[m];
				}	
			}

			for(int k=0; k<64; k++){
				//Create temporary words for compression
				equationNumber = 3;
				equationCompute(equationNumber, 0, j);
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = Data[3].result[m];
					binaryAddition[2].Data[m] = HashValues[7].WorkingValues[m];
					if(ConstantValues[k].WorkingValues[m] == '1'){
						binaryAddition[3].Data[m] = 1;
					}
					if(ConstantValues[k].WorkingValues[m] == '0'){
						binaryAddition[3].Data[m] = 0;
					}
					binaryAddition[4].Data[m] = schedule[j][k].word[m];
				}
				choice();
				binaryAdditionFunction(0);

				for(int m=0; m<32; m++){
					temp[m] = binaryAddition[8].Data[m];
				}

				//Clear binaryAddition class
				for(int m=0; m<9; m++){
					for(int n=0; n<32; n++){
						binaryAddition[m].Data[n] = 0;
					}
				}
				equationNumber = 2;
				equationCompute(equationNumber, 0, j);
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = Data[3].result[m];
				}
				majority();
				binaryAdditionFunction(3);
				for(int m=0; m<32; m++){
					temp1[m] = binaryAddition[2].Data[m];
				}

				//Compression
				//Move Hash Values down 1
				for(int m=7; m>0; m--){
					for(int n=0; n<32; n++){
						HashValues[m].WorkingValues[n] = HashValues[m-1].WorkingValues[n];
					}
				}
				//Binary Add temp and temp1 
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = temp[m];
					binaryAddition[1].Data[m] = temp1[m];
				}
				binaryAdditionFunction(3);
				
				//Make Binary Addition result the first hash value
				for(int m=0; m<32; m++){
					HashValues[0].WorkingValues[m] = binaryAddition[2].Data[m];
				}
				//Binary Add temp to HashValues[4]
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = temp[m];
					binaryAddition[1].Data[m] = HashValues[4].WorkingValues[m];
				}
				binaryAdditionFunction(3);
				for(int m=0; m<32; m++){
					HashValues[4].WorkingValues[m] = binaryAddition[2].Data[m];
				}
			}
			//Add Working Hash Values to Original Hash Values
			for(int k=0; k<8; k++){
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = HashValues[k].OriginalValues[m];
					binaryAddition[1].Data[m] = HashValues[k].WorkingValues[m];
				}
				binaryAdditionFunction(3);
				for(int m=0; m<32; m++){
					HashValues[k].OriginalValues[m] = binaryAddition[2].Data[m];
					HashValues[k].WorkingValues[m] = binaryAddition[2].Data[m];
				}
			}
		}
		
		//Convert output from binary to hex
		string output[64];
		int Word = 0;
		int Value = 0;
		//Combine WorkingValues together and split into 64 chunks, 4-bit string
		for(int j=0; j<64; j++){
			for(int k=0; k<4; k++){
				if(HashValues[Word].WorkingValues[Value] == 1){
					output[j] = output[j] + '1';
				}
				else{
					output[j] = output[j] + '0';
				}
			if(Value == 31){
				Value = 0;
				Word++;
			}		
			else{
				Value++;
			}
			}
		}
		
		//Copy output hash to input to be recomputed
		if(i==0){
			string temp;
			temp = binaryToHex(output);
			for(int j=0; j<64; j++){
				minerInput[j] = temp[j];
			}
			for(int j=64; j<160; j++){
				minerInput[j] = '\0';
			}
		}
		
		//Displays final output
		if(i==1){
			string temp;
			string temp1;
			temp = binaryToHex(output);
			//Convert little endian to hex
			//For every two characters, swap them
			//Then reverse the whole string
			for(int j=32; j>0; j--){
				for(int k=2; k>0; k--){
					temp1 = temp1 + temp[((j*2)-k)];
				}
			}
			result = temp1;
		}
	}
	return(result);
}
//4 Types of equations that needs to be computed
//Equations 0 and 1 needs two right shifts and a normal shift
//Eauations 2 and 3 needs three right shifts
void equationCompute(int equationNumber, int wordNumber, int blockNumber){
	int Order;
	int RightShiftValue = 0;
	int ShiftValue = 0;
	for(int i=0; i<2; i++){
		RightShiftValue = Shift[equationNumber].Value[i];
		Order = i;
		rightShift(RightShiftValue, Order, equationNumber, wordNumber, blockNumber);
	}
	Order = 2;
	if(equationNumber == 0 | equationNumber == 1){

		ShiftValue = Shift[equationNumber].Value[2];
		shift(ShiftValue, Order, wordNumber, blockNumber);
	}
	
	else{
		for(int i=0; i<3; i++){
			RightShiftValue = Shift[equationNumber].Value[i];
			rightShift(RightShiftValue, Order, equationNumber, wordNumber, blockNumber);
		}
	}
	xortest();
}

void rightShift(int RightShiftValue, int Order, int equationNumber, int wordNumber, int blockNumber){
	//Right Shift based on RightShiftValue
	for(int i=0; i<32; i++){
		if((i+RightShiftValue)<32){
			if (equationNumber == 0 | equationNumber == 1){
				Data[Order].result[i+RightShiftValue]=schedule[blockNumber][wordNumber].word[i];
			}
			if (equationNumber == 2){
				Data[Order].result[i+RightShiftValue]=HashValues[0].WorkingValues[i];
			}
			if (equationNumber == 3){
				Data[Order].result[i+RightShiftValue]=HashValues[4].WorkingValues[i];
			}
		}
		else{
			if (equationNumber == 0 | equationNumber == 1){
				Data[Order].result[i-(32-RightShiftValue)]=schedule[blockNumber][wordNumber].word[i];
			}
			if (equationNumber == 2){
				Data[Order].result[i-(32-RightShiftValue)]=HashValues[0].WorkingValues[i];
			}
			if (equationNumber == 3){
				Data[Order].result[i-(32-RightShiftValue)]=HashValues[4].WorkingValues[i];
			}
		}
	}
}
void shift(int ShiftValue, int Order, int wordNumber, int blockNumber){
	//Shift based on ShiftValue
	for(int i=0; i<ShiftValue+1; i++){
		Data[Order].result[i] = 0;
	}
	for(int i=ShiftValue; i<32; i++){
		Data[Order].result[i] = schedule[blockNumber][wordNumber].word[i-ShiftValue];
	}	
}
void xortest(){
	for(int i=0; i<32; i++){
		int add = 0;
		if(Data[0].result[i] == 1){
			add = add + 1;
		}
		if(Data[1].result[i] == 1){
			add = add + 1;
		}
		if(Data[2].result[i] == 1){
			add = add + 1;	
		}
		if(add == 1 | add == 3){
			Data[3].result[i] = 1;
		}
		else{
			Data[3].result[i] = 0;
		}
	}
}

void binaryAdditionFunction(int equationsCount){
	for(int i=0; i<4 - equationsCount; i++){
		int carry = 0;
		for(int j=0; j<32; j++){
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 0){
				binaryAddition[5 + i - equationsCount].Data[31-j] = 0;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 1){
				binaryAddition[5 + i - equationsCount].Data[31-j] = 1;
				carry = 0;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 3){
				binaryAddition[5 + i - equationsCount].Data[31-j] = 1;
				carry = 1;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 2){
				binaryAddition[5 + i - equationsCount].Data[31-j] = 0;
				carry = 1;
			}
		}
	}
}

void majority(){
	for(int i=0; i<32; i++){
		int add = HashValues[0].WorkingValues[i] + HashValues[1].WorkingValues[i] + HashValues[2].WorkingValues[i];
		if(add == 2 | add == 3){
			binaryAddition[1].Data[i] = 1;
		}
		else{
			binaryAddition[1].Data[i] = 0;
		}
	}
}
void choice(){
	for(int i=0; i<32; i++){
		if(HashValues[4].WorkingValues[i] == 1){
			binaryAddition[1].Data[i] = HashValues[5].WorkingValues[i];
		}
		if(HashValues[4].WorkingValues[i] == 0){
			binaryAddition[1].Data[i] = HashValues[6].WorkingValues[i]; 
		}
	}
}