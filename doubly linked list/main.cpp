#pragma GCC diagnostic ignored "-Wreturn-type"
#include "linkedlist.cpp"


int main() {
    linkedList <int> list;
    list.add_last(1);
    list.add_first(2);
    list.add_last(3);
    list.add_last(4);
    list.add(5, 1);
    list.print();
    list.reverse();
    list.print();
    return 0;
}