#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<queue>

std::string frequencySort(std::string s)
{
    std::string result="";
    std::map<char, int> freq;
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>> > maxHeap;

    for(char ch : s)
    freq[ch]++;
    for(auto &eachVal : freq)
    {
        maxHeap.push({eachVal.second, eachVal.first});//we need to sort by frequncy of character and not sort by character
    }

    while(!maxHeap.empty())
    {
        int howFreqCharacter=maxHeap.top().first; //number of times the character(with largest frequency) appears in the input string
        char ch=maxHeap.top().second;
        for(int i=0;i<howFreqCharacter;i++)
        {
            result+=ch;
        }
        maxHeap.pop();
    }
    return result;
}

int main()
{
    std::cout<<"Sorted string based on frequency is : "<<frequencySort("tree")<<std::endl;
    return 0;
}