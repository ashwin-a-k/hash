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
	numSlots = h.numSlots
	arr_ptr = new List<T>[numSlots];
	
	for (int i = 0; i < numSlots; i++)
	{
		arr_ptr[i] = h.arr_ptr[i];
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
		
	}
	
}
