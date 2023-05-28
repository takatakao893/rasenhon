#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct Node{
    unsigned int key = 0;
    shared_ptr<Node> prev = nullptr;
    shared_ptr<Node> next = nullptr;
};

void print_nodes(const shared_ptr<Node>& top){
    auto cur = top->next;
    while (cur->next){
        cout << cur->key << " ";
        cur = cur->next;
    }
    cout << cur->key << endl;
}

int main(){
    unsigned int n;
    cin >> n;
    const auto top = make_shared<Node>();
    shared_ptr<Node> last = nullptr;
    for(unsigned int i=0; i<n; i++){
        string command;
        cin >> command;
        if(command == "insert"){
            unsigned int key;
            cin >> key;
            auto node = make_shared<Node>();
            node->key = key;
            node->prev = top;
            node->next = top->next;
            if (node->next) {node->next->prev = node; }
            else{ last = node;}
            top->next = node;
        }else if(command == "delete"){
            unsigned int key;
            cin >> key;
            auto tmp = top->next;
            while(tmp){
                if(tmp->key == key){
                    tmp->prev->next = tmp->next;
                    if(tmp->next) tmp->next->prev = tmp->prev;
                    else last = tmp->prev;
                    break;
                }
                tmp=tmp->next;
            }
        }else if(command == "deleteFirst"){
            if(top->next){
                auto node = top->next;
                top->next = node->next;
                if(node->next) node->next->prev = top;
                else last = nullptr;
            }
        }else if(command == "deleteLast"){
            if(last){
                last->prev->next = nullptr;
                last = last->prev;
            }
        }
    }
    print_nodes(top);
    return 0;
}