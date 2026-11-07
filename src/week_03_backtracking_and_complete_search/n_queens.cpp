#include <iostream>
#include <string>
#include <vector>
using namespace std;

void place(int row, int n, vector<bool>& columns, vector<bool>& diagonals, vector<bool>& antiDiagonals,
           vector<int>& queens, vector<vector<int>>& solutions)
{
    if (row == n)
    {
        solutions.push_back(queens);
        return;
    }

    for (int column = 0; column < n; column++)
    {
        int diagonal = row - column + n - 1;
        int antiDiagonal = row + column;

        if (columns[column] || diagonals[diagonal] || antiDiagonals[antiDiagonal])
            continue;

        columns[column] = diagonals[diagonal] = antiDiagonals[antiDiagonal] = true;
        queens.push_back(column);

        place(row + 1, n, columns, diagonals, antiDiagonals, queens, solutions);

        queens.pop_back();
        columns[column] = diagonals[diagonal] = antiDiagonals[antiDiagonal] = false;
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> solutions;
    vector<int> queens;
    vector<bool> columns(n, false);
    vector<bool> diagonals(2 * n - 1, false);
    vector<bool> antiDiagonals(2 * n - 1, false);

    place(0, n, columns, diagonals, antiDiagonals, queens, solutions);
    return solutions;
}

void printBoard(const vector<int>& queens)
{
    int n = queens.size();
    for (int row = 0; row < n; row++)
        cout << string(queens[row], '.') << 'Q' << string(n - queens[row] - 1, '.') << endl;
}

int main()
{
    vector<vector<int>> solutions = solveNQueens(4);

    cout << "Solutions for n = 4: " << solutions.size() << endl;
    printBoard(solutions[0]);

    cout << "Solutions for n = 6: " << solveNQueens(6).size() << endl;
    cout << "Solutions for n = 8: " << solveNQueens(8).size() << endl;
}
