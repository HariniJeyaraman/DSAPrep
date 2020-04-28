//Finding power in an optimized way
/* a^b = a^(b/2) * a^(b^2) if b is even
       = a * a^(b-1/2) * a^(b-1/2) if b is odd
*/

#include<iostream>
#include<cstdlib>
#include<vector>

int power_fast(int a, int b)
{
    int ans;
    //a^0 = 1
    if(b==0)
        return 1;
    //a^1 = a
    else if(b==1)
        return a;
    else if(b%2==0)
    {
        ans=power_fast(a,b/2); //storing the value of a^b/2 instead of computing the same value twice
        return ans*ans;
    }
    else
    {
        ans=power_fast(a,(b-1)/2);
        return a*ans*ans;
    }
    return ans;
}

int main()
{
    int a=12,b=2;
    std::cout<<"Power is : "<<power_fast(a,b)<<"\n";
    return 0;
}

