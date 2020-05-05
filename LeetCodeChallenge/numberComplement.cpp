//Number Complement
//Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
/*
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

//Only solution which did not get Run Time Error due to integer overflow
 int findComplement1(int num) {
        if(num==0)
            return 1;
        
        int n=num;
        int bit=1;
        while(n>0)
        {
         num=num^bit;
         n/=2;
         bit=bit<<1;
        }
        return num;
    }

//Got Integer Overflow
int findComplement2(int num)
{
    int n = floor(log2(num)+1);;
    int num_with_all_ones =(int) (1<<n)-1;
    return (num_with_all_ones^num);
}

//Got integer Overflow
int findComplement3(int num)
{
    if(num==0)
        return 1;
    int result=0;
    int power=1;
    while(num>0)
    {
        int pop=num%2;
        int c=(num%2)^1;
        result+=c*power;
        power=power<<1;
        num=num>>1;
    }
    return result;
}

int main()
{
    std::cout<<"Complement is : "<<findComplement1(110)<<std::endl;
    std::cout<<"Complement is : "<<findComplement2(110)<<std::endl;
    std::cout<<"Complement is : "<<findComplement3(110)<<std::endl;
    return 0;
}