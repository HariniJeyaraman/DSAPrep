// Implement strStr() in C++
/*
Return the index of the first occurence of needle in haystack
If needle is an empty string, return 0
If needle is not present in haystack, return -1
*/
#include <cstdlib>
#include <cstring>
#include <iostream>

int strStr(std::string haystack, std::string needle) {
  int start = -1, f = 0;

  if (needle.size() == 0)
    start = 0;
  else {

    for (int i = 0; i < needle.size(); ++i) {
      for (int j = 0; j < haystack.size(); ++j) {
        int count = 0;
        if (haystack[j] == needle[i]) {
          int i_temp = i + 1;
          int j_temp = j + 1;

          while (i_temp != needle.size()) {
            if (haystack[j_temp++] == needle[i_temp++]) {
              count++;
            }
          }
          if (count == needle.size() - 1) {
            start = j;
            goto label;
          }

        } else
          continue;
      }
    }
  }
label:;//to break out of the nested for loop once the 1st occurence of needle is found
  return start;
}

int main() {
  std::string haystack =
      "babaaaabbbbbabbaababbaaabbabaaaabaaaabbaabaabababaabbaabbaaaaababba";
  std::string needle = "bbaa";
  int start = strStr(haystack, needle);
  std::cout << "The first occurence index is : " << start << "\n";
}

/*
Input :
haystack : "babaaaabbbbbabbaababbaaabbabaaaabaaaabbaabaabababaabbaabbaaaaababba"
needle : "bbaa"
Output :
The first occurence index is : 13
*/