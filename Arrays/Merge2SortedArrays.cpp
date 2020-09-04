#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define per(i,a) for(int i = a; i >= 0; i--)
#define lli long long
#define nl cout<<"\n"
#define aop(a,n) rep(i,0,n) cout<<a[i]<<" ";nl
#define aip(a,n) rep(i,0,n) cin>>a[i]

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
	int n = 1, m = 1;
	cin >> n >> m;
	int a[n + 1] = {0}, b[m + 1] = {0};
	aip(a, n);
	aip(b, m);

	//TC = O(m*n) SC = O(1) -- No Extra Space

	//Traverse from second array back
	//Position it at correct position in first array
	//Now position last ele of first array if it was changed

	per(i, m - 1)
	{
		//VVI step to save temp
		int val = b[i], temp = a[n - 1];
		int j;
		for (j = n - 2; j >= 0 && a[j] > val; j--)
			a[j + 1] = a[j];
		if (j != n - 2)
		{
			a[j + 1] = b[i];
			b[i] = temp;
		}
		aop(a, n);
		aop(b, m);
		nl;
	}
	aop(a, n);
	aop(b, m);

	return 0;
}
