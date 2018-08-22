/*
 * Question 1
 * By Matthew Di Meglio 31/05/2018
 * cs2521 2018 semester 2
 * 
 * splitAtNode(l, n) should, if n is a node in the list l,
 * split the list just before the node n
 *
 * EXAMPLE 1. If
 * l -> [1] -> [1] -> [1] -> X
 *              ^
 * n -----------+
 * Then after calling splitAtNode(l, n), should have
 * l -> [1] -> X    [1] -> [1] -> X
 *                   ^
 * n ----------------+
 *
 * EXAMPLE 2. If
 * l -> [1] -> [2] -> [3] -> X
 *       ^
 * n ----+
 * Then after calling splitAtNode(l, n), should have
 * l -> X    [1] -> [2] -> [3] -> X
 *            ^
 * n ---------+
 *
 * EXAMPLE 3. If
 * l -> [1] -> [1] -> [1] -> X
 *       
 * n -> [1] -> [1] -> X
 * Then after calling splitAtNode(l, n), should have
 * l -> [1] -> [1] -> [1] -> X
 *       
 * n -> [1] -> [1] -> X
 */

#include "q1.h"

void splitAtNode(List l, Link n) {
    Link curr = l->head;
    if(!curr) {
        return;
    }
    Link next = l->head->next;
    
    if(curr == n) {
        l->head = NULL;
    }

    while(next != NULL && next != n) {
        curr = curr -> next;
        next = next -> next;
    }

    curr -> next = NULL;

}