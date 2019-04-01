#include <iostream>

using namespace std;

class List {
public:
    struct Node {
        int var;
        Node* pNext;
        Node* pBefore;
        Node (int val, Node* pn, Node* pb) : var{val}, pNext{pn}, pBefore{pb} {}};
        List() :HEAD{nullptr}, size_{0} {}
        void push_back(int val);
        void push_front(int val);
        void pop_back();
        void pop_front();
        int getSize(){return size_;}
        void show();
        void reverse();
        double peak();
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
    void List:: reverse(){
        Node *pPrevNode = nullptr, *pNode = HEAD, *pNextNode;
        while(pNode !=nullptr){
            pNextNode = pNode->pNext;
            pNode->pNext = pPrevNode;

            pPrevNode = pNode;
            pNode = pNextNode;

        }
        HEAD = pPrevNode;
    }
    double List::peak(){
        Node* pNode = HEAD;
        while(pNode->pNext != nullptr)
        {
            pNode = pNode->pNext;
        }
        return(pNode->var);
    }
    int main()
    {
        List l1;
        l1.push_back(1);
        l1.push_back(5);
        l1.push_back(3);

        l1.show();
        l1.reverse();
        l1.show();



        return 0;
    }
