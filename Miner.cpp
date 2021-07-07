/* Miner.cpp

User inputs block header, nonce gets generated and added to block header, hash gets computed, Compute output gets compared to target

*/

//TODO:
//Integrate with SHA256
//Add nonce to block header
//Check hash against target
//Implement initialNonce value

//#include "SHA256.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    char input[152];
    int nonceCount[8];
    int initialNonce;
    cout<<"Enter Block Header: ";
    cin.getline(input,153);
    cout<<"Enter Initial Nonce Value: ";
    cin>>initialNonce;
    cout<<endl;
    
    //Block Validation
    if(input[0]+input[1]+input[2]+input[3]+input[4]+input[5]+input[6]+input[7] != 385){
    cout<<"Incorrect Input"<<endl;
    exit(1);
    }
    
    /*
    //Print input
    for(int i=0; i<153; i++){
        cout<<i<<": "<<input[i]<<endl;
    }
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
    target = (32-target)*2
    cout<<target<<endl;
    
    //Increment nonce
    while(true){
        string nonce;
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
                    nonce = nonce + '0';
                    break;
                case 1:
                    nonce = nonce + '1';
                    break;
                case 2:
                    nonce = nonce + '2';
                    break;
                case 3:
                    nonce = nonce + '3';
                    break;
                case 4:
                    nonce = nonce + '4';
                    break;
                case 5:
                    nonce = nonce + '5';
                    break;
                case 6:
                    nonce = nonce + '6';
                    break;
                case 7:
                    nonce = nonce + '7';
                    break;
                case 8:
                    nonce = nonce + '8';
                    break;               
                case 9:
                    nonce = nonce + '9';
                    break;
                case 10:
                    nonce = nonce + 'a';
                    break;
                case 11:
                    nonce = nonce + 'b';
                    break;
                case 12:
                    nonce = nonce + 'c';
                    break;
                case 13:
                    nonce = nonce + 'd';
                    break;
                case 14:
                    nonce = nonce + 'e';
                    break;
                case 15:
                    nonce = nonce + 'f';
                    break;
            }
        }
       //make nonce little endian
		string temp = nonce;
        string temp1;
        for(int j=4; j>0; j--){
			for(int k=2; k>0; k--){
				temp1 = temp1 + temp[((j*2)-k)];
			}
		}
        nonce = temp1;
       cout<<nonce<<endl;

    }
}