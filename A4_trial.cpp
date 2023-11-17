#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<int>>& board) {
    for ( auto row : board) {
        for (int value : row) {
            cout << value << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

bool isSafe(vector<vector<int>>& board,int row,int col,int n){
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

bool solveNQueensUtil(vector<vector<int>>& board,int col,int n){
    if(col>=n){
        printSolution(board);
        return true;
    }
    bool res=false;
    for(int i=0;i<n;i++){
        if(isSafe(board,i,col,n)){
            board[i][col]=1;
            res=solveNQueensUtil(board,col+1,n) || res;
            board[i][col]=0;
        }
    }
    return res;
}

void solveNQueens(int firstQueenRow, int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    board[firstQueenRow][0]=1;
    solveNQueensUtil(board,1,n);
}

int main(){
    int n;
    cin>>n;
    int firstQueenRow;
    cin>>firstQueenRow;
    solveNQueens(firstQueenRow,n);

    return 0;
}