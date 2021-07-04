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
	cout<<"Constant Values:"<<endl;
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
		//Print
		cout<<ConstantValues[i].WorkingValues[j];
	}
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
		
		binaryAdditionFunction();

		for(int j=0; j<32; j++){
			schedule[i].word[j] = binaryAddition[8].Data[j];
		}

		//Print for sanity check
		cout<<endl<<"Add1:   ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[5].Data[j];
		}
		cout<<endl<<"Add2:   ";
		for(int j=0; j<32; j++){
			cout<<binaryAddition[6].Data[j];
		}
		cout<<endl<<"Result: ";
		for(int j=0; j<32; j++){
			cout<<schedule[i].word[j];
		}
	cout<<endl<<endl;
	}

	/*
	//Print words after modification
	for(int i=0; i<64; i++){
		cout<<i<<": ";
		for(int j=0; j<32; j++){
			cout<<schedule[i].word[j];
		}
		cout<<endl;
	}
	*/
	
	//Create temporary words for compression
	int temp[32];
	int temp1[32];
	
	int equationNumber = 3;
	equationCompute(equationNumber, 0);
	for(int i=0; i<32; i++){ //Change to j when looping
		binaryAddition[0].Data[i] = Data[3].result[i];
		binaryAddition[2].Data[i] = HashValues[7].WorkingValues[i];
		binaryAddition[3].Data[i] = ConstantValues[0].WorkingValues[i];
		binaryAddition[4].Data[i] = schedule[0].word[i];
	}
	choice();
	binaryAdditionFunction();

	cout<<"One:    ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[0].Data[i];
	}
	cout<<endl<<"Two:    ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[1].Data[i];
	}
	cout<<endl<<"Three:  ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[2].Data[i];
	}
	cout<<endl<<"Four:   ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[3].Data[i];
	}
	cout<<endl<<"Five:   ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[4].Data[i];
	}
	cout<<endl<<"Add1:   ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[5].Data[i];
	}
	cout<<endl<<"Add2:   ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[6].Data[i];
	}
	cout<<endl<<"Add3:   ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[7].Data[i];
	}
	cout<<endl<<"Result: ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[8].Data[i];
	}
	for(int i=0; i<32; i++){
		temp[i] = binaryAddition[8].Data[i];
	}
	cout<<endl;
	
	//Clear binaryAddition class
	for(int i=0; i<9; i++){
		for(int j=0; j<32; j++){
			binaryAddition[i].Data[j] = 0;
		}
	}
	equationNumber = 2;
	equationCompute(equationNumber, 0);
	for(int i=0; i<32; i++){
		binaryAddition[0].Data[i] = Data[3].result[i];
	}
	majority();
	binaryAdditionFunction();
	cout<<"One:    ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[0].Data[i];
	}
	cout<<endl<<"Two:    ";
	for(int i=0; i<32; i++){
		cout<<binaryAddition[1].Data[i];
	}
	cout<<endl<<"Result: ";
	for(int i=0; i<32; i++){
		temp1[i] = binaryAddition[8].Data[i];
		cout<<temp1[i];
	}
	cout<<endl;
	
	//Compression
	//Move Hash Values down 1
	for(int i=7; i>0; i--){
		for(int j=0; j<32; j++){
			HashValues[i].WorkingValues[j] = HashValues[i-1].WorkingValues[j];
		}
	}
	//Binary Add temp and temp1 
	for(int i=0; i<32; i++){
		binaryAddition[0].Data[i] = temp[i];
		binaryAddition[1].Data[i] = temp1[i];
	}
	binaryAdditionFunction();
	
	//Make Binary Addition result the first hash value
	for(int i=0; i<32; i++){
		HashValues[0].WorkingValues[i] = binaryAddition[8].Data[i];
	}
	
	//Print for sanity pls
	cout<<"Working Hash Values"<<endl;
	for(int i=0; i<8; i++){
		for(int j=0; j<32; j++){
			cout<<HashValues[i].WorkingValues[j];
		}
		cout<<endl;
	}
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
			if (equationNumber == 2){
				Data[Order].result[i+RightShiftValue]=HashValues[0].WorkingValues[i];
			}
			if (equationNumber == 3){
				Data[Order].result[i+RightShiftValue]=HashValues[4].WorkingValues[i];
			}
		}
		else{
			if (equationNumber == 0 | equationNumber == 1){
				Data[Order].result[i-(32-RightShiftValue)]=schedule[wordNumber].word[i];
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

//Try to find a way to improve this
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