#include <iostream>
#include "funcs.h"

int main() {
    int N;

    std::cout<<"Enter an integer for n x n board: ";
    std::cin>> N;

    int board[N];
    //initialize the board
    for(int i = 0; i < N; i++){
        board[i] = -1;
    }

    if(eight_queens(0, board, N)){
        display(board, N);
    }
    else{
        std::cout<<"Impossible";
    }

}

