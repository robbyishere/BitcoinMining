//TODO:
//Make equationCompute() function more modular (be able to send 32 bits for modification) 
//Compress msg schedule
//Compute all 3 message blocks
//Compute final hash
#include "SHA256.h"

struct messageBlocks{
	int block[512];
} msg[3];

struct messageSchedule{
	int word[32];
} schedule[64];

struct equationData{
	int result[32];
} Data[4];

struct equationShiftValues{
	int Value[3];
} Shift[4];
struct ConstantValues{
	double Original[64];
	string Computed[64];
}ConstantValues;
struct HashValues{
	double InitialValues;
	int WorkingValues[32];
}HashValues[8];
struct binaryAddition{
	int Data[32];
}binaryAddition[7];

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
	ConstantValues.Original[0] = cbrt(2);
	ConstantValues.Original[1] = cbrt(3);
	ConstantValues.Original[2] = cbrt(5);
	ConstantValues.Original[3] = cbrt(7);
	ConstantValues.Original[4] = cbrt(11); 
	ConstantValues.Original[5] = cbrt(13);
	ConstantValues.Original[6] = cbrt(17);
	ConstantValues.Original[7] = cbrt(19);
	ConstantValues.Original[8] = cbrt(23);
	ConstantValues.Original[9] = cbrt(29);
	ConstantValues.Original[10] = cbrt(31);
	ConstantValues.Original[11] = cbrt(37);
	ConstantValues.Original[12] = cbrt(41);
	ConstantValues.Original[13] = cbrt(43);
	ConstantValues.Original[14] = cbrt(47);
	ConstantValues.Original[15] = cbrt(53);
	ConstantValues.Original[16] = cbrt(59);
	ConstantValues.Original[17] = cbrt(61);
	ConstantValues.Original[18] = cbrt(67);
	ConstantValues.Original[19] = cbrt(71);
	ConstantValues.Original[20] = cbrt(73);
	ConstantValues.Original[21] = cbrt(79);
	ConstantValues.Original[22] = cbrt(83);
	ConstantValues.Original[23] = cbrt(89);
	ConstantValues.Original[24] = cbrt(97);
	ConstantValues.Original[25] = cbrt(101);
	ConstantValues.Original[26] = cbrt(103);
	ConstantValues.Original[27] = cbrt(107);
	ConstantValues.Original[28] = cbrt(109);
	ConstantValues.Original[29] = cbrt(113);
	ConstantValues.Original[30] = cbrt(127);
	ConstantValues.Original[31] = cbrt(131);
	ConstantValues.Original[32] = cbrt(137);
	ConstantValues.Original[33] = cbrt(139);
	ConstantValues.Original[34] = cbrt(149);
	ConstantValues.Original[35] = cbrt(151);
	ConstantValues.Original[36] = cbrt(157);
	ConstantValues.Original[37] = cbrt(163);
	ConstantValues.Original[38] = cbrt(167);
	ConstantValues.Original[39] = cbrt(173);
	ConstantValues.Original[40] = cbrt(179);
	ConstantValues.Original[41] = cbrt(181);
	ConstantValues.Original[42] = cbrt(191);
	ConstantValues.Original[43] = cbrt(193);
	ConstantValues.Original[44] = cbrt(197);
	ConstantValues.Original[45] = cbrt(199);
	ConstantValues.Original[46] = cbrt(211);
	ConstantValues.Original[47] = cbrt(223);
	ConstantValues.Original[48] = cbrt(227);
	ConstantValues.Original[49] = cbrt(229);
	ConstantValues.Original[50] = cbrt(233);
	ConstantValues.Original[51] = cbrt(239);
	ConstantValues.Original[52] = cbrt(241);
	ConstantValues.Original[53] = cbrt(251);
	ConstantValues.Original[54] = cbrt(257);
	ConstantValues.Original[55] = cbrt(263);
	ConstantValues.Original[56] = cbrt(269);
	ConstantValues.Original[57] = cbrt(271);
	ConstantValues.Original[58] = cbrt(277);
	ConstantValues.Original[59] = cbrt(281);
	ConstantValues.Original[60] = cbrt(283);
	ConstantValues.Original[61] = cbrt(293);
	ConstantValues.Original[62] = cbrt(307);
	ConstantValues.Original[63] = cbrt(311);
	cout<<"Constant Values:"<<endl;
	for(int i=0; i<64; i++){
		int ConstantInteger = ConstantValues.Original[i];
		double hex = (ConstantValues.Original[i] - ConstantInteger); //remove starting integer 
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
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0000";
					break;
				case 1:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0001";
					break;
				case 2:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0010";
					break;
				case 3:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0011";
					break;
				case 4:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0100";
					break;
				case 5:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0101";
					break;
				case 6:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0110";
					break;
				case 7:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "0111";
					break;
				case 8:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1000";
					break;
				case 9:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1001";
					break;
				case 10:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1010";
					break;
				case 11:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1011";
					break;
				case 12:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1100";
					break;
				case 13:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1101";
					break;
				case 14:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1110";
					break;
				case 15:
					ConstantValues.Computed[i] = ConstantValues.Computed[i] + "1111";
					break;
			}

		}
		cout<<ConstantValues.Computed[i]<<" ";
		cout<<endl;
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
	cout<<"Initial Hash Values:"<<endl;
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
		//reverse and convert to string
		for(int j=0; j<32; j++){
			if(binary[31-j] == 1){
				HashValues[i].WorkingValues[j] = 1;
			}
			else{
				HashValues[i].WorkingValues[j] = 0;
			}
		}
		
		for(int j=0; j<32; j++){
			cout<<HashValues[i].WorkingValues[j];	
		}
		cout<<endl;
		}

	}
