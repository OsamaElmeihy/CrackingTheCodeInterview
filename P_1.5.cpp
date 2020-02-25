#include <iostream>

using namespace std;
//wrong implemetation!!!
bool oneEdit (const char* s1,const char* s2){
    int* letters = new int[26];
    int i=0,counter=0;
    while(s1[i]!='\0'){
        letters[s1[i++]-'a']++;
    }
    i=0;
    while(s2[i]!='\0'){
        letters[s2[i++]-'a']--;
    }
    for(int j=0;j<26;j++){
    	if(letters[j]!=0)
		counter++;
	if(counter>2)
		return false;
    }
    return true;
}
int main()
{
    cout << oneEdit("bape","pabe") << endl;
    return 0;
}
