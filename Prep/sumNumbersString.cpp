//Given a string containing alphanumeric characters, calculate sum of all numbers present in the string.
#include<stdlib.h>
#include<iostream>
#include<cctype>
using namespace std;

int sum_numbers_string(string s)
{
    int sum=0;
    string str="";
    for(int i=0;i<s.length();i++)
    {
        if(isdigit(s[i]))
        {
            str+=s[i];
            if(!isdigit(s[i+1]))
            {
                int n=stoi(str);
                sum+=n;
                str="";
            }
        }
    }
    return sum;
}

int main()
{
    cout<<sum_numbers_string("1abc2x30yz67");
    return 0;
}