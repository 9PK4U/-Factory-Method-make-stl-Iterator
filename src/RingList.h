//#include <optional>
#include "Iterator.h"

template<class T>
class Node {
	template<class C>
	friend class RingList;
	template<class C>
	friend class Iterator;
	T data;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;

	Node(T value) : data(value){} 
	//~Node(){}
	Node* remove(void)
	{
		if (prev && next)
		{
			prev->next = next;
			next->prev = prev;
			next = prev = this;
		}
		return  this;
	}
public:
	bool operator==(T const &d) const
	{
		return data == d;
	}
	bool operator==(Node<T> *d) const
	{
		return this == d;
	}
	bool operator>(T const& d) const
	{
		return data > d;
	}
	bool operator<(T const& d) const
	{
		return data < d;
	}
	T operator*()
	{
		return data;
	}

	void operator=(Node<T> const& i)
	{
		data = i.data;
	}
	void getData(T dt)
	{
		data = dt;
	}
};
template<class T>
class RingList
{
	Node<T>* node = nullptr;
	Node<T>* beginNode = nullptr;
	size_t _size = 0;

public:
	typedef Iterator<Node<T>> iterator;
	typedef Iterator<const Node<T>> const_iterator;

	iterator begin()
	{
		if (!beginNode) { return beginNode; }
		return iterator(beginNode);
	}
	iterator end()
	{
		if (!node) { return node; }
		iterator it(node->next);
		it.flag = true;
		return it;
	}

	const_iterator begin() const
	{
		return const_iterator((const Node<T>*)beginNode);
	}
	const_iterator end() const
	{
		const_iterator&& it(node->next);
		it.flag = true;
		return it;
	}

	size_t size() const
	{
		return _size;
	}
	~RingList()
	{
		while (beginNode != nullptr)
		{
			removeElement(beginNode->data);
		}
	}

	void addElement(T value);
	void removeElement(T value);
};

template <class T>
inline void RingList<T>::addElement(T value) {
    Node<T>* tmp = new Node<T>(value);

    if (this->node == nullptr) {
        tmp->next = tmp->prev = tmp;
        this->node = tmp;
        this->beginNode = tmp;
    }
    else {
        tmp->next = node->next;
        node->next = tmp;
        tmp->prev = node;
        tmp->next->prev = tmp;
        node = tmp;
    }
	_size++;
}

template<class T>
inline void RingList<T>::removeElement(T value)
{
	for (auto &it : *this)
	{
		if (it.data == value)
		{
			
			if (it == beginNode)
			{
				if (beginNode == node)
				{
					it.next = nullptr;
					it.prev = nullptr;
				}
				beginNode = beginNode->next;
			}
			if (it == node)
			{
				if (beginNode == node)
				{
					it.next = nullptr;
					it.prev = nullptr;
				}
				node = node->prev;
			}
			it.remove();
			delete &it;
			_size--;
			break;
		}
	}
}
