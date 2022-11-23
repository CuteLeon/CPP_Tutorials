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
	void push(T const&);  // 入栈
	void pop();               // 出栈
	T top() const;            // 返回栈顶元素
	bool empty() const {       // 如果为空则返回真。
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
