/* Miner.cpp

User inputs block header, nonce gets generated and added to block header, hash gets computed, Compute output gets compared to target

*/

//TODO:
//Add block validation (Check for block version)

//#include "SHA256.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    char input[153];
    int nonceCount[8];
    cout<<"Enter Block Header: ";
    cin.getline(input,153);
    //Print input
    for(int i=0; i<153; i++){
        cout<<input[i];
    }
    cout<<endl;
    //Initialize nonce
    for(int i=0; i<8; i++){
        nonceCount[i] = 0;
        cout<<nonceCount[i]<<endl;
    }
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