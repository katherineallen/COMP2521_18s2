#define TRUE 1
#define FALSE 0

typedef struct { int a; int b; } Item;


int before(Item first, Item second, Item sorted[], int lo, int hi) {
    int firstFound = FALSE;
    int secondFound = FALSE;
    for(int i=lo; i<=hi; i++){
        if (sorted[i].a == first.a && sorted[i].b == first.b) {
            firstFound = TRUE;
        } else if (sorted[i].a == second.a && sorted[i].b == second.b) {
            secondFound = TRUE;
        }

        if(secondFound && !firstFound) {
            return FALSE;
        }
    }

    return TRUE;
}

int isStableSort(Item original[], Item sorted[], int lo, int hi) { 
    for(int i=lo; i<hi; i++){
        if (original[i].a == original[i+1].a && !before(original[i], original[i+1], sorted, lo, hi)){
            return FALSE;
        }
    }
    return TRUE;
}

