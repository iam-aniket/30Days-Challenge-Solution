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

void insert(int n)
{
	node* temp = new node();
	temp->data = n;
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
void findMiddle()
{
	node *f = head, *s = head;
	if (head != NULL)
	{
		while (f != NULL && f->link != NULL)
		{
			f = f->link->link;
			s = s->link;
		}
		cout << "Middle Element = " << s->data << "\n";
	}
}
int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	struct node* head = NULL;
	int n = 1;
	cout << "Enter no of nodes : ";
	cin >> n;

	cout << "Enter data : ";
	rep(i, 0, n)
	{
		int x = 0;
		cin >> x;
		insert(x);
	}

	cout << "LL : ";
	display();
	findMiddle();

	return 0;
}
