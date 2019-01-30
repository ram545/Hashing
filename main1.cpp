#include "./hash.h"

//Used Kernighan and Ritchie's function function for multiplicative hash functions
int calcHash(string str){
    int len,i,M=31;
    ll res=initialValue;
    len = str.length();
    for(i=0;i<len;i++){
        res = res*M + str[i];
    }
    return res%tableSize;
}

int main(){
    int len,i,tem,hashVal;
    struct node* hashRec[tableSize];
	string str;
	getline(cin,str);
    len=str.length();
    for(i=0;i<len;i++){
        tem=i;
        while(i<len && str[i]!=' '){
            i++;
        }
        if(tem!=i){
            hashVal=calcHash(str.substr(tem,i-tem));
            if(hashRec[hashVal]==NULL){
                hashRec[hashVal]=new node();
            }
        }
    }
}
