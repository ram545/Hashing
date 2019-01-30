#include<iostream>
#include<cstring>
#define ll long long
#define tableSize 100
#define initialValue 0
using namespace std;


struct node{
    string val;
    int occurence;
    int pos[20]={0};
    node *next;
    node(string val,int position){
        this->val = val;
        pos[occurence]=position;
        occurence = 1;
        next=NULL;
    }
    bool isEq(string val){
        return this->val==val;
    }
};
