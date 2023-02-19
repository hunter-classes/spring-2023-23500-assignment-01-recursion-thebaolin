#include <iostream>
using namespace std;

// is_safe(int row, int col) will return whether or not the spot at [row][col] (of the N by N board)
// does not have a 1 in the same row to its left, diagonal up-left, and diagonal down-left.
// Returns true if it's all 0s, false if there's any occurrences of 1.

//global
const int N = 10;
int board[N][N] = {};

void reset(){
   for(int i=0; i < N; i++){
       for(int j=0; j<N; j++){
           board[i][j] = 0;
       }
   }
}

int tempBoard [4][4] = {{1,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}};
int tempN = 4;

bool is_safe(int tempBoard[4][4], int curr_row, int curr_col){

   //Check the all spots Left of current_row, current_col
    for(int c = curr_col; c >= 0; c--){
        if(tempBoard[curr_row][c] == 1){
            return false;
        }
    }

   //Check the all spots Up-Left of current_row, current_col
    for(int r = curr_row, c = curr_col; r >= 0 && c >= 0; r--, c--){
        if(tempBoard[r][c] == 1){
            return false;
        }
    }

   //Check the all spots Down-Left of current_row, current_col
    for(int r = curr_row, c = curr_col; c >= 0 && r < tempN; r++, c--){
        if(tempBoard[r][c] == 1){
            return false;
        }
    }
   return true;
}

void eight_queens(){

}
void display(){
   for(int i=0; i < tempN; i++){
       for(int j=0; j<tempN; j++){
           if(tempBoard[i][j] == 0){
               cout << "_ ";
           }
           else{
               cout << "Q ";
           }
       }
       cout << endl;
   }
}

int main() {
   //reset();
   display();
   cout << boolalpha << is_safe(tempBoard, 0, 3);
}

