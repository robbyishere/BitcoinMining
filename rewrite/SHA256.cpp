/*TODO
Include <bit> for rotr
Find faster string to integer function?
*/

#include <iostream>
#include <bitset>

struct constantValues{
	std::bitset<32> word;
}constantValue[63];
struct hashValues{
	std::bitset<32> word;
}hashValue[1][7];
struct messageStruct{
	std::bitset<32> word;
}message[31];
struct blockStruct{
	std::bitset<32> word;
}block[1][63];

void populateConstantValues(){
	constantValue[0].word = 0b01000010100010100010111110011000;
	constantValue[1].word = 0b01110001001101110100010010010001;
	constantValue[2].word = 0b10110101110000001111101111001111;
	constantValue[3].word = 0b11101001101101011101101110100101;
	constantValue[4].word = 0b00111001010101101100001001011011; 
	constantValue[5].word = 0b01011001111100010001000111110001;
	constantValue[6].word = 0b10010010001111111000001010100100;
	constantValue[7].word = 0b10101011000111000101111011010101;
	constantValue[8].word = 0b11011000000001111010101010011000;
	constantValue[9].word = 0b00010010100000110101101100000001;
	constantValue[10].word = 0b00100100001100011000010110111110;
	constantValue[11].word = 0b01010101000011000111110111000011;
	constantValue[12].word = 0b01110010101111100101110101110100;
	constantValue[13].word = 0b10000000110111101011000111111110;
	constantValue[14].word = 0b10011011110111000000011010100111;
	constantValue[15].word = 0b11000001100110111111000101110100;
	constantValue[16].word = 0b11100100100110110110100111000001;
	constantValue[17].word = 0b11101111101111100100011110000110;
	constantValue[18].word = 0b00001111110000011001110111000110;
	constantValue[19].word = 0b00100100000011001010000111001100;
	constantValue[20].word = 0b00101101111010010010110001101111;
	constantValue[21].word = 0b01001010011101001000010010101010;
	constantValue[22].word = 0b01011100101100001010100111011100;
	constantValue[23].word = 0b01110110111110011000100011011010;
	constantValue[24].word = 0b10011000001111100101000101010010;
	constantValue[25].word = 0b10101000001100011100011001101101;
	constantValue[26].word = 0b10110000000000110010011111001000;
	constantValue[27].word = 0b10111111010110010111111111000111;
	constantValue[28].word = 0b11000110111000000000101111110011;
	constantValue[29].word = 0b11010101101001111001000101000111;
	constantValue[30].word = 0b00000110110010100110001101010001;
	constantValue[31].word = 0b00010100001010010010100101100111;
	constantValue[32].word = 0b00100111101101110000101010000101;
	constantValue[33].word = 0b00101110000110110010000100111000;
	constantValue[34].word = 0b01001101001011000110110111111100;
	constantValue[35].word = 0b01010011001110000000110100010011;
	constantValue[36].word = 0b01100101000010100111001101010100;
	constantValue[37].word = 0b01110110011010100000101010111011;
	constantValue[38].word = 0b10000001110000101100100100101110;
	constantValue[39].word = 0b10010010011100100010110010000101;
	constantValue[40].word = 0b10100010101111111110100010100001;
	constantValue[41].word = 0b10101000000110100110011001001011;
	constantValue[42].word = 0b11000010010010111000101101110000;
	constantValue[43].word = 0b11000111011011000101000110100011;
	constantValue[44].word = 0b11010001100100101110100000011001;
	constantValue[45].word = 0b11010110100110010000011000100100;
	constantValue[46].word = 0b11110100000011100011010110000101;
	constantValue[47].word = 0b00010000011010101010000001110000;
	constantValue[48].word = 0b00011001101001001100000100010110;
	constantValue[49].word = 0b00011110001101110110110000001000;
	constantValue[50].word = 0b00100111010010000111011101001100;
	constantValue[51].word = 0b00110100101100001011110010110101;
	constantValue[52].word = 0b00111001000111000000110010110011;
	constantValue[53].word = 0b01001110110110001010101001001010;
	constantValue[54].word = 0b01011011100111001100101001001111;
	constantValue[55].word = 0b01101000001011100110111111110011;
	constantValue[56].word = 0b01110100100011111000001011101110;
	constantValue[57].word = 0b01111000101001010110001101101111;
	constantValue[58].word = 0b10000100110010000111100000010100;
	constantValue[59].word = 0b10001100110001110000001000001000;
	constantValue[60].word = 0b10010000101111101111111111111010;
	constantValue[61].word = 0b10100100010100000110110011101011;
	constantValue[62].word = 0b10111110111110011010001111110111;
	constantValue[63].word = 0b11000110011100010111100011110010;
}

void populateHashValues(){
	hashValue[0][0].word = 0b01101010000010011110011001100111;
	hashValue[0][1].word = 0b10111011011001111010111010000101;
	hashValue[0][2].word = 0b00111100011011101111001101110010;
	hashValue[0][3].word = 0b10100101010011111111010100111010;
	hashValue[0][4].word = 0b01010001000011100101001001111111;
	hashValue[0][5].word = 0b10011011000001010110100010001100;
	hashValue[0][6].word = 0b00011111100000111101100110101011;
	hashValue[0][7].word = 0b01011011111000001100110100011001;
	//Duplicate values
	for(int i=0; i<8; i++){
		hashValue[1][i] = hashValue[0][i];
	}
}

