#include <stdio.h>
#define N 4
int board[N][N];
int col[N] = {0};
int diag1[2*N] = {0};
int diag2[2*N] = {0};

int solutionCount = 0;

void printBoard() {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("V ");
            else if (board[i][j] == -1)
                printf("X ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        printBoard();
        return;
    }

    for (int c = 0; c < N; c++) {

        if (board[row][c] == -1)
            continue;

        if (col[c] || diag1[row + c] || diag2[row - c + N - 1])
            continue;

        board[row][c] = 1;
        col[c] = diag1[row + c] = diag2[row - c + N - 1] = 1;

        solve(row + 1);

        board[row][c] = 0;
        col[c] = diag1[row + c] = diag2[row - c + N - 1] = 0;
    }
}

int main() {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Blocked cells
    board[1][1] = -1;
    board[2][2] = -1;

    solve(0);

    if (solutionCount == 0)
        printf("No valid solutions\n");

    return 0;
}