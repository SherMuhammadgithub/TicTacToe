#include <iostream>
using namespace std;
void printBoard(char[][3]);
void printing_input(char[][3], string, int);
bool checkForWinner(int, char[][3]);
bool checkrows(char[][3], int);
bool checkColumns(char[][3], int);
bool checkdigonals(char[][3], int);
main()
{
    char board[3][3] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '};
    printBoard(board);
    int count = 0;
    string Prev;
    while (count < 9)
    {
    start:
        if (count % 2 == 0)
        {
            cout << "Player X turn" << endl;
        }
        else
        {
            cout << "Player O turn" << endl;
        }

        string input;
        cout << "Enter (A1, B1, C1 e.g.): ";
        cin >> input;
        if (Prev != input)
        {
            Prev = input;
            printing_input(board, input, count);
            system("cls");
            printBoard(board);
            bool result = checkForWinner(count, board);
            if (result)
            {
                if (count % 2 == 0)
                {
                    cout << "Winner is X" << endl;
                    break;
                }
                else
                {
                    cout << "Winner is O" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Already Entered!" << endl;
            goto start;
        }
        count++;
    }
    if (count == 9)
    {
        cout << "The Match has been drawn!";
    }
}
void printBoard(char arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void printing_input(char arr[][3], string input, int count)
{
    int character, num;
    character = input[0] - 65;
    num = input[1] - 49;
    if (count % 2 == 0)
    {
        arr[character][num] = 'X';
    }
    else
    {
        arr[character][num] = 'O';
    }
}
bool checkForWinner(int count, char arr[][3])
{
    if (checkrows(arr, count) || checkColumns(arr, count) || checkdigonals(arr, count))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkrows(char arr[][3], int count)
{
    int counter = 0;
    for (int rows = 0; rows < 3; rows++)
    {
        counter = 0;
        for (int cols = 0; cols < 3; cols++)
        {
            if (count % 2 == 0) // if even check for X only
            {
                if (arr[rows][cols] == 'X')
                {
                    counter++;
                }
            }
            else // if Odd check for O only
            {
                if (arr[rows][cols] == 'O')
                {
                    counter++;
                }
            }
        }
        if (counter == 3)
        {
            return true;
        }
    }
    return false;
}
bool checkColumns(char arr[][3], int count)
{
    int counter = 0;
    for (int cols = 0; cols < 3; cols++)
    {
        counter = 0;
        for (int rows = 0; rows < 3; rows++)
        {
            if (count % 2 == 0) // if even check for X only
            {
                if (arr[rows][cols] == 'X')
                {
                    counter++;
                }
            }
            else // if Odd check for O only
            {
                if (arr[cols][rows] == 'O')
                {
                    counter++;
                }
            }
        }
        if (counter == 3)
        {
            return true;
        }
    }
    return false;
}
bool checkdigonals(char arr[][3], int count)
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        if (count % 2 == 0)
        {
            if (arr[i][i] == 'X')
            {
                counter++;
            }
        }
        else
        {
            if (arr[i][i] == 'O')
            {
                counter++;
            }
        }
    }
    if (counter == 3)
    {
        return true;
    }

    counter = 0;
    for (int rows = 0, cols = 2; rows < 3; rows++, cols--)
    {
        if (count % 2 == 0)
        {
            if (arr[rows][cols] == 'X')
            {
                counter++;
            }
        }
        else
        {
            if (arr[rows][cols] == 'O')
            {
                counter++;
            }
        }
    }
    if (counter == 3)
    {
        return true;
    }

    return false;
}