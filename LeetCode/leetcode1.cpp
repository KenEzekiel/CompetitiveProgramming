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
        if (height.size() <= 2)
        {
            if (height.size() == 2)
            {
                if (height[0] == 0 || height[1] == 0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        // Want to find top 2 max height, which is more separated

        // get max height, then get second max height with max area

        int max_idx = 0;
        int max_height = height[0];

        REP(i, 0, height.size())
        {
            cout << "elmt " << height[i] << endl;
            if (height[i] > max_height)
            {
                max_height = height[i];
                max_idx = i;
            }
        }

        cout << max_height << endl;

        int max_area = 0;
        int area;
        int saved_idx;
        REP(i, 0, height.size())
        {
            area = min(max_height, height[i]) * dif(i, max_idx);
            if (area > max_area)
            {
                max_area = area;
                saved_idx = i;
            }
        }

        // Cek yang diluar max height itu
        // saved < max, max < saved
        if (saved_idx < max_idx)
        {
            // cek dari i < saved ke max dan saved ke i > max
            for (int i = 0; i < saved_idx; i++)
            {
                area = min(max_height, height[i]) * dif(i, max_idx);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
            for (int i = max_idx + 1; i < height.size(); i++)
            {
                area = min(height[saved_idx], height[i]) * dif(saved_idx, i);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
        }
        else
        {
            // cek dari i < max ke saved dan max ke i > saved
            for (int i = 0; i < max_idx; i++)
            {
                area = min(height[i], height[saved_idx]) * dif(i, saved_idx);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
            for (int i = saved_idx + 1; i < height.size(); i++)
            {
                area = min(max_height, height[i]) * dif(max_idx, i);
                if (area > max_area)
                {
                    max_area = area;
                }
            }
        }

        return max_area;
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
