#include<iostream>
using namespace std;

struct link {
    int value;
    link * next;
    link() { value = 0; next = 0; }
    link(int _value) {value = _value; next = 0; }
};

void printList( link * );

int main(){
    link * eventop = 0;
    link * oddtop = 0;
    link * mergetop = 0;
    link * mergebottom;
    link * previous = 0;
    link * current = 0;
    link * lptr = 0;

    int invalue;

    cout << "Input an integer, enter 0 to terminate: " << flush;
    cin >> invalue;
        while ( /* test condition goes here */ ) {
            /* This while loop builds the two sorted linked lists. */
            cout << "Input an integer, enter 0 to terminate: " << flush;
            cin >> invalue;
        }

    printList( oddtop );
    cout << "\n\n";
    printList( eventop );
    cout << "\n\n";
    mergetop = mergebottom = 0;

        while ( /* test condition goes here */ ) {
        /* Code to build the merged list goes here.
        mergetop should point to the top of the list
        mergebottom whould point to the bottom of
        the list */
        }

    printList ( mergetop );
    cout << "\n\n";
    previous = 0;
    current = mergetop;

    while ( /* test condition goes here */) {
        /* Code to remove even values from the merged list
        goes here. */
     }
        printList ( mergetop );
            while ( mergetop ) {
                lptr = mergetop;
                mergetop = mergetop->next;
                delete lptr;
            }
    return 0; 
}

void printList( link * list ){
/* Your code goes here. */
}