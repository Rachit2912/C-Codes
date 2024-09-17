#include<iostream>
#include <unordered_map>
#include "044 Linked List Basics.cpp"
using namespace std;

// CLONE A LL WITH RANDOM POINTERS : 
/* isme har node me data,next and 1 extra random pointer bhi hoga jo usi ll me kisi node ya null ko point kr rha hoga 
bss iss poori ll ki deep copy krni h 
*/

// Eg. Node in the given question :
class rNode{
    public:
    int data;
    rNode* next;
    rNode* random;

   rNode(int x) : data(x), next(nullptr), random(nullptr) {}

};

//Approach 1 : first the copy the ll as normal with next pointers only then for the random pointers, store how much nodes you have to cover to get that random pointer and add to the current node of the our clone ll's that specific node.
// S.C : O(1), T.C : O(n^2)


// Approach 2 :
/*
first copy ll as normal with next pointers only then make a map which will do the mapping for the nodes of original ll to the nodes of cloned ll 
and for finding the random, we'll go to the originalNode's random and find it's mapping through the map and allocate it to the random pointer of that node of clone LL's node.
T.C : O(n) ; S.C : O(n)
*/ 

void insertAtTail(rNode* &head, rNode* &tail, int d) {
        rNode* newNode = new rNode(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }

rNode *cloneLL(rNode *head){

	// step 1 : create a clone list and copy the content of our ll with next pointers only 
	rNode* cloneHead = NULL;
	rNode* cloneTail = NULL;
	rNode* temp = head;
	while(temp != NULL){
		insertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	// step 2 : create a map for store the mappings from original list to clone list
	unordered_map<rNode*, rNode*> oldToClone;

	rNode* originalNode = head;
	rNode* cloneNode = cloneHead;
	while(originalNode != NULL && cloneHead != NULL){
		oldToClone[originalNode] = cloneNode;
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;
	}

	originalNode = head;
	cloneNode = cloneHead;

	while(originalNode != NULL){
		cloneNode->random = oldToClone[originalNode->random];
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;
	}

return cloneHead;
}

// Approach 3 : 
/*
step 1 : create a clone ll with next pointers only
step 2 : add cloneNodes in between the originalNodes
step 3 : add random pointers to cloneNodes with the help of originalNodes
step 4 : reverse the changes done in step 2 
step 5 : return the cloneHead as your answer
T.C : O(n) ; S.C : O(1)
*/
rNode* copyRandomList(rNode* head) {
        
	// step 1 : create a clone list and copy the content of our ll with next pointers only 
	rNode* cloneHead = NULL;
	rNode* cloneTail = NULL;
	rNode* temp = head;
	while(temp != NULL){
		insertAtTail(cloneHead, cloneTail, temp->data);
		temp = temp->next;
	}

	// step 2 : add clone nodes in between the originalNodes
	

	rNode* originalNode = head;
	rNode* cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {
                rNode *next = originalNode->next;
                originalNode->next = cloneNode;
                originalNode = next;

                next = cloneNode->next;
                cloneNode->next = originalNode;
                cloneNode = next;
        }



        // step 3 : random pointer copy to cloneNodes
    	temp = head;
        while (temp != NULL){
			if(temp->next != NULL){
				temp->next->random = temp->random ? temp->random->next : temp->random;
			}

			temp = temp->next->next;

		}

        //step 4 : revert the changes done in step 2
		originalNode = head;
		cloneNode = cloneHead;

		while(originalNode != NULL && cloneNode != NULL){
			originalNode->next = cloneNode->next;
			originalNode = originalNode->next;

                        if (originalNode != NULL) {
                                cloneNode->next = originalNode->next;
                        }
                        cloneNode = cloneNode->next;
		}

    
// step 5 : return the cloneHead as your answer
return cloneHead;

    }


int main(){



return 0;
}