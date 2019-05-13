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
#include <queue>

using namespace std;
int dx[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
int dy[8] = { -1, 1, 2, 2, -1, 1, -2, -2 };

int NumberOfMoves(int n, int m, int xx, int yy)
{
	int quantity = 0;
	for (int i = 0; i < 8; i++)
	{
		int posx = xx + dx[i], posy = yy + dy[i];
		if (posy >= 0 && posy < m&&posx >= 0 && posx < n)
			quantity++;
	}
	return quantity;
}
struct Position
{
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setlocale(LC_ALL, "rus");
	int n, m, mx, my, ex, ey, mcount = 0, ecount = 0;
	cin >> n >> m >> mx >> my >> ex >> ey;
	vector<vector<int>> a(n, vector<int>(m));
	if (NumberOfMoves(n, m, ex, ey) < NumberOfMoves(n, m, mx, my))
	{
		swap(mx, ex); swap(my, ey);
	}
	Position base;
	queue<Position> coordinate;
	a[mx][my] = 1;
	base.x = mx; base.y = my; coordinate.push(base);
	while (!coordinate.empty())
	{
		int currenti = coordinate.front().x, currentj = coordinate.front().y; coordinate.pop(); 
		for (int i = 0; i < 8; i++)
		{
			int posx = currenti + dx[i], posy = currentj + dy[i];
			if (posy >= 0 && posy<m&&posx >= 0 && posx<n&&a[posx][posy] == 0)
			{
				a[posx][posy] = a[currenti][currentj] + 1;
				base.x = posx; base.y = posy; coordinate.push(base);
				if (a[ex][ey] != 0)
				{
					cout << a[ex][ey] - 1;
					system("pause");
					exit(0);
				}
			}
		}
	}
	system("pause");
}