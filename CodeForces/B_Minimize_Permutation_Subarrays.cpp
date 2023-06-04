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

void solve(vi a, int max) {
    // Using two pointers method
    for (auto el : a) {
        cout << el << " ";
    }
    cout << endl;
    int n = a.size() - 1;
    int i = 0;
    int it1, it2;
    int mindiff = max;
    int dist = 0;
    int cnt = 0;

    while (i < n) {
        int diff = abs(a[i] - a[n]);
        cout << "diff " << diff << endl;
        if (diff <= mindiff) {
            int isTrue = 0;
            if (diff == mindiff) {
                if (abs(i - n) > dist) {
                    isTrue++;
                } 
            } else {
                isTrue++;
                cnt++;
            }
            if (isTrue) {
                it1 = i;
                it2 = n;
                mindiff = diff;
                dist = abs(i - n);
                
                cout << "it1 " << it1 << " it2 " << it2 << " mindiff " << mindiff << " dist " << dist << endl;
            } else {
                cout << "not true" << endl;
            }
            
        } else {
            cnt++;
        }

        int idiff = abs(a[i] - a[i+1]);
        int ndiff = abs(a[n] - a[n-1]);

        if (idiff >= ndiff) {
            cout << "i++" << endl;
            i++;
        } else {
            cout << "n--" << endl;
            n--;
        }


    }

    float threshold = ((float) a.size())/2;
    if (cnt <= threshold) {
        cout << "1 1 aaa " << cnt << " " << threshold << endl;
    } else {
        cout << it1+1 << " " << it2+1 << endl;
    }
    
    

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
// Mau jauhin element yang difference nya paling kecil

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a;
        int max = 0;
        while(n--) {
            int temp;
            cin >> temp;
            if (temp > max) {
                max = temp;
            }
            a.PB(temp);
        }

        solve(a, max);
    }

  return 0;
}