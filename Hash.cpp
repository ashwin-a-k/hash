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
// Hash ( void )
// Default Constructor for Hash class
// Parameters: none
// returns: none
//=====================================================
template <class T> 
	Hash<T>::Hash( void )
{
	numSlots = 10;
	arr_ptr = new List<T>[numSlots];
}

//=====================================================
// Hash( int table_size )
// constructor with integer parameter
// Parameters: int table_size
// returns none
//=====================================================
template <class T> 
	Hash<T>::Hash( int table_size )
{
	numSlots = table_size;
	arr_ptr = new List<T>[numSlots];
}

//=====================================================
// Hash (const Hash<T> &h )
// Copy Constructor
// Parameters: Hash<T> &h
// Returns: none
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
// ~Hash(void)
// Destructor, deletes the array pointer
// No Parameters
// Returns none
//=====================================================
template<class T>
	Hash<T>::~Hash	( void )
{
	delete[] arr_ptr;
}

//=====================================================
// operator= ( const Hash<T> &hash )
// assignment operator
// Parameters: Hash<T> &hash
// returns *this, a hash table
//=====================================================
template <class T>
Hash<T> Hash<T>::operator= ( const Hash<T> &hash )
{
	if (this != &hash) {
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
// query ( const T &item )
// Returns true if an item is in the list and if 
// it is not, it returns false
// Parameters: const T &item
// returns boolean true or false
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
// remove (T &item)
// remove operator, it removes something from the hash
// table
// Parameters: T &item
// Returns nothing
//=====================================================
template <class T>
void Hash<T>::remove (T &item)
{
	int index_hor = -1;
	int index_ver = -1;
	
	for (int i = 0; i < numSlots; i++) {
		index_ver = arr_ptr[i].search(item);
		if (index_ver != -1) {
			index_hor = i;
			break;
		}
		
	}
	if (index_hor != -1)
		arr_ptr[index_hor].remove(index_ver);
	else throw underflow_error("Can't find item to remove");
}

//=====================================================
// insert (T &item)
// insert operator NEED REVISION
// Parameters: T &item
// Returns nothing
//=====================================================
template <class T>
void Hash<T>::insert (T &item)
{
	int hashVal = item.getHashValue(numSlots);
	arr_ptr[hashVal].prepend(item); //front
}


//=====================================================
// clearAll (void)
// clears everything in the hash table
// Parameters: none
// Returns nothing
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
// getSlotCount(int slot)
// Takes an integer parameter indicating a slot in the 
// table and returns the number of items in the slot
// Parameters: none
// Returns arr_ptr[slot].length();
//=====================================================
template <class T>
int Hash<T>::getSlotCount (int slot)
{
	// throw error if it is out of range
	if(slot < 0 || slot > numSlots)
        	throw std::out_of_range("index is out of range");

	return arr_ptr[slot].length();
}

//=====================================================
// getNumSlots(void)
// Finds the number of slots in the table and returns it
// Parameters: none
// returns numSlots
//=====================================================
template <class T>
int Hash<T>::getNumSlots ( void )
{
	return numSlots;
}
