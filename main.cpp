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
    void pop();
    int getSize(){return size_;}
    void show();
private:
  Node* HEAD = nullptr;
  int size_ =0;
};

void List::push(int val){ // push values
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
void List::pop(){ // pop values

    if(HEAD != nullptr){
      if(size_ == 1){ // jeden el.
          delete HEAD;
          HEAD= nullptr;
      }

    else{ // wincyj ele
        Node* pNode = HEAD, *pPrev = nullptr;
        while(pNode->pNext != nullptr)
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
        delete(pNode);
        pPrev->pNext = nullptr;
    }
      size_ --;
}
}

void List::show(){ // show function
    Node* pNode = HEAD;
    while(pNode!= nullptr)
    {
        cout <<"Wartosc noda to: "<<pNode->var<<endl;
        pNode = pNode->pNext;
    }

}
int main()
{
    List l1;
     l1.push(13);
     l1.push(23);
     l1.push(34);
     l1.push(4);
     l1.push(314);
     l1.show();
    cout << l1.getSize() << endl;
    l1.pop();
    l1.pop();
    l1.pop();
    l1.show();
   cout << l1.getSize() << endl;
    return 0;
}
