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

const int MOD = 1000000007;

int factorial(int a)
{
    int ret = 1;
    for (int i = a; i > 0; i--)
    {
        ret *= i;
    }
    return ret;
}
int solve(vector<int> &a, int k)
{
    int n = a.size();

    // Initialize an array to store the number of times each bitwise AND value occurs in the array.
    vector<int> and_values(1 << k, 0);

    for (int i = 0; i < n; i++)
    {
        and_values[a[i]]++;
    }

    // Initialize an array to store the number of non-empty subsequences of the array such that the bitwise AND of the elements in the subsequence has exactly i set bits.
    vector<int> dp(1 << k, 0);

    // Initialize the base cases.
    dp[0] = 1;

    for (int i = 1; i < (1 << k); i++)
    {
        // Add the contribution from all subsequences of length 1 that end in the current bitwise AND value.
        dp[i] = (dp[i] + and_values[i]) % MOD;

        // Add the contribution from all subsequences of length 2 that end in the current bitwise AND value.
        for (int j = 0; j < i; j++)
        {
            if ((i & j) == j)
            {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    // cout << dp << endl;

    return dp[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << solve(a, k) << endl;
    }

    return 0;
}
