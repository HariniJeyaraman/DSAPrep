#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>
#include <sstream>

std::string reverseWords(std::string s)
{
    std::stack<std::string> sStack;
    std::string ret;
    std::istringstream strm(s);
    std::string word;
    while (strm >> word)
       sStack.push(word);
    while (!sStack.empty())       
    {
        if ( !ret.empty() )
        ret += " ";
        ret += sStack.top();
        sStack.pop();
    }
    return ret;
}

int main()
{
    std::string s;
    std::cout<<"Enter the string : ";
    getline(std::cin, s);
    std::string rev;
    rev=reverseWords(s);
    std::cout<<"Reversed string : "<<rev<<"\n";
    return 0;
}