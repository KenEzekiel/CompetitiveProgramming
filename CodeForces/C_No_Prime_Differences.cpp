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

bool is_prime(int n)
{
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  int root = sqrt(n);
  REP(i, 2, root + 1)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    if (!is_prime(m))
    {
      REP(i, 0, n)
      {
        REP(j, 0, m)
        {
          cout << i * m + j + 1 << " ";
        }
        cout << "\n";
      }
    }
    else if (!is_prime(n))
    {
      REP(i, 0, n)
      {
        REP(j, 0, m)
        {
          cout << j * n + i + 1 << " ";
        }
        cout << "\n";
      }
    }
    else
    {
      int shift = 0;
      REP(i, 0, n)
      {
        REP(j, 0, m)
        {
          int num = i * m + j + 1 + shift;
          if (num > (i + 1) * m)
          {
            num -= m;
          }
          cout << num << " ";
        }
        shift++;
        if (shift == m)
        {
          shift = 0;
        }
        cout << "\n";
      }
    }
  }
  return 0;
}