//=====================================================
// Ashwin Krishnamurthy, Daniel Chu and Jianheng Guo
// Febuary 2024
// Hash.h
// This file contains definitions for the Hash
// Table class
//=====================================================

#include "Hash.h"
#include "List.cpp"

//=====================================================
// default constructor
//=====================================================
template <class T> 
	Hash<T>::Hash( void )
{
	int numSlots = 10;
	List<T>* arr_ptr = new List<T>[numSlots];
}

//=====================================================
// constructor with integer parameter
//=====================================================
template <class T> 
	Hash<T>::Hash( int table_size )
{
	int numSlots = table_size;
	List<T>* arr_ptr = new List<T>[numSlots];
}

//=====================================================
// copy constructor
//=====================================================
template <class T>
	Hash<T>::Hash( const Hash<T> &h )
{
	int numSlots = h.numSlots;
	List<T>* arr_ptr = new List<T>[numSlots];
	
	for (int i = 0; i < numSlots; i++)
	{
		arr_ptr[i] = h.arr_ptr[i]; // might be broken
	}
}

//=====================================================
// Destructor
//=====================================================
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
	if (this != hash)
	{
		delete arr_ptr[];
		
		int numSlots = other.numSlots;
		List<T>* arr_ptr = new List<T>[numSlots]; 
		for (int i = 0; i < numSlots; i++)
		{
			arr_ptr[i] = h.arr_ptr[i]; // might be broken
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
	for (int i = 0; i < numSlots; i++)
	{
		List<T> l1 = arr_ptr[i];
		if (l1.query(item) == true)
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
	int hashValue = item.getHashValue(numSlots);
	arr_ptr[hashValue].remove(item);
}

//=====================================================
// insert operator
//=====================================================
template <class T>
void Hash<T>::insert (T &item)
{
	int hashValue = item.getHashValue(numSlots);
	arr_ptr[hashValue].insert(item);
}


//=====================================================
// clear all
//=====================================================
template <class T>
void Hash<T>::clearAll (void );
{
	for (int i = 0; i < numSlots; i++)
	{
		arr_ptr[i].clear();
	}
}


//=====================================================
// getSlotCounts
//=====================================================
template <class T>
int getSlotCounts (int slot)
{
	List<T> l1 = arr_ptr[slot];
	return l1.length();
}

//=====================================================
// getNumSlots operator
//=====================================================
template <class T>
int Hash<T>::getNumSlots ( int slot )
{
	return numSlots;
}



