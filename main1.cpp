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
    struct node* hashRec[tableSize],*temp,*head,*last;
	string str,word;
	getline(cin,str);
    len=str.length();
    for(i=0;i<len;i++){
        tem=i;
        while(i<len && str[i]!=' '){
            i++;
        }
        if(tem!=i){
        	word=str.substr(tem,i-tem);
            hashVal=calcHash(word);
            if(hashRec[hashVal]==NULL){
                hashRec[hashVal]=new node(word,tem+1);
            }
            else{
            	head=hashRec[hashVal];
            	while(head!=NULL){
            		if(head->next==NULL)
            			last=head;
            		if(head->isEq(word))
            			break;
            		head=head->next;
            	}
            	if(head!=NULL){
            		head->setData(tem+1);
            	}
            	else{
            		temp=new node(word,tem+1);
            		last->next=temp;
            	}
            }
        }
    }
    for(i=0;i<100;i++){
    	head=hashRec[i];
    	while(head!=NULL){
    		head->showData();
    	}
    }
}
