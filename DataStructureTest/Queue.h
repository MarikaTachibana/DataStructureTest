#pragma once
#include "DataStructureBace.h"
#include <vector>
#include <assert.h>

template <typename T>
class Queue : public DataStructureBace
{
public:
	Queue(int size)
	{
		head = 0;
		dataArr.resize(size);
		this->size = size;
	}

	void Enqueue(T data)
	{
		if (cnt < size)
		{
			if (head + cnt >= size)
				dataArr[head + cnt - size] = data;
			else
				dataArr[head + cnt] = data;
			cnt++;
		}
		else
			assert(!"overflow");
	}
	
	T Dequeue()
	{
		T temp = -999;
		if (cnt > 0)
		{
			if (head >= size)
				head = 0;

			temp = dataArr[head];
			dataArr[head++] = 0;
			cnt--;
		}
		else
			assert(!"underflow");

		return temp;
	}

	int Size()
	{
		return size;
	}

	int Count()
	{
		return cnt;
	}

private:
	std::vector<T> dataArr;
	int head;
	int size;
	int cnt;
};