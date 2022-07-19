//  You're a square!
/* Examples
-1  =>  false
 0  =>  true
 3  =>  false
 4  =>  true
25  =>  true
26  =>  false */

#include <math.h>

bool is_square(int n)
{
    int tmp = sqrt(n);
    if (tmp*tmp != n)
    {
        return false;
    }

    return true;
}
