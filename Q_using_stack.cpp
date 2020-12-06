#include<bits/stdc++.h>
using namespace std;

class Q
{
	stack<int> s1,s2;
	public:
	void Cenque(int);
	void deque();
	int front();
	bool empty();
	void enque(int);
	void Cdeque();
	int Cfront();
	bool Cempty();	
};

void Q :: Cenque(int n)
{
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(n);
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void Q :: deque()
{
	if(s1.empty())
		cout<<"Q is empty";
		
	else
		s1.pop();
	
}

int Q :: front()
{
	return s1.top();
}

bool Q :: empty()
{
	return s1.empty();
}

void Q :: enque(int n)
{
	s1.push(n);
}

void Q :: Cdeque()
{
	if(s1.empty() && s2.empty())
	{
		cout<<"Q is empty";
		return;
	}
	
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
	else
		s2.pop();
}

int Q :: Cfront()
{
	if(s1.empty() && s2.empty())
	{
		return -1;
	}
	
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
	
	else
		return s2.top();
}

bool Q :: Cempty()
{
	return (s1.empty() && s2.empty());
}

int main()
{
	Q q,r;
	q.Cenque(1);
	q.Cenque(2);
	q.Cenque(3);
	cout<<"Queue Data :";
	while(!q.empty())
	{
		cout<<q.front()<<ends;
		q.deque();
	}
	
	r.enque(4);
	r.enque(5);
	r.enque(6);
	cout<<"\nCostly Deque Q data :";
	while(!r.Cempty())
	{
		cout<<r.Cfront()<<ends;
		r.Cdeque();
	}

}
