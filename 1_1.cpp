#include <iostream>
using namespace std;

double rasta(int i, int j, double m[100][2])
{
	return sqrt((m[i][0] - m[j][0])*(m[i][0] - m[j][0]) + (m[i][1] - m[j][1])*(m[i][1] - m[j][1]));
}

int main() 
{
	int n;
	double m[100][2];   // исходный
	double l[100][100]; // лучшие суммы
	double d[100][100]; // расстояния
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> m[i][0] >> m[i][1];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = rasta(i, j, m);
		//	l[i][j] = 1000000;
		}
	}

	for (int i = 0; i < n; i++)
	{
		l[i][i + 2] = 0;
		l[i][i + 1] = 0;
	}

	double min,z;
	for (int a = 3; a < n; a++)
		for (int b = 0; b < n - a; b++)
		{
			int i = b;
			int j = b + a; 
			min = 1000000;
			for (int k = i+1; k < j; k++)
			{
				z = l[i][k] + l[k][j] + d[i][k] + d[k][j];//  d[i][j];
				if (k == i + 1) z = z - d[i][k];
				if (k == j - 1) z = z - d[k][j];
				if (min>z)
					min = z;
				if (min < 0) min = -1;
			}
			l[i][j] = min;
		}
	
		cout << l[0][n-1];
	return 0;
}