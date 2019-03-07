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
    void show();
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
void List::show(){
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
    return 0;
}
