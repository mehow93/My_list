#include <iostream>

using namespace std;

class List {
public:
    struct Node {
      int var;
      Node* pNext;
      Node (int val, Node* pn) : var{val}, pNext{pn}{}

    };
    List() :HEAD{nullptr}, size_{0} {}
    void push(int val);
    int getSize(){return size_;}
private:
  Node* HEAD = nullptr;
  int size_ =0;
};

void List::push(int val){
    Node* pNode =HEAD;
    if(pNode != nullptr)
    {
       while(pNode->pNext != nullptr)
       {
           pNode = pNode->pNext;
       }
       pNode->pNext = new Node(val, nullptr);
    }
    else{
 HEAD = new Node (val, nullptr);
    }
    size_++;
}
int main()
{
    List l1;
     l1.push(1);
     l1.push(2);
     l1.push(3);
    cout << l1.getSize() << endl;
    return 0;
}
