#pragma once

// Does not really work if you input a reference that is initialised inside the argument of Enqueue. 
// If it has been initialised beforehand it seems to work fine.

template<typename T>
class CircularQueue
{
public:
	CircularQueue(size_t size);
	~CircularQueue();
	bool Enqueue(const T& value);
	T* Dequeue();
	size_t Length() const;
	bool IsEmpty() const;

private:
	size_t _size;
	size_t _first;
	size_t _last;
	bool _isEmpty;

	const T** _circularQueue;
};

template<typename T>
inline CircularQueue<T>::CircularQueue(size_t size)
	: _first(-1), _last(-1), _isEmpty(true) //cursed overflow.
{
	_size = size;
	_circularQueue = new const T*[_size];
	
	if (!_circularQueue) //Redundant?
		throw std::exception("Could not create Queue.");

	_circularQueue[0] = nullptr;
}

template<typename T>
inline CircularQueue<T>::~CircularQueue() 
{
	delete(_circularQueue);
}

template<typename T>
inline bool CircularQueue<T>::Enqueue(const T& value)
{
	if (_last + 1 == _first) return false;


	_isEmpty = false;
	if (_size - 1 == _last) 
	{
		if (_circularQueue[0] == nullptr)
		{
			_last = 0;
			_circularQueue[_last] = &value;
			return true;
		}
		else
		{
			return false;
		}
	}
	_last++;
	_circularQueue[_last] = &value;
	return true;
}

template<typename T>
inline T* CircularQueue<T>::Dequeue()
{
	//std::cout << "first = " << _first << " last = " << _last << std::endl;
	if (_first == -1 && _last == 0) _isEmpty = true;
	
	if (_first == _last)
	{
		_isEmpty = true;
		return const_cast<T*>(_circularQueue[_first]);
	}
	if (_size - 1 == _first)
	{
		_first = 0;
		T* result = const_cast<T*>(_circularQueue[_first]);
		_circularQueue[_first] = nullptr;
		return result;
	}

	_first++;
	if (_first == _last) _isEmpty = true;

	T* result = const_cast<T*>(_circularQueue[_first]);
	_circularQueue[_first] = nullptr;
	return result;
}

template<typename T>
inline size_t CircularQueue<T>::Length() const
{
	return _size;
}

template<typename T>
inline bool CircularQueue<T>::IsEmpty() const
{
	return _isEmpty;
}