#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
/*
Password Decryption :
Alice wants to secure his bank account details and wants to encrypt his password P. He wants to encrypt it in such a fashion:-
Suppose P = "zyxabc", he will randomly shuffle his password, then he will concatenate a random string S1 in starting of P and a random string S2 at end of the string P. Let S1 = "fgh" and S2 = "bvf" then encrypted string become H = "fghcxabyzbvf".
Bob has got a password and an encrypted string, He being a hacker wants to check if the encrypted string can be a valid one for the password he have.
The password and encrypted password only consists of lower case english alphabets.

Input:
First line of input contains an integer T, denoting the number of test cases. First line of each test case contains the string P, second line of the test case contains the string H.

Output:
Print "Yes" if it is a valid one else "No".

Your Task:
This is a functional problem . You don't need to take input just complete the function valid() which accepts two strings P and S as parameters and return 0 or 1.

Constraints:
1<= T  <=30
1<= |P| <=105
1<= |H| <=105

Example:
Input:
2
zyxabc
fghcxabyzbvf
htc
hxtcczht

Output:
Yes
No

*/
//Method to check if both the hash arrays are equal or not
bool isEqual(int a[], int b[])
{
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

//String P is the password string and S is the encrypted string containing shuffled password
//We need to check and validate if the encrypted string contains the password or not
bool validatePassword(string P, string S)
{
    //In order to contain the password, S should have a length >= length of Password
    if(P.size()>S.size())
        return false;
    int hash1[26]={0};
    int hash2[26]={0};
    //Populating hash1 containing frequency of each character of Password string
    for(int i=0;i<P.size();i++)
        hash1[P[i]-'a']++;
    
    int l=0;
    int r=P.size()-1;
    //Populating the first hash2 window of size P.size()
    for(int i=l;i<=r;i++)
    {
        hash2[S[i]-'a']++;
    }
    if(isEqual(hash1, hash2))
        return true;
    
    //shifting the window of fixed length (length of P) by increasing r and l and adding S[r] to hash and removing S[l] from hash
    for(int i=r+1;i<S.size();i++)
    {
        hash2[S[l]]--;
        l++;
        hash2[S[r]]++;
        r++;
        //checking if both hash arrays are equal for every window
        if(isEqual(hash1, hash2))
            return true;
    }
    return false;

}

int main()
{
    string P="zyxabc";
    string S="fghcxabyzbvf";
    cout<<validatePassword(P,S)<<endl;
    return 0;
}