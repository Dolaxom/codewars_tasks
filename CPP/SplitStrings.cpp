// Split Strings

/*Complete the solution so that it splits the string into 
pairs of two characters. If the string contains an odd number 
of characters then it should replace the missing second character 
of the final pair with an underscore ('_').

Examples:
'abc' =>  ['ab', 'c_']
'abcdef' => ['ab', 'cd', 'ef']

https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/train/cpp
*/

#include <string>
#include <vector>

using std::vector;
using std::string;

vector<string> solution(const string &s)
{
    vector<string> result;
    unsigned long i = 0;
    while (s.length() != 0)
    {
        unsigned long currentStep = i;
        for (; i < currentStep + 2;)
        {
            
            string token;
            if (i + 1 >= s.length())
            {
                token = {s[i], '_'};
            }
            else
            {
                token = {s[i], s[i+1]};
            }
            result.push_back(token);
            i += 2;
        }
    
    if (i >= s.length())
        break;

    }
    
    return result;
}