void hexToBinary(char input[]){
	std::string result;
	int count=0;
	int wordCount=0;
	for(int i=0; i<161; i++){
		//Split into 32 bit words
		if(count==8){
			message[wordCount].word = stoul(result,nullptr,2); //convert string to unsigned int
			count=0;
			wordCount = wordCount+1;
			result.clear();	
		}
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
		count = count + 1;
	}
}

//Also known as a right rotate
std::bitset<32> rightShift(std::bitset<32> word, int rightShiftValue){
	std::bitset<32> temp;
	for(int i=0; i<32; i++){
		if(rightShiftValue-1-i>-1){
			temp.set(31-i,word[rightShiftValue-1-i]);
		}
		else{
			temp.set(31-i,word[31+(rightShiftValue-i)]);
		}
	}
	return temp;
}

//Applies rightShifts and Shifts to the word depending on the shiftValues and XOR all the results together
std::bitset<32> equationCompute(std::bitset<32> word, int equationType, int shiftValue1, int shiftValue2, int shiftValue3){
	std::bitset <32> XOR[2];
	XOR[0] = rightShift(word, shiftValue1);
	XOR[1] = rightShift(word, shiftValue2);
	if(equationType == 0){
		XOR[2] = word>>shiftValue3;
	}
	if(equationType == 1){
		XOR[2] = rightShift(word, shiftValue3);
	}
	return XOR[0]^=XOR[1]^=XOR[2];
}

std::bitset<32> majority(){ //Put all words on top of each other and analyze each column if it has a majority of '1's or '0's.
	std::bitset<32> temp;
	for(int i=0; i<32; i++){
		int add = hashValue[1][0].word[i] + hashValue[1][1].word[i] + hashValue[1][2].word[i];
		if(add == 2 | add == 3){
			temp.set(i, 1);
		}
		else{
			temp.set(i, 0);
		}
	}
	return temp;
}

std::bitset<32> choice(){ //hashValue[4] determines if the output is the value of hashValue[5] or hashValue[6]
	std::bitset<32> temp;
	for(int i=0; i<32; i++){
		if(hashValue[1][4].word[i] == 1){
			temp.set(i, hashValue[1][5].word[i]);
		}
		if(hashValue[1][4].word[i] == 0){
			temp.set(i, hashValue[1][6].word[i]);
		}
	}
	return temp;
}

int main(){
	populateConstantValues();
	//Initialize header
	char input[169]; //Needs 169 characters to avoid corruption after adding nonce
	std::cout<<"Enter Block Header: ";
	std::cin.getline(input,153);
	std::cin.clear();
	std::cin.ignore(9999,'\n');
	//Initialize nonce
	for(int i=0; i<8; i++){
		input[152+i] = '0';
	}
	hexToBinary(input);
	for(int i=0; i<32; i++){
		std::cout<<message[i].word<<std::endl;
	}
	std::cout<<std::endl;
	//Compute hash twice
	for(int i=0; i<2; i++){
		populateHashValues(); //Needs to be reset for second hash //SOMEHOW BREAKS MESSAGE???!!!
		for(int j=0; j<32; j++){
			std::cout<<message[j].word<<std::endl;
		}
		exit(0);
		//Add separator, message length, and block count
		int blockCount;
		if(i==0){
			message[20].word.set(31,1);
			message[31].word.set(7,1);
			message[31].word.set(9,1);
			blockCount = 2;
		}
		if(i==1){
			blockCount = 1;
			exit(0);
		}
		std::cout<<std::endl;
		for(int j=0; j<blockCount; j++){
			//Split message into blocks
			for(int k=0; k<16; k++){
				block[j][k].word = message[k+(16*j)].word;
				std::cout<<block[j][k].word<<std::endl;
			}
			//Fill blocks
			for(int k=16; k<64; k++){
				block[j][k].word = block[j][k-7].word.to_ulong() + block[j][k-16].word.to_ulong() + equationCompute(block[j][k-2].word, 0, 17, 19, 10).to_ulong() + equationCompute(block[j][k-15].word, 0, 7, 18, 3).to_ulong();
				std::cout<<block[j][k].word<<std::endl;
			}
			std::cout<<std::endl;
			
			for(int k=0; k<64; k++){
				//Temp words for compression
				std::bitset<32> temp[1];
				temp[0] = equationCompute(hashValue[1][0].word, 1, 6, 11, 25).to_ulong() + hashValue[1][7].word.to_ulong() + choice().to_ulong() + constantValue[k].word.to_ulong() + block[j][k].word.to_ulong();
				temp[1] = equationCompute(hashValue[1][0].word, 1, 2, 13, 22).to_ulong() + majority().to_ulong();
				//Compression
				//Move hashValues down 1
				for(int m=7; m>0; m--){
					hashValue[1][m].word = hashValue[1][m-1].word;
				}
				hashValue[1][0].word = temp[0].to_ulong() + temp[1].to_ulong();
				hashValue[1][4].word = hashValue[1][4].word.to_ulong() + temp[0].to_ulong(); 
			}
			if(blockCount == 2){
				//Add modified hashValues to original hashValues to compute second block
				for(int k=0; k<8; k++){
					hashValue[0][k].word = hashValue[0][k].word.to_ulong() + hashValue[1][k].word.to_ulong();
				}
			}
		}
		for(int j=0; j<8; j++){
			std::cout<<hashValue[1][j].word<<std::endl;
		}
		exit(0);
	}
}
