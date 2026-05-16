#include <iostream>
#include <stack>
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
            _count--;
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur != nullptr) {
            if (cur->data == value) {
               
                prev->next = cur->next;
                delete cur; 
                _count--;
                return true;
            }  
            prev = prev->next;
            cur = cur->next;
        }
        return false;
    }

    bool contains(const string& value) const{
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == value) {
               
                return true;
            }   
            cur = cur->next;
        }
        return false;


    }

    int count(const string& value)const{
        if (head == nullptr) {
            cout << "head nullptr";
            return;
        }
        Node* cur = head; 
        int contador = 0;
        while(cur != nullptr){
            if(cur->data == value){
                contador++;
            }
            cur = cur->next;
        }
        return contador; 
    }
    int size()const{
        return _count;
    }
    void print() const{
        cout << "Bag: ["; 
        Node* cur = head;

        while (cur != nullptr)
        {
            cout << cur->data;
            if (cur->next != nullptr) cout << ",";
        }
        cout << "]";
        

    }

}
struct Command{
    enum Type {ADD, REMOVE} type;
    string value;
};
class UndoableBag{

private: 
    Bag bag;
    stack<Command> undoStack;
    stack<Command> redoStack;
public:

    UndoableBag(){
    }

    void add(const string& value){
        bag.add(value);
        undoStack = Command{ADD, value};
        redoStack = stack<Command>{};

        cout << "ADD: " << value;
        
    }
    bool removeOne(const string& value){
        bool removed = bag.removeOne(value);
        if(removed == true){
            
        }
    }
}



int main(){

    cout << "hola mundo, espero poder hacerlo bien lol(league of legends)" << endl ;

    return 0;
}