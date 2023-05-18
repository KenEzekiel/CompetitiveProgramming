#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    vector<vector<char>> transpose(vector<vector<char>> &b)
    {
        if (b.size() == 0)
            return b;

        vector<vector<char>> trans_vec(b[0].size(), vector<char>());

        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j < b[i].size(); j++)
            {
                trans_vec[j].push_back(b[i][j]);
            }
        }

        return trans_vec;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Check row
        // std::cout << "Checking row" << std::endl;
        for (int i = 0; i < board.size(); i++)
        {
            vector<char> line = board[i];
            set<char> rownums;

            for (int j = 0; j < line.size(); j++)
            {
                char c = line[j];
                if (rownums.find(c) != rownums.end())
                {
                    return false;
                }
                if (c != '.')
                {
                    rownums.insert(c);
                }
            }
        }

        vector<vector<char>> trans = transpose(board);

        // Check column
        // std::cout << "Checking column" << std::endl;
        for (int i = 0; i < trans.size(); i++)
        {
            vector<char> line = trans[i];
            set<char> rownums;

            for (int j = 0; j < line.size(); j++)
            {
                char c = line[j];
                if (rownums.find(c) != rownums.end())
                {
                    return false;
                }
                if (c != '.')
                {
                    rownums.insert(c);
                }
            }
        }

        // Check subsquare
        // 9 subsquare
        // std::cout << "Checking submatrix" << std::endl;
        for (int i = 1; i < 8; i += 3)
        {
            for (int j = 1; j < 8; j += 3)
            {
                set<char> subnums;
                for (int l = -1; l < 2; l++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        char c = board[i + l][j + m];
                        std::cout << c << " ";
                        if (subnums.find(c) != subnums.end())
                        {
                            return false;
                        }
                        if (c != '.')
                        {
                            subnums.insert(c);
                        }
                    }
                }
                std::cout << std::endl;
            }
        }
        return true;
    }
    // 0ms
    // bool isValidSudoku(vector<vector<char> > &board)
    // {
    //     int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

    //     for(int i = 0; i < board.size(); ++ i)
    //         for(int j = 0; j < board[i].size(); ++ j)
    //             if(board[i][j] != '.')
    //             {
    //                 int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
    //                 if(used1[i][num] || used2[j][num] || used3[k][num])
    //                     return false;
    //                 used1[i][num] = used2[j][num] = used3[k][num] = 1;
    //             }

    //     return true;
    // }
};

int main()
{
    vector<vector<char>> board;

    char matrix[9][9]{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (int i = 0; i < 9; i++)
    {
        vector<char> v;
        for (int j = 0; j < 9; j++)
        {
            v.push_back(matrix[i][j]);
        }
        board.push_back(v);
    }

    Solution solution;
    std::cout << solution.isValidSudoku(board) << endl;
    return 0;
}
