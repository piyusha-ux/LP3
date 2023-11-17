#include <iostream>
#include <vector>

void printSolution(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(std::vector<std::vector<int>>& board, int col, int n) {
    if (col >= n) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; 
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQueens(int firstQueenRow, int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    board[firstQueenRow][0] = 1;
    solveNQueensUtil(board, 1, n);
}

int main() {
    int n = 4;
    int firstQueenRow = 2;

    solveNQueens(firstQueenRow, n);
    return 0;
}
