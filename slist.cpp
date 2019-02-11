
#include "slist.h"

/*
Class Library File
*/


// Constructor
slist::slist() {
    this-> length = 0;
    this-> head = NULL;
}

//Adds a new value to the end of this list.
void slist::add(Airport value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    //create a temp pointer
    Node* temp = head;

    if (temp != NULL) {
        while (temp->next != NULL) {
        temp = temp->next;
          //length++;
        }

      temp->next = newNode;
    }   else {
        head = newNode;
    }
      length++;
}


//Removes all elements from this list.
void slist::clear() {
    Node* temp1 = head->next;
    while(temp1!=NULL) // as I am considering tail->next = NULL
    {
        head->next = temp1->next;
        temp1->next = NULL;
        free(temp1);
        temp1 = head->next;
}}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool slist::equals(slist* arr) {
    bool isSame = true;
    if(length != arr->length) {
        return false;
    }
    else {
        Node* curr = head;
        Node* curr2 = arr->head;
        while(curr != NULL ) {
            if(!(curr->data.code == curr2->data.code && curr->data.longitude == curr2->data.longitude && curr->data.latitude == curr2->data.latitude)) {
                isSame = false;
            }
            curr = curr->next;
            curr2 = curr2->next;
        }
        return isSame;
    }
}

//Returns the element at the specified index in this list.
Airport slist::get(int index) {
    Node* current = head;

     // the index of the
     // node we're currently
     // looking at
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
}


//insert(index, value)		//Inserts the element into this list before the specified index.
void slist::insert(int index, Airport data) {
    Node* temp1 = new Node();
       temp1->data = data;
       temp1->next = NULL;
       int n = 0;
       if (n == 1){
        temp1->next = head;
        head = temp1;
        return;
       }
       Node* temp2 = new Node();
       for (int i = 0; i < n-2; i++){// i feel like it doesn't even go through this loop
        temp2 = temp2->next;
       }
       temp1->next = temp2->next;
       temp2->next = temp2;
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void slist::swap(int index1, int index2) {
    Node* thenode = head;
    Node* nodeC = thenode->next->next;
    Node* nodeB = thenode->next;

    nodeB->next = nodeC->next;

    thenode->next = nodeC;

    nodeC->next = nodeB;

}
// isEmpty()				//Returns true if this list contains no elements.
bool slist::isEmpty() {
    return (this->head == NULL);
}

// remove(index)			//Removes the element at the specified index from this list.
void slist::remove(int index) {
    bool exit;
        Node *pPre = NULL;
        Node* pCur = head;
        Node* headPtr = head;
        int currentIndex = 0;

        while ( pCur )
        {
            // Here we just loop until we reach our desired index.
            if (currentIndex == index)
            {
                break;
            }

            // Increment the current index and pCur to the next item.
            currentIndex++;
            pPre = pCur;
            pCur = pCur -> next;
        }

        // If pCur is still valid at this point, it means we broke at the
        // proper place and pCur should be at the proper index.
        if ( pCur )
        {
            if ( pPre )
            {
                pPre -> next = pCur -> next;
                delete pCur;
                exit = true; // return true if successful
            }
            else
            {
                headPtr = pCur -> next;
                delete pCur;
                exit = true; // return true if successful
            }
        }
        else
            exit = false; // return false if unsuccessful


}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void slist::set(int index, Airport value) {
 Node* n = head;
 if(head == n)
    {
        if(head->next == NULL)
        {
            printf("There is only one node. The list can't be made empty ");
            return;
        }

        /* Copy the data of next node to head */
        head->data = head->next->data;

        // store address of next node
        n = head->next;

        // Remove the link of next node
        head->next = head->next->next;

        // free memory
        free(n);

}

// size()					//Returns the number of elements in this list.
int slist::size() {
    int count = 0;  // Initialize count
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
slist* subList(Airport* start, int length)  {
    Node* ptr1 = first, *ptr2 = second;

        // If both linked lists are empty, return true
        if (first == NULL && second == NULL)
            return true;

        // Else If one is empty and other is not return
        // false
        if ( first == NULL ||
            (first != NULL && second == NULL))
            return false;

        // Traverse the second list by picking nodes
        // one by one
        while (second != NULL)
        {
            // Initialize ptr2 with current node of second
            ptr2 = second;

            // Start matching first list with second list
            while (ptr1 != NULL)
            {
                // If second list becomes empty and first
                // not then return false
                if (ptr2 == NULL)
                    return false;

                // If data part is same, go to next
                // of both lists
                else if (ptr1->data == ptr2->data)
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }

                // If not equal then  break the loop
                else break;
            }

            // Return true if first list gets traversed
            // completely that means it is matched.
            if (ptr1 == NULL)
                return true;

            // Initialize ptr1 with first again
            ptr1 = first;

            // And go to next node of second list
            second = second->next;
        }

        return false;
}

// toString()				//Converts the list to a printable string representation.
void slist::toString() {
    Node* temp = head;

    while(temp != NULL) {
        Airport current = temp->data;
        string code = current.code;
        double longg = current.longitude;
        double latt = current.latitude;
        string name = current.name;
        cout << "CODE: " << code << " LONGITUDE: " << longg << " LATITUDE: " << latt << " " << name << endl;
        temp = temp->next;
  }
}



