#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define aop(a,n) rep(i,0,n) cout<<a[i]<<" ";nl
#define aip(a,n) rep(i,0,n) cin>>a[i]
#define so(a,n) sort(a,a+n)
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
	int temp = 0, Maxsum = 0, start = 0, s = 0, end = 0;
	bool flag = false;
	rep(i, 0, n)
	{
		if (a[i] >= 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)	//Atleast one positive no present
	{
		rep(i, 0, n)
		{
			temp += a[i];
			if (temp > Maxsum)	//If current Temp Subarray greater than Max subarray
			{
				Maxsum = temp;
				start = s;		//Update global maximum ka start and end
				end = i;
			}
			if (temp < 0)		//Greedy - We require only positive
			{
				temp = 0;
				s = i + 1;		//Local start for next subarray
			}
		}
		cout << "Start = " << s << " End = " << end << "\n";
		cout << "Max Subarray Sum = " << Maxsum << "\n";
	}
	else	//All negative nos in array
	{
		int pos = 0, min_neg = INT_MIN;
		rep(i, 0, n)
		{
			if (a[i] > min_neg)
			{
				pos = i;
				min_neg = a[i];
			}
		}
		cout << "Pos = " << pos << "\n";
		cout << "MAX Subarray Sum = " << min_neg << "\n";
	}
	return 0;
}
