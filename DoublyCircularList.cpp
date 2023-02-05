/*---DoublyCircularList.cpp------------------------------------------
            This file implements DCList's functions
--------------------------------------------------------------------*/

/* 
 * File:   DoublyCircularList.cpp
 * Author: Elissa Abou Hassan
 *
 * Created on October 15, 2022, 3:03 PM
 */

#include "DoublyCircularList.h"


//List copy constructor
DCList:: DCList(const DCList &orig){
    //if original list is empty, interrupt execution
    if(orig.isEmpty()){
        exit(1);
    }
    mySize = 0;
    myFirst = NULL;
    //store myFirst ptr of orig list in temp
    NodePtr temp = orig.myFirst;
    //loop through orig list until size
    for(int i = 0; i < orig.mySize; i++){
        //insert data in temp ptr into the copy list at the end
        if(insertAtEnd(temp->data)){
            //move to next node of orig list
            temp = temp->next;
        }
       
    }
}

//Overload assignment operator
DCList& DCList:: operator=(const DCList& rightHandSide){
    
    if(this == &rightHandSide){
        return *this;
    }
    this->~DCList();
    
    mySize = 0;
    myFirst = NULL;
    
    //after deleting the list check if rightHandSide is empty
    if(rightHandSide.isEmpty()){
        return *this; //return *this
    }
    
    NodePtr temp = rightHandSide.myFirst;
    for(int i = 0; i < rightHandSide.mySize; i++){
        if(insertAtEnd(temp->data)){
             temp = temp->next;
        }
    }
    return *this;
}

//Destructor
DCList:: ~DCList(){
    NodePtr temp; //pointer for iteration

    /*
    Using a while loop to remove nodes from the chain 
    if myFirst is not equal to null
    */
    for (int i = 0; i < mySize; i++){
        temp = myFirst;
        myFirst = myFirst->next;

        delete temp;
    }
}

//Search node 
DCList:: NodePtr DCList:: searchNode(const ElementType &data) const{

    //if list is empty
    if(isEmpty()){
        return NULL;
    }

    NodePtr temp = myFirst;
    //traverse loop to find data
    for(int i = 0; i < mySize; i++){
        if(temp->data == data){
            return temp; //if found, return ptr to data
        }
        temp = temp->next;
    }
    return NULL;
}

//Checks if list is empty
bool DCList:: isEmpty() const{
    return mySize == 0;
}

//Search for data in list
bool DCList:: search(const ElementType &data) const{

    //if list is empty
    if(isEmpty()){
        cerr<<"The List is empty, nothing to search."<<endl;
        exit(1);
    }

    //if data is not null (found) return true
    if(searchNode(data) != NULL){
        return true;
    }
    //if not found return false
    else{
        return false;
    }

}

//Insert data at position
bool DCList:: insertAtPosition(ElementType data, int pos){

    //Check if position is invalid
    if(pos < 0 || pos > mySize){
        cerr<<"Invalid position.\nThe list remains intact."<<endl;
        return false;
    }

    //Ptr to store myFirst 
    NodePtr temp = myFirst;
    //Create a new node to insert
    NodePtr newNode = new DoublyNode(data);

    //If list is empty
    if(myFirst == NULL){
        myFirst = newNode; //myFirst now points to the newNode
        newNode->next = myFirst; //assign next of newNode to myFirst
        newNode->prev = myFirst; //assign prev of newNode to myFirst

        mySize++;
        return true;
    }

    //Insert at beginning
    if(pos == 0){
        newNode->next = myFirst; //new node points to my first
        //to make it circular (connect first and last node)
        newNode->prev = myFirst->prev; //prev of new node points to last node
        newNode->prev->next = newNode; // next of last node points to newNode
        myFirst->prev = newNode; //prev of my first now points to newNode

        myFirst = newNode; //myFirst now points to the new node at beginning

        mySize++;
        return true;
    }

    //Insert at middle or end
    else{
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }

        newNode->next = temp->next;
        (temp->next)->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;

        mySize++;
        return true;
    }
    return false;
}

//Insert at end
bool DCList:: insertAtEnd(ElementType data){
    return insertAtPosition(data, mySize);
}

//Insert at beginning
bool DCList:: insertAtBeginning(ElementType data){
    return insertAtPosition(data, 0);
}

//Delete at position
bool DCList:: deleteAtPosition(int pos){

    //if list is empty
    if(isEmpty()){
        cerr<<"List is empty.\nNothing to delete"<<endl;
        exit(1);
    }

    //if position is invalid
    if(pos < 0 || pos >= mySize){
        cerr<<"Invalid position."<<endl;
        return false;
    }

    NodePtr toDelete = myFirst;

    //if there is only one node in the list
    if(mySize == 1){
        myFirst = NULL; //point myFirst to null
        delete toDelete; //delete node
        mySize--;
        return true;
    }

    //delete node at pos 0
    if(pos == 0){
        //to make it circular (connect first and last node)
        (myFirst->next)->prev = myFirst->prev; //point prev of second node to last node
        (myFirst->prev)->next = myFirst->next; //point next of last node to second node
        myFirst = myFirst->next;

        delete toDelete;
        mySize--;
        return true;
    }

    //delete node from middle or end
    else{
        NodePtr predPtr;

        //iterate till position
        for(int i = 0; i < pos; i++){
            predPtr = toDelete; //predecessor of node to be deleted
            toDelete = toDelete->next; //points to node to be deleted
        }

        //to make it circular (connect first and last node)
        predPtr->next = toDelete->next;
        toDelete->next->prev = predPtr;

        delete toDelete;
        mySize--;
        return true;
    }
    return false;
}

