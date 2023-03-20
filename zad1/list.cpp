#include "list.h"
#include<iostream>

class ListElement{
    public:
        ListElement * next;
        ListElement * prev;
        int value;
        ListElement(ListElement * previous, int value, ListElement * nex){
            this -> prev = previous;
            this -> value = value;
            this -> next = nex;
        }
};

class List{
    private:
        ListElement * head;
        ListElement * tail;
        short dataSize;

    public: 
        List(int size){
            head = new ListElement(nullptr, 0, nullptr);
            ListElement * current = head;
            for(int i = 1; i < size; i++){
                current -> next = new ListElement(current, 0, nullptr);
                current -> next -> prev = current;
                current = current -> next;
            }
            tail = current;
        }

        void displayList(){
            ListElement * currentPointer = head;
            std::cout << "--------LISTA---------\n";
            while(currentPointer -> next != nullptr){
                std::cout << currentPointer -> value << " <-> ";
                currentPointer = currentPointer -> next;
            }
            std::cout << currentPointer -> value << std::endl << std::endl;
        }


        bool addAtStart(int value){
            head -> prev = new ListElement(nullptr, value, head);
            head = head -> prev;
            return true;
        }

        bool addAtEnd(int value){
            tail -> next = new ListElement(tail, value, nullptr);
            tail = tail -> next;
            return true;
        }

        bool addAt(int index, int value){
            ListElement * currentPointer = head;
            while(index > 0){
                if(currentPointer -> next == nullptr) {
                    if(currentPointer == tail) return addAtEnd(value);
                    return false;
                }
                currentPointer = currentPointer -> next;
                index--;
            }
            if(currentPointer == head) {
                return addAtStart(value);
            }
            currentPointer -> prev -> next = new ListElement(currentPointer -> prev, value, currentPointer);
            currentPointer -> prev = currentPointer -> prev -> next;
            return true;
        }

        bool setValueAt(int index, int value){
            ListElement * currentPointer = head;
                while(index > 0){
                    if(currentPointer -> next == nullptr) return false;
                    currentPointer = currentPointer -> next;
                    index--;
                }
                currentPointer -> value = value;
                return true;
        }

        bool removeElementOfValue(int valueToFind){
            ListElement * currentPointer = head;
            while(true){
                if(currentPointer -> value == valueToFind) break;
                if(currentPointer == tail) return false;
                currentPointer = currentPointer -> next;
            }
            if(currentPointer == head){
                head -> next -> prev = nullptr;
                head = head -> next;
                free(currentPointer);
                return true;
            }
            if(currentPointer == tail){
                tail -> prev -> next = nullptr;
                tail = tail -> prev;
                free(currentPointer);
                return true;

            }
            currentPointer -> next -> prev = currentPointer -> prev;
            currentPointer -> prev -> next = currentPointer -> next;
            free(currentPointer);
            return true;
        }

        bool findElementOfValue(int valueToFind){
            ListElement * currentPointer = head;
                while(true){
                    if(currentPointer -> value == valueToFind) return true;
                    if(currentPointer == tail) return false;
                    currentPointer = currentPointer -> next;
                }
        }
};

int main(){

    List newList = List(1);
    newList.addAtEnd(2);
    newList.addAtEnd(2);
    newList.addAtEnd(2);
    newList.addAtEnd(2);
    newList.addAtEnd(2);
    newList.addAtEnd(3);
    newList.displayList();
    return 0;
}