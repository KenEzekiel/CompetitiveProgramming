#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define SQ(a) (a) * (a)
using namespace std;

// Max area is length * height

class Solution
{
public:
    int dif(int a, int b)
    {
        return a > b ? a - b : b - a;
    }
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;

        int area;
        int maxArea = 0;
        int count = 0;
        while (left < right)
        {
            // cout << left << " " << right << endl;
            area = min(height[left], height[right]) * (right - left);
            if (area > maxArea)
            {
                maxArea = area;
            }
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution solution = Solution();
    vi a = vector<int>();
    int b[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int c[2] = {0, 2};
    int d[100] = {76, 155, 15, 188, 180, 154, 84, 34, 187, 142, 22, 5, 27, 183, 111, 128, 50, 58, 2, 112, 179, 2, 100, 111, 115, 76, 134, 120, 118, 103, 31, 146, 58, 198, 134, 38, 104, 170, 25, 92, 112, 199, 49, 140, 135, 160, 20, 185, 171, 23, 98, 150, 177, 198, 61, 92, 26, 147, 164, 144, 51, 196, 42, 109, 194, 177, 100, 99, 99, 125, 143, 12, 76, 192, 152, 11, 152, 124, 197, 123, 147, 95, 73, 124, 45, 86, 168, 24, 34, 133, 120, 85, 81, 163, 146, 75, 92, 198, 126, 191};
    for (int i = 0; i < 100; i++)
    {
        a.push_back(d[i]);
    }
    cout << solution.maxArea(a);
}
