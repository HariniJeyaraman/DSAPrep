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

/*
For example number of 2's in 9!
9! = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 
No. of 2's :
9/2 = 4
4/2 = 2
2/2 = 1
No. of 2's is 4+2+1 = 7

No. of 2's = No. of 2's in 2 + No. of 2's in 4 + No. of 2's in 4 + No. of 2's in 6 + No. of 2's in 8
            (2 = 2^1 , 4 = 2^2 , 6 = 2^1 * 3 , 8 = 2^3)
           = 1 + 2 + 1 + 3 = 7
*/ 
