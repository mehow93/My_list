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
    void reverse();
    void show();
    void show_backward();
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
void List::reverse(){

    Node *pNode = HEAD, *pTmpNode = nullptr;
    while(pNode != nullptr)
    {
        pTmpNode = pNode->pBefore;
        pNode->pBefore = pNode->pNext;
        pNode->pNext = pTmpNode;
        pNode = pNode->pBefore;

    }
    if(pTmpNode == nullptr)
        HEAD = pNode;
    else {
        HEAD = pTmpNode->pBefore;
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
void List::show_backward(){
    Node *pNode = HEAD;
    if (pNode == nullptr)
        return;

    while(pNode->pNext != nullptr) // setting pointer to the last node
    {
        pNode = pNode->pNext;
    }

    while(pNode != nullptr)
    {
        cout << "The value is: "<<pNode->var <<endl;
        pNode = pNode->pBefore;
    }

}
int main()
{
    List l1;

    l1.show();
    l1.reverse();
    l1.show();








    return 0;
}
