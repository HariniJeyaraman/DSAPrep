//Reverse the words in a given string
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

void reverseWords(char s[])
{
    char temp[strlen(s)];
    memset(temp, 0, sizeof temp);
    char temp2[strlen(s)];
    int k=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
         if(s[i]==' ' || i==0)
        {
            if(i==0 && s[i]!=' ')
                temp[k]=s[i];
            for(int p=strlen(temp)-1;p>=0;p--)
                cout<<temp[p];
            cout<<" ";
            k=0;
            i--;
            memset(temp, 0, sizeof temp);

        }
        // if(s[i]!=' ')
        // {
            temp[k]=s[i];
            k++;
        // }
    }
}

int main()
{
    char s[100]="hi there baby what is it";
    reverseWords(s);
}