#include<iostream>
#include<string>
#include"list.cpp"

using namespace std;

int main() {
    int a0 = 11;
    int a1 = 22;
    int a2 = 33;
    int a3 = 44;
    int a4 = 55;
    List<int> test; 

    test.append(a0);
    cout << test.get_item(0) << endl;

    test.append(a1);
    cout << test.get_item(1) << endl;
  
    test.append(a2);
    cout << test.get_item(2) << endl;

    test.append(a3);
    cout << test.get_item(3) << endl;

    test.append(a4);
    cout << test.get_item(4) << endl;

    cout << test.pop(0) << endl;
    cout << test.pop(3) << endl;

    int new_item = 0;
    test.insert(3, new_item);
    cout << "resualt "<< endl;
    for (size_t i = 0; i < test.get_size(); i++) {
        cout << test.get_item(i) << endl;
    }
    return 0; 
}