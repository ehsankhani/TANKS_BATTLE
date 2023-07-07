#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool checkindex(int x, int y);
void printsudoku(int arr[9][9])
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout << "+---+---+---+---+---+---+---+---+---+---+" << "\n";
	cout<<"|"<<"   "<<"|";
	for(int i = 0; i < 9; i++)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		cout<<" "<<i;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		cout<<" |";
	}
	cout <<"\n"<<"+---+---+---+---+---+---+---+---+---+---+"<<"\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		cout<<" "<<i;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		cout<<" |";
		for (int j = 0; j < 9; j++)
		{
			if(arr[i][j] != 0)
			{
				bool ex = false;
				for(int k = 0; k < 9; k++)
				{
					if(k != j && arr[i][k] == arr[i][j])
						ex = true;
				}
				for(int k =0; k < 9; k++)
				{
					if(k != i && arr[k][j] == arr[i][j])
						ex = true;
				}
				if(ex)
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				else
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 7);
			}
			if(checkindex(i, j) == false)
				SetConsoleTextAttribute(hConsole, 13);
			cout << " " << arr[i][j] << " ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			cout<<"|";
		}
		cout << "\n";
		cout << "+---+---+---+---+---+---+---+---+---+---+" << "\n";
	}
	SetConsoleTextAttribute(hConsole, 7);
}
void solvesudoku(int arr[9][9], int x, int y, int &value)
{	
	   if (value <= 9 & value >= 0)
	   {
		  arr[x][y] = value;
	   }
}
bool checkindex(int x, int y)
{
	if((x == 0 && (y == 0 || y == 1)) || (x == 1 && (y == 3 || y == 8)) || (x == 2 && (y == 4 || y == 6)) || (x == 3 && (y == 1 || y == 8)) || (x == 4 && (y == 3 || y==4)) || (x == 5 && (y == 2 || y == 6)) || (x == 6 && (y == 0 || y == 5)) || (x == 7 && y == 7) || (x == 8 && (y == 2 || y == 5)))
		return false;
	return true;
}
bool checkwin(int arr[9][9])
{
	bool ex = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(arr[i][j] == 0)
				ex = false;	
		}
	}
	if(ex)
	{
		ex = false;
		for (int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				for(int k = 0; k < 9; k++)
				{
					if(k != j && arr[i][k] == arr[i][j])
						ex = true;
				}
				for(int k =0; k < 9; k++)
				{
					if(k != i && arr[k][j] == arr[i][j])
						ex = true;
				}
			}
		}
		if(ex == false)
			return true;
	}
	return false;
}
int main()
{
	do
	{
		cout << "Choose an option:   (1.new-game / 2.exit) : ";
		int n;
		cin >> n;
		if (n == 1)
		{
			srand(time(0));
			int my_random_number = 1 + rand() % 8;
			int board[9][9] =
			{
			{1 + rand() % 3,4 + rand() % 6,0,0,0,0,0,0,0},
			{0,0,0,4 + rand() % 6,0,0,0,0,1 + rand() % 3},
			{0,0,0,0,1 + rand() % 3,0,4 + rand() % 6,0,0},
			{0,1 + rand() % 3,0,0,0,0,0,0,4 + rand() % 6},
			{0,0,0,1 + rand() % 3,4 + rand() % 6,0,0,0,0},
			{0,0,4 + rand() % 5,0,0,0,1 + rand() % 3,0,0},
			{4 + rand() % 6,0,0,0,0,1 + rand() % 3,0,0,0},
			{0,0,0,0,0,0,0,1 + rand() % 3,0},
			{0,0,1 + rand() % 3,0,0,4 + rand() % 6,0,0,0},
			};
			printsudoku(board);
			cout<<endl;
			while(checkwin(board) == false)
		    {
				int x, y;
				int value;
				cout<<"Enter X Y Value : ";
				cin >>x>>y>>value;
				if(checkindex(x, y))
					solvesudoku(board, x, y, value);
				system("cls");
				printsudoku(board);
			}
			cout << endl << "You Solved Sudoku" << endl << endl;
			cout << "would you like to quit or not?   (1.Yes / 2.No) : ";
			int h;
			cin >> h;
		}
		else
		{
			cout << "good bay";
			return 0;
		}
		system("cls");
	} while ("h=1");
}
