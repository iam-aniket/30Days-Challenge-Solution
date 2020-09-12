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

	//PrefixSum+Hashing
	//Two Points where Presum is same

	//Corner case :- Take care to include if any element is 0 update max_len as 1 if its less

	unordered_map<int, int> presum;
	int sum = 0;
	int max_len = 0;
	rep(i, 0, n)
	{
		sum += a[i];
		if (a[i] == 0 && max_len == 0)
			max_len = 1;

		if (sum == 0)
			max_len = i + 1;

		if (presum.find(sum) != presum.end())
			max_len = max(max_len, i - presum[sum]);
		else
			presum[sum] = i;
	}
	cout << "Length of Longest Subarray with zero sum is : " << max_len << "\n";
	return 0;
}
/*
8
15 -2 2 -8 1 7 10 23
OP : 5
////////////////////
3
1 0 3
OP : 1
*/
