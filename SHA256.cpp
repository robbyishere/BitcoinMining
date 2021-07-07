//TODO:
//Make ConstantValues and HashValues shortcut
//Cut down struct array values?
//Improve binaryAdditionFunction

#include "SHA256.h"

struct messageBlocks{
	int block[512];
} msg[2];

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
	double Original;
	string Computed;
	int WorkingValues[32];
}ConstantValues[64];
struct HashValues{
	double InitialValues;
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
	ConstantValues[0].Original = cbrt(2);
	ConstantValues[1].Original = cbrt(3);
	ConstantValues[2].Original = cbrt(5);
	ConstantValues[3].Original = cbrt(7);
	ConstantValues[4].Original = cbrt(11); 
	ConstantValues[5].Original = cbrt(13);
	ConstantValues[6].Original = cbrt(17);
	ConstantValues[7].Original = cbrt(19);
	ConstantValues[8].Original = cbrt(23);
	ConstantValues[9].Original = cbrt(29);
	ConstantValues[10].Original = cbrt(31);
	ConstantValues[11].Original = cbrt(37);
	ConstantValues[12].Original = cbrt(41);
	ConstantValues[13].Original = cbrt(43);
	ConstantValues[14].Original = cbrt(47);
	ConstantValues[15].Original = cbrt(53);
	ConstantValues[16].Original = cbrt(59);
	ConstantValues[17].Original = cbrt(61);
	ConstantValues[18].Original = cbrt(67);
	ConstantValues[19].Original = cbrt(71);
	ConstantValues[20].Original = cbrt(73);
	ConstantValues[21].Original = cbrt(79);
	ConstantValues[22].Original = cbrt(83);
	ConstantValues[23].Original = cbrt(89);
	ConstantValues[24].Original = cbrt(97);
	ConstantValues[25].Original = cbrt(101);
	ConstantValues[26].Original = cbrt(103);
	ConstantValues[27].Original = cbrt(107);
	ConstantValues[28].Original = cbrt(109);
	ConstantValues[29].Original = cbrt(113);
	ConstantValues[30].Original = cbrt(127);
	ConstantValues[31].Original = cbrt(131);
	ConstantValues[32].Original = cbrt(137);
	ConstantValues[33].Original = cbrt(139);
	ConstantValues[34].Original = cbrt(149);
	ConstantValues[35].Original = cbrt(151);
	ConstantValues[36].Original = cbrt(157);
	ConstantValues[37].Original = cbrt(163);
	ConstantValues[38].Original = cbrt(167);
	ConstantValues[39].Original = cbrt(173);
	ConstantValues[40].Original = cbrt(179);
	ConstantValues[41].Original = cbrt(181);
	ConstantValues[42].Original = cbrt(191);
	ConstantValues[43].Original = cbrt(193);
	ConstantValues[44].Original = cbrt(197);
	ConstantValues[45].Original = cbrt(199);
	ConstantValues[46].Original = cbrt(211);
	ConstantValues[47].Original = cbrt(223);
	ConstantValues[48].Original = cbrt(227);
	ConstantValues[49].Original = cbrt(229);
	ConstantValues[50].Original = cbrt(233);
	ConstantValues[51].Original = cbrt(239);
	ConstantValues[52].Original = cbrt(241);
	ConstantValues[53].Original = cbrt(251);
	ConstantValues[54].Original = cbrt(257);
	ConstantValues[55].Original = cbrt(263);
	ConstantValues[56].Original = cbrt(269);
	ConstantValues[57].Original = cbrt(271);
	ConstantValues[58].Original = cbrt(277);
	ConstantValues[59].Original = cbrt(281);
	ConstantValues[60].Original = cbrt(283);
	ConstantValues[61].Original = cbrt(293);
	ConstantValues[62].Original = cbrt(307);
	ConstantValues[63].Original = cbrt(311);
	for(int i=0; i<64; i++){
		int ConstantInteger = ConstantValues[i].Original;
		double hex = (ConstantValues[i].Original - ConstantInteger); //remove starting integer 
		cout.precision(16);
		int HexStore[8];
		char input[8];
		//convert to hex
		for(int j=0; j<8; j++){
			hex = hex*16;
			HexStore[j] = hex;
			hex = hex - HexStore[j];
			//convert to binary
			switch(HexStore[j]){
				case 0:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0000";
					break;
				case 1:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0001";
					break;
				case 2:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0010";
					break;
				case 3:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0011";
					break;
				case 4:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0100";
					break;
				case 5:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0101";
					break;
				case 6:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0110";
					break;
				case 7:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "0111";
					break;
				case 8:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1000";
					break;
				case 9:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1001";
					break;
				case 10:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1010";
					break;
				case 11:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1011";
					break;
				case 12:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1100";
					break;
				case 13:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1101";
					break;
				case 14:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1110";
					break;
				case 15:
					ConstantValues[i].Computed = ConstantValues[i].Computed + "1111";
					break;
			}
		}
	//Convert string to int array
	for(int j=0; j<32; j++){
		if (ConstantValues[i].Computed[j] == '1'){
			ConstantValues[i].WorkingValues[j] = 1;
		}
		else{
			ConstantValues[i].WorkingValues[j] = 0;
		}
	}
	}
}
void computeInitialHashValues(){
	HashValues[0].InitialValues = sqrt(2);
	HashValues[1].InitialValues = sqrt(3);
	HashValues[2].InitialValues = sqrt(5);
	HashValues[3].InitialValues = sqrt(7);
	HashValues[4].InitialValues = sqrt(11);
	HashValues[5].InitialValues = sqrt(13);
	HashValues[6].InitialValues = sqrt(17);
	HashValues[7].InitialValues = sqrt(19);
	int InitialInteger;
	for(int i=0; i<8; i++){
		InitialInteger = HashValues[i].InitialValues;
		int binary[32];
		//remove starting integer and multiply by 2^32
		double binaryConvert = trunc(((HashValues[i].InitialValues - InitialInteger) * pow(2,32)));
		int loop = 0;
		//convert to binary
		while(binaryConvert>0){
			if(fmod(binaryConvert,2) >= 1){ //Divide by 2 and see if there is a remainder. If yes, bit is 1
				binary[loop] = 1;
			}
			else{
				binary[loop] = 0;
			}
			binaryConvert = trunc(binaryConvert); //remove decimal if there is one
			binaryConvert = binaryConvert/2; //prepare for calculating next bit
			loop++;
		}
		//pad to 32 bits
		for(int j=loop; j<32; j++){
			binary[j] = 0;
		}
		//reverse and convert to int array
		for(int j=0; j<32; j++){
			if(binary[31-j] == 1){
				HashValues[i].WorkingValues[j] = 1;
			}
			else{
				HashValues[i].WorkingValues[j] = 0;
			}
		}
		
		for(int j=0; j<32; j++){
			HashValues[i].OriginalValues[j] = HashValues[i].WorkingValues[j]; //duplicate values
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

int main(){
	char input[161];
	cout<<"Enter the block header: ";
	cin.getline(input,161);
	
	for(int i=0; i<2; i++){
	
		int characterCount = cin.gcount(); //Make sure on second loop, character count is correct
		string binary = hexToBinary(input, characterCount);
		
		//pad to 1024 (512*2) characters or 512 characters 
		int pad;
		int maxLength;
		if(i==0){
			pad = 640;
			maxLength = 1024;
		}
		if(i==1){
			pad = 256;
			maxLength = 512;
		}
		for(int j=pad; j<maxLength; j++){
			binary = binary + '0';
		}

		//add padding separator and define message length
		if(i==0){
			binary[640] = '1'; //separator
			//message length
			binary[1016] = '1';
			binary[1014] = '1';
		}
		if(i==1){
			binary[256] = '1'; //separator
			binary[503] = '1'; //message length
		}

		//Splitting message into 512 bit message blocks and convert from string to int
		int blockCount;
		if(i==0){
			blockCount = 2;
		}
		if(i==1){
			blockCount = 1;
		}
		for(int j=0; j<blockCount; j++){
			for(int k=0+(512*j); k<512*(j+1); k++){
				if(binary[k] == '1'){
					msg[j].block[k-512*j] = 1;
				}
				else{
					msg[j].block[k-512*j] = 0;
				}
			}
		}
		populateShiftValues();
		computeConstants();
		computeInitialHashValues();
		//Loop for every block (i<2)
		for(int j=0; j<blockCount; j++){
			int temp[32];
			int temp1[32];
			int equationNumber;
			//initialize message schedule
			//Split block into 32 bit "words"
			for(int k=0; k<16; k++){
				for(int m=0+(32*k); m<32*(k+1); m++){
					schedule[j][k].word[m-32*k] = msg[j].block[m];
				}
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
				binaryAdditionFunction();
				for(int m=0; m<32; m++){
					schedule[j][k].word[m] = binaryAddition[8].Data[m];
				}			
			}

			for(int k=0; k<64; k++){
				//Create temporary words for compression
				equationNumber = 3;
				equationCompute(equationNumber, 0, j);
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = Data[3].result[m];
					binaryAddition[2].Data[m] = HashValues[7].WorkingValues[m];
					binaryAddition[3].Data[m] = ConstantValues[k].WorkingValues[m];
					binaryAddition[4].Data[m] = schedule[j][k].word[m];
				}
				choice();
				binaryAdditionFunction();

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
				binaryAdditionFunction();

				for(int m=0; m<32; m++){
					temp1[m] = binaryAddition[8].Data[m];
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
				binaryAdditionFunction();
				
				//Make Binary Addition result the first hash value
				for(int m=0; m<32; m++){
					HashValues[0].WorkingValues[m] = binaryAddition[8].Data[m];
				}
				//Binary Add temp to HashValues[4]
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = temp[m];
					binaryAddition[1].Data[m] = HashValues[4].WorkingValues[m];
				}
				binaryAdditionFunction();
				for(int m=0; m<32; m++){
					HashValues[4].WorkingValues[m] = binaryAddition[8].Data[m];
				}
			}
			//Add Working Hash Values to Original Hash Values
			for(int k=0; k<8; k++){
				for(int m=0; m<32; m++){
					binaryAddition[0].Data[m] = HashValues[k].OriginalValues[m];
					binaryAddition[1].Data[m] = HashValues[k].WorkingValues[m];
				}
				binaryAdditionFunction();
				for(int m=0; m<32; m++){
					HashValues[k].OriginalValues[m] = binaryAddition[8].Data[m];
					HashValues[k].WorkingValues[m] = binaryAddition[8].Data[m];
				}
			}
		}
		//Convert output from binary to hex
		string output[64];
		int Word = 0;
		int Value = 0;
		//Combine WorkingValues and split into 64 chunks, 4-bit string
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
		
		//Copy output hash to input
		if(i==0){
			string temp;
			temp = binaryToHex(output);
			for(int j=0; j<64; j++){
				input[j] = temp[j];
			}
			for(int j=64; j<162; j++){
				input[j] = '\0';
			}
		}
		//Displays final output
		if(i==1){
			cout<<binaryToHex(output)<<endl;
		}
	}
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

//Try to find a way to improve this so it doesn't run unnecessary loops
//We need to calculate 2,4, and 5 equations
//When calculating 2 equations, it needs to binary add empty arrays to get to binaryAddition[8]
//Maybe subtract 1/2 from `i<4` in the for loop and `binaryAddition[5+i]`? when needed?
/*
0 + 1 stores in 5
2 + 3 stores in 6
4 + 5 stores in 7
6 + 7 stores in 8
*/
void binaryAdditionFunction(){
	for(int i=0; i<4; i++){
		int carry = 0;
		for(int j=0; j<32; j++){
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 0){
				binaryAddition[5 + i].Data[31-j] = 0;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 1){
				binaryAddition[5 + i].Data[31-j] = 1;
				carry = 0;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 3){
				binaryAddition[5 + i].Data[31-j] = 1;
				carry = 1;
			}
			if(binaryAddition[0 + (i*2)].Data[31-j] + binaryAddition[1 + (i*2)].Data[31-j] + carry == 2){
				binaryAddition[5 + i].Data[31-j] = 0;
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