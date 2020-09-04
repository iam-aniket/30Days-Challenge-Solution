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
	int n = 1, sum = 1;
	cin >> n >> sum;
	int a[n + 1] = {0};
	aip(a, n);

	//Hashing - TC = O(n) SC = O(n)

	unordered_set<int> s;

	rep(i, 0, n)
	{
		if (s.find(sum - a[i]) != s.end())
			cout << a[i] << "--" << sum - a[i] << "\n";
		else
			s.insert(a[i]);
	}
	return 0;
}
