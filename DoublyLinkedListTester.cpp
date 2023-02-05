/*--main.cpp--------------------------------------------------
 
     This is the tester file for the DCList implementation
 
-------------------------------------------------------------*/
/* 
 * File:   main.cpp
 * Author: Elissa Abou Hassan
 *
 * Created on October 15, 2022, 3:02 PM
 */

#include <cstdlib>
#include "DCList.h"

using namespace std;

//prototype
void menu();

int main(int argc, char** argv) {
    
    DCList myTestList; //create empty list
    int choice, data, pos;
    

    cout<<"Welcome to Doubly-Circular Linked List Test program.\n"
            "An Empty DCList of integers has been created for you.\n";
    
    do{
        menu(); //invoke function to display options
        cin>> choice; //input choice
        
        switch(choice){
            
            //choice 1
            case 1:{
                cout<<"Input data to insert at beginning:\n";
                cin>> data; 
                
                if(myTestList.insertAtBeginning(data)){
                    cout<<"Element was successfully inserted at the beginning of the list"<<endl;
                }
                cout<<myTestList; //display list
                
                break;
            }
            
            //choice 2
            case 2:{
                cout<<"Input data to insert at end:\n";
                cin>> data;
                
                if(myTestList.insertAtEnd(data)){
                    cout<<"Element was successfully inserted at the end of the list"<<endl;
                }
                cout<<myTestList;
                
                break;
            }
            
            //choice 3
            case 3:{
                cout<<"Please enter position of the array "
                        "you would like to insert an element at (any value >= 1)\n";
                cin>> pos;
                
                cout<<"Input data to insert:\n";
                cin>> data;
                
                if(myTestList.insertAtPosition(data, pos-1)){
                    cout<<"Element was successfully inserted at pos " <<pos<< " of the list"<<endl;
                }
                cout<<myTestList;
                
                break;
            }
            
            //choice 4
            case 4:{
                
                cout<<"\nPlease enter position of the array "
                        "you would like to delete an element at (any value >= 1)\n";
                cin>> pos;
                
                if(myTestList.isEmpty()){
                    cout<<"The list is empty";
                }
                
                else if(myTestList.deleteAtPosition(pos-1)){
                    cout<<"Element was successfully deleted at pos " <<pos<< " of the list"<<endl;
                    cout<<myTestList;
                }
                
                else{
                    cout<<"Element was not deleted"<<endl;
                    cout<<myTestList;
                }
                
                
                break;
            }
            
            //choice 5
            case 5:{
                cout<<myTestList;
                
                cout<<"Please enter the value you want to delete the one before it:\n";
                cin>>data;
                
                if(myTestList.deleteBeforeAnElement(data)){
                    cout<<"Data before "<<data<<" was successfully deleted"<<endl;
                }
                cout<<myTestList;
                
                break;
            }
            
            //choice 6
            case 6:{
                cout<<"Please enter the value you want to search for in the list:\n";
                cin>>data;
                
                if(myTestList.isEmpty()){
                    cout<<"The list is empty";
                }
                
                else if(myTestList.search(data)){
                    cout<<data<<" was successfully found in the list"<<endl;
                    cout<<myTestList;
                }
                else{
                    cout<<data<< " was not found in the list"<<endl;
                    cout<<myTestList;
                }
                
                
                break;
            }
            
            //choice 7
            case 7:{ 
                cout<<"Enter data to find and delete all occurrences:\n";
                cin>>data;
                
                if(myTestList.isEmpty()){
                    cout<<"The list is empty";
                }
                
                else{
                    int numOfDeleted = myTestList.findAndDelete(data);
                    
                    cout<<numOfDeleted<<" occurrences of the data were deleted"<<endl;
                    cout<<myTestList;
                }
                
                
                
                
                break;
                
            }
            
            //choice 8
            case 8:{
                cout<<myTestList;
                
                data = myTestList.removeFirst();
                cout<<"Value of first element deleted is: "<< data<<endl;
                
                cout<<myTestList;
                
                break;
            }
            
            //choice 9
            case 9:{
                cout<<myTestList;
                
                data = myTestList.removeLast();
                cout<<"Value of last element deleted is: "<< data<<endl;
                
                cout<<myTestList;
                
                break;
            }
            
            //choice 10
            case 10:{
                
                if(myTestList.isEmpty()){
                    cout<<"The list is empty";
                }
                
                else{
                    int numOfDeleted = myTestList.deleteDuplicates();
                    
                    cout<<numOfDeleted<<" duplicates have been deleted from the list"<<endl;
                    cout<<myTestList;
                }
                
                break;
            }
            
                
        }
        
    }while(choice != 11); //exit loop if user inputs 11 as choice
    
    return 0;
}

//function to display menu
void menu(){
    cout<<"\nPlease choose one of the following options:"<<endl;
    cout<<"1.  Insert at beginning\n2.  Insert at end\n3.  Insert at position\n"
            "4.  Delete at position\n5.  Delete before an element\n"
            "6.  Search element\n7.  Find and delete\n8.  Remove first element\n"
            "9.  Remove last element\n10. Delete duplicated elements\n"
            "11. Exit\n";
}

