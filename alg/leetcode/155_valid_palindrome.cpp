
#include <string>
using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) 
    {
        int left = 0, right = s.length() - 1;
        while(left < right)
        {
            while (!isalnum(s[left]) && left < right)
            {
                left++;
            }
            while (!isalnum(s[right]) && left < right)
            {
                right--;
            }
            if (left >= right)
            {
                return true;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    bool result = false;
    result = Solution::isPalindrome("aa");
    return 0;
}