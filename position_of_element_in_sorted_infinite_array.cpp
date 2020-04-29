//Find position of an element in a sorted array of infinite numbers
//Suppose you have a sorted array of infinite numbers, how would you search an element in the array?
#include<iostream>
#include<cstdlib>
#include<vector>

//Since the array is sorted we can use binary search, but we do not know the size of the array , that is end of array is unknown
int binarySearch(std::vector<int> a, int beg, int end, int target)
{
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==target)
            return mid;
        else if(a[mid]<target)
            beg=mid+1;
        else    
            end=mid-1;
    }
    return -1;
}

int positionOfElement(std::vector<int> a, int target)
{
    int beg=0;
    int end=1;
    int val=a[0];
    //finding the element position to perform binary search
    while(val<target)
    {
        beg=end; //storing previous value of end
        end=end*2; //double index end
        val=a[end]; //update new val
    }
    return binarySearch(a,beg,end,target);
}

//This is a lame method since we're calling binarySearch function inside a while loop and the time complexity will be too huge
//Do NOT use this lame method, dear future self !
int positionOfElement_lame_method(std::vector<int> a, int target)
{
    if(a.size()==1) //lame condition check, unnecessary since array is supposed to be infinite
    {
        if(a[0]==target)
            return 0;
        else
            return -1;
    }

    int beg=0;
    int end=1;
    int pos=-1;
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE 
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING 
    while(1)
    {
        pos=binarySearch(a,beg,end,target);
        if(pos==-1)
        {
            end++;
        }
        else
            return pos;
    } 
    
}

int main()
{
    std::vector<int> a={3, 5, 7, 9, 10, 90, 100, 130,  
                               140, 160, 170}; 
    std::cout<<"The position of element is : "<<positionOfElement_lame_method(a,130)<<"\n";
    std::cout<<"The position of element is : "<<positionOfElement(a,130)<<"\n";
    return 0;
}