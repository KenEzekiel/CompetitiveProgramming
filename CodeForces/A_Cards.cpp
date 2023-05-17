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

void solve(int n, vector<char> b)
{
    int nNum = 0;
    int zNum = 0;
    int rNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 'n')
        {
            nNum++;
        }
        if (b[i] == 'z')
        {
            zNum++;
        }
        if (b[i] == 'r')
        {
            rNum++;
        }
    }

    int one = 0;
    for (int i = 0; i < nNum; i++)
    {
        one++;
        cout << 1;
        if (i != nNum - 1)
        {
            cout << " ";
        }
    }
    for (int i = 0; i < zNum; i++)
    {
        if (one && i == 0)
        {
            cout << " ";
        }
        cout << 0;
        if (i != zNum - 1)
        {
            cout << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<char> buf(n);

    REP(i, 0, n - 1)
    {
        cin >> buf[i];
    }

    solve(n, buf);

    return 0;
}
