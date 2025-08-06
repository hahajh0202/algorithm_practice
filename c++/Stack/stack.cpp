#include <iostream>
#include <string>       /* 자동으로 size 조절해주는 좀 더 안전한 string 객체를 쓰기 위함. */
#include <sstream>      /* istringstream 사용을 위함 */
#include <stack>        /* stack 객체 선언을 위함 */

using namespace std;

stack<int> s;

int main(){
    int cmd_number;

    cin >> cmd_number;                      /* 입력 버퍼에 입력된 실제 값만 변수에 넣어줌. \n앞에 있는 실제 값들만. */
    cin.ignore();                           /* 입력 버퍼에 남아있는 \n을 제거해줌. */

    for (int i = 0; i < cmd_number; i++)
    {
        string line;
        getline(cin, line);                 /* 공백 포함해서 한 줄 전체를 받음. */
        istringstream iss(line);            /* 받은 한 줄 전부를 cin처럼 입력스트림처럼 활용할 준비를 마침. */

        string cmd;
        int value;

        iss >> cmd >> value;                /* 입력스트림은 >> 연산을 사용 가능하며, >> 연산은 공백(탭, 엔터포함)을 기준으로 토큰을 나눠 변수에 저장하는 성질이 있음. */

        if (cmd == "push")
        {
            s.push(value);
        }
        else if (cmd == "pop")
        {
            if (!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (cmd == "size")
        {
            cout << s.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (s.empty()){
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else if (cmd == "top")
        {
            if (!s.empty()){
                cout << s.top() << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else 
        {
            /* Do Nothing */
        }
    }

    return 0;
}
