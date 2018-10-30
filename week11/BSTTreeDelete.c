#define TRUE 1
#define FALSE 0

typedef struct BSTNode *Link;
typedef struct BSTNode *BSTree;

typedef struct BSTNode {
   int  value;
   Link left, right;
   int deleted;
} BSTNode;


int BSTreeFind(BSTree t, int v)
{
   if (t == NULL)
      return FALSE;
   else if (v < t->value)
      return BSTreeFind(t->left, v);
   else if (v > t->value)
      return BSTreeFind(t->right, v);
   else 
      return !(t->deleted);
      
}

int BSTreeNumNodes(BSTree t)
{
   if (t == NULL)
      return 0;
   else
        
      return (t->deleted ? 0:1) + BSTreeNumNodes(t->left)
               + BSTreeNumNodes(t->right);
}

BSTree BSTreeDelete(BSTree t, int x) {
    if (t == NULL) {
        return NULL;
    }
    if (t->value == x) {
        t->deleted = TRUE;
        return t;
    } 
    if (x < t->value) {
        t->left = BSTreeDelete(t->left, x);
        return t;
    } else {
        t->right = BSTreeDelete(t->right, x);
        return t;
    }

}

BSTree BSTreeDelete(BSTree t, int x) {
    if (t == NULL) {
        return NULL;
    }
    if (x < t->value) {
        t->left = BSTreeDelete(t->left, x);
        return t;
    } else (x > t->value) {
        t->right = BSTreeDelete(t->right, x);
        return t;
    }

    if (t->value == x) {
        if (t->left == NULL && t->right == NULL) {
            releaseNode(t);
            return NULL;
        }

        if (t->right != NULL and t->left == NULL) {
            return t->right;
        }

        if (t->left != NULL and t->right == NULL) {
            return t->left;
        }

        //case of 2 children
        BSTree s = inOrderSuccessor(t);

        if (s->right != NULL) {
            findSParent(t, s) -> left = s->right;
        }

        s->left = t->left;
        s->right = t->right;
        return s;

    } 

}

BSTree findSParent (BSTree s, BSTree t) {
    if (t == NULL) {
        return NULL;
    }
    if (t->left == s){
        return t;
    }
    if (s->value < t->value) {
        return findSParent(t->left, s);
    }
    else findSParent(t->right, s);

}

BSTree inOrderSuccessor(BSTree t) {
    BSTree curr = t->right;
    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

void showBSTreeInfix(BSTree t) {
    if (t==NULL) return;
    showBSTreeInfix(t->left);
    if (!t->deleted) printf("%d\n", t->value);
    showBSTreeInfix(t->right);

}

BSTree BSTreeInsert(BSTree t, int x) {
    if (t == NULL) {
        return newNode(x);
    }

    if (t->value == x && t->deleted) {
        t->deleted = FALSE;
        return t;
    }

    if (t->value == x) {
        return t;
        
    }

    if (x < t->left) {
        t->left = BSTreeInsert(t->left);
        return t;
    } else {
        t->right = BSTreeInsert(t->right);
        return t;
    }

}


int max(BSTree t) {

}

int min(BSTree t) {

}





















