/*You are given an array (which will have a length of at least 3, but could be very large) containing integers.
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N.
Write a method that takes the array as an argument and returns this "outlier" N.*/

#include <iostream>
#include <vector>

using std::vector;

int FindOutlier(vector<int> arr)
{
    int result;
    int even = 0, odd = 0;
    if (arr.size() >= 3)
    {
        for (int check = 0; check < 3; check++) {
            if (arr.at(check) % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        if (even > odd) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr.at(i) % 2 != 0) {
                    return arr.at(i);
                }
            }
        } else {
            for (int i = 0; i < arr.size(); i++) {
                if (arr.at(i) % 2 == 0) {
                    return arr.at(i);
                }
            }
        }
    }

    return 0;
}

int main()
{
    vector<int> arrNums = {3, 5, 7, 9, 12, 11, 13};
    int test = FindOutlier(arrNums);
    std::cout << test;
}