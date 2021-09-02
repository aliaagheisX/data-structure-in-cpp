/* 
    node -> represt the item of list by data and hold the address of previous node and the next node
 */
template <typename T = int>
struct node{
    T data;
    node* next;
    node* prev;
    node(T value) {
        data=value;
        next = prev = NULL;
    }
};

/* 
***********     the double linked list shoud have functoin to       ***********
1- display details
    - is_empty : to check if the list empty or not                          o(1)
    - get_size : to get the number of items in list                         o(1)
    - []       : get the item of specific index and can change its value    o(n)
    - print    : print all items on the list                                o(n)


2- add items
    - add_first : to add item at the [beginning] of list                    o(1)
    - add_last  : to add item at the [end] of list                          o(1)
    - add       : to add item at the [index] of list                        o(n)


3-delete items
    - delete_first : to delte item at the [beginning] of list               o(1)
    - delete_last  : to delte item at the [end] of list                     o(1)
    - del          : to delte item at the [index] of list                   o(n)

4-manipulate list
    - reverse : reverse items                                               o(n)

*/
template <typename T = int>
class linkedList {
    private:
        node<T>* head;
        node<T>* tail;
        int size = 0;
    public:
        linkedList();
        ~linkedList();


        bool is_empty();
        int get_size();
        T &operator[](int index);
        void print();
        
        void add_first(T value); 
        void add_last(T value);
        void add(T value, int index);
       
        

       
        void delete_first();   
        void delete_last();    
        void del(int index);

        void reverse();

        
};