//=====================================================
// Ashwin Krishnamurthy, Daniel Chu and Jianheng Guo
// Febuary 2024
// Hash.h
// This file contains definitions for the Hash
// Table class
//=====================================================

#include<stdexcept>
#include "Hash.h"
#include "List.h"

//=====================================================
// default constructor
//=====================================================
template <class T> 
	Hash<T>::Hash( void )
{
	numSlots = 10;
	arr_ptr = new List<T>[numSlots];
}

//=====================================================
// constructor with integer parameter
//=====================================================
template <class T> 
	Hash<T>::Hash( int table_size )
{
	numSlots = table_size;
	arr_ptr = new List<T>[numSlots];
}

//=====================================================
// copy constructor
//=====================================================
template <class T>
	Hash<T>::Hash( const Hash<T> &h )
{
	numSlots = h.numSlots;
	arr_ptr = new List<T>[numSlots];
	
	for (int i = 0; i < numSlots; i++) {
		arr_ptr[i] = h.arr_ptr[i]; // might be broken
	}
}

//=====================================================
// Destructor
//=====================================================
template<class T>
	Hash<T>::~Hash	( void )
{
	delete[] arr_ptr;
}

//=====================================================
// assignment operator
//=====================================================
template <class T>
Hash<T> Hash<T>::operator= ( const Hash<T> &hash )
{
	if (this != hash) {
		delete[] arr_ptr;
		
		numSlots = hash.numSlots;
		List<T>* arr_ptr = new List<T>[numSlots]; 
		for (int i = 0; i < numSlots; i++) {
			arr_ptr[i] = hash.arr_ptr[i]; // might be broken
		}	
	}
	return *this;
	
}

//=====================================================
// query operator
//=====================================================
template <class T>
bool Hash<T>::query( const T &item )
{
	for (int i = 0; i < numSlots; i++) {
		if (arr_ptr[i].query(item))
			return true;
	}
	return false;
}

//=====================================================
// remove operator
//=====================================================
template <class T>
void Hash<T>::remove (T &item)
{
	int index = -1;
	for (int i = 0; i < numSlots; i++) {
		if (arr_ptr[i].query(item)) {
			index = i;
			break;
		}
	}
	if (index != -1)
		arr_ptr[index].remove(item);
}

//=====================================================
// insert operator NEED REVISION
//=====================================================
template <class T>
void Hash<T>::insert (T &item)
{
	int hashVal = item.getHashValue(numSlots);
	arr_ptr[hashVal].prepend(item); //front
}


//=====================================================
// clear all
//=====================================================
template <class T>
void Hash<T>::clearAll (void )
{
	for (int i = 0; i < numSlots; i++)
	{
		arr_ptr[i].clear();
	}
}


//=====================================================
// getSlotCount
//=====================================================
template <class T>
int Hash<T>::getSlotCount (int slot)
{
	return arr_ptr[slot].length();
}

//=====================================================
// getNumSlots operator
//=====================================================
template <class T>
int Hash<T>::getNumSlots ( void )
{
	return numSlots;
}