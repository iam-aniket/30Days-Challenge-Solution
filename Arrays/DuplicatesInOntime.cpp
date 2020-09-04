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

	//Elements are in range O to n-1 we can use index as hashmap to avoid external usage
	//of hash like set or map and hence SC = O(1) & TC = O(n)

	//Method1 - but generates duplicates multiple times
	/*rep(i, 0, n)
	{
		if (a[abs(a[i] - 1)] < 0)
			cout << a[i] << "\n";
		else
			a[abs(a[i] - 1)] = -a[abs(a[i] - 1)];
	}*/

	//Method2 - Better
	for (int i = 0; i < n; i++)
	{
		int index = a[i] % n;
		a[index] += n;
	}
	for (int i = 0; i < n; i++)
	{
		if ((a[i] / n) > 1)		//VVVI step
			cout << i << "\n";
	}
	return 0;
}
