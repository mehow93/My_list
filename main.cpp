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
    void pop_back();
    void pop_front();
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
void List::pop_back(){ // poping node from end of list

    if(HEAD != nullptr)
    {
        if(size_ == 1){ // only HEAD
            delete(HEAD);
            HEAD = nullptr;
        }


    else // more nodes
    {
        Node *pNode = HEAD;
        Node *pPrev =nullptr;

        while(pNode->pNext != nullptr)
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
        delete(pNode);
        pPrev->pNext = nullptr;

    }
         size_--;
    }

}
void List::pop_front(){ //poping nodes from front
    if(HEAD != nullptr)
    {
        if(size_ == 1){ // only HEAD
            delete(HEAD);
            HEAD = nullptr;
        }


    else // more nodes
    {
        Node *pNode = HEAD;
        HEAD = HEAD->pNext;
        delete(pNode);


    }
         size_--;
    }
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
     l1.push_front(34);
     l1.pop_front();
     l1.pop_front();
     l1.show();
     cout << l1.get_size()<<endl;


    return 0;
}
