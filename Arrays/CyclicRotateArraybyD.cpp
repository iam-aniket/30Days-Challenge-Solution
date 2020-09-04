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
	int n = 1, k = 1;
	cin >> n >> k;
	int a[n + 1] = {0};
	aip(a, n);
	//TC = O(n) SC = O(1)
	//1)Reverse a[0..k] then Reverse a[k+1...n-1]
	//2)Then Reverse whole a[0...n-1]
	int j = k - 1;
	rep(i, 0, k)
	{
		if (i < j)
		{
			swap(a[i], a[j]);
			j--;
		}
		else
			break;
	}
	j = n - 1;
	rep(i, k, n)
	{
		if (i < j)
		{
			swap(a[i], a[j]);
			j--;
		}
		else break;
	}
	j = n - 1;
	rep(i, 0, n)
	{
		if (i < j)
		{
			swap(a[i], a[j]);
			j--;
		}
		else
			break;
	}
	aop(a, n);
	return 0;
}
