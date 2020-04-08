//Count the number of trailing zeroes in a factorial of a given number
/*
A trailing zero is always produced by prime factors 2 and 5. If we can count the number of 5s and 2s, our task is done.
We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done
*/
#include<iostream>
#include<cstdlib>

int trailingZeroes(int A) {
    int count=0;
    for(int i=5;A/i>=1;i=i*5)
    {
        count+=A/i;
    }
    return count;
}

int main()
{
    int n;
    std::cout<<"Enter the number : ";
    std::cin>>n;
    std::cout<<"The number of trailing zeroes for "<< n <<" ! : "<<trailingZeroes(n)<<"\n";
    return 0;
}