// labstack.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
bool double1(char *word);
bool pleetouch2(char *word);
bool complix3(char *word);
bool algebr4(char *word);
bool skob5(char *word);
void all(char *word);

bool inttrue(char s);
bool str(char s, char sp);

template< class T >
class Stack {

private:
	int MAX;
	int top;
	T* items;

public:
	Stack(int size){
		MAX = size;
		top = -1;
		items = new T[MAX];
	}

	~Stack(){ delete[] items; }

	void push(T c){
		if (full()){
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	T pop(){
		if (empty()){
			cout << "Stack Empty!" << endl;
			return NULL;
			exit(1);
		}


		return items[top--];
	}

	T free(){
		top = -1;
		return true;
	}

	int empty(){ return top == -1; }

	int full(){ return top + 1 == MAX; }
};

int what;
char word[200] = { " " };

int main(){
	setlocale(0, "");
	cout << "������� ���������:\n";

//start:
	char p[2] = { " " };

	gets_s(word);
	strcat_s(word, p);
	all(word);
	system("pause");
	return 0;
}


bool double1(char *word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
          if (sost==0)
		{
			if (inttrue(word[i]) || word[i] == '-')
				s.push(1);
			else
			{
	           s.push(-1);
 			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i]=='.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (inttrue(word[i]))
				s.push(3);
			else if (word[i] == ' ')
			{
				cout << "Yes\n";
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if(sost == -1)
		{
			cout << "Err\n";
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		cout << "Err\n";
		return false;
	}


	return true;
}
bool pleetouch2(char *word){
	/////////////////////////
	Stack<int> s(8);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (inttrue(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i] == '.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (inttrue(word[i]))
				s.push(3);
			else if (word[i]=='e')
			{
				s.push(4);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 4)
		{
			if (word[i] == '+' || word[i] == '-')
				s.push(5);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 5)
		{
			if (inttrue(word[i]))
				s.push(6);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 6)
		{
			if (inttrue(word[i]))
				s.push(6);
			else if (word[i] == ' ')
			{
				cout << "Yes\n";
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			cout << "Err\n";
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		cout << "Err\n";
		return false;
	}


	return true;
}
bool complix3(char *word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (inttrue(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i] == '-' || word[i] == '+')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(2);
			else if (word[i] = 'j')
			{
				s.push(3);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
            if (word[i] == ' ')
			{
				cout << "Yes\n";
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			cout << "Err\n";
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		cout << "Err\n";
		return false;
	}


	return true;
}
bool algebr4(char *word)
{
Stack<int> s(3);
s.free();
s.push(0);
int len = strlen(word);
for (int i = 0; i < len; i++)
{
	int sost = s.pop();
	if (sost == 0)
	{
		if (word[i] == 'b' || word[i] == 'a')
			s.push(1);
		else
		{
			s.push(-1);
		}
	}
	else if (sost == 1)
	{
		if (word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
			s.push(0);
		else if (word[i] == ' ')
		{
			cout << "Yes\n";
			return true;
		}
		else
		{
			s.push(-1);
		}
	}
	else if (sost == -1)
	{
		cout << "Err\n";
		return false;
	}
	else
	{
		s.push(-1);
	}
}

if (s.pop() == -1)
{
	cout << "Err\n";
	return false;
}


return true;
}
bool skob5(char *word)
{
	Stack<int> s(3);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (word[i] == '(')
				s.push(1);
			else if (inttrue(word[i]) || word[i] == 'b' || word[i] == 'a' || word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(0);
			else if (word[i] == ' ')
			{
				cout << "Yes\n";
				return true;
			}
			else
				s.push(-1);
		}
		else if (sost == 1)
		{
			if (word[i] == ')')
				s.push(0);
			else if (inttrue(word[i]) || word[i] == 'b' || word[i] == 'a' || word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			cout << "Err\n";
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		cout << "Err\n";
		return false;
	}


	return true;
}

void all(char *word)
{	
cout << "\n����� � ����. ������: ";
double1(word);
cout << "����� � ����. ������: ";
pleetouch2(word);
cout << "����������� �����: ";
complix3(word);
cout << "���������� �������������� ��������� ��� ������: ";
algebr4(word);
cout << "��� ������ �������� ������(��� �� ���): ";
skob5(word); 

}

bool inttrue(char s)
{
	switch (s)
	{
	case '1': return true; break;
	case '2': return true; break;
	case '3': return true; break;
	case '4': return true; break;
	case '5': return true; break;
	case '6': return true; break;
	case '7': return true; break;
	case '8': return true; break;
	case '9': return true; break;
	case '0': return true; break;

	default: return false;
		break;
	}
}


