/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/
#include<iostream>
#include<cstdlib>
#include<cstring>

int firstUniqChar(std::string a) {
        int flag=0;
        for(int i=0;i<a.length();i++)
        {
            flag=0;
            for(int j=0;j<a.length();j++)
            {
                if(i!=j && a[i]==a[j])
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==0)
                return i;
        }
        return -1;
    }

int main()
{
    std::cout<<"The index of 1st non-repeating character is : "<<firstUniqChar("loveleetcode")<<std::endl;
    return 0;
}