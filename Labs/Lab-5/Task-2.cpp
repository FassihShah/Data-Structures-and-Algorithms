#include<iostream>
#include<stack>
#include"Stack_Implementation.cpp"
using namespace std;
bool isVisited(int* rows, int* cols, int r, int c, int p)
{
	for (int i = 0; i < p; i++)
	{
		if (rows[i] == r && cols[i] == c)
			return true;
	}
	return false;
}
void findTreasure(const char maze[5][7], Point start)
{
	stack<Point> p;
	int rows[35];
	int cols[35];
	int r = start.row;
	int c = start.col;
	int points = 0;
	while (maze[r][c] != 'E')
	{
		if (r < 5 - 1 && maze[r + 1][c] == '.' && !isVisited(rows, cols, r, c, points))
		{
			r++;
			rows[r];
			p.push(Point(r, c));
			points++;
		}
		else if (r - 1 >= 0 && maze[r - 1][c] == '.' && !isVisited(rows, cols, r, c, points))
		{
			r--;
			rows[r];
			p.push(Point(r, c));
			points++;
		}
		else if (c < 7 - 1 && maze[r][c + 1] == '.' && !isVisited(rows, cols, r, c, points))
		{
			c++;
			cols[c];
			p.push(Point(r, c));
			points++;
		}
		else if (c - 1 >= 0 && maze[r][c - 1] == '.' && !isVisited(rows, cols, r, c, points))
		{
			c--;
			cols[c];
			p.push(Point(r, c));
			points++;
		}
		else
		{
			cout << "No Valid Path Found!";
			exit(0);
		}
	}
	while (!p.empty())
	{
		cout << "Found the treasure! Path\n";
		Point a = p.top();
		p.pop();
		cout << "(" << a.row << "," << a.col << ") ";
	}
}
int main()
{

	cout << endl;
	return 0;
}