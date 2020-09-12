#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define mp make_pair
#define ff first
#define ss second
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
	int n = 1;
	cin >> n;
	int a[n + 1] = {0};
	aip(a, n);

	//First add all nos into hash set
	//Then if a number is a start pos - while loop till consecutive increments present in the array
	//Maximize this length

	unordered_set<int> s;

	rep(i, 0, n)
	s.insert(a[i]);

	int ans = 0;
	rep(i, 0, n)
	{
		if (s.find(a[i] - 1) == s.end())
		{
			int start_val = a[i];
			int ct = 0;
			while (s.find(start_val) != s.end())
			{
				ct++;
				start_val++;
			}
			ans = max(ans, ct);
		}
	}
	cout << "Longest Consecutive Numbers Subsequence length = " << ans << "\n";
	return 0;
}
/*
14
3 6 8 7 5 4 99 100 101 102 103 104 105 106

OP : 8(103,104....,106)
*/
