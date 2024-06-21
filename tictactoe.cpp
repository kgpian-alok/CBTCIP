#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//for checking match winner 


void gridPattern(int arr[3][3])
{

    cout << "        |        |        \n    ";
    if (arr[0][0] == -1) cout << 1;
    else if (arr[0][0]) cout << "x";
    else cout << "o";
    cout << "   |   ";
    if (arr[0][1] == -1) cout << 2;
    else if (arr[0][1]) cout << "x";
    else cout << "o";
    cout << "    |   ";
    if (arr[0][2] == -1) cout << 3;
    else if (arr[0][2]) cout << "x";
    else cout << "o";
    cout << "    \n_ _ _ _ |_ _ _ _ |_ _ _ _ \n        |        |        \n    ";
    if (arr[1][0] == -1) cout << 4;
    else if (arr[1][0]) cout << "x";
    else cout << "o";
    cout << "   |   ";
    if (arr[1][1] == -1) cout << 5;
    else if (arr[1][1]) cout << "x";
    else cout << "o";
    cout << "    |   ";
    if (arr[1][2] == -1) cout << 6;
    else if (arr[1][2]) cout << "x";
    else cout << "o";
    cout << "     \n_ _ _ _ |_ _ _  _|_ _ _  _\n        |        |        \n    ";
    if (arr[2][0] == -1) cout << 7;
    else if (arr[2][0]) cout << "x";
    else cout << "o";
    cout << "   |   ";
    if (arr[2][1] == -1) cout << 8;
    else if (arr[2][1]) cout << "x";
    else cout << "o";
    cout << "    |   ";
    if (arr[2][2] == -1) cout << 9;
    else if (arr[2][2]) cout << "x";
    else cout << "o";
    cout << "    \n        |        |        \n";
}
int checker(int grid[3][3], int Win)
{
    if(grid[0][0] == Win && grid[0][1] == Win && grid[0][2] == Win) return 1;
    else if(grid[1][0] == Win && grid[1][1] == Win && grid[1][2] == Win) return 1;
    else if(grid[2][0] == Win && grid[2][1] == Win && grid[2][2] == Win) return 1;
    else if(grid[0][0] == Win && grid[1][0] == Win && grid[2][0] == Win) return 1;
    else if(grid[0][1] == Win && grid[1][1] == Win && grid[2][1] == Win) return 1;
    else if(grid[0][2] == Win && grid[1][2] == Win && grid[2][2] == Win) return 1;
    else if(grid[0][0] == Win && grid[1][1] == Win && grid[2][2] == Win) return 1;
    else if(grid[2][0] == Win && grid[1][1] == Win && grid[0][2] == Win) return 1;
    else return 0;
}
void solve()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) arr[i][j] = -1;
    string n1;
    cout << "Please Enter the name of Player1: ";
    cin.ignore();
    getline(cin, n1);
    string n2;
    cout << "Please Enter the name of Player2: ";
    cin.ignore();
    getline(cin, n2);
    int x, y;
    for (int move = 0; move < 9; move += 2)
    {
        gridPattern(arr);
        do
        {
            cout << "Enter the number 1-9 for P1: ";
            cin >> x;
        } while (x < 1 || x > 9);
        int i = (x - 1) / 3, j = (x - 1) % 3;
        while (arr[i][j] != -1)
        {
            cout << "Already moved so please enter again:- ";
            cin >> x;
            i = (x - 1) / 3, j = (x - 1) % 3;
        }
        arr[i][j] = 1;
        if(checker(arr,1))
        {
            cout<<n1<<" is winner \n";
            return;
        }
        gridPattern(arr);
        if (move == 8) break;
        do
        {
            cout << "Enter the number 1-9 for P2: ";
            cin >> y;
        } while (y < 1 || y > 9);
        i = (y - 1) / 3, j = (y - 1) % 3;
        while (arr[i][j] != -1)
        {
            cout << "Already moved so please enter again:- ";
            cin >> y;
            i = (y - 1) / 3, j = (y - 1) % 3;
        }
        arr[i][j] = 0;
        if(checker(arr,0))
        {
            cout<<n2<<" is winner \n";
            return;
        }
    }
    cout<<"Match is draw\n";
}
int main()
{
    int check = 1;
    do
    {
        solve();
        cout << "\nWant to play game again?\nEnter 1. Yes\n2. No\n";
        cin >> check;
    } while (check == 1);
    return 0;
}