#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define nl cout<<"\n"

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
bool sortbydesc(int &a, int &b)
{	return a > b;	}

int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	int m = 1, n = 1;
	cin >> m >> n;

	int a[m + 1][n + 1] = {0};
	rep(i, 0, m)rep(j, 0, n)cin >> a[i][j];

	//Given a boolean matrix mat[M][N] of size M X N,
	//modify it such that if a matrix cell mat[i][j] is 1 (or true)
	//then make all the cells of ith row and jth column as 1.

	//If a[i][j] is marked 1 make all cells of i'th row and j'th coloumn to 1

	//VVI Optimization for space

	//Use first row and coloumn itself as marking for rest (m-1)(n-1) matrix

	//TC - O(m*n)
	//SC - O(1)

	int row_flag = 0, col_flag = 0;
	rep(i, 0, m)
	{
		rep(j, 0, n)
		{
			if (i == 0 && a[i][j] == 1)
				row_flag = 1;
			if (j == 0 && a[i][j] == 1)
				col_flag = 1;
			if (a[i][j] == 1)			//Matrix itself used as temp hashing / marking
			{
				a[i][0] = 1;
				a[0][j] = 1;
			}
		}
	}

	//VVI - Note here start i and j start from 1
	//as First filling only (m-1)(n-1)

	rep(i, 1, m)
	{
		rep(j, 1, n)
		if (a[0][j] == 1 || a[i][0] == 1)
			a[i][j] = 1;
	}

	if (row_flag)
		rep(i, 0, n)
		a[0][i] = 1;
	if (col_flag)
		rep(i, 0, m)
		a[i][0] = 1;
	
	rep(i, 0, m)
	{
		rep(j, 0, n)
		cout << a[i][j] << " ";
		nl;
	}
	return 0;
}
