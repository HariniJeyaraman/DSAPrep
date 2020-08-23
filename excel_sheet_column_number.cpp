/*
171. Excel Sheet Column Number
Easy

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:

Input: "A"
Output: 1

Example 2:

Input: "AB"
Output: 28

Example 3:

Input: "ZY"
Output: 701
*/

class Solution {
public:
    int titleToNumber(string s) {
        if(s.length()==0)
            return s[0]-'A'+1;
        int result=0,ind=0;
        for(int i=s.length()-1;i>=0;i--){
            result+=((pow(26,i))*(s[ind]-'A'+1));
            ind++;
        }
        return result;
    }
};

/*AA=27
AB = 28
...
.
.
..
AZ = 26+26 = 52
BA = 53

ZY = 701
ZZ = 702

AAA = 703*/