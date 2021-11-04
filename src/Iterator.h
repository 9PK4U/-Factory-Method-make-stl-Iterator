#pragma once
#include <iterator>
#include <iostream>
template <class Iter>

class Iterator
{
	//friend class RingList;
public:
	using iterator_type		= Iter;
	using iterator_category = std::random_access_iterator_tag;
	using value_type		= iterator_type;
	using difference_type	= ptrdiff_t;
	using reference			= iterator_type&;
	using pointer			= iterator_type*;

	iterator_type* value;
	bool flag = false;

//private:
	Iterator(Iter* p) : value(p) {}
public:
	Iterator(const Iterator& it) : value(it.value), flag(it.flag) {}

	bool operator!= (Iterator const& other) const
	{
		if (value != other.value)
		{
			return true;
		}
		else
			if (flag != other.flag)
			{
				return true;
			}
		return false;
	}
	bool operator== (Iterator const& other) const
	{

		return value == other.value;
	}
	typename Iterator::reference operator*() const
	{
		return *value;
	}
	Iterator& operator++()
	{
		flag = true;
		value = value->next;
		return *this;
	}
		Iterator& operator--()
	{
		flag = false;
		value = value->prev;
		return *this;
	}
	difference_type operator-(Iterator const& other) const
	{
		return value - other.value;
	}
	Iterator& operator+=(difference_type v)
	{
		auto it = this;
		for (size_t i = 0; i < v; i++)
		{
			it->operator++();
		}
		
		return *it;
	}
	Iterator& operator+(difference_type v)
	{
		auto it = this;
		for (size_t i = 0; i < v; i++)
		{
			it->operator++();
		}
		return *it;
	}
	Iterator& operator-=(difference_type v)
	{
		auto it = this;
		for (size_t i = 0; i < v; i++)
		{
			it->operator--();
		}
		return *it;
	}
	Iterator& operator-(difference_type v)
	{
		auto it = this;
		for (size_t i = 0; i < v; i++)
		{
			it->operator--();
		}
		return *it;
	}
	bool operator<(Iterator const& other) const
	{
		if (other.value->data > value->data)
			return true;
		return false;
	}
};
