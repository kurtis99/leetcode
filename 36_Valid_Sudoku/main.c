#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>





/*
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int i, j;
    for (i = 0; i < boardSize; i++) {
        unsigned cols_bits = 0;
        unsigned rows_bits = 0;
        for (j = 0; j < boardSize; j++) {
            char cols = board[i][j];
            char rows = board[j][i];
            if (cols != '.') {
                cols -= '0';
                if (cols_bits & (1 << cols))
                    return false;
                cols_bits |= (1 << cols);
            }
            if (rows != '.') {
                rows -= '0';
                if (rows_bits & (1 << rows))
                    return false;
                rows_bits |= (1 << rows);
            }
        }
    }

    char koefs[][2] = {
       // x   y
        { 0,  0},

        { 0,  1},
        { 0, -1},
        { 1,  0},
        {-1,  0},

        { 1,  1},
        {-1, -1},
        {-1,  1},
        { 1, -1},
    };

    for (i = 1; i < boardSize; i += 3) {
        for (j = 1; j < boardSize; j += 3) {
            unsigned boxs_bits = 0;
            for (int k = 0; k < sizeof(koefs) / sizeof(koefs[0]); k++) {
                char *curr_k = koefs[k];
                char box = board[i + curr_k[0]][j + curr_k[1]];
                if (box == '.')
                    continue;
                box -= '0';
                if (boxs_bits & (1 << box))
                    return false;
                boxs_bits |= (1 << box);
            }
        }
    }

    return true; 
}

int main() {

    char board_1[9][9]   = { 
                            {'5','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'},
                         };
    char board_2[9][9]   = {
                            {'8','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'},
                         };

    int boardColSize = 9;
    int ret;

    char *pointers[9];
    for (int i = 0; i < 9; i++) {
        pointers[i] = board_1[i];
    }
    ret = isValidSudoku(pointers, 9, &boardColSize);
    printf("%d\n", ret);

    for (int i = 0; i < 9; i++) {
        pointers[i] = board_2[i];
    }
    ret = isValidSudoku(pointers, 9, &boardColSize);
    printf("%d\n", ret);

    return 0;
}
