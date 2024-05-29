#include "clist.h"

int main() {
    CList lst1;
    lst1.insertBegin(6);
    lst1.insertBegin(20);
    lst1.insertBegin(600);
    lst1.insertEnd(60);
    lst1.sort();
    lst1.show(true);
    lst1.show();

    return 0;
}