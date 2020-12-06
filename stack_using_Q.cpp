#include<bits/stdc++.h>
using namespace std;


class QStack
{
	queue<int> Q;
	public:
	void Cpush(int);
	void push(int);
	void pop();
	int Cpop();
	int top();
	bool empty();
};

//Making push costly
void QStack :: Cpush(int n)
{
	int size = Q.size();
	Q.push(n);
	for(int i=0;i<size;i++)
	{
		Q.push(Q.front());
		Q.pop();
	}
}

void QStack :: pop()
{
	if(Q.empty())
	{
		cout<<"Stack is empty."<<endl;
		return;
	}
	Q.pop();
}

void QStack :: push(int n)
{
	Q.push(n);
}
// Making pop costly
int QStack :: Cpop()
{
	int size = Q.size();
	for(int i=0;i<size-1;i++)
	{
		Q.push(Q.front());
		Q.pop();
	}
	int res = Q.front();
	Q.pop();
	return res;
}
int QStack :: top()
{
	
	return (Q.empty()?-1:Q.front());
}

bool QStack :: empty()
{
	return Q.empty();
}

int main()
{
	QStack s,r;
	s.Cpush(1);
	s.Cpush(2);
	s.Cpush(3);
	cout<<"Stack Elements:";
	while(!s.empty())
	{
		cout<<s.top()<<ends;
		s.pop();
	}
	r.push(4);
	r.push(5);
	r.push(6);
	cout<<"\nCostly pop Stack Elements:";
	while(!r.empty())
	{
		cout<<r.Cpop()<<ends;
	}
}
