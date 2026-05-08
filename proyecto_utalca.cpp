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

    void add(const string& value){}
    bool removeOne(const string& value){}

}

class UndoableBag{

}



int main(){

    cout << "hola mundo, espero poder hacerlo bien lol" << endl ;

    return 0;
}