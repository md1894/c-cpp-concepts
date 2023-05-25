#include<iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

class List {
    private:
        Node* head;
        size_t length;

    public:
        List(): head(nullptr), length(0) {

        }

        static void add(Node** node, int data){
            Node *new_node = new Node();
            new_node->data = data;
            new_node->next = nullptr;
            *node = new_node;
        }

        void insert_at(int element, int index) {
            if(index == this->length){
                this->add_element(element);
            }else if(index < 0 || index > this->length) {
                throw std::out_of_range("Index out of range");
            }else if(index == 0) {
                Node *new_node;
                List::add(&new_node, element);
                new_node->next = this->head;
                this->head = new_node;
            }else {
                Node *prev = this->head;
                Node *curr = this->head->next;
                int curr_index = 1;

                while(curr != nullptr) {
                    if(curr_index == index) {
                        Node *new_node;
                        List::add(&new_node, element);
                        prev->next = new_node;
                        new_node->next = curr;
                        break;
                    }else{
                        prev = prev->next;
                        curr = curr->next;
                    }
                }
            }
            ++this->length;
        }

        void add_element(int data) {
            if(this->head == nullptr){
                List::add(&this->head, data);
            }else{
                Node* curr = this->head;
                while(curr != nullptr){
                    if(curr->next == nullptr) {
                        List::add(&curr->next, data);
                        break;
                    }else
                        curr = curr->next;
                }
            }
            this->length++;
        }

        int get_middle(){
            if(this->head == nullptr){
                return -1;
            }

            Node *fast = this->head;
            Node *slow = this->head;

            while(fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }

            return slow->data;
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
                curr = curr->next;
            }
            o << endl;
            return o;
        }

        size_t size() {
            return this->length;
        }
};

int main(){
    List list;
    list.add_element(10);
    list.add_element(20);
    list.add_element(30);
    list.add_element(40);
    list.add_element(50);
    list.add_element(60);
    cout << list;
    cout << list.get_middle() << endl;
    return 0;
}