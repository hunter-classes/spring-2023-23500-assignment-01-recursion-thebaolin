#include <iostream>
using namespace std;

//returns whether spot at r and c is safe or not
bool is_safe(int* board, int curr_row, int curr_col, int N){

    //check in same col
    for (int i = 0; i < curr_row; i++) {
        if (board[i] == curr_col) {
            return false;
        }
    }

    //check diagonal up-left
    for (int i = curr_row, j = curr_col; i >= 0 && j >= 0; i--, j--) {
        if (board[i] == j) {
            return false;
        }
    }

    //check diagonal down-left
    for (int i = curr_row, j = curr_col; i >= 0 && j < N; i--, j++) {
        if (board[i] == j) {
            return false;
        }
    }

    return true;
}

bool eight_queens(int curr_row, int* board, int N){

    //solved, all queens have been placed
    if (curr_row == N){
        return true;
    }

    //try each col in curr_row
    for (int curr_col = 0; curr_col < N; curr_col++) {
        if (is_safe(board, curr_row, curr_col, N)) {

            //place queen
            board[curr_row] = curr_col;

            //try placing the remaining queenz
            if(eight_queens(curr_row + 1, board, N)){
                return true;
            }

            ///backtracking, removing queen at this spot
            board[curr_row] = -1;
        }
    }

    //tried all cols, nothing worked :(
    return false;
}

//display the board!
void display(int* board, int N){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i] == j){
                cout<<"Q ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int N;

    cout<<"Enter an integer for n x n board: ";
    cin>> N;

    int board[N];
    for(int i = 0; i < N; i++){
        board[i] = -1;
    }

    if(eight_queens(0, board, N)){
        display(board, N);
    }
    else{

    }


}

