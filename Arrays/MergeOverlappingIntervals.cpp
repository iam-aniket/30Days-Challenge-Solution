#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
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
struct interval
{
	int start ;
	int end;
};
bool sortbyfirst(interval i1, interval i2)
{
	return (i1.start < i2.start);
}
int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	int n = 1;
	cin >> n;
	interval arr[n + 1];
	//cout << "Enter " << n << " interval pair wise : \n";
	rep(i, 0, n)
	{
		int x = 1, y = 1;
		cin >> x >> y;
		arr[i].start = x;
		arr[i].end = y;
	}

	sort(arr, arr + n, sortbyfirst);

	stack<interval> s;
	s.push(arr[0]);

	rep(i, 1, n)
	{
		interval temp = s.top();
		if (arr[i].start > temp.end)
			s.push(arr[i]);
		else
		{
			temp.end = max(arr[i].end, temp.end);
			s.pop();
			s.push(temp);
		}
	}
	cout << "Merged Interval : \n";
	while (!s.empty())
	{
		interval x = s.top();
		cout << x.start << " -- " << x.end << "\n";
		s.pop();
	}

	return 0;
}
