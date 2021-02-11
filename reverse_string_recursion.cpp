#include<cstdlib>
#include<iostream>
using namespace std;

//"string" -> "gnirts"
string reverse(string s, int n){
    string res="";
    if(n<=0) return "";
    res+=reverse(s.substr(1), n-1)+(s[0]);
    return res;
}

int main(){
    char inp[] = {'s','t', 'r','i','n','g','\0'};
    cout<<reverse(inp, 6)<<endl;
}

/*
Stack : 

Base Case !
"", 0        : returns ""
___________
"g", 1       : returns "" + "g" = "g"
___________
"ng", 2      : returns "g" + "n" = "gn"
___________
"ing", 3     : returns "gn" + "i" = "gni"
___________
"ring", 4    : returns "gni" + "r" = "gnir"
___________
"tring", 5   : returns "gnir" + "t" = "gnirt"
___________
"string", 6  : returns "gnirt" + "s" = "gnirts"
*/