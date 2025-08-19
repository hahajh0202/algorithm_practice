#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> v){
    vector<int> ans;

    queue<int> x;
    queue<int> y;

    for (int i = 0; i < 3; i++)
    {
        x.push(v[i][0]);
        y.push(v[i][1]);
    }

    while(x.size() != 1){
        int cur_value = x.front();
        x.pop();

        if (cur_value == x.front())
        {
            x.pop();
            ans.push_back(x.front());
        }
        else {
            x.push(cur_value);
        }
    }

    while(y.size() != 1){
        int cur_value = y.front();
        y.pop();

        if (cur_value == y.front())
        {
            y.pop();
            ans.push_back(y.front());
        }
        else {
            y.push(cur_value);
        }
    }

    return ans;
}