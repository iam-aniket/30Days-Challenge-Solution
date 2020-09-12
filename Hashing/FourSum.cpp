#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define mp make_pair
#define ff first
#define ss second
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
	int n = 1, x = 1;
	cin >> n >> x;
	int a[n + 1] = {0};
	aip(a, n);

	//Standard Hashing - O(n^2) SC = O(n^2)
	//Remember to check all 4 indices are different

	unordered_map < int, pair<int, int>> m;

	rep(i, 0, n)
	rep(j, i + 1, n)
	m[a[i] + a[j]] = mp(i, j);

	rep(i, 0, n)
	{
		rep(j, i + 1, n)
		{
			int sum = a[i] + a[j];
			if (m.find(x - sum) != m.end())
				if (m[x - sum].ff != i && m[x - sum].ff != j && m[x - sum].ss != i && m[x - sum].ss != j)
					cout << "Qudruple : " << a[i] << " + " << a[j] << " + " << a[m[x - sum].ff] << " + " << a[m[x - sum].ss] << "\n";
		}
	}
	return 0;
}
