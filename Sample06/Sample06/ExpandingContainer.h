#ifndef GROWINGCONTAINER_H
#define GROWINGCONTAINER_H

#include <iostream>


template<typename  dataType, unsigned initSize = 5, unsigned growCoeficient = 2>
class ExpandingContainer {
private:
	dataType* _array;
	unsigned _arraySize;
	unsigned _numberOfValidElements;
	void extendArray();
	bool isFreeSpaceInArray() const;
public:
	ExpandingContainer();
	~ExpandingContainer();
	void Add(const dataType& o);
	dataType& operator[](int index);
	dataType operator[](int index) const;
	unsigned int Size() const;
	void AddToIndex(int index, const dataType& o);
	void Remove(int index);
};

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
ExpandingContainer<dataType, initSize, growCoeficient>::ExpandingContainer() {
	if (growCoeficient <= 1)
		throw std::invalid_argument("invalid grow coeficient - must be greater than 1");
	if (initSize <= 0)
		throw std::invalid_argument("invalid init size - muset be larger than 0");

	_arraySize = initSize;
	_array = new dataType[initSize];
	_numberOfValidElements = 0;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
ExpandingContainer<dataType, initSize, growCoeficient>::~ExpandingContainer() {
	delete[] _array;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
bool ExpandingContainer<dataType, initSize, growCoeficient>::isFreeSpaceInArray() const {
	return _numberOfValidElements < _arraySize;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
void ExpandingContainer<dataType, initSize, growCoeficient>::extendArray() {
	dataType* tmpArray = new dataType[_arraySize * growCoeficient];
	for (unsigned i = 0; i < _arraySize; i++) {
		tmpArray[i] = _array[i];
	}

	dataType* tmp = _array;
	_array = tmpArray;
	delete[] tmp;
	_arraySize *= growCoeficient;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
void ExpandingContainer<dataType, initSize, growCoeficient>::Add(const dataType& o) {
	if (!isFreeSpaceInArray()) {
		extendArray();
	}
	_array[_numberOfValidElements++] = o;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
dataType& ExpandingContainer<dataType, initSize, growCoeficient>::operator[](int index) {
	if (index < 0 || index >= _numberOfValidElements) {
		throw std::out_of_range("invalid index parameter");
	}
	return _array[index];
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
dataType ExpandingContainer<dataType, initSize, growCoeficient>::operator[](int index) const {
	if (index < 0 || index >= _numberOfValidElements) {
		throw std::out_of_range("invalid index parameter");
	}
	return _array[index];
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
unsigned int ExpandingContainer<dataType, initSize, growCoeficient>::Size() const {
	return _numberOfValidElements;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
void ExpandingContainer<dataType, initSize, growCoeficient>::AddToIndex(int index, const dataType& o) {
	if (index < 0 || index >= _arraySize)
		throw std::out_of_range("invalid index parameter");
	if (index > _numberOfValidElements)
		throw std::invalid_argument("invalid index - will make array inconsistent");
	if (index == _numberOfValidElements)
	{
		Add(o);
		return;
	}
	if (!isFreeSpaceInArray()) {
		extendArray();
	}
	for (int i = _numberOfValidElements; i >= index+1; i--)
	{
		_array[i] = _array[i-1];
	}
	_array[index] = o;
	_numberOfValidElements++;
}

template<typename  dataType, unsigned initSize, unsigned growCoeficient>
void ExpandingContainer<dataType, initSize, growCoeficient>::Remove(int index) {
	if (index < 0 || index >= _numberOfValidElements) {
		throw std::out_of_range("invalid index parameter");
	}
	while (index < _numberOfValidElements - 1)
	{
		_array[index] = _array[index + 1];
		index++;
	}
	_numberOfValidElements--;
}
#endif // !GROWINGCONTAINER_H