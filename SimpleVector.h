#pragma once
#include <algorithm>

template <typename T>
class SimpleVector
{
	T* data;
	int currentSize = 0;
	int currentCapacity = 10;
public:
	SimpleVector()
	{
		data = new T[currentCapacity];
	}
	SimpleVector(int capacity)
	{
		currentCapacity = capacity;
		data = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other)
	{
		currentCapacity = other.currentCapacity;
		currentSize = other.currentSize;
		data = new T[currentSize];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	}
	~SimpleVector()
	{
		delete[] data;
	}
	T& operator[](int i)
	{
		if (i >= currentSize) {
			throw std::out_of_range("범위 밖의 인덱스를 조회하려고 시도 중입니다...");
		}
		return data[i];
	}
	void resize(int capacity)
	{
		if (currentCapacity > capacity) return;
		currentCapacity = capacity;

		T* temp = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	};
	void push_back(const T& value)
	{
		if (currentSize == currentCapacity) {
			resize(currentCapacity + 5);
		}
		data[currentSize] = value;
		currentSize++;
	}
	void pop_back()
	{
		currentSize--;
	}
	int size() const
	{
		return currentSize;
	}
	int capacity() const
	{
		return currentCapacity;
	}
	void sortData()
	{
		std::sort(data, data + currentSize);
	}
};