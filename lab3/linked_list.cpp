#include <iostream>
#include <string> 

using namespace std;

struct Node {
  int key;
  Node* next;
}; 

void insert( Node*& head, int key) {

  Node * temp;
  temp = new Node;
  temp->key = key;

  temp->next = head;
  head = temp;
    
}

void print( Node* head ) {
  Node* temp = head;
  cout << "[";
  while( temp != NULL ) {
    cout << temp->key;
    if( temp->next != NULL ) cout << ", ";
    temp = temp->next;
  }
  cout << "]" << endl;
}

// This function deletes the last element in the linked list.
// Pre-condition: The head of a linked list is provided.
// Post-condition: The last element of that linked list has been removed.
void delete_last_element( Node* &head )
{
  Node *l1=head,*l2=head;
  if(head != NULL){
    while(l2->next != NULL){
        l1 = l2;//
        l2 = l2->next;
    }
    if(l1 != NULL){
      l1->next = NULL;
    }
    if (l1 == l2 and head == l1){
      head = NULL;
      // cout << "Empty list"<<endl;
    }
  }
}

// This function inserts a key after a node with a given key.
// If there is no node with the given key, no action.
// Pre-condition: The head of a linked list,
// a key to indicate where to insert,
// and a new key to insert are provided.
// Post-condition: If a node with key is found, the linked list
// contains a new node (newKey) after that node.
void insert_after( Node* head, int key, int newKey )
{
  Node *temp=head, *newNode = new Node;
  while(temp!=NULL){
    if(temp->key == key){
      newNode->key = newKey;
      if(temp->next==NULL){
        temp->next = newNode;
      }
      else{
        newNode->next = temp->next;
        temp->next = newNode;
      }
      break;
    }
    temp = temp->next;
  }
}

// This function merges two linked lists.
// Pre-condition: Two linked lists (list1 and list2) are provided.
// Post-condition: A new linked list is returned that contains the keys
// of list1 and list2, starting with the first key of list1, then the
// first key of list2, etc. When one list is exhausted, the remaining
// keys come from the other list.
// For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
Node* interleave( Node* list1, Node* list2 )
{
  Node *newHead, *temp;
  
  if(list1 != NULL){
    newHead = new Node;
    newHead->key = list1->key;
    list1 = list1->next;
    temp = newHead;
  }
  while(list1 != NULL or list2 != NULL){
    if (list2 != NULL){
      temp->next = new Node;
      temp->next->key = list2->key;
      list2 = list2->next;
      temp = temp->next;
    }
    if (list1 != NULL){
      temp->next = new Node;
      temp->next->key = list1->key;
      list1 = list1->next;
      temp = temp->next;
    }
  }
  return newHead;
}

int main() {

  Node * list1 = NULL;
  Node * list2 = NULL;
  Node * list3 = NULL;
  Node * list4 = NULL;
  Node * list5 = NULL;

  insert( list1, 1);
  insert( list1, 2);

  cout << "<A> List 1: ";
  print( list1 );

  insert( list2, 10);
  insert( list2, 9);
  insert( list2, 8);
  insert( list2, 7);
  insert( list2, 6);

  cout << "<B> List 2: ";
  print( list2 );

  delete_last_element( list1 );
  cout << "<C> List 1: ";
  print( list1 );

  delete_last_element( list1 );
  cout << "<D> List 1: ";
  print( list1 );

  delete_last_element( list1 );
  cout << "<E> List 1: ";
  print( list1 );

  insert(list1, 11);
  insert_after(list1, 11, 12);
  cout << "<F> List 1: ";
  print( list1 );

  insert_after(list1, 13, 14);
  cout << "<G> List 1: ";
  print( list1 );

  list4 = interleave(list1, list2);
  cout << "<H> List 4: ";
  print( list4 );

  list5 = interleave(list4, list1);
  

  list4 = interleave(list1, list3);
  cout << "<I> List 4: ";
  print( list4 );

  list4 = interleave(list3, list3);
  cout << "<J> List 4: ";
  print( list4 );

  // cout << "<J> List 5: ";
  // print( list5 );

  return 0;
}
