#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int rows = 3;
const int coloums = 3;

void verticalLine();
void horizontalLine();
void location(char a[][coloums]);
void display(char a[][coloums]);
void tikTacUser1(char a[][coloums]);
void tikTacUser2(char a[][coloums]);
bool check(char a[][coloums], string &nameWinner, string name1, string name2 );
void dataFile(string name,int score);
int main()
{
	string name1, name2, winner;
	int score = NULL;
	bool terminate = false;
	char repeat = 'N';
	cout << "PLease enter the name of User 1\n";
	getline(cin,name1);
	cout << "PLease enter the name of User 2\n";
	getline(cin, name2);
	do
	{
		
		char arr[rows][coloums] = {}; // for each repeat array initilize as an emplty
		cout << "Points to member \n";
		location(arr);
		//inputing
		for (int i = 0; i < 5; i++)
		{

			tikTacUser1(arr);
			display(arr);
			terminate = check(arr, winner, name1, name2);
			if (terminate == true)
			{
				score = 10;
				break;
			}
			else if (i == 4) // to avoid one extra move
			{
				break;
			}
			tikTacUser2(arr);
			display(arr);
			terminate = check(arr, winner, name1, name2);
			if (terminate == true)
			{
				score = 10;
				break;
			}
		}
		if (terminate == false)
		{
			cout << "Draw\n Nobody is the winner\n";
		}
		dataFile(winner, score);
		// to play again
		cout << "Do you want to play again (Y/N):\n"; 
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');
	
	return 0;
}

void verticalLine()
{
	cout << "\n\t";
	for (int i = 0; i < 3; i++)
	{
		cout << " |\t";
	}
}
void horizontalLine()
{
	int counter = 2;
	cout << "\n\t";
	for (int i = 1; i < 20; i++)
	{
		if (counter == i) // creat a space and put | there
		{
			cout << "|";
			counter += 8;
		}
		else
		{
			cout << "-";
		}
	}
	verticalLine();
}
void location(char a[][coloums])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloums; j++)
		{
			cout << "\t" << i << j << "\t";
		}
		cout << "\n\n";
	}
}
void display(char a[][coloums])
{
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int j = 0; j < coloums; j++)
		{
			cout << a[i][j] << "|\t";
		}
		horizontalLine();
		cout << "\n";
	}
}

void tikTacUser1(char a[][coloums])
{
	int i = 0, j = 0;
	cout << "User 1\nPlease enter the point at which you want to tik\n";
	cin >> i >> j;
	a[i][j] = 'X';
}
void tikTacUser2(char a[][coloums])
{
	int i = 0, j = 0;
	cout << "User 2\nPlease enter the point at which you want to tac\n";
	cin >> i >> j;
	a[i][j] = 'O';
}
bool check(char a[][coloums], string &nameWinner, string name1, string name2)
{
	// for horizontal check
	for (int i = 0; i < rows; i++)
	{
		int tik = 0;
		int tac = 0;
		for (int j = 0; j < coloums; j++)
		{
				if (a[i][j] == 'X')
				{
					tik++;
				}
				else if (a[i][j] == 'O')
				{
					tac++;
				}
		}
		if (tik == 3)
		{
			cout << "User 1 has won\n";
			nameWinner = name1; //for saveing the winner name in the file
			return true; // return true to terminate the loop in the main
		}
		else if (tac == 3)
		{
			cout << "User 2 has won\n";
			nameWinner = name2;
			return true;
		}
	}
	//for vertical check
	for (int i = 0; i < rows; i++)
	{
		int tik = 0;
		int tac = 0;
		for (int j = 0; j < coloums ; j++)
		{
			if (a[j][i] == 'X') //
			{
				tik++;
			}
			else if (a[j][i] == 'O') //
			{
				tac++;
			}
		}
		if (tik == 3)
		{
			cout << "User 1 has won\n";
			nameWinner = name1;
			return true;
		}
		else if (tac == 3)
		{
			cout << "User 2 has won\n";
			nameWinner = name2;
			return true;
		}
	}
	//for diagonal check
	int tikDiagonal = 0;
	int tacDiagonal = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j <= i; j++)
		{
			
			if (a[i][j] == 'X')
			{
				
				tikDiagonal++;
			}
			else if (a[i][j] == 'O')
			{
				tacDiagonal++;
			}
		}
		if (tikDiagonal == 3)
		{
			cout << "User 1 has won\n";
			nameWinner = name1;
			return true;
		}
		else if (tacDiagonal == 3)
		{
			cout << "User 2 has won\n";
			nameWinner = name2;
			return true;
		}
	}
	//for right to left diagonal
	int tikInverseDiagonal = 0;
	int tacInverseDiagonal = 0;
	for (int i = 0; i < rows; i++)
	{
		
		for (int j = 2 - i; j <= 2 - i; j++)
		{
			if (a[i][j] == 'X')
			{
				tikInverseDiagonal++;
			}
			else if (a[i][j] == 'O')
			{
				tacInverseDiagonal++;
			}
		}
		if (tikInverseDiagonal == 3)
		{
			cout << "User 1 has won\n";
			nameWinner = name1;
			return true;
		}
		else if (tacInverseDiagonal == 3)
		{
			cout << "User 2 has won\n";
			nameWinner = name2;
			return true;
		}
	}
	return false;
}
void dataFile(string name,int score)
{
	fstream dataFile;
	dataFile.open("F:\\nadeem\\Score Board.txt", ios :: out | ios :: app);
	dataFile << "\n" << name << "\t" << score;
	dataFile.close();
}