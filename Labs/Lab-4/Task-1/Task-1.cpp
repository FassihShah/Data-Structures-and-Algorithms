#include<iostream>
#include"String.h"
#include"Stack_Implementation.cpp"
using namespace std;
bool isValid(const String& s)
{
	Stack<char> stack(100);
	int size = s.getSize();
	for (int i = 0; i < size; i++)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			stack.push(s[i]);
		else if ((s[i] == '}' && stack.top() == '{') || (s[i] == ')' && stack.top() == '(') || (s[i] == ']' && stack.top() == '['))
		{
			stack.pop();
		}
	}
	if (stack.isEmpty())
		return true;
	return false;
}
int main()
{
	String s = { "((()){})" };
	cout << isValid(s);
	cout << endl;
	return 0;
}