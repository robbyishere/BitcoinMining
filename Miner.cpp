/* Miner.cpp

User inputs block header, nonce gets generated and added to block header, hash gets computed, Compute output gets compared to target

*/

//TODO:
//cout not printing correct output?
//Check hash against target
//Implement initialNonce value

#include "SHA256.h"

int main(){
    char input[160];
    int nonceCount[8];
    int initialNonce;
    int finished = 0;
    cout<<"Enter Block Header: ";
    cin.getline(input,153);
    cout<<"Enter Initial Nonce Value: ";
    //cin>>initialNonce;
    cout<<endl;
    
    //Block Header Validation
    //Checks for correct block version
    if(input[0]+input[1]+input[2]+input[3]+input[4]+input[5]+input[6]+input[7] != 385){
    cout<<"Incorrect Input"<<endl;
    exit(1);
    }
    /*
    //Print input
    for(int i=0; i<153; i++){
        cout<<input[i];
    }
    cout<<endl;
    */
    //Initialize nonce
    for(int i=0; i<8; i++){
        nonceCount[i] = 0;
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
    cout<<target<<endl;

    while(true){
        //Increment nonce
        char nonce[8];
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
        //make nonce little endian
        char temp1[8];
        for(int i=4; i>0; i--){
            for(int j=2; j>0; j--){
	    		temp1[7-((i*2)-(3-j))] = nonce[((i*2)-j)];
	    	}
	    }
        //Add nonce to block header
        for(int i=0; i<8; i++){
            input[152+i] = temp1[i];
        }

        for(int i=0; i<160; i++){
            cout<<input[i];
        }
        cout<<endl;
        cout<<SHA256(input)<<endl;
        cin.ignore();
    }

}   