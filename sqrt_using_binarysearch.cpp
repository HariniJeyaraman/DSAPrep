//Finding sqaure root of x using binary search
#include<iostream>
#include<cstdlib>

//Note: mid * mid will overflow if not done carefully. So instead, we eliminate the multiplcation and resort to a little bit of division.
int sqrt_binary_search(int x, int beg, int end)
{
    int ans;
    if(x==0)
        return 0;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(mid==x/mid) //mid*mid==x
        {
            ans=mid;
            break;
        }
        else if(x/mid>mid) //x>mid*mid
        {
            beg=mid+1;
            ans=mid;
        }
            
        else
            end=mid-1;
    }
    return ans;
}

int main()
{
    int n;
    std::cout<<"Enter the number";
    std::cin>>n;
    std::cout<<"Sqrt is : "<<sqrt_binary_search(n,0,n)<<"\n";
    return 0;
}