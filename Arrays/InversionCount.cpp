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
int mergeSort(int a[], int temp[], int left, int mid, int right)
{
	int i, j , k;
	int count = 0;
	i = left;
	j = mid;
	k = left;

	while ((i <= mid - 1) && (j <= right))
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			count += (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];

	for (i = left; i <= right; i++)
		a[i] = temp[i];
	return count;
}
int countInv(int a[], int temp[], int left, int right)
{
	int mid, count = 0;
	if (right > left)
	{
		mid = (right + left) / 2;
		count += countInv(a, temp, left, mid);
		count += countInv(a, temp, mid + 1, right);

		count += mergeSort(a, temp, left, mid + 1, right);
	}
	return count;
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
	int a[n + 1] = {0};
	aip(a, n);
	int temp[n + 1] = {0};
	int ans = countInv(a, temp, 0, n - 1);
	cout << ans << "\n";
	return 0;
}
