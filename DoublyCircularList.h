/*---DoublyCircularList.h--------------------------------------------------------------------

This is the header file for the Doubly-Circular Linked List implementation
Basic operations are:
    Constructor:            construct an empty list
    Copy Constructor:       create a copy of a list
    Destructor:             delete list from memory
    DoublyNode(class):      to instantiate a new node
    Assignment operator:    overload operator=
    isEmpty:                checks if list is empty
    search:                 checks if item exists in list
    insertAtPosition:       insert item at position
    insertAtEnd:            insert item at the end of list
    insertAtBeginning:      insert item at the beginning of the list
    deleteAtPosition:       deletes the node present at position
    deleteAValue:           deletes the node that contains the item
    deleteBeforeAnElement:  delete the node before the node where data was found
    findAndDelete:          deletes the all the occurrences of an item
    removeFirst:            cuts the first node from the list 
    removeLast:             cuts the last node from the list
    deleteDuplicates:       keeps only the first occurrence of an element in the list
    display:                display the content of the list
    operator<<:             overload operator<<

----------------------------------------------------------------------------------*/

/* 
 * File:   DoublyCircularList.h
 * Author: Elissa Abou Hassan
 *
 * Created on October 15, 2022, 3:03 PM
 */

#ifndef DCLIST_H
#define DCLIST_H

#include <iostream>
using namespace std;

typedef int ElementType;

class DCList{

    private:

        /*** DoublyNode class ***/
        class DoublyNode{
            public:
                ElementType data; //data in node
                DoublyNode *prev; //ptr to previous node in list
                DoublyNode *next; //ptr to next node in list

                /*DoublyNode default constructor*/
                DoublyNode(ElementType n):
                data(n), next(NULL), prev(NULL){
                }
        };

        typedef DoublyNode *NodePtr;

        int mySize; //size of list
        NodePtr myFirst; //ptr to first node in list
        
        /*
        Searches for node that contains data
        
        Precondition: data is the value to be searched for in the list
        Postcondition: a pointer to the node that contains the data is returns,
                        if data not found NULL is returned
        */
        NodePtr searchNode(const ElementType &data) const;

        /*
        Delete the node that contains the data in parameter

        Precondition: data is the value to be deleted from the list
        Postcondition: true is returned if data has been deleted from the list, 
                        false if not (execution interrupts if list is empty).
        */
        bool deleteAValue(ElementType data);
        

    public:

        /*
        Construct a DCList object.

        Precondition: mySize is set to 0 and myFirst is set to null
        Postcondition: an empty DCList is constructed
        */
        DCList():
        myFirst(NULL), mySize(0){
        };

        /*
        Construct a copy of DCList object.

        Precondition: A copy of orig is needed; orig is a const
                      reference parameter. 
        Postcondition:  A copy of orig has been constructed.
        */
        DCList(const DCList &orig);

        /*
        Destroys a DCList object.

        Precondition:  The life of a DCList object is over.
        Postcondition: The memory allocated by the constructor
        for the DCList object has been returned to the heap.
        */
        ~DCList();

        /*
        Assign a copy of a DCList object to the current object.

        Precondition: none 
        Postcondition: A copy of rightHandSide has been assigned to this
        object. A const reference to this list is returned.
        */
        DCList& operator=(const DCList &rightHandSide);

        /*
        Check if a list is empty.

        Precondition:  none
        Postcondition: true is returned if the list is empty, false if not.
        */
        bool isEmpty() const;

        /*
        Check if item exists in list

        Precondition: data is the value to search for in the list.
        Postcondition: true is return if item is found, false if not.
        */
        bool search(const ElementType &data) const;

        /*
        Insert an item into the list at a given position.

        Precondition:  data is the value to be inserted, pos is the position
        Postcondition: true if item has been inserted into the list at the position
                        in parameter, false if not. Invalid position, return false
        */
        bool insertAtPosition(ElementType data, int pos);

        /*
        Insert an item at the end of the list

        Precondition: data is the value to be inserted at the end; 
                    insertAtPosition() is invoked to insert data.
        Postcondition: true is returned if data has been inserted into the list at the end, 
                        false if not.
        */
        bool insertAtEnd(ElementType data);

        /*
        Insert an item at the beginning of the list

        Precondition: data is the value to be inserted at the beginning; 
                       insertAtPosition() is invoked to insert data.
        Postcondition: true is returned if data has been inserted into the list at the beginning, 
                        false if not.
        */
        bool insertAtBeginning(ElementType data);

        /*
        Delete the node present at position

        Precondition: pos indicates the position of the data to be deleted
        Postcondition: true is returned if data at pos has been deleted from the list, 
                        false if not (execution interrupted if list is empty).
        */
        bool deleteAtPosition(int pos);

        /*
        Delete the node before the node where data was found.

        Precondition: takes an item data of type ElementType and searches for it in the DCList.
        Postcondition: If data is found, then it should delete the node before the node where data 
                        was found and return true, false if not (execution interrupted if list is empty).
        */
        bool deleteBeforeAnElement(ElementType data);

        /*
        Delete all the occurrences of an item data.

        Precondition: data is the item to be deleted from the list
        Postcondition: if item is found, delete all occurrences and return
                        number of deleted occurrences.
        */
        int findAndDelete(const ElementType &data);

        /*
        Cut the first node from the list and return its data.

        Precondition: none
        Postcondition: cuts the first node from the list and returns its data.
                        If the list is empty, the function should interrupt the execution.
        */
        ElementType removeFirst();

        /*
        Cut the last node from the list and return its data.

        Precondition: none
        Postcondition: cuts the last node from the list and returns its data.
                        If the list is empty, the function should interrupt the execution.
        */
        ElementType removeLast();

        /*
        Keep only the first occurrence of an element in the list and remove all the others

        Precondition: none
        Postcondition: returns the number of deleted repeated items. 
                        If the list is empty, the function should interrupt the execution.
        */
        int deleteDuplicates();

        /*
        Display a list.

        Precondition:  The ostream out is open. 
        Postcondition: The list represented by this DCList object has been
        inserted into out. 
        */
        void display(ostream &out) const;

};

/* Prototype of output operator */ 
ostream &operator<<(ostream &out, const DCList &list);

#endif /* DCLIST_H */
