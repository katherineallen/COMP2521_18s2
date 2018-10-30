#define TRUE 1
#define FALSE 0

typedef struct BSTNode *Link;
 
typedef struct BSTNode {
   int  value;
   Link left, right;
   int deleted;
} BSTNode;


int BSTreeFind(BSTree t, int v)
{
   if (t == NULL)
      return 0;
   else if (v < t->value)
      return BSTreeFind(t->left, v);
   else if (v > t->value)
      return BSTreeFind(t->right, v);
   else if (!(t -> deleted)) 
   // (v == t->value)
      return 1;
   else
      return 0;
}

int BSTreeNumNodes(BSTree t)
{
   if (t == NULL)
      return 0;
   else
      return t->deleted + BSTreeNumNodes(t->left)
               + BSTreeNumNodes(t->right);
}

BSTree BSTreeDelete(BSTree t, int x) {
   if(t==NULL){
      return t;
   }

   if(t->value == x) {
      t->deleted = TRUE;
      return t;
   } else if (x < t->value) {
      t->right = BSTreeDelete(t->right, x);
   } else {
      t->left = BSTreeDelete(t->left, x);
   }
}

void showBSTreeInfix(BSTree t) {
   if(t==NULL){
      return;
   }

   showBSTreeInfix(t->left);
   if(t->deleted == FALSE) {
      printf("%d ", t->value);
   }
   showBSTreeInfix(t->right);
}

BSTree BSTreeInsert(BSTree t, int x) {
   if(t==NULL) { //if tree is empty
      t = BSTreeNewNode(x);
      t->left = NULL;
      t->right = NULL;
      t->deleted = FALSE;
      return t;
   }
   else if(BSTreeFind(t, x)){
      return t; //no changes if already in tree
   } if(t->deleted == TRUE && t->value = x){
      t->value = x;

   } else if (t->deleted == TRUE && (max(t->left) < x) && (min(t->right) >= x)) {
      t->value = x;

   } else if (t->value < x) {
      t->right =  BSTreeInsert(t->right);
   } else if (t->value >= x) {
      t->left =  BSTreeInsert(t->left);
   }

   return t;

}

int max(BSTree t) {
   if(t==NULL){
      return 0;
   }

   if(max(t->left) < t->value) {
      return t->value;
   } else {
      return max(t->left);
   }
}

int min(BSTree t) {
   if(t==NULL){
      return INT_MAX;
   }

   if(min(t->right) > t->value) {
      return t->value;
   } else {
      return min(t->right);
   }
}
