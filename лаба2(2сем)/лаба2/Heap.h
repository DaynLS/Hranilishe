#pragma once
#include <iostream>

template <class T>
class BinaryHeap
{
	static const int MAXsize = 100;
	int heapsize;
	T* keeping;
public:
	BinaryHeap()
	{
		keeping = new T[MAXsize];
		heapsize = 0;
	}
	~BinaryHeap()
	{
		delete[] keeping;
	}
	void addelem(T a)
	{
		int i, parent;
		i = heapsize;
		parent = (i - 1) / 2;
		keeping[i] = a;
		while (parent >= 0 && i > 0)
		{
			if (i == 0)
				break;
			if (keeping[i] < keeping[parent])
			{
				T temp = keeping[parent];
				keeping[parent] = keeping[i];
				keeping[i] = temp;
			}
			i = parent;
			parent = (i - 1) / 2;
		}
		heapsize++;
	}
	void pop_forward()
	{
		T tech;
		keeping[0] = tech;
		keeping[0] = keeping[MAXsize - 1];
		heapsize--;
		heapify(0);
	}
	T top()
	{
		return(keeping[0]);
	}
	void heapify(int i)
	{
		int left, right;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < heapsize) {
			if (keeping[i] > keeping[left]) {
				swap(keeping[i], keeping[left]);
				heapify(left);
			}
		}
		if (right < heapsize) {
			if (keeping[i] > keeping[right]) {
				swap(keeping[i], keeping[right]);
				heapify(right);
			}
		}
	}
	int getsize()
	{
		return(this->heapsize);
	}
};

/*void outHeap()
	{
		int i = 0;
		int check = 1;
		while (i < heapsize)
		{
			while ((i < check) && (i < heapsize))
			{
				std::cout << keeping[i] << " ";
				i++;
			}
			std::cout << "\n";
			check = check * 2 + 1;
		}
	}*/