string hexToBinary(char input[], int characterCount){
	string result;
	for(int i=0; i<characterCount; i++){
		switch(input[i]){ 
			case 'a':
				result = result + "01100001";
				break;
			case 'b':
				result = result + "01100010";
				break;
			case 'c':
				result = result + "01100011";
				break;
			case 'd':
				result = result + "01100100";
				break;
			case 'e':
				result = result + "01100101";
				break;
			case 'f':
				result = result + "01100110";
				break;
			case '0':
				result = result + "00000000";	
				break;
			case '1':
				result = result + "00000001";	
				break;
			case '2':
				result = result + "00000010";	
				break;
			case '3':
				result = result + "00000011";	
				break;
			case '4':
				result = result + "00000100";	
				break;
			case '5':
				result = result + "00000101";	
				break;
			case '6':
				result = result + "00000110";	
				break;
			case '7':
				result = result + "00000111";	
				break;
			case '8':
				result = result + "00001000";	
				break;
			case '9':
				result = result + "00001001";	
				break;
		}
	}
	return result;
}

int main(){
	char input[161];
	cout<<"Enter the input: ";
	cin.getline(input,161);
	cout<<"Character Count: "<<cin.gcount()<<endl;
	int characterCount = cin.gcount();
	string binary = hexToBinary(input, characterCount);

	//print input for sanity check
	for(int i=0; i<cin.gcount()-1; i++){
		cout<<i<<" "<<input[i]<<endl;
	}
	
	//pad to 1536 (512*3) characters 
	for(int i=1280; i<1536; i++){
		binary = binary + '0';
	}


	binary[1280] = '1'; //add padding separator
	//define message length of 1280
	binary[1525] = '1';
	binary[1527] = '1';

	//print binary conversion for sanity check
	cout<<endl<<"Message:"<<endl<<binary<<endl;

	//Splitting message into 512 bit message blocks and convert from string to int
	for(int i=0; i<3; i++){
		for(int j=0+(512*i); j<512*(i+1); j++){
			if(binary[j] == '1'){
				msg[i].block[j-512*i] = 1;
			}
			else{
				msg[i].block[j-512*i] = 0;
			}
		}
	}
	//print msgBLKs for sanity check
	for(int i=0; i<3; i++){
		cout<<endl<<"msgBLK"<<i<<":"<<endl;
		for(int j=0; j<512; j++){
			cout<<msg[i].block[j];
		}
	}
	
	cout<<endl;

	//initialize message schedule
	//Split block into 32 bit "words"
	for(int i=0; i<16; i++){
		for(int j=0+(32*i); j<32*(i+1); j++){
			schedule[i].word[j-32*i] = msg[0].block[j];
		}
	}
	
	//Print out words for sanity check
	cout<<endl<<endl<<"msgBLK0: ";
	for(int i=0; i<16; i++){
		cout<<endl<<"Word "<<i<<": ";
		for(int j=0; j<32; j++){
				cout<<schedule[i].word[j];
		}
	}
	
	cout<<endl;

//CHECK FROM HERE DOWN
	populateShiftValues();
	computeConstants();
	computeInitialHashValues();
	cout<<endl;

	//Fill out rest of message schedule (i<64)
	for(int i=16; i<17; i++){
		for(int j=0; j<32; j++){
			binaryAddition[1].Data[j] = schedule[i-7].word[j];
			binaryAddition[3].Data[j] = schedule[i-16].word[j];
			binaryAddition[4].Data[j] = 0;
		}
		int wordNumber = i-2;
		int equationNumber = 1;
		equationCompute(equationNumber, wordNumber);
		for(int j=0; j<32; j++){
			binaryAddition[0].Data[j] = Data[3].result[j];
		}
		wordNumber = i-15;
		equationNumber = 0;
		equationCompute(equationNumber, wordNumber);
		for(int j=0; j<32; j++){
			binaryAddition[2].Data[j] = Data[3].result[j];
		}
		//Print for sanity check
		cout<<"One:    ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[0].Data[j];
		}
		cout<<endl<<"Two:    ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[1].Data[j];
		}
		cout<<endl<<"Three:  ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[2].Data[j];
		}
		cout<<endl<<"Four:   ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[3].Data[j];
		}
		
		//Binary Addition
		for(int j=0; j<3; j++){
			int inc = j;
			binaryAdditionFunction(inc);
		}
		for(int j=0; j<32; j++){
			schedule[i].word[j] = binaryAddition[6].Data[j];
		}

		//Print for sanity check
		cout<<endl<<"Add1:   ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[4].Data[j];
		}
		cout<<endl<<"Add2:   ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[5].Data[j];
		}
		cout<<endl<<"Result: ";
		for(int j=0; j<32; j++){
			cout<<schedule[i].word[j];
		}

	}
	cout<<endl;
