
/*
Header file for single linked list class library
*/

#include <iostream>
#include <string>
#ifndef SLIST_H
#define SLIST_H


using namespace std;

class Airport
{
public:
    char code[256];
    char type[256];
    char name[256];
    double longitude;
    double latitude;
    double elevation;
    char continent[256];
    char isoCountry[256];
    char isoRegion[256];
    char municipality[256];
    char gpsCode[256];
    char iataCode[256];
    char localCode[256];
    void toString() {
        cout << "IDENT: " << code << " TYPE: " << type << " NAME: " << name << " LONG: " << longitude << " LAT: " << latitude << " ELEVATION: " << elevation << " LOCAL CODE: " << localCode<< endl;
    }

};

class Node
{
    public:
        Node* next;
        Airport data;
};

class slist {

    public:
        int length;
        Node* head;
        slist();
        void add(Airport value); //Adds a new value to the end of this list.
        void toString();
        void clear();
        bool equals(slist* arr);  //Returns true if the two lists contain the same elements in the same order.
        Airport get(int index); //Returns the element at the specified index in this list.
        void insert(int index, Airport data);		//Inserts the element into this list before the specified index.
        void exchg(int index1, int index2);		//Switches the payload data of specified indexex.
        void swap(int index1,int index2);		//Swaps node located at index1 with node at index2
        bool isEmpty();			//Returns true if this list contains no elements.
        void remove(int index);			//Removes the element at the specified index from this list.
        void set(int index, Airport value);		//Replaces the element at the specified index in this list with a new value.
        int size();					//Returns the number of elements in this list.
        slist* subList(Airport* start, int length);	//Returns a new list containing elements from a sub-range of this list.

};

#endif SLIST_H


