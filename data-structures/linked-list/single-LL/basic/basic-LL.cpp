#include<iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

class List {
    private:
        Node* head;

    public:
        List(): head(nullptr) {

        }

        static void add(Node* node, int data){
            node = new Node();
            node->data = data;
            node->next = nullptr;
        }

        void add_element(int data) {
            if(this->head == nullptr){
                List::add(this->head, data);
            }else{
                Node* curr = this->head;
                while(curr != nullptr){
                    if(curr->next == nullptr) {
                        List::add(curr->next, data);
                    }else{
                        curr = curr->next;
                    }
                }
            }
        }

        int& operator[](int index) {
            
            if(index == 0 && this->head != nullptr)
                return this->head->data;
            else{
                int curr_index = 1;
                Node* curr = this->head;
                while(curr != nullptr) {
                    if(curr_index == index) {
                        return curr->data;
                    }else{
                        curr_index++;
                        curr = curr->next;
                    }
                }
                throw std::out_of_range("Index out of range");
            }
        }

        friend ostream& operator<<(ostream &o, const List &l){
            Node *curr = l.head;
            while(curr != nullptr){
                o << curr->data << " ";
            }
            o << endl;
            return o;
        }
};

int main(){
    List list;
    list.add_element(10);
    list.add_element(20);
    list.add_element(30);
    cout << list[2] << endl;
    cout << "---------" << endl;
    cout << list;
    return 0;
}