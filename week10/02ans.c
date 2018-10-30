typedef struct BSTNode *BSTree;
 
BSTree newBSTree();               // create an empty BSTree
void dropBSTree(BSTree);          // free memory associated with BSTree
void showBSTree(BSTree);          // display a BSTree
void showBSTreeNode(BSTree);      // display BSTree root node
 
void BSTreeInfix(BSTree);         // print values in infix order
void BSTreePrefix(BSTree);        // print values in prefix order
void BSTreePostfix(BSTree);       // print values in postfix order
void BSTreeLevelOrder(BSTree);    // print values in level-order
 
int BSTreeDepth(BSTree);          // #nodes in longest branch
int BSTreeNumNodes(BSTree);       // count #nodes in BSTree
int BSTreeNumLeaves(BSTree);      // count #leaves in BSTree
 
BSTree BSTreeInsert(BSTree, int); // insert a new value into a BSTree
int BSTreeFind(BSTree, int);      // check whether a value is in a BSTree
BSTree BSTreeDelete(BSTree, int); // delete a value from a BSTree

typedef struct BSTNode *Link;
 
typedef struct BSTNode {
   int  value;
   Link left, right;
} BSTNode;

int BSTreeMaxBranchLen(BSTree t) {
    if(t==NULL) {
        return NULL;
    }
    
    if(t->left == NULL && t->right == NULL){
        return 0;
    }

    if (BSTreeMaxBranchLen(t->left) > BSTreeMaxBranchLen(t->right)) {
        return 1+BSTreeMaxBranchLen(t->left);
    } else {
        return 1+BSTreeMaxBranchLen(t->right);
    }
}

int BSTreeMaxBranchLen(BSTree t) {

    if(t->left == NULL && t->right == NULL){
        return 0;
    }

    int rightLength = 0;
    int leftLength = 0;

    if(t->left != NULL){
        leftLength = BSTreeMaxBranchLen(t->left);
    }

    if(t->right != NULL){
        rightLength = BSTreeMaxBranchLen(t->right);
    }

    if (leftLength > rightLength){
        return 1+leftLength;
    } else {
        return 1+rightLength;
    }

}

int BSTreeMaxBranchLen(BSTree t) {
    if(t==NULL){
        return -1;
    }

    int leftLength = BSTreeMaxBranchLen(t->left);
    int rightLength = BSTreeMaxBranchLen(t->right);

    if(leftLength > rightLength){
        return 1+leftLength;
    } else {
        return 1+rightLength;
    }

}

int BSTWidth(BSTree t) { 
    return 3*BSTreeNumNodes(t);

}

int BSTWidth(BSTree t) { 

    return (!t ? 0 : 3+BSTWidth(t->left)+BSTWidth(t->right)); 

}

int BSTWidth(BSTree t) { 

    if(t->left == NULL && t->right == NULL){
        return 3;
    }

    int leftWidth = 0;
    int rightWidth = 0;

    if(t->left != NULL){
        leftWidth = BSTWidth(t->left);
    }

    if(t->right != NULL){
        rightWidth = BSTWidth(t->right);
    }

    return (leftWidth + rightWidth);

}

int BSTreeSearch(BSTree t, int i){

    if(t==NULL){
        return FALSE;
    }

    if (t->value == i){
        return TRUE;
    }

    if(t->right == NULL && t->left == NULL){
        return FALSE;
    }

    if(i<t->value){
        return BSTreeSearch(t->left, i);
    } else {
        return BSTreeSearch(t->right, i);
    }

}

int main (int argc, char * argv[]){

    return EXIT_SUCCESS;

}