#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)

using namespace std;

struct node
{
	int data;
	node* link;
};

struct node* head;

void insert(int x)
{
	struct node* temp = new node();
	temp->data = x;
	temp->link = NULL;
	if (head != NULL)
		temp->link = head;
	head = temp;
}
void display()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->link;
	}
	cout << "NULL\n";
}

int nthNodeFromEnd(int n)
{
	int ct = 0;
	node* temp = head;
	while (temp != NULL)
	{
		ct++;
		temp = temp->link;
	}
	int count = 0, val = 0;

	if (count == ct - n)//HEAD node/First node to be removed
	{
		int val = head->data;
		temp = head;

		head = temp->link;
		temp->link = NULL;

		return val;
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			count++;
			if (count == ct - n)
			{
				val = temp->link->data;

				node* next = temp->link;

				temp->link = next->link;
				next->link = NULL;

				break;
			}
			temp = temp->link;
		}
	}
	return val;
}
int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	struct node* head = NULL;
	int no = 1, n = 1, x = 1;
	cin >> no;

	rep(i, 0, no)
	{
		cin >> x;
		insert(x);
	}

	cout << "Enter position of Nth Node from end u wish to fetch :- \n";
	cin >> n;

	display();
	cout << n << " th Node from end is : ";
	int val = nthNodeFromEnd(n);
	cout << val << "\n";
	display();
	return 0;
}
