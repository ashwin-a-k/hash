//========================================================
// March 2024
// List.h
// Name: Daniel Chu, Ashwin Krishnamurthy 
// This file contains the List class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

template <class T> 
class List
{
private:
	// struct for Node for linked list
	struct Node
	{
		T	item;
		Node 	*next;
		Node  	*prev;
	};
	
	Node	*head;		// the pointer for the linked list
	Node	*tail;
	void	clear		(void );
	
public:
	List		( void );
	List		( const List<T> &mylist );
	~List		( void );
List<T> operator=	( const List<T> &mylist );
void	prepend	( const T &item);
void	append		( const T &item );
T &	operator[]	( int index );
void	insert		( const T &item, int index );
void	remove		( int index );
int	search		( const T &item ) const;
int	length		( void ) const;
bool	empty		( void ) const;
List<T> concat		( const List<T> &list ) const;
bool	query		( const T &item );

friend ostream & operator<< ( ostream &os, List<T> &mylist )
{
	Node *ptr = mylist.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}





};


#include "List.cpp"

#endif


