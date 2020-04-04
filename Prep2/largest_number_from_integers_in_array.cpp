// Given a list of non negative integers, arrange them such that they form the
// largest number
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

bool my_sort(std::string a, std::string b) {
    if (a + b > b + a)
        return true;
    else
        return false;
}

std::string largestNumber(std::vector<int> a) {
    std::vector<std::string> string_a;
    // storing integers in vector a as strings in vector string_a
    for (int val : a) {
        string_a.push_back(std::to_string(val));
    }
    // sorting using my_sort as custom sort
    std::sort(string_a.begin(), string_a.end(), my_sort);
    std::string result = "";
    // appending every string element in string_a vector into a single string
    for (std::string str : string_a) {
        result += str;
    }
    // check for trailing zeroes in result
    int i;
    for (i = 0; i < result.size(); ++i) {
        if (result[i] != '0')
            break;
    }
    // no trailing zeroes
    if (i == 0)
        return result;
    else if (i == result.size())
        return "0";
    else
        return result.substr(i, result.size() - i);
}

int main() {
    int n;
    std::cout << "Enter the size of array : ";
    std::cin >> n;
    std::vector<int> a(n);
    std::cout << "Enter the value for the elements : \n";
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::string result = largestNumber(a);
    std::cout << "The largest number from the elements of the array is :  "
              << result << "\n";
    return 0;
}

/*Sample Input-Output
Enter the size of array : 5
Enter the value for the elements :
0 12 44 9 100
The largest number from the elements of the array is :  944121000
*/
