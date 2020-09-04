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
	//Most optimal Way - TC = O(n + m))  SC = O(n + m)
	unordered_set<int> s, union_s;
	rep(i, 0, n)
	s.insert(a[i]);
	rep(i, 0, m)
	{
		if (s.find(b[i]) != s.end())
			union_s.insert(b[i]);
		else
			s.insert(b[i]);
	}
	for (auto x : s)cout << x << " "; nl;
	for (auto x : union_s)cout << x << " "; nl;
	return 0;
}
