#include <iostream>

using namespace std;

bool PalindromePermutation(char* arr)
{
    bool* letters = new bool[26];
    int i=0,countOdd=0;
    while(arr[i]!='\0')
    {
        if(arr[i]!=' ')
            letters[arr[i]-'a'] ^= letters[arr[i]-'a'];
        i++;
    }
    for(int j=0; j<26; j++)
    {
        if(letters[j])
            countOdd++;
        if(countOdd>1)
            return false;
    }
    return true;
}
int main()
{
    cout << PalindromePermutation("tact coa") << endl;
    return 0;
}
