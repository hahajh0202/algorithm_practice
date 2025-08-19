#include <queue>
#include <iostream>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location);

int main () {
    vector<int> input_priorities = {1, 1, 9, 1, 1, 1};
    int retval;

    retval = solution(input_priorities, 0);

    cout << "result = " << retval << endl;

    return 0;
}

int solution(vector<int> priorities, int location){
    int answer = 0;
    queue<pair<int, int>> index_priority;
    priority_queue<int> pri;

    for (int i = 0; i < priorities.size(); i++)
    {
        index_priority.push({i, priorities[i]});
        pri.push(priorities[i]);
    }

    while(!index_priority.empty()){
        int cur_index = index_priority.front().first;
        int cur_priority = index_priority.front().second;
        index_priority.pop();

        if (cur_priority == pri.top())
        {
            answer++;
            pri.pop();

            if (cur_index == location){
                return answer;
            }
        }
        else {
            index_priority.push({cur_index, cur_priority});
        }

    }

    
    /* index_priority debug */
    /*
    while(!index_priority.empty()){
        cout << "index: " << index_priority.front().first << " priority: " << index_priority.front().second << endl;
        index_priority.pop();
    }
    */

    /* pri debug */
    /*
    int j = 0;
    while(!pri.empty()){
        cout << "pri[" << j << "] = " << pri.top() << endl;
        pri.pop();
        ++j;
    }
    */

    return answer;
}