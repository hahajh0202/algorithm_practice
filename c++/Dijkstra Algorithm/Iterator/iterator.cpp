// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // int main() {

// //     vector<int> ex(4, 10);

// //     for (vector<int>::iterator it = ex.begin(); it != ex.end(); ++it)
// //     {
// //         cout << *it << endl;
// //     }

// //     vector<pair<int, int>> gr;
// //     gr.push_back({1,1});
// //     gr.push_back({2,2});
// //     gr.push_back({3,3});
// //     gr.push_back({4,4});

// //     for (vector<pair<int, int>>::const_iterator it = gr.begin(); it != gr.end(); ++it)
// //     {
// //         cout << it->first << " , " << it->second << endl;
// //     }

// //     return 0;
// // }

// #include <iostream>
// using namespace std;

// int main() {
//     cout << "__cplusplus = " << __cplusplus << '\n';

//     if (__cplusplus >= 201703L) {
//         cout << " C++17 이상이 적용되었습니다!" << '\n';
//         // auto, structured binding, if with initializer 등 사용 가능
//         auto [x, y] = pair<int, int>{1, 2};
//         cout << "auto structured binding test: " << x << ", " << y << '\n';
//     } else {
//         cout << " C++17 미만입니다. 컴파일 옵션을 확인하세요." << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <utility> // pair
using namespace std;

int main() {
    // 1. C++ 표준 버전 확인
    cout << "__cplusplus = " << __cplusplus << "\n";
    if (__cplusplus >= 201703L) {
        cout << "✅ C++17 이상이 적용되었습니다!\n";
        // C++17 기능: 구조적 바인딩
        auto [x, y] = pair<int, int>{1, 2};
        cout << "Structured binding test -> x: " << x << ", y: " << y << "\n";
    } else {
        cout << "❌ C++17 미만입니다. 컴파일 옵션(-std=c++17)을 확인하세요.\n";
    }

    cout << "----------------------------------\n";

    // 2. vector 테스트
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    cout << "[vector] ";
    for (auto num : v) cout << num << " ";
    cout << "\n";

    // 3. deque 테스트
    deque<int> dq = {10, 20};
    dq.push_front(5);
    dq.push_back(30);
    cout << "[deque] ";
    for (auto num : dq) cout << num << " ";
    cout << "\n";

    // 4. queue 테스트
    queue<int> q;
    q.push(100);
    q.push(200);
    cout << "[queue] front: " << q.front() << ", back: " << q.back() << "\n";
    q.pop();
    cout << "After pop, front: " << q.front() << "\n";

    // 5. stack 테스트
    stack<string> st;
    st.push("first");
    st.push("second");
    cout << "[stack] top: " << st.top() << "\n";
    st.pop();
    cout << "After pop, top: " << st.top() << "\n";

    return 0;
}
