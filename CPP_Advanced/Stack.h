#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack
{
private:
	vector<T> items;
public:
	void push(T const&);  // ��ջ
	void pop();               // ��ջ
	T top() const;            // ����ջ��Ԫ��
	bool empty() const {       // ���Ϊ���򷵻��档
		return items.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	items.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (items.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	items.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (items.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return items.back();
}
