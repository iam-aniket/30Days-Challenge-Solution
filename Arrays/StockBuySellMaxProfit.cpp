#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define per(i,a) for(int i = a; i >= 0; i--)
#define lli long long
#define pb push_back
#define mp make_pair
#define nl cout<<"\n"
#define ff first
#define ss second
#define vi vector<int>
#define pie 3.1415926535
#define mx(a,n) *max_element(a,a+n)
#define mn(a,n) *min_element(a,a+n)
#define aop(a,n) rep(i,0,n) cout<<a[i]<<" ";nl
#define aip(a,n) rep(i,0,n) cin>>a[i]
#define so(a,n) sort(a,a+n)
#define sodesc(a,n) sort(a,a+n,sortbydesc)
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
	int n = 1;
	cin >> n;
	int a[n + 1] = {0};
	aip(a, n);

	//Vizualize Valley and Peak method
	//And buy at every valley and sell at corresponding next peak

	//TC = O(n) SC = O(1)

	int i = 0, amt = 0;

	while (i <= n - 1)
	{
		while ((i <= n - 1) && a[i + 1] <= a[i])	//Find local Minima
			i++;

		if (i == n - 1)
			break;

		int buy = i;
		i++;		//Next position after buy

		while ((i <= n - 1) && a[i + 1] >= a[i])	//Find Local maxima
			i++;

		int sell = i;

		cout << "Buy at " << a[buy] << " & Sell at " << a[sell] << "\n";

		amt += a[sell] - a[buy];

		i++;		//Next position after sell
	}
	cout << "Final Stock Amount = " << amt << "\n";
	return 0;
}
