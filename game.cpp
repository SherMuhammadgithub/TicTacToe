#include <iostream>
#include <windows.h>
using namespace std;
void printBoard(char[][3]);
void printing_input(char[][3], string, int);
bool checkForWinner(int, char[][3]);
bool checkrows(char[][3], int);
bool checkColumns(char[][3], int);
bool checkdigonals(char[][3], int);
bool ch3ckValidInput(string);
bool checkForPrevInput(string, char[][3]);
main()
{
    char board[3][3] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '};
    int count = 0;
    string input;
    string Prev;
    while (count < 9)
    {
    start:
        system("cls");
        printBoard(board);
        if (count % 2 == 0)
        {
            cout << "Player X turn" << endl;
        }
        else
        {
            cout << "Player O turn" << endl;
        }
        cout << "Enter (A1, B1, C1 e.g.): ";
        cin >> input;
        if (checkForPrevInput(input, board))
        {
            if (ch3ckValidInput(input))
            {
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
                cout << "Invalid Input!" << endl;
                Sleep(1000);
                system("cls");
                goto start;
            }
        }
        else
        {
            cout << "Already Entered!" << endl;
            Sleep(1000);
            system("cls");
            goto start;
        }
        count++;
    }
    if (count == 9)
    {
        cout << "The Match has been drawns!";
    }
}
void printBoard(char arr[][3])
{
    cout << "   1   2   3" << endl;
    cout << "A  " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "B  " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "C  " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
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
bool ch3ckValidInput(string input)
{
    if (input.length() == 2)
    {
        if (input[0] == 'A' || input[0] == 'B' || input[0] == 'C')
        {
            if (input[1] == '1' || input[1] == '2' || input[1] == '3')
            {
                return true;
            }
        }
    }
    return false;
}
bool checkForPrevInput(string input, char arr[][3])
{
    int character, num;
    character = input[0] - 65;
    num = input[1] - 49;
    if (arr[character][num] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
