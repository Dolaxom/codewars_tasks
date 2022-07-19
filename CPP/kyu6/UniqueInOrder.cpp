/* Implement the function unique_in_order which takes as argument 
a sequence and returns a list of items without any 
elements with the same value next to each other 
and preserving the original order of elements. */
// https://www.codewars.com/kata/54e6533c92449cc251001667/train/cpp

#include <string>
#include <vector>
#include <iostream>

using std::vector;

template <typename T>
vector<T> uniqueInOrder(const vector<T>& iterable)
{
    T lastChar;
    vector<T> result;

    for (T i : iterable)
    {
        if (i != lastChar)
        {
            result.push_back(i);   
        }

        lastChar = i;
    }
    
    return result;
}

vector<char> uniqueInOrder(const std::string& iterable)
{
    char lastChar;
    vector<char> result;

    for (char i : iterable)
    {
        if (i != lastChar)
            result.push_back(i);

        lastChar = i;
    }
    
    return result;
}

int main()
{
    const vector<int> test1 = {1, 2, 2, 3, 4, 5};
    const std::string test2 = "AbbBoaa";

    for (int i : uniqueInOrder(test1)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (char i : uniqueInOrder(test2)) {
        std::cout << i << " ";
    }
}