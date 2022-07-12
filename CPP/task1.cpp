/* Return the number (count) of vowels in the given string.
We will consider a, e, i, o, u as vowels for this Kata (but not y).
The input string will only consist of lower case letters and/or spaces. */

#include <iostream>
#include <string>

using namespace std;

int getCount(const string& inputStr)
{
    const int ARR_SIZE = 5;
    char arrVowels[ARR_SIZE] = {'a', 'e', 'i', 'o', 'u'};
    int num_vowels = 0;

    int strLength = inputStr.length();
    for (int i = 0; i < strLength; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            if (inputStr[i] == arrVowels[j]) {
                num_vowels++;
            }
        }
    }

    return num_vowels;
}

int main()
{
    int test = getCount("abracadabra");
    cout << test;
}