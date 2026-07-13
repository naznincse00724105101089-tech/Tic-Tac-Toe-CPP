#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
}

bool checkWin(char p)
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p)
            return true;

        if(board[0][i]==p && board[1][i]==p && board[2][i]==p)
            return true;
    }

    if(board[0][0]==p && board[1][1]==p && board[2][2]==p)
        return true;

    if(board[0][2]==p && board[1][1]==p && board[2][0]==p)
        return true;

    return false;
}

void move(int pos,char p)
{
    int r=(pos-1)/3;
    int c=(pos-1)%3;

    if(board[r][c]!='X' && board[r][c]!='O')
        board[r][c]=p;
    else
        cout<<"Position already taken!\n";
}

int main()
{
    int pos;

    for(int i=1;i<=9;i++)
    {
        displayBoard();

        if(i%2!=0)
        {
            cout<<"Player X, Enter Position: ";
            cin>>pos;
            move(pos,'X');

            if(checkWin('X'))
            {
                displayBoard();
                cout<<"Player X Wins!\n";
                return 0;
            }
        }
        else
        {
            cout<<"Player O, Enter Position: ";
            cin>>pos;
            move(pos,'O');

            if(checkWin('O'))
            {
                displayBoard();
                cout<<"Player O Wins!\n";
                return 0;
            }
        }
    }

    displayBoard();
    cout<<"Match Draw!\n";

    return 0;
}
