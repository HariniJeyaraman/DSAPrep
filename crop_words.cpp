#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

string cropWords(string msg, int k)
{
    string temp="";
    string result="";
    vector<string> words;
    for(int i=0;i<msg.size();i++)
    {
        // cout<<msg[i];
        if(msg[i]!=' ')
            temp+=msg[i];
        if(msg[i]==' '||i==msg.size()-1)
        {
            words.push_back(temp);
            words.push_back(" ");
            temp.clear();
        }
    }

    for(string el : words)
    {
        if(el.length()<=k)
        {
            result+=el;
            k=k-el.length();
        }
        else break;
    }
    int c=0;
    //Removing the spaces at the end by counting the number of spaces to remove
    for(int i=result.size()-1;i>=0;i--)
    {
        if(result[i]==' ')
            c++;
        else
            break;
    }
    //returning the subtring of result without spaces at the end
    return result.substr(0,result.size()-c);
}

int main()
{
    cout<<cropWords("      Codility We test coders     ", 10);
}

/* TEST CASES :
console.log(cropWords("codility We test coders", 14) === "codility We")
console.log(cropWords(" co de my", 5) === " co")
console.log(cropWords(" co de my", 7) === " co de")
console.log(cropWords("   ", 2) === "")
console.log(cropWords("   re", 2) === "") //3 spaces before
console.log(cropWords(" c ", 3) === " c")
console.log(cropWords(" c d  ", 5) === " c d")
console.log(cropWords("co de my", 5) === "co de")
console.log(cropWords("Word", 4) === "Word")
console.log(cropWords("codility We test coders", 23) === "codility We test coders")
console.log(cropWords("withOutSpaces", 14) === "withOutSpaces")
console.log(cropWords("", 14) === "")
console.log(cropWords("Separatedby hyphens", 14) === "Separatedby")
console.log(cropWords("      Codility We test coders     ", 14) === "      Codility") //6 leading spaces
console.log(cropWords("      Codility We test coders     ", 10) === "") //6 leading spaces
*/
