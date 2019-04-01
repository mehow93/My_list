#include <iostream>

using namespace std;

class List {
public:
    struct Node {
        int var;
        Node* pNext;
        Node* pBefore;
        Node (int val, Node* pb, Node* pn ) : var{val}, pBefore{pb}, pNext{pn} {}};
    List() :HEAD{nullptr}, size_{0} {}
    void push_back(int val);
    void push_front(int val);
    void show();
    int get_size(){return size_;}

private:
    Node* HEAD = nullptr;
    int size_ =0;
};

void List::push_back(int val){// pushing new values to end of list
    Node *pNode = HEAD;
    if(pNode != nullptr)
    {
        while(pNode->pNext != nullptr)
        {
            pNode = pNode->pNext;
        }
        pNode->pNext = new Node(val,pNode,nullptr);
    }
    else
    {
        HEAD = new Node(val,nullptr,nullptr);
    }
    size_++;
}

void List::push_front(int val){ // pushing values to front of list
    Node *pNode = HEAD;
    if(pNode != nullptr)
    {
        while(pNode->pBefore != nullptr)
        {
            pNode = pNode->pBefore;
        }
        pNode->pBefore = new Node(val,nullptr,pNode);
        HEAD = pNode->pBefore;
    }
    else
    {
        HEAD = new Node(val,nullptr,nullptr);
    }
    size_++;


}
void List::show(){
    Node *pNode = HEAD;
    while(pNode != nullptr)
    {
        cout << "The value is: "<<pNode->var <<endl;
        pNode = pNode->pNext;
    }

}

int main()
{
     List l1;
     l1.push_back(3);
     l1.push_back(4);
     l1.push_back(12);
     l1.push_front(23);
     l1.push_front(12);
     cout << l1.get_size()<<endl;
     l1.show();



    return 0;
}
