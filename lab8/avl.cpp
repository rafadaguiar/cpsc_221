#include <iostream>
#include <iomanip>	// provides setw()
#include <cstdlib>	// provides atoi()
#include <cmath> // provides abs()
using namespace std;

typedef int KType;

struct Node {
  KType key;
  int height;
  Node * left;
  Node * right;
};

Node* createNode( KType key, Node* l = NULL, Node* r = NULL ) {
  //
  // Creates a new Node containing key, with 'l' as its left 
  // child and 'r' as its right child, with height=0
  //
  // PRE:  key is valid, l points to a Node or is NULL and r 
  //       points to a Node or is NULL
  // POST: If there is enough free memory space, a new Node is created
  //	   and its address is returned; otherwise, NULL is returned.

  Node* result = new Node;
  result->key = key;
  result->height = 0;
  result->left = l;
  result->right = r;
  return result;
}

void deleteTree( Node*& root ) {
  //
  // Deletes a tree rooted at root
  //
  // PRE:  root is a valid Node address or NULL
  // POST: All the nodes in the tree rooted at root are deleted and   
  //       root is set to NULL.

  if ( root != NULL ) {
    deleteTree( root->left );
    deleteTree( root->right );
    delete root;
    root = NULL;
  }
}

int height( Node * x ) {
  //
  // Returns the height of node x or -1 if x is NULL.
  //
  if( x == NULL ) return -1;
  return x->height;
}

bool updateHeight( Node * x ) {
  //
  // Recalculates the height of x from the height of its children.
  // Returns true iff the height of x changes.
  //
  if( x == NULL ) return false;
  int m = max(height(x->left), height(x->right)) + 1;
  if( x->height != m ) {
    x->height = m;
    return true;
  }
  return false;
}

void rotateLeft( Node *& a ) {
  // "rotates" the subtree rooted at a to the left (counter-clockwise)
  Node * b = a->right;
  a->right = b->left;
  b->left = a;
  updateHeight(a);
  updateHeight(b);
  a = b;
}

void rotateRight( Node *& b ) {
  // "rotates" the subtree rooted at b to the right (clockwise)
  Node * a = b->left;
  b->left = a->right;
  a->right = b;
  updateHeight(b);
  updateHeight(a);
  b = a;
}

void doubleRotateLeft( Node *& a ) {
  rotateRight(a->right);
  rotateLeft(a);
}

void doubleRotateRight( Node *& a ) {
  rotateLeft(a->left);
  rotateRight(a);
}

void balance( Node *& x ) {
  //
  // Check if node x is unbalanced (i.e., the heights of its
  // two children differ by more than one).  If it is, rebalance
  // at x using one of rotateLeft, rotateRight, doubleRotateLeft,
  // or doubleRotateRight, whichever is appropriate.
  //
  int left_height,left_left_height,left_right_height,right_left_height,right_height,right_right_height;
  
  if(x->left == NULL){
    left_height = -1;
  }else{
    left_height = x->left->height;
    left_left_height = (x->left->left == NULL) ?  -1: x->left->left->height;
    left_right_height = (x->left->right == NULL) ?  -1: x->left->right->height;
  }
  if(x->right == NULL){
    right_height = -1;
  }else{
    right_height = x->right->height;
    right_left_height = (x->right->left == NULL) ?  -1: x->right->left->height;
    right_right_height = (x->right->right == NULL) ?  -1: x->right->right->height;
  }
  
  if(left_height - right_height != 0 and
     left_height - right_height != -1 and
     left_height - right_height != 1){

    if(left_height - right_height < 0){ // Rotate-Left
      if(right_left_height - right_right_height < 0){
        rotateLeft(x);
        // cout<<"(rotateLeft)"<<endl;
      }else{
        doubleRotateLeft(x);
        // cout<<"(doubleRotateLeft)"<<endl;
      }
    }else{ // Rotate-Right
      if(left_left_height - left_right_height > 0){
        rotateRight(x);
        // cout<<"(rotateRight)"<<endl;
      }else{
        doubleRotateRight(x);
        // cout<<"(doubleRotateRight)"<<endl;
      }
    }
    
  }


}

void insert( int key, Node *& root ) {
  //
  // Insert key into the AVL tree rooted at root.
  // Restore balance if required.
  //
  if( root == NULL ) {
    root = createNode(key);
    return;
  }
  if( key < root->key ) {
    insert( key, root->left );
  } else {
    insert( key, root->right );
  }
  if( updateHeight(root) ) balance(root);
}


void printTreeHelper( Node * r, int d ) {
//
// Prints out the tree sideways
//
// PRE:  root is a valid Node address 
// POST: The tree rooted at r is printed in reverse inorder with nodes  
//       indented 3 * d spaces; this produces a tree that has its root near  
//       the left side of the screen and the leaves near the right side
  if( r == NULL ) return;
  printTreeHelper( r->right, d+1 );
  cout << setw( 3 * d ) << "";		// output 3 * d spaces
  cout << r->key << endl;
  printTreeHelper( r->left, d+1 );
}
void printTree( Node * r ) {
  printTreeHelper( r, 0 );
}

// keys to insert by default
int defaultKeys[] = {70, 10, 60, 20, 50, 30, 40, 25, 27, 5};

int main( int argc, char *argv[] ) {
  Node *T = NULL;
  int *keys;
  int n;

  if( argc == 1 ) {	// if no command line args use default keys
    n = sizeof(defaultKeys)/sizeof(int);
    keys = new int[n];
    for( int i=0; i < n; ++i ) {
      keys[i] = defaultKeys[i];
    }
  } else {		// use keys given on command line
    n = argc - 1;
    keys = new int[n];
    for( int i=0; i < n; ++i ) {
      keys[i] = atoi(argv[i+1]);
    }
  }

  for( int i=0; i < n; ++i ) {
    cout << "Insert: " << keys[i] << endl;
    insert(keys[i], T);
    cout << "Tree:" << endl;
    printTree(T);
  }

  // Free up allocated memory
  delete[] keys;
  deleteTree(T);

  return 0;
}
