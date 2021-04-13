#include <iostream>
using namespace std;
void printBoard(char Board[8][8])
{
    static int kase = 0;
    kase++;
    cout << endl << "Case: " << kase << endl;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout << Board[i][j];
        }
        cout << endl;
    }
}
void placeQueen(char Board[8][8], int row, int colMask, int rdMask, int ldMask)
{
    if(row==8)
    {
        printBoard(Board);
        return;
    }
    for(int j=0; j<8; j++)
    {
        int colIndex = 1<<(7-j);
        if((colMask|rdMask|ldMask) & colIndex)
        {
            continue;

        }
        else
        {
            Board[row][j]='Q';
            placeQueen(Board, row+1, colMask|colIndex, (rdMask|colIndex)>>1,(ldMask|colIndex)<<1);
            Board[row][j]='.';
        }
    }
}
int main()
{
    char Board[8][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            Board[i][j] = '.';
        }
    }
    int colMask = 0;
    int rdMask = 0;
    int ldMask = 0;
    placeQueen(Board, 0, colMask, rdMask, ldMask);
    return 0;
}
