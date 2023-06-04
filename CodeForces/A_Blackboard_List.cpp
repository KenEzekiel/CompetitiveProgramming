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

void solve(vi a) {
    int max = 0;
    for (auto i : a) {
        if (i < 0) {
            cout << i << endl;
            return;
        }
        if (i > max) {
            max = i;
        }
    }
    cout << max << endl;
    return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

    int t;

  cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a;
        while(n--) {
            int temp;
            cin >> temp;
            a.PB(temp);
        }

        solve(a);
    }


  return 0;
}