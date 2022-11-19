#include <iostream>
#include "stddef.h"
#include "geesespotter_lib.h"

// Function Definitions For "EarlyGeeseSpotter" Assignment - Harry Wang - ECE 150 Project 3, Part 1
// ______________________________________________________________________________________________________________________________________
// 5 Functions Total = createBoard, hideBoard, cleanBoard, printBoard, and mark
// ______________________________________________________________________________________________________________________________________
// No clue if it's meant to be like this but I kept the order of the functions given in the files despite the fact that the order that 
// the functions are given don't really make logical sense. It's ok thought since these are function definitions so the order don't 
// really matter that much.

char * createBoard(std::size_t xdim, std::size_t ydim);
// use xdim and ydim to create a board of that size for the game to be able to start
// create arrays from the elements in the game and set size of the array using (xdim * ydim)
//return the elements in the game so to use it in other parts of the program
char * createBoard(std::size_t xdim, std::size_t ydim){
    int size_of_array = (xdim * ydim);
    char *element_in_game = 0;
    element_in_game = new char[size_of_array]{};
    return element_in_game; 
}


void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim);
// not technically one of the functions that I have to define for this portion of the project but must be included so that the code can run in Marmoset
void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){
    int xloc = 0;
    int yloc = 0;
    int position = 0;
    for ( int j = 0 ; j < (ydim * xdim); j++){
        if ( (board[j] & valueMask()) == 9 ){
            yloc = j/xdim;
            xloc = j%xdim;
 
            if ( xloc < (xdim - 1)){
                position = (xloc + 1) + yloc*xdim;
                if (board[position] != 9){
                    board[position]++;
                }
            }
            
            if (xloc >= 1){
                position = (xloc - 1) + yloc*xdim;
                if (board[position] != 9){
                    board[position]++;
                }
            }    

            if (yloc > 0){
                    position = xloc + (yloc - 1)*xdim;
                    if (board[position] != 9){
                        board[position]++;
                    } 
                    if (xloc > 0){
                        position = xloc - 1 + (yloc - 1)*xdim;
                        if (board[position] != 9){
                            board[position]++;
                        }
                    }
                    if (xloc < (xdim - 1)){
                        position = xloc + 1 + (yloc - 1)*xdim;
                        if (board[position] != 9){
                            board[position]++;
                        }
                    }
                }

            if (yloc < (ydim - 1)){
                position = xloc + (yloc + 1)*xdim;
                if(board[position] != 9){
                    board[position]++;
                }


                if (xloc > 0){
                    position = xloc - 1 + (yloc + 1)*xdim;
                    if (board[position] != 9){
                        board[position]++;
                    }
                }
                if (xloc < (xdim -1)){
                    position = xloc + 1 + (yloc + 1)*xdim;
                    if (board[position] != 9){
                        board[position]++;
                    }
                }
            }

                
        }
    }              
}
    


void hideBoard(char * board, std::size_t xdim, std::size_t ydim);
// hiding the values within the xdim * ydim board so that you can't see the numbers under the board
// iterates through the board (xdim * ydim) and then assigns a hidden value at the positions on the baord
void hideBoard(char * board, std::size_t xdim, std::size_t ydim){
    for(int position_on_board{0}; position_on_board < (xdim * ydim); position_on_board++){
        board[position_on_board] = board[position_on_board] | hiddenBit();
    }
}


void cleanBoard(char * board);
// deallocate the borad using pointers and delete and null
// first delete the board array and then allocate it to the nullptr so that the array can no longer be called
void cleanBoard(char * board){
    delete[] board;
    board = nullptr;
} 

int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
// Again, this function isn't needed to be defined but must be included for code to successfully run
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    int position = (xdim)*(yloc -1) - (xdim - xloc);
    int calculate_position = 0;

     if ((board[position] & markedBit()) == markedBit()){
        return 1;
    } else if ((board[position] & hiddenBit()) != hiddenBit()){
        return 2;
    } else if (board[position] == 9){
        board[position] &= ~hiddenBit();
        return 9;
    } else if ((board[position] & valueMask()) == 0){
        if ( xloc >= 1){
            calculate_position = (xloc -1) + yloc*xdim;
            if (board[calculate_position] != 9){
                board[calculate_position] &= ~hiddenBit();
            }
        }
        if (xloc < (xdim - 1)){
            calculate_position = (xloc + 1) + yloc*xdim;
            if (board[calculate_position] != 9){
                board[calculate_position] &= ~hiddenBit();
            }
        }


        if (yloc < (ydim - 1)){
            calculate_position = xloc + (yloc + 1)*xdim;
            if (board[calculate_position] != 9){
                board[calculate_position] &= ~hiddenBit();
            }
            if (xloc > 0){
                calculate_position = xloc - 1 + (yloc + 1)*xdim;
                if (board[calculate_position] != 9){
                    board[calculate_position] &= ~hiddenBit();
                }
            }
            if (xloc < (xdim - 1)){
                calculate_position = xloc + 1 + (yloc + 1)*xdim;
                if(board[calculate_position] !=9){
                    board[calculate_position] &= ~hiddenBit();
                }
            }
            
        }


        if (yloc > 0){
            calculate_position = xloc + (yloc - 1)*xdim;
            if (board[calculate_position] != 9){
                board[calculate_position] &= ~hiddenBit();
            }
            if (xloc > 0){
                calculate_position = xloc - 1 + (yloc -1)*xdim;
                if (board[calculate_position] != 9){
                    board[calculate_position] &= ~hiddenBit();
                }
            }
            if (xloc < (xdim - 1)){
                calculate_position = xloc + 1 + (yloc -1)*xdim;
                if (board[calculate_position] != 9){
                    board[calculate_position] &= ~hiddenBit();
                }
            }
        }
    }


    board[position] &= ~hiddenBit();
    return 0;

}


int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
// if the same spot is pressed twice, it doesn't change
// after the game is over, the borad resets back to 0 and restarts
int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    int element_in_game = ((yloc  + 1) * xdim - (xdim - (xloc)));
    if (!board[element_in_game] & hiddenBit()){
        return 2;
    } else {
        board[element_in_game] = (board[element_in_game] ^ markedBit());
        return 0;
    }
}


bool isGameWon(char * board, std::size_t xdim, std::size_t ydim);
// Last one that isn't neccessarily included in the functions I need to define but must be included so that the code will, in it's entirety, run
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){
    
    for (int j = 0; j < (xdim*ydim) ; j++ ){
        
        if ((((board[j] & hiddenBit()) == hiddenBit()) && ((board[j] & valueMask()) != 9))) {
            return false;
        } else if (((board[j] & hiddenBit()) != hiddenBit()) && ((board[j] & valueMask()) == 9)){
            return false;
        }
    }
    
    return true;
}

void printBoard(char * board, std::size_t xdim, std::size_t ydim);
// printing the number(values) that are corresponding to number of geese surrounding the space
// iterate through each of the positions on the board for all the x's and y's that the user inputs to the program
// for marked positions, the code will print out an "M", while in positions that are hidden, the program will print out an asterix in that position
void printBoard(char * board, std::size_t xdim, std::size_t ydim){
        int element_in_game = 0;
    for (int x_spot_value{0}; x_spot_value < xdim; x_spot_value++){
        for (int y_spot_value{0}; y_spot_value < ydim; y_spot_value++){
            if (board[element_in_game] & markedBit()){
                std::cout << "M" ;
            } else if (board[element_in_game] & hiddenBit()){
                std::cout << "*" ;
            } else {
                std::cout << (board[element_in_game] & valueMask());
            }
            element_in_game++; 
        }
        std::cout << std::endl;
    }
}