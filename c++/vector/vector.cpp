#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);

    cout << "size: " <<  v.size() << endl;

    cout << v[0] << "," << v[1] << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}