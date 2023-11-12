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
    while (true) {

            if (invalue == 0){ 
                break;
            }

            //DEBUG CODE
            //cout << "You entered: " << invalue << endl;

            //store the invalue in newlink
            link *newlink = new link(invalue);
            if (invalue % 2 == 0){
                //find if the number is even or odd

                if (eventop == nullptr || eventop->value >= newlink->value){
                    //Ok, so there is a few things going on here.
                    //eventop == nullptr, is saying that if the list is empty, create an empty list.
                    //the comparison >=, checks if the value of eventop is greater than or equal to the new value, and then adds the smaller values to the begining of the list
                    newlink->next = eventop;
                    eventop = newlink;

                } else {   
                    link *currentnum = eventop;
                    //so if those conditions above are not met, that must mean the value needs to be inserted at the end or middle of the list.

                        while (currentnum->next != nullptr && currentnum->next->value < newlink->value){
                            //this line right here ^^^ gave me so many issues to debug initially my program would not take more than 2 inputs into each list
                            //so it is checking to see if current is pointing to nullptr then checking to see if that value of current is less then the invalue
                            //then add it to the middle of the list.

                            currentnum = currentnum->next;
                        }

                    //add the value to the end of the list
                    newlink->next = currentnum->next;
                    currentnum->next = newlink;
                }
            } else {

                //repeat the proccess above, but for odd numbers this time.
                if (oddtop == nullptr || oddtop->value >= newlink->value){
                    newlink->next = oddtop;
                    oddtop = newlink;

                } else {
                    link *currentnum = oddtop;
                    while (currentnum->next != nullptr && currentnum->next->value < newlink->value){
                        currentnum = current->next;
                    }
                    newlink->next = currentnum->next;
                    currentnum->next = newlink;

                }
            }

            cout << "Input an integer, enter 0 to terminate: " << flush;
            cin >> invalue;

        }

    //print odd list
    cout << "\n";
    cout << "Odd list: ";
    printList( oddtop );
    cout << "\n\n";

    //print even list
    cout << "Even list: ";
    printList( eventop );
    cout << "\n\n";

    mergetop = mergebottom = 0;
    while (eventop != nullptr || oddtop != nullptr ) {

        link *mergedNode; //declaring with no definiton

        if (oddtop == nullptr || (eventop != nullptr && eventop->value < oddtop->value) ){
            //So, Odd should always be first, because the value of 1 is the lowest number aside from 0, but we use that to terminate.
            //but, if oddtop were to equal a odd number > than 1, we need to add eventop first if it contains a number lower than the oddtop number.
            mergedNode = eventop;
            eventop = eventop->next;
        } else {
            mergedNode = oddtop;
            oddtop = oddtop->next;
        }

        if (mergetop == nullptr) {
            //mergetop would be the first thing added to the list
            mergetop = mergedNode;
            mergebottom = mergedNode;
        } else {
            //if mergetop is not the first, then that means there are already things in the list, updating mergebottm to point ot the end of the list
            mergebottom->next = mergedNode;
            mergebottom = mergedNode;
        }
    }
    
    //print merged list
    cout << "Merged list: ";
    printList ( mergetop );
    cout << "\n\n";

    previous = 0;
    current = mergetop;
    while (current != nullptr) {
        if (current->value % 2 == 0){
            //figures if the value is even, if it is, it needs to remove it.
            if (previous == nullptr){
                //if previous is empty, current is the top of the list. so delete current.
                mergetop = current->next;
                delete current;
                current = mergetop;
            } else {
                //if previous is not empty, move to the next value and get to the continue on to the end of the list.
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        } else {
            //move both positions forward.
            previous = current;
            current = current->next;
        }
    }

    //print demerged list
    cout << "Demerged list: ";
    printList ( mergetop );
    cout << "\n\n";

    while ( mergetop ) {
        lptr = mergetop;
        mergetop = mergetop->next;
        delete lptr;
    }
    return 0;
}

void printList(link * list){
    link *current = list;
    while (current != nullptr){

        //output whatever current is
        cout << current->value << " -> ";

        //update current to the next value in the list and output current, until current == nullptr;
        current = current->next;

        if (current == nullptr){
            cout << "0";
        }
    }
}