//Delete a value
bool DCList:: deleteAValue(ElementType data){

    //if list is empty
    if(isEmpty()){
        cerr<<"List is empty.\nNothing to delete"<<endl;
        exit(1);
    }
    
    //if only one element in list
    if(mySize == 1){
        NodePtr toDelete = myFirst;
        myFirst = NULL; //point myFirst to null
        delete toDelete; //delete node
        mySize--;
        return true;
        
    }

    NodePtr toDelete = searchNode(data); //stor ptr of data to delete
    //if data is not found
    if(toDelete == NULL){
        cerr<<"Data is not in the list\n";
        return false;
    }
    
    NodePtr predPtr = toDelete->prev;
    
    if (toDelete == myFirst)
        myFirst = toDelete->next;
    
    predPtr->next = toDelete->next;
    toDelete->next->prev = predPtr;

    delete toDelete;
    mySize--;
    return true;

}

//Delete before an element
bool DCList:: deleteBeforeAnElement(ElementType data){

    //if list only has one node
    if(mySize == 1){
        cerr<<"List only has one element.\nNothing to delete before it."<<endl;
        return false;
    }

    NodePtr temp = searchNode(data);
    if(temp == NULL){
        cerr<<"Data is not in the list\n";
        return false;
    }
    
    NodePtr toDelete = temp->prev;
    
    if(toDelete == myFirst){
        myFirst = temp;
    }
    
    temp->prev = toDelete->prev;
    toDelete->prev->next = temp;

    delete toDelete;
    mySize--;
    return true;

}

//find data and delete all occurrences 
int DCList:: findAndDelete(const ElementType &data){
    //if list is empty
    if(isEmpty()){
        cerr<<"List is empty.\nNothing to delete"<<endl;
        exit(1);
    }

    //traverse through list
    int deletionCounter = 0;
    int origSize = mySize; //var to store initial size before deleting
    for(int i = 0; i < origSize; i++){
        if(searchNode(data) != NULL){ 
            deleteAValue(data); //if data found, delete it
            deletionCounter++; // and increment count
        }
        else{
            break;
        }
    }
    return deletionCounter; //return number of deleted nodes
}

//remove first element in list
ElementType DCList:: removeFirst(){
    ElementType toRemove = myFirst->data;
            
    if(deleteAtPosition(0)){
        cout<<"First element deleted successfully\n"; //print this if deleted successfully
    }
    return toRemove; //return data of first element
}

//remove last element in list
ElementType DCList:: removeLast(){
    ElementType toRemove = myFirst->prev->data;
    
    if(deleteAtPosition(mySize-1)){
        cout<<"Last element deleted successfully\n"; //print this if deleted successfully
    }
    return toRemove; //return data of last element
}

//delete duplicates in list
int DCList:: deleteDuplicates(){
    //if list is empty
    if(isEmpty()){
        cerr<<"List is empty.\nNothing to delete"<<endl;
        exit(1);
    }
    
    int deletionCount = 0; //count number of deleted duplicates
    
    //i and j to determine position of data
    int i = 0;
    int j = 0;
    
    NodePtr curr = myFirst; //set curr ptr to first node
    NodePtr temp = myFirst->next; //set temp to next node of curr
    while(curr->next != myFirst){
        
        i = j + 1;
        while(temp->next != myFirst->next){
            //if duplicate found, delete it
            if(temp->data == curr->data){ 
                temp = temp->next; //move temp to next, to compare it to curr
                deleteAtPosition(i);
                deletionCount++;
            }
            //if not found, move to next node and increment position
            else{
                temp = temp->next;
                i++;
            }
        }
        curr = curr->next; //now move curr to next node, to compare it again
        temp=curr->next;
        j++;
    }
    return deletionCount;
    
}

//display list
void DCList:: display(ostream &out) const{
    
    //if list is empty
    if(isEmpty()){
        out<<"\nThe list is empty"<<endl;
    }
    else{
        out<<"\nThe list is: ";
        NodePtr temp = myFirst; //ptr to traverse through list
        for(int i = 0; i < mySize; i++){
            out<<temp->data<<" "; //print data
            temp = temp->next; //move ptr to next node
        }
        out<<endl;
    }
}

//overload operator <<
ostream &operator<<(ostream &out, const DCList &list){
    list.display(out);
    return out;
}






