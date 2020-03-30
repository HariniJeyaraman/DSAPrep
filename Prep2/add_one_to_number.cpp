#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
//Add 1 to number
/*
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.
*/
 /*
 Here we are calculating the number of trailing zeroes to the left that we need to exclude while printing the output
 For example : if the input is 0,0,1,2,3,4 => The output should be 1,2,3,5 and NOT 0,0,1,2,3,5
 So, here we are finding the number of continuos 0's in the input that we need to exclude in the output
 */

vector<int> plusOne(vector<int> &A) {
    vector<int> A1(A.size());
    A1=A;
    int c=0,ind=0;
   if(A[0]==0)
   {
    c=1;
    while(1)
    {
        if(A[ind]+A[ind+1]==0)
        {
         c++;
         ind++;
         }   
        else
            break;
    }
   }
   //cout<<" C is : " <<c<<"\n";
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]<9)
        {
            A[i]++;
            if(A1[0]==0 && A.size()>1)
                return std::vector<int>(A.begin() + c, A.end());
            else
            return A;
        }
        A[i]=0;   
    }
    vector<int> result(A.size()+1);
    result[0]=1;
    return result;
}

int main()
{
    vector<int> A(10);
    A={0,0,4,5,2,0,9,7,1,2};
    cout<<"Sum is : ";
    vector<int> result = plusOne(A);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<< " ";
    return 0;

}

/* Output:
    Sum is : 4 5 2 0 9 7 1 3
*/
