/*
Determine whether an integer is a palindrome. Do this without extra space.
A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.
*/
#include<iostream>
#include<cstdlib>

bool palindrome(int A)
{
    int rev=0,pop=0;
    if(A==0)
        return true;
    //Input cannot have trailing 0's in start. Ex : 1210 is not a palindrome only 01210 is a palindrome but input cannot have trailing 0's.
    if(A<0 || A%10==0)
        return false;
    //Reversing only half of the integer and comparing the 2 halves
    while(A>rev)
    {
        pop=A%10;
        A/=10;
        rev=rev*10+pop;
    }
    //if the integer has odd number of digits, rev will contain an extra digit than A
    if(A==rev || A==rev/10)
        return true;
    else
        return false;
}

int main()
{
    int n;
    std::cout<<"Enter the integer";
    std::cin>>n;
    if(palindrome(n))
        std::cout<<"The integer is a palindrome !\n";
    else    
        std::cout<<"Not a palindrome \n";
    return 0;
}