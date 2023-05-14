#include <iostream>
#include "game_of_life.h"

using namespace std;

bool game_of_life::random_value(int i)
{
    return rand()%100+1<=i;
}

bool game_of_life::cell_taken(int i, int j)
{
    return _generation[i][j];
}

int game_of_life::neighbours_of_cell(int i, int j)
{
    int neighbours = 0;
    if (i == 0 && j == 0) //top left
    {
        if (_generation[0][1])
        {
            neighbours++;
        }
        if (_generation[1][0])
        {
            neighbours++;
        }
        if (_generation[1][1])
        {
            neighbours++;
        }
    }
    else if (i == ROWS - 1 && j == 0) //bottom left
    {
        if (_generation[i][1])
        {
            neighbours++;
        }
        if (_generation[i - 1][0])
        {
            neighbours++;
        }
        if (_generation[i - 1][1])
        {
            neighbours++;
        }
    }
    else if (i == ROWS - 1 && j == COLS - 1) //bottom right
    {
        if (_generation[i][j - 1])
        {
            neighbours++;
        }
        if (_generation[i - 1][j])
        {
            neighbours++;
        }
        if (_generation[i - 1][j - 1])
        {
            neighbours++;
        }
    }
    else if (i == 0 && j == COLS - 1) //top right
    {
        if (_generation[0][j - 1])
        {
            neighbours++;
        }
        if (_generation[1][j])
        {
            neighbours++;
        }
        if (_generation[1][j - 1])
        {
            neighbours++;
        }
    }
    else if (j == 0) //left middle
    {
        if (_generation[i - 1][0])
        {
            neighbours++;
        }
        if (_generation[i - 1][1])
        {
            neighbours++;
        }
        if (_generation[i][1])
        {
            neighbours++;
        }
        if (_generation[i + 1][1])
        {
            neighbours++;
        }
        if (_generation[i + 1][0])
        {
            neighbours++;
        }
    }
    else if (i == 0) //top middle
    {
        if (_generation[0][j - 1])
        {
            neighbours++;
        }
        if (_generation[1][j - 1])
        {
            neighbours++;
        }
        if (_generation[1][j])
        {
            neighbours++;
        }
        if (_generation[1][j + 1])
        {
            neighbours++;
        }
        if (_generation[0][j + 1])
        {
            neighbours++;
        }
    }
    else if (j == COLS - 1) //right middle
    {
        if (_generation[i - 1][j])
        {
            neighbours++;
        }
        if (_generation[i - 1][j - 1])
        {
            neighbours++;
        }
        if (_generation[i][j - 1])
        {
            neighbours++;
        }
        if (_generation[i + 1][j - 1])
        {
            neighbours++;
        }
        if (_generation[i + 1][j])
        {
            neighbours++;
        }
    }
    else if (i == ROWS - 1) //bottom middle
    {
        if (_generation[i][j - 1])
        {
            neighbours++;
        }
        if (_generation[i - 1][j - 1])
        {
            neighbours++;
        }
        if (_generation[i - 1][j])
        {
            neighbours++;
        }
        if (_generation[i - 1][j + 1])
        {
            neighbours++;
        }
        if (_generation[i][j + 1])
        {
            neighbours++;
        }
    }
    else //middle
    {
        if (_generation[i - 1][j - 1])
        {
            neighbours++;
        }
        if (_generation[i - 1][j])
        {
            neighbours++;
        }
        if (_generation[i - 1][j + 1])
        {
            neighbours++;
        }
        if (_generation[i][j - 1])
        {
            neighbours++;
        }
        if (_generation[i][j + 1])
        {
            neighbours++;
        }
        if (_generation[i + 1][j - 1])
        {
            neighbours++;
        }
        if (_generation[i + 1][j])
        {
            neighbours++;
        }
        if (_generation[i + 1][j + 1])
        {
            neighbours++;
        }
    }
    return neighbours;
}

game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (random_value(25))
            {
                _generation[i][j] = true;
            }
            else
            {
                _generation[i][j] = false;
            }
        }
    }
}

game_of_life::game_of_life(int probability)
{
    reset(probability);
}

void game_of_life::next_generation()
{
    for (int y = 0; y < ROWS; y++) 
    {
        for (int x = 0; x < COLS; x++) //x=left/right, y=top/bottom
        {
            if (cell_taken(y, x)) //old
            {
                if (neighbours_of_cell(y, x) < 2 || neighbours_of_cell(y, x) > 3)
                {
                    _next_generation[y][x] = false;
                }
                else
                {
                    _next_generation[y][x] = true;
                }
            }
            else //new
            {
                if (neighbours_of_cell(y, x) == 3)
                {
                    _next_generation[y][x] = true;
                }
                else
                {
                    _next_generation[y][x] = false;
                }
            }
        }
    }
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++) //x=left/right, y=top/bottom
        {
            _generation[y][x] = _next_generation[y][x];
        }
    }
}

void game_of_life::draw()
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            if (_generation[y][x])
            {
                cout << "*";
            }
            else
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}

void game_of_life::reset(int probability)
{

    srand(time(nullptr));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (random_value(probability))
            {
                _generation[i][j] = true;
            }
            else
            {
                _generation[i][j] = false;
            }
        }
    }
}
