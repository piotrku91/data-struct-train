#pragma once
// Simple template stack implementation coded by Piotr K. (piotrq.eu)

template <typename T>
class stacky
{
private:
	struct node
	{
		T data;
		node *next;
	};
	node *head;

public:
	stacky() : head(nullptr){};
	stacky(const std::initializer_list<T> &x)
	{
		for (auto &item : x)
		{
			push(item);
		};
	};

	void push(const T &newdata)
	{
		node *tmpnode = new node();
		tmpnode->data = newdata;
		tmpnode->next = head;
		head = tmpnode;
	};

	void pop()
	{
		if (!empty())
		{
			node *tmpnode = head;
			head = head->next;
			delete tmpnode;
		};
	};

	bool empty()
	{
		return (head == nullptr);
	};

	void clear()
	{
		while (!empty())
		{
			pop();
		}
	};

	T top()
	{
		return head->data;
	};
};
