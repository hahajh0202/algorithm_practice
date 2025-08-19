#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {

    /* {weight, node} pair 선언. weight이 작은 순서대로(오름차순) 자동 정렬되게끔 하는 priority_queue */
    /* 다익스트라는 최소 힙 기반 우선순위 큐가 핵심임. */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    /* 각 노드까지 걸리는 거리(weight) 및 노드 입력 */
    pq.push({2, 1});
    pq.push({5, 2});
    pq.push({1, 3});

    /* priority_queue 내용 확인 */
    while(!pq.empty()){
        int cur_weight = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        cout << "현재 node에서 node(" << cur_node << ")까지의 weight(거리): " << cur_weight << endl;

    }

    return 0;
}