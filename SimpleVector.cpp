#include "SimpleVector.h"


template <typename T>
SimpleVector<T>::SimpleVector()
{
	data = new T[currentCapacity];
}