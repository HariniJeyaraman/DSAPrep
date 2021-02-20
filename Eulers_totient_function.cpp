/*
Euler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
Examples :

Φ(1) = 1  
gcd(1, 1) is 1

Φ(2) = 1
gcd(1, 2) is 1, but gcd(2, 2) is 2.

Φ(3) = 2
gcd(1, 3) is 1 and gcd(2, 3) is 1

Φ(4) = 2
gcd(1, 4) is 1 and gcd(3, 4) is 1

Φ(5) = 4
gcd(1, 5) is 1, gcd(2, 5) is 1, 
gcd(3, 5) is 1 and gcd(4, 5) is 1
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int eulerTotient(unsigned int n){
    unsigned int result = 1;
    for(int i=2;i<n;i++){
        if(gcd(i, n) == 1){
            result++;
        }
    }
    return result;
}

int main(){
    for(int i=1;i<=10;i++){
        cout<<"phi("<<i<<") = "<<eulerTotient(i)<<endl;
    }
    return 0;
}