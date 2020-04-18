/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.
If the last word does not exist, return 0.
*/
#include<iostream>
#include<cstring>
#include<cstdlib>

int lastWord(std::string str)
{
    int count=0;
    bool flag=false;
    for(int i=str.size()-1;i>=0;i--)
    {
         if(!isspace(str[i])){
            flag = true; 
            count++; 
        } 
        else { 
            if (flag == true) 
                return count; 
        } 
    
    }
    return count;

}

int main()
{
    std::string s="what the hell lastword   ";
    std::cout<<"Length of last word is : "<<lastWord(s)<<"\n";
    return 0;
}