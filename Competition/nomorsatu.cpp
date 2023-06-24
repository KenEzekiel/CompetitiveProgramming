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

void print(vector<vector<char>> map) {
    for (auto line : map) {
        for (auto c : line) {
            cout << c;
        }
        cout << endl;
    }
}

void transformSurroundToWater(vector<vector<char>> map, int i, int j, int n, int m) {
    if (i > 0 && map[i-1][j] == '.') {
        map[i-1][j] = 'X';
    }
    if (i < n-1 && map[i+1][j] == '.') {
        map[i+1][j] = 'X';
    }
    if (j > 0 && map[i][j-1] == '.') {
        map[i][j-1] = 'X';
    }
    if (j < m-1 && map[i][j+1] == '.') {
        map[i][j+1] = 'X';
    }
}

void solve(vector<vector<char>> map, int n, int m) {
    int count = 0;
    float max_affected = 0;
    for (int k = 0; k < 3; k++) {

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool hasWater = false;
            if (map[i][j] == '#') {
                continue;
            } else if (map[i][j] == '.') {
                // cek atas
                if (i > 0) {
                    if (map[i-1][j] == 'O') {
                        hasWater = true;
                    }
                }
                // cek bawah
                if (i < n-1) {
                    if (map[i+1][j] == 'O') {
                        hasWater = true;
                    }
                }

                // cek kiri
                if (j > 0) {
                    if (map[i][j-1] == 'O') {
                        hasWater = true;
                    }
                }

                // cek kanan
                if (j < m-1) {
                    if (map[i][j+1] == 'O') {
                        hasWater = true;
                    }
                }
            }
            if (k > 0) {
                if (hasWater) {
                    map[i][j] = 'X';
                }
            }

        }

        for (int j = 0; j < m; j++) {
            float affected = 0;
            bool hasWater = false;
            if (map[i][j] == '#') {
                continue;
            } else if (map[i][j] == '.') {
                // cek atas
                if (i > 0) {
                    if (map[i-1][j] == '.' ) {
                        affected++;
                    } else if (map[i-1][j] == 'O') {
                        hasWater = true;
                    }
                }

                // cek bawah
                if (i < n-1) {
                    if (map[i+1][j] == '.' ) {
                        affected++;
                    } else if (map[i+1][j] == 'O') {
                        hasWater = true;
                    }
                }

                // cek kiri
                if (j > 0) {
                    if (map[i][j-1] == '.' ) {
                        affected++;
                    } else if (map[i][j-1] == 'O') {
                        hasWater = true;
                    }
                }

                // cek kanan
                if (j < m-1) {
                    if (map[i][j+1] == '.' ) {
                        affected++;
                    } else if (map[i][j+1] == 'O') {
                        hasWater = true;
                    }
                }
            }

            if (max_affected < affected) {
                max_affected = affected;
            }
            
            if (k > 0) {
                cout << "Sebelum " << endl;
                print(map);
                if (hasWater) {
                    map[i][j] = 'X';
                }
                else if (affected == max_affected) {
                    map[i][j] = 'O';
                } else if (k > 1 && map[i][j] == '.') {
                    map[i][j] = 'O';
                }
                cout << "Sesudah " << endl;
                print(map);
            }
            
        }
    }
    }
    print(map);
}

int countDot(vector<vector<char>> map) {
    int count = 0;
    for (auto line : map) {
        for (auto c : line) {
            if (c == '.') {
                count++;
            }
        }
    }
    return count;
}

int countX(vector<vector<char>> map) {
    int count = 0;
    for (auto line : map) {
        for (auto c : line) {
            if (c == 'X') {
                count++;
            }
        }
    }
    return count;
}

void solve2(vector<vector<char>> map, int n, int m, int threshold) {
 // g total X
 // h total .
 // g + h max
 // prune : g + h <= g sebelumnya
 
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n;
  cin >> m;


  vector<vector<char>> map = vector<vector<char>>();

  for (int i = 0; i < n; i++) {
    vector<char> vc = vector<char>();
    for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        vc.PB(c);
    }
    map.PB(vc);
  }

  solve2(map, n, m, countDot(map));

//   print(map);


  return 0;
}