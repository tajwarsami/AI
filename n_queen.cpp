#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int> >& board, int row, int col, int N)
{
    for (int x = 0; x < col; x++)
        if (board[row][x] == 1)
            return false;
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
        if (board[x][y] == 1)
            return false;
    for (int x = row, y = col; x < N && y >= 0; x++, y--)
        if (board[x][y] == 1)
            return false;
    return true;
}

bool solveNQueens(vector<vector<int> >& board, int col, int N)
{
    if (col == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, N))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int N;
    cout << "Enter the number of queens (and board size): ";
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    if (!solveNQueens(board, 0, N))
        cout << "No solution found";
    return 0;
}
