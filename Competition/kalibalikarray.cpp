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

void print(vi arr) {
  cout << "Array adalah ";
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vi arr = vi();
  for (int i = 0; i < 2*n; i++) {
    int elmt;
    cin >> elmt;
    arr.PB(elmt);
  }

//   print(arr);

  int nOp;
  cin >> nOp;

  for (int i = 0; i < nOp; i++) {
    int op;
    cin >> op;
    if (op == 1) {
        int elNum;
        cin >> elNum;
        cout << arr[elNum-1] % 998244353 << endl;
    }
    else if (op == 2) {
        int d;
        cin >> d;
        for (int j = n - d; j < n + d; j++) {
            arr[j] = arr[j] * 2;
        }
        reverse(arr.begin(), arr.end());
        // print(arr);
    } else {
        break;
    }
  }



  return 0;
}