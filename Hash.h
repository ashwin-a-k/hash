//=====================================================
// Ashwin Krishnamurthy, Daniel Chu and Jianheng Guo
// Febuary 2024
// Hash.h
// This file contains definitions for the Hash
// Table class
//=====================================================
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "List.h"

#define DEFAULT_HASH_SIZE 10
using namespace std;

template<class T>
class Hash
{
private:
	int numSlots;
	List<T>* arr_ptr;
public:
			Hash		( void );
			Hash		( int table_size );
			Hash		( const Hash<T> &h );
			~Hash		( void );
	Hash<T>	operator=	( const Hash<T> &hash );
	bool		query		( const T &item );
	void		insert		( T &item );
	void 		clearAll	( void );
	int		getSlotCount	( int slot );
	int 		getNumSlots	( int slot );
	
}

#include "Hash.cpp"

#endif
