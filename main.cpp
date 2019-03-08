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
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    int getSize(){return size_;}
    void show();
private:
  Node* HEAD = nullptr;
  int size_ =0;
};

void List::push_back(int val){ // putting new values to stack at top of it
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
void List::pop_back(){ // pop values from top

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
void List::push_front(int val){
   HEAD = new Node (val, HEAD);
   size_ ++;
}

void List:: pop_front(){
    if(HEAD != nullptr){
    Node* pNode = HEAD;
    HEAD = HEAD->pNext;
    delete(pNode);
    size_--;
    }

}
int main()
{
    List l1;
l1.pop_front();
l1.push_front(1);
l1.push_back(2);
l1.push_front(5);
l1.show();
cout<<"rozmiar: "<<l1.getSize()<<endl;
l1.pop_front();
l1.show();
cout<<"rozmiar: "<<l1.getSize()<<endl;

    return 0;
}
