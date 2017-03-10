#ifndef LIST_H
#define LIST_H

template <typename Type>
struct TElement{
    Type data;
    TElement<Type> *next;
};

template <typename Type>
struct List{
    TElement<Type> *start;
};

template <typename Type>
int initialize(List<Type> &list){
    list.start = nullptr;
    return 1;
}

template <typename Type>
TElement<Type> *newElement(Type data){
    TElement<Type> * element = new TElement<Type>;
    element->data = data;
    element->next = nullptr;
    return element;
}

template <typename Type>
int push_back(List<Type> &list, Type data){
    TElement<Type> *buffer;
    buffer = newElement(data);
    if(list.start == nullptr){
        list.start = buffer;
        return 1;
    } else {
        TElement<Type> *nav;
        nav = list.start;
        while(nav->next != nullptr)
            nav = nav->next;
        nav->next = buffer;
    }
    return 0;
}

template <typename Type>
int push_begin(List<Type> &list, Type data){
    TElement<Type> *buffer;
    buffer = newElement(data);
    if(list.start == nullptr){
        list.start = buffer;
        return 1;
    }
    buffer->next = list.start;
    list.start = buffer;
    return 1;
}

template <typename Type>
int push_position(List<Type> &list, int position, Type data){
    TElement<Type> *buffer;
    buffer = newElement(data);
    TElement<Type> *nav;
    nav = list.start;
    for(int i = 0; i < position - 1; i++){
        nav = nav->next;
    }
    buffer->next = nav->next;
    nav->next = buffer;
    return 1;
}

template <typename Type>
int pop_back(List<Type> &list){
    if(list.start == nullptr)
        return 0;

    TElement<Type> *nav;
    nav = list.start;
    while (nav->next->next != nullptr) {
        nav = nav->next;
    }
    nav->next = nullptr;
    return 1;
}

template <typename Type>
int pop_begin(List<Type> &list){
    list.start = list.start->next;
    return 1;
}

template <typename Type>
int pop_position(List<Type> &list, int position){
    if(list.start == nullptr)
        return 0;
    if(list.start->next != nullptr && position == 0){
        list.start = list.start->next;
        return 1;
    }

    TElement<Type> *nav;
    nav = list.start;
    for(int i = 0; i < position - 1; i++){
        nav = nav->next;
    }
    nav->next = nav->next->next;
    return 1;
}

#endif // LIST_H
