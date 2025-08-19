#include <utility>
#include <iostream>

using namespace std;

int main() {
    pair<int, string> p = make_pair(1, "apple");

    cout << p.first << endl;
    cout << p.second << endl;

    return 0;
}