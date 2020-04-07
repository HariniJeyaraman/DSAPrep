//Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 
//O(n*log(log(n)))
//The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million
#include<iostream>
#include<cstdlib>
#include<cstring>
void prime_numbers(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for(int i=p*p;i<=n;i=i+p)
            {
                prime[i]=false;
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(prime[i])
            std::cout<<i<<" ";
    }
}

int main()
{
    int n;
    std::cout<<"Enter the number : ";
    std::cin>>n;
    prime_numbers(n);
    std::cout<<"\n";
    return 0;
}