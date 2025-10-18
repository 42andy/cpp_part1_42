#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (n > 0)
		_array = new T[n]();
}

template<typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (_array)
			delete[] _array;

		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBounds();
	return _array[index];
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBounds();
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
