#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)

void solve(int c1, int c2, int c3, int a1, int a2, int a3, int a4, int a5)
{
    int possible = 1;

    int cap1 = c1 - a1;
    int cap2 = c2 - a2;
    int cap3 = c3 - a3;

    // cout << cap1 << " " << cap2 << " " << cap3 << endl;

    if (cap1 < 0 || cap2 < 0 || cap3 < 0)
    {
        possible = 0;
    }

    if (cap1 + cap3 < a4)
    {
        possible = 0;
    }
    else
    {
        int item4 = 0;
        if (a4 > cap1)
        {
            item4 = a4 - cap1;
        }

        cap3 -= item4;
    }

    if (cap2 + cap3 < a5)
    {
        possible = 0;
    }

    if (possible == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        solve(c1, c2, c3, a1, a2, a3, a4, a5);
    }
}
