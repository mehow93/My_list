#include <iostream>

using namespace std;

class List {
public:
    struct Node {
      int var;
      Node* pNext;

    };
    List() :HEAD{nullptr}, size_{0} {}
    int getSize(){return size_;}
private:
  Node* HEAD = nullptr;
  int size_ =0;
};
int main()
{
    List l1;

    cout << l1.getSize() << endl;
    return 0;
}
