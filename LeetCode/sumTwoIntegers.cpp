#include <bits.h>
#include <iostream>

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};

int main()
{
    Solution sol = Solution();
    std::cout << sol.getSum(1000, -1000) << std::endl;
    return 0;
}
