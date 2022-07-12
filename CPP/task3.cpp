/* Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times. 

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

*/

#include <iostream>
#include <vector>

using std::vector;

int findOdd(const vector<int>& numbers)
{
    vector<int> tmp;

    for (unsigned long i = 0; i < numbers.size(); i++) {
        bool canWrite = true;
        if (i == 0) {
            tmp.push_back(numbers.at(i));
            tmp.push_back(1);
            continue;
        }

        for (unsigned long j = 0; j < tmp.size(); j += 2) {
            if (numbers.at(i) == tmp.at(j)) {
                canWrite = false;
            }
        }

        if (canWrite) {
            tmp.push_back(numbers.at(i));
            tmp.push_back(1);
        }
    }

    for (unsigned long i = 0; i < tmp.size(); i += 2) {
        int count = 0;
        for (unsigned long j = 0; j < numbers.size(); j++) {
            if (tmp[i] == numbers[j]) {
                count++;
            }
            tmp.at(i + 1) = count; 
        }
    }


    for (unsigned long i = 1; i < tmp.size(); i += 2) {
        if (tmp[i] % 2 != 0) {
            return tmp[i - 1];
        }
    }

    return 0;
}

int main()
{
    vector<int> V = {0, 1, 0,1,0};

    std::cout << findOdd(V);    // 4

    return 0;
}