/*
	for(int i=0; i<64; i++){
		cout<<i<<": ";
		for(int j=0; j<32; j++){
			cout<<schedule[i].word[j];
		}
		cout<<endl;
	}
*/
}
void equationCompute(int equationNumber, int wordNumber){
	int Order;
	int RightShiftValue = 0;
	int ShiftValue = 0;
	for(int i=0; i<2; i++){
		RightShiftValue = Shift[equationNumber].Value[i];
		Order = i;
		rightShift(RightShiftValue, Order, wordNumber, equationNumber);
	}
	Order = 2;
	if(equationNumber == 0 | equationNumber == 1){

		ShiftValue = Shift[equationNumber].Value[2];
		shift(ShiftValue, Order, wordNumber);
	}
	
	else{
		for(int i=0; i<3; i++){
			RightShiftValue = Shift[equationNumber].Value[i];
			rightShift(RightShiftValue, Order, wordNumber, equationNumber);
		}
	}
	xortest();

	for(int i=0; i<4; i++){
		cout<<endl<<i<<": ";
		for(int j=0; j<32; j++){
			cout<<Data[i].result[j];
		}
		cout<<endl;
	}

}

void rightShift(int RightShiftValue, int Order, int wordNumber, int equationNumber){
	//Right Shift based on RightShiftValue
	for(int i=0; i<32; i++){
		if((i+RightShiftValue)<32){
			if (equationNumber == 0 | equationNumber == 1){
				Data[Order].result[i+RightShiftValue]=schedule[wordNumber].word[i];
			}
			else{
				Data[Order].result[i+RightShiftValue]=HashValues[4].WorkingValues[i];
			}
		}
		else{
			if (equationNumber == 0 | equationNumber == 1){
				Data[Order].result[i-(32-RightShiftValue)]=schedule[wordNumber].word[i];
			}
			else{
				Data[Order].result[i-(32-RightShiftValue)]=HashValues[4].WorkingValues[i];
			}
		}
	}

}
void shift(int ShiftValue, int Order, int wordNumber){
	//Shift based on ShiftValue
	for(int i=0; i<ShiftValue+1; i++){
		Data[Order].result[i] = 0;
	}
	for(int i=ShiftValue; i<32; i++){
		Data[Order].result[i] = schedule[wordNumber].word[i-ShiftValue];
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
void binaryAdditionFunction(int inc){
	int carry = 0;
		for(int i=0; i<32; i++){
			if(binaryAddition[0 + (inc*2)].Data[31-i] + binaryAddition[1 + (inc*2)].Data[31-i] + carry == 0){
				binaryAddition[4 + inc].Data[31-i] = 0;
			}
			if(binaryAddition[0 + (inc*2)].Data[31-i] + binaryAddition[1 + (inc*2)].Data[31-i] + carry == 1){
				binaryAddition[4 + inc].Data[31-i] = 1;
				carry = 0;
			}
			if(binaryAddition[0 + (inc*2)].Data[31-i] + binaryAddition[1 + (inc*2)].Data[31-i] + carry == 3){
				binaryAddition[4 + inc].Data[31-i] = 1;
				carry = 1;
			}
			if(binaryAddition[0 + (inc*2)].Data[31-i] + binaryAddition[1 + (inc*2)].Data[31-i] + carry == 2){
				binaryAddition[4 + inc].Data[31-i] = 0;
				carry = 1;
			}
	}
}
