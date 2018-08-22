typedef struct _node *Link;
 
typedef struct _node {
    char value;
	Link next;
	Link prev;
} node;


typedef struct _list {
    Link head;
    Link tail;
} *List;

List selectSort(List ls) { 
    List new = newList();
    while(length(new) != length(ls)){
        
    }

}