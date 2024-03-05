//===============================
// List.cpp
// List with Linked List Structure with method implementations
// Name: Daniel Chu, Ashwin Krishnamurthy 
// March 2024
//===============================



#include "List.h"

//==============================================
// List(void)
// Contructor for List class
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
List<T>::List( void ){

    head = NULL;
    tail = NULL;

}

//==============================================
// List(const List<T> &mylist)
// Contructor for List class
// Create a new List from an existing one.
// INPUT: const List<T> &mylist
// RETURN: none
//==============================================
template <class T> 
List<T>::List( const List<T> &mylist ){
    
    head = NULL;
    tail = NULL;
    if (mylist.head == NULL) {
        // If the input list is empty, return
        return;
    } 

    Node * qtr = mylist.head;
    
    // copy the Node until the end
    while (qtr != NULL) {
        append(qtr->item);
        qtr = qtr->next;
    }
    
}


//==============================================
// ~List(void)
// Destructor for List class
// Cleans up the memory of the list.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
List<T>::~List	( void ){

	clear();
    // Call clear function for destruction
    Node* ptr;

    // clear all the dynamically allocated memeory to the list nodes
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }

    // set the tail to NULL
    tail = NULL;


}

//==============================================
// operator= ( const List<T> &mylist )
// Assignment operator.
// Assign list to the class
// INPUT: const List<T> &mylist 
// RETURN: List<T>
//==============================================
template <class T> 
List<T> List<T>::operator= ( const List<T> &mylist ){

    // clear the existing list before assign new value for the new list
    clear();
    
    head = NULL;
    tail = NULL;

    // if the input list is empty, return
    if (mylist.head == NULL) {
        return *this;
    } 

    Node * qtr = mylist.head;
    while (qtr != NULL) {
        append(qtr->item);
        qtr = qtr->next;
    }
    

    return *this;

}



//==============================================
// append (const T &item)
// Appends a new item onto the back of the list.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void	List<T>::append( const T &item	){

    Node* newNode = new Node{item, NULL, NULL};


    //if there is no element in the list then assign new node to the head and tail and return
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // append newNode to the tail
    Node *qtr = tail;
    qtr->next = newNode;
    newNode->prev =qtr;

    // update tail node
    tail = newNode;
}



//==============================================
// prepend (const T &item)
// prepend a new item onto the front of the list.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void	List<T>::prepend( const T &item	){

    // create newNode instance
    Node* newNode = new Node{item, NULL, NULL};


    //if there is no element in the list then assign new node to the head and tail and return
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // append newNode to the front
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}




//==============================================
// operator[](int index)
// Accesses (by reference) the item at the specified index.
// INPUT: int index
// RETURN: T &
//==============================================
template <class T> 
T &		List<T>::	operator[]	( int index ){

    // Throw erre if out of range
    if(index < 0 || index > length() -1){
        cout << "Out of range" << endl;
        throw std::out_of_range("List<T>::operator[] : index is out of range");
    }

    Node *qtr = head;

    // not sure to include qtr != NULL && index >0
    while(index > 0){
        index --;  
        qtr = qtr->next;
    }

    return qtr->item;



}

//==============================================
// insert(const T &item, int index)
// Inserts a new value at the specified position.
// INPUT: const T &item, int index
// RETURN: none
//==============================================
template <class T> 
void List<T>::insert(const T &item, int index ){

    // throw error if it is out of range
    if(index < 0 || index > length()){
        cout << "Invalid position" << endl;
        throw std::out_of_range("List<T>::insert(const T &item, int index ) : index is out of range");

    }

    // if it is inserting to the head, then just prepend
    if (index == 0) {
        prepend(item);
        return;
    }

    // if it is end, jsut call append
    if(index == length()){
        append(item);
        return;
    }

    // create new node for the insert
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node *qtr = head;
    // loop to the index where to insert
    while(index > 1){
        index--;  
        qtr = qtr->next;
    }

    // insert the new node
    newNode->next = qtr->next;
    newNode->prev = qtr;
    if(qtr->next !=NULL){
        qtr->next->prev = newNode;
    }

    qtr->next = newNode;

}

//==============================================
// remove(int index)
// Removes an item at the specified location.
// INPUT: int index
// RETURN: none
//==============================================
template <class T> 
void	List<T>::	remove		( int index ){

    if(index < 0 || index > length()-1){
        cout << "Invalid position" << endl;
        throw std::out_of_range("List<T>::remove( int index ) : index is out of range");
    }

    Node* temp; 

    // if we try to delete the first node of the list 
    if (index == 0) {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    
    Node *qtr = head;
    if(index == length()-1){
        tail = tail->prev;
    }
    // loop to the node we try to delete (need to be the node that points to the node we are trying to delete)
    while(index > 1){
        index--;  
        qtr = qtr->next;
    }

    temp = qtr->next;
    qtr->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = qtr;
    }

    delete temp;

}



//==============================================
// length( void )
// Returns the number of items in the list.
// INPUT: none
// RETURN: int
//==============================================
template <class T> 
int		List<T>::	length		( void ) const{

    int cnt = 0;
    Node *qtr = head;
    
    // loop until it reach to the end of the list
    while(qtr != NULL){
        qtr = qtr->next;
        cnt ++;
    }

    return cnt;


}


//==============================================
// search( const T &item )
// Returns the index of items in the list.
// INPUT: const T &item
// RETURN: int
//==============================================
template <class T> 
int		List<T>::	search		( const T &item ) const{

    // set defalut index to -1
    int index = -1;

    Node *qtr = head;

    // loop till the end of the list
    while(qtr != NULL){
        index++;
        if(qtr->item == item){ // If the item is found, return the index
            return index;
        }
        qtr = qtr->next; // move the next node
    }

    return -1;


}


//==============================================
// isEmpty(void)
// Returns true if the list is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================
template <class T> 
bool	List<T>::	empty		( void ) const{

    return head == NULL; // check the head is pointing to null, if so then the list is empty

}



//==============================================
// concat(const List<T> &mylist )
// concat two existing lists to return the newly created list.
// INPUT: const List<T> &mylist
// RETURN: List<T>
//==============================================
template <class T> 
List<T>	List<T>::concat( const List<T> &mylist ) const{

    //create newly created list for return
    List<T> resultList;

    Node* ptr = head;

    // start appending first list
    while (ptr != NULL) {
        resultList.append(ptr->item);
        ptr = ptr->next;
    }

    // start appending second list
    Node* qtr = mylist.head;
    while (qtr != NULL) {
        resultList.append(qtr->item);
        qtr = qtr->next;
    }

    // tail should be pointing to the last node memory address


    return resultList;
}

 


//==============================================
// clear( void )
// Removes all items from the list.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
void List<T>::clear( void ){

    Node* ptr;

    // clear all the dynamically allocated memeory to the list nodes
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }

    // set the tail to NULL
    tail = NULL;

}

//==============================================
// query( void )
// checks if something is in the list or not
// INPUT: none
// RETURN: boolean true or false
//==============================================
template <class T> 
bool List<T>query ( const T &item );
{
    // set defalut index to -1
    int index = -1;

    Node *qtr = head;

    // loop till the end of the list
    while(qtr != NULL){
        index++;
        if(qtr->item == item){ // If the item is found, return the index
            return true;
        }
        qtr = qtr->next; // move the next node
    }

    return false;
}

