#define TRUE 1
#define FALSE 0

typedef struct { int a; int b; } Item;

int before(Item first, Item second, Item original[], int lo, int hi) {
    int secondSeen = FALSE;
    for (int i=0; i<hi; i++) {
        if(original[i].a == first.a && original[i].b == first.b) {
            if (secondSeen) return FALSE;
        }
        if(original[i].a == second.a && original[i].b == second.b) {
            secondSeen = TRUE;
        }
    }
    return TRUE;
}

int isStableSort(Item original[], Item sorted[], int lo, int hi) { 
    for(int i=0; i<hi; i++){
        if(sorted[i].a == sorted[i+1].a && !before(sorted[i], sorted[i+1], original, lo, hi)) {
            return FALSE;
        }
    }
    return TRUE;
}

