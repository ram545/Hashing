#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int i,len;
	char ch;
	int hash[28]={0};
	string str;
	getline(cin,str);
	len = str.length();
	for(i=0;i<len;i++){
		if(str[i]>='a' && str[i]<='z')
			hash[str[i]-'a']++;
		else if(str[i]>='A' && str[i]<='Z')
			hash[str[i]-'A']++;
	}
	for(i=0;i<26;i++){
		ch = 'a'+i;
		cout << "Character: " << ch << " Frequency: " << hash[i] << endl;
	}
}