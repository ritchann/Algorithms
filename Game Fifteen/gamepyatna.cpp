#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string> 
#include <algorithm> 
#include <cstdlib> 
#include <vector> 
#include <cmath> 
#include <set> 
#include <iterator> 
#include <map>
#include <queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

struct Diapason
{
	char mas[3][3];
	int SpaceX;
	int SpaceY;
	string s;
	int prev_SpaceX;
	int prev_SpaceY;
};

Diapason SearcSpace(Diapason temp)
{
	string temp_str = "";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp_str += temp.mas[i][j];
			if (temp.mas[i][j] == '_')
			{
				temp.SpaceX = i;
				temp.SpaceY = j;
			}
		}
	}
	temp.s = temp_str;
	return temp;
}

Diapason ToMas(string str,Diapason temp)
{
	temp.mas[0][0] = str[0];
	temp.mas[0][1] = str[1];
	temp.mas[0][2] = str[2];
	temp.mas[1][0] = str[3];
	temp.mas[1][1] = str[4];
	temp.mas[1][2] = str[5];
	temp.mas[2][0] = str[6];
	temp.mas[2][1] = str[7];
	temp.mas[2][2] = str[8];
	return temp;
}
void PrintVec(Diapason temp)
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << temp.mas[i][j];
		cout << endl;
	}
	cout << "_________" << endl;
}
void Print(Diapason temp,vector<Diapason> tempvec)
{

	while (temp.prev_SpaceX != -1 && temp.prev_SpaceY != -1)
	{
		int k;
		swap(temp.mas[temp.SpaceX][temp.SpaceY], temp.mas[temp.prev_SpaceX][temp.prev_SpaceY]);
		temp = SearcSpace(temp);
		for (int i = 0; i < tempvec.size(); i++)
		{
			if (tempvec[i].s == temp.s)
			{
				k = i;
				i = tempvec.size();
			}
		}
		temp = tempvec[k];
		PrintVec(temp);
	}
}

int main()
{
	queue<Diapason> nextStates;
	queue<int> q_dia;
	vector<Diapason> forprint;
	setlocale(LC_ALL, "Russian");
	Diapason  temp_str;
	string str, base_str = "diapason_";
	q_dia.push(0);
	cin >> str;
	temp_str = ToMas(str, temp_str);
	temp_str=SearcSpace(temp_str);
	temp_str.prev_SpaceX = -1;
	temp_str.prev_SpaceY = -1;
	nextStates.push(temp_str);
	forprint.push_back(temp_str);
	while (!nextStates.empty())
	{
		Diapason tek = nextStates.front();
		if (tek.s == base_str)
		{
			PrintVec(tek);
			Print(tek, forprint);
			cout << "Перестановок: " << q_dia.front() << endl;
			system("pause");
			exit(0);
		}
		nextStates.pop();
		tek = SearcSpace(tek);
		for (int i = 0; i < 4; i++)
		{
			int itek = tek.SpaceX + dx[i], jtek = tek.SpaceY + dy[i], l = q_dia.front() + 1;
			if (itek >= 0 && itek < 3 && jtek >= 0 && jtek < 3)
			{
				Diapason  temp = tek;
				swap(temp.mas[itek][jtek], temp.mas[temp.SpaceX][temp.SpaceY]);
				temp = SearcSpace(temp);
				if (!(temp.SpaceX == tek.prev_SpaceX && temp.SpaceY == tek.prev_SpaceY))
				{
					q_dia.push(l);
					temp.prev_SpaceX = tek.SpaceX;
					temp.prev_SpaceY = tek.SpaceY;
					nextStates.push(temp);
					forprint.push_back(temp);
				}
			}
		}
		q_dia.pop();
	}
}