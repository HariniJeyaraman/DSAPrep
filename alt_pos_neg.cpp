//Rearrange positive and negative numbers alternatively
#include<cstdlib>
#include<iostream>
using namespace std;

void segregate_pos_neg(int a[], int n) {
    int left = 0;
    int right = n - 1;
    while (1) {
        while (a[left] < 0 && left < right)
            left++;
        while (a[right] > 0 && left < right)
            right--;
        if (left < right) {
            std::swap(a[left], a[right]);
        } else
            break;
    }

    std::cout << "Array after partition function\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\t";
    }
    int pos = left, neg = 0; 
  
    // Increment the negative index by  
    // 2 and positive index by 1, 
    // i.e., swap every alternate negative  
    // number with next positive number 
    while (pos < n && neg < pos && a[neg] < 0) 
    { 
        swap(a[neg], a[pos]); 
        pos++; 
        neg += 2; 
    } 

    std::cout << "Array after alternating \n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\t";

    }
}

int main()
{
    int a[]={12,-3,-19,8,-5,6,-4,10,11};
    int n=sizeof(a)/sizeof(a[0]);
    segregate_pos_neg(a,n);
    return 0;
}