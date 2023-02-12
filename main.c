#include <stdio.h>
#include <stdlib.h>
#include "life.h"



int main(int argc, char* argv[])
{
    int time_steps = atoi(argv[1]);
    int game_size = atoi(argv[2]);
    int start = atoi(argv[3]);

    int game_board[game_size];
    int i, j;

    // initialize the game board
    for (i = 0; i < game_size; i++)
    {
        game_board[i] = start;
    }

    // print initial game board
    printf("Initial Game Board:\n");
    for (i = 0; i < game_size; i++)
    {
        printf("%d ", game_board[i]);
    }
    printf("\n");

    // run the game for time_steps
    for (i = 0; i < time_steps; i++)
    {
        int new_board[game_size];

        // calculate new board based on isAlive and shouldDie functions
        for (j = 0; j < game_size; j++)
        {
            if (isAlive(game_board, j, game_size))
            {
                if (shouldDie(game_board, j, game_size))
                {
                    new_board[j] = 0;
                }
                else
                {
                    new_board[j] = 1;
                }
            }
            else
            {
                if (hasTwoLiveNeighbors(game_board, j, game_size))
                {
                    new_board[j] = 1;
                }
                else
                {
                    new_board[j] = 0;
                }
            }
        }

        // update the game board with the new values
        for (j = 0; j < game_size; j++)
        {
            game_board[j] = new_board[j];
        }

        // print game board after each step
        printf("Game Board after step %d:\n", i + 1);
        for (j = 0; j < game_size; j++)
        {
            printf("%d ", game_board[j]);
        }
        printf("\n");
    }

    return 0;
}
