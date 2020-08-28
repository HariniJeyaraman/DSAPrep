/*
415. Add Strings
Easy

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1, j=num2.size()-1,carry=0,sum=0,temp=0;
        string result="";
        while(i>=0 && j>=0){
            int pop1 = num1[i] -'0';
            int pop2 = num2[j] - '0';
            temp=pop1+pop2+carry;
            sum = (temp)%10;
            result+=to_string(sum);
            carry = (temp)/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            sum=(num1[i]-'0'+carry)%10;
            carry=(num1[i]-'0'+carry)/10;
            result+=to_string(sum);
            i--;
        }
        while(j>=0)
        {
            sum=(num2[j]-'0'+carry)%10;
            carry=(num2[j]-'0'+carry)/10;
            result+=to_string(sum);
            j--;
        }
        if(carry>0){
            result+=to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};