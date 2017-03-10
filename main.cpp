#include <iostream>
#include "list.h"

using namespace std;

template <typename Type>
void printList(List<Type> list){
    TElement<Type> *nav;
    nav = list.start;
    while(nav != nullptr){
        cout << nav->data << endl;
        nav = nav->next;
    }
    cout << "-----------" << endl;
}

int main(){

    // Do the list :)

    return 0;
}
