/*
Given a positive integer A, return an array of strings with all the integers
from 1 to N. But for multiples of 3 the array should have “Fizz” instead of the
number. For the multiples of 5, the array should have “Buzz” instead of the
number. For numbers which are multiple of 3 and 5 both, the array should have
“FizzBuzz” instead of the number.
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

std::vector<std::string> fizzBuzz(int A) {
    std::vector<std::string> result;
    for (int i = 1; i <= A; i++) {
        if (i % 15 == 0)
            result.push_back("FizzBuzz");

        else if (i % 5 == 0)
            result.push_back("Buzz");

        else if (i % 3 == 0)
            result.push_back("Fizz");

        else
            result.push_back(std::to_string(i));
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter the integer : ";
    std::cin >> n;
    std::vector<std::string> result = fizzBuzz(n);
    for (std::string str : result)
        std::cout << str << "\t";
    std::cout << "\n";
}