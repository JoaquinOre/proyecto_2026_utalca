#include <iostream>
using namespace std;


class Bag{
private:
    struct Node{
        string data;
        Node* next;
        Node(const string& d) : data(d), next(nullptr) {} 
    };
    Node* head;
    int _count;
public: 

    Bag(){
        head = nullptr;
        _count = 0; 

    }
    ~Bag(){
        Node* cur = head;
        while (cur != nullptr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    void add(const string& value){
        Node* nwNode = new Node(value);
        nwNode->next = head;
        head = nwNode;
        _count++;
       

    }
    bool removeOne(const string& value){

        if (head == nullptr) return 0;
        if (head -> data == value){
            Node* temp = head; 
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur != nullptr) {
            if (cur->data == value) {
               
                prev->next = cur->next;
                delete cur; 
                return;
            }  
            prev = prev->next;
            cur = cur->next;
        }
    }

    bool contains(const string& value) const{
        Node* prev = head;
        Node* cur = head->next;
        while (cur != nullptr) {
            if (cur->data == value) {
               
                return true;
            }  
            prev = prev->next;
            cur = cur->next;
        }
        return false;


    }

}

class UndoableBag{

}



int main(){

    cout << "hola mundo, espero poder hacerlo bien lol" << endl ;

    return 0;
}