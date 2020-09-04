#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define lli long long
#define nl cout<<"\n"
#define aop(a,n) rep(i,0,n) cout<<a[i]<<" ";nl
#define aip(a,n) rep(i,0,n) cin>>a[i]
#define tc int t = 1;cin>>t;while(t--)

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
	int n;
	cin >> n;
	int a[n + 1] = {0};
	aip(a, n);

	//Sort array of 0s,1s and 2s only
	//Visualize Dutch National Flag Algorithm

	int zero = 0, one = 0, two = n - 1;
	while (one <= two)
	{
		if (a[one] == 0)
		{
			swap(a[one], a[zero]);
			zero++;
			one++;
		}
		else if (a[one] == 1)
			one++;
		else
		{
			swap(a[one], a[two]);
			two--;
		}
	}
	aop(a, n);
	return 0;
}
/*
12
0 1 1 0 1 2 1 2 0 0 0 1
*/
