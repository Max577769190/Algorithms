#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> array;

    for (int i = 0; i != 10; ++i) {
        array.push_back(i);
    }
    
    for (auto i : array) {
        cout << i << endl;
    }
    return 0;
}