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


}
int main()
{



    return 0;
}
