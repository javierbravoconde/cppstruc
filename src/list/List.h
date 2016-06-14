/*
 * List.h
 *
 *  Created on: Jun 13, 2016
 *      Author: javier
 */

#ifndef LIST_LIST_H_
#define LIST_LIST_H_

#include <boost/shared_ptr.hpp>
#include <iostream>

namespace structs {

template<typename T> class List;
template<typename T> class mylist_iterator;


template<typename T>
class Cell {

	friend class List<T> ;
	friend class mylist_iterator<T> ;

public:
	Cell(T value) :
			_value(value) {

	}
private:
	boost::shared_ptr<Cell> _next;
	T _value;
};

template<typename T>
class List {
public:
	List() {
	}
	virtual ~List() {
	}

	typedef mylist_iterator<T> iterator;

	void push_front(T iValue) {
		boost::shared_ptr<Cell<T> > aNewCell(new Cell<T>(iValue));

		if (_head) {
			aNewCell->_next = _head;
		} else {
			_tail = aNewCell;
		}
		_head = aNewCell;

	}

	void push_back(T iValue) {
		boost::shared_ptr<Cell<T> > aNewCell(new Cell<T>(iValue));

		if (_head) {
			_tail->_next = aNewCell;
		} else {
			_head = aNewCell;
		}

		_tail = aNewCell;
	}

	iterator begin() { return mylist_iterator<T>(_head); }
	iterator end() { return mylist_iterator<T>(boost::shared_ptr<Cell<T> >()); }

private:

	boost::shared_ptr<Cell<T> > _head;
	boost::shared_ptr<Cell<T> > _tail;
};

template<typename T>
class mylist_iterator: public std::iterator<std::forward_iterator_tag, T> {
	friend class List<T> ;

public:
	T& operator*();
	const mylist_iterator<T>& operator++();
	bool operator!=(const mylist_iterator<T>& other) const;

private:
	boost::shared_ptr< Cell<T> > _pointee;
	mylist_iterator(boost::shared_ptr< Cell<T> > pointee) :
		_pointee(pointee) {
	}
};



template<typename T>
T& mylist_iterator<T>::operator*() {
	return _pointee->_value;
}
template<typename T>
const mylist_iterator<T>& mylist_iterator<T>::operator++() {
	assert(_pointee != NULL);
	_pointee = _pointee->_next;
	return *this;
}
template<typename T>
bool mylist_iterator<T>::operator!=(const mylist_iterator<T>& other) const {
	return this->_pointee != other._pointee;
}

} /* namespace structs */

#endif /* LIST_LIST_H_ */
