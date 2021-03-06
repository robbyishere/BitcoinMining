/* Miner.cpp

User inputs block header, nonce gets generated and added to block header, hash gets computed, Compute output gets compared to target

*/

//TODO:
//Add initialNonce hex to decimal converter?
//Improve Code

#include "SHA256.h"

int main(){
    char input[160];
    int nonceCount[8];
    int initialNonce;
    int finished = 0;
    cout<<"Enter Block Header: ";
    cin.getline(input,153);
    cin.clear();
    cin.ignore(9999,'\n');
    
    //Block Header Validation
    //Checks for correct block version
    if(input[0]+input[1]+input[2]+input[3]+input[4]+input[5]+input[6]+input[7] != 385){
    cout<<"Incorrect Input"<<endl;
    exit(1);
    }
    
    //Initialize nonce
    for(int i=0; i<8; i++){
        nonceCount[i] = 0;
        input[152+i] = 0;
    }    
    //Convert input to binary
    string message = hexToBinary(input, 152);
    message = message + "00000000000000000000000000000000";
    //Custom nonce prompt and conversion
    char answer;
    cout<<"Do you want to enter custom nonce? (Y or N): ";
    cin>>answer;
    switch(answer){
        case 'Y':
            for(int i=0; i<8; i++){
                int temp;
                cout<<"Enter number "<<i<<" of nonce (int):";
                cin>>temp;
                cout<<endl;
                nonceCount[i] = temp;
            }
    }
    
    //Find target
    char temp[2];
    int target = 0;
    temp[0] = input[150];
    temp[1] = input[151];
    //Convert target value from hex to decimal
    if(temp[0] == '1'){
        target = 16;
    }
    if(temp[1] == '0'){
        target = target + 0;
    }
    if(temp[1] == '1'){
        target = target + 1;
    }
    if(temp[1] == '2'){
        target = target + 2;
    }
    if(temp[1] == '3'){
        target = target + 3;
    }
    if(temp[1] == '4'){
        target = target + 4;
    }
    if(temp[1] == '5'){
        target = target + 5;
    }
    if(temp[1] == '6'){
        target = target + 6;
    }
    if(temp[1] == '7'){
        target = target + 7;
    }
    if(temp[1] == '8'){
        target = target + 8;
    }
    if(temp[1] == '9'){
        target = target + 9;
    }
    if(temp[1] == 'a'){
        target = target + 10;
    }
    if(temp[1] == 'b'){
        target = target + 11;
    }
    if(temp[1] == 'c'){
        target = target + 12;
    }
    if(temp[1] == 'd'){
        target = target + 13;
    }
    if(temp[1] == 'e'){
        target = target + 14;
    }
    if(temp[1] == 'f'){
    target = target + 15;
    }
    target = (32-target)*2;
    
    //Initialize Constant Values
    struct ConstantValueStruct ConstantValues[64];
    computeConstants(ConstantValues);
    
    int count = 0;
    while(finished == 0){
        //Copy Input array to temp2
        char temp2[160];
        for(int i=0; i<160; i++){
            temp2[i] = input[i];
        }
        
        //Compute SHA256 hash from input
        string temp3;
        temp3 = SHA256(message, ConstantValues);
        //Print hash
        cout<<count<<": "<<temp3<<endl;
        
        //Copy back temp2 to Input Array
        //(Changes to input array in SHA256 function forwards changes to this function)
        for(int i=0; i<160; i++){
            input[i] = temp2[i];
        }
        
        //Counts zeros in hash
        int temp4;
        for(int i=0; i<target; i++){
            if(temp3[i] == '0'){
                temp4++;
            }
        }
        //Compare number of zeros to target
        if(temp4==target){
            finished = 1;
        }
        else{
            temp4=0;
            count++;
        }
        
        //Increment nonce
        for(int i=7; i>-1; i--){
            if(i==7 && nonceCount[7]<16){
                nonceCount[7] = nonceCount[7] + 1;
            }
            if(nonceCount[i] == 16){
                nonceCount[i-1] = nonceCount[i-1] + 1;
                nonceCount[i] = 0;
            }
        }
        //Convert nonce to hex
        char nonce[8];
        for(int i=0; i<8; i++){
            switch(nonceCount[i]){
                case 0:
                    nonce[i] = '0';
                    break;
                case 1:
                    nonce[i] = '1';
                    break;
                case 2:
                    nonce[i] = '2';
                    break;
                case 3:
                    nonce[i] = '3';
                    break;
                case 4:
                    nonce[i] = '4';
                    break;
                case 5:
                    nonce[i] = '5';
                    break;
                case 6:
                    nonce[i] = '6';
                    break;
                case 7:
                    nonce[i] = '7';
                    break;
                case 8:
                    nonce[i] = '8';
                    break;               
                case 9:
                    nonce[i] = '9';
                    break;
                case 10:
                    nonce[i] = 'a';
                    break;
                case 11:
                    nonce[i] = 'b';
                    break;
                case 12:
                    nonce[i] = 'c';
                    break;
                case 13:
                    nonce[i] = 'd';
                    break;
                case 14:
                    nonce[i] = 'e';
                    break;
                case 15:
                    nonce[i] = 'f';
                    break;
            }
        }
        
        //Make nonce little endian
        char temp1[8];
        for(int i=4; i>0; i--){
            for(int j=2; j>0; j--){
	    		temp1[7-((i*2)-(3-j))] = nonce[((i*2)-j)];
	    	}
	    }
        //Convert nonce to binary
        string test = hexToBinary(temp1, 8);
        
        //Add nonce to block header
        for(int i=608; i<640; i++){
            message[i] = test[i-608];
        }
    }
}   