#include <iostream>             /* 디버깅 (cout) */
#include <queue>                /* priority_queue 선언 */
#include <vector>               /* vector 선언 (기본적으로 stack의 내장함수를 갖고 있음) */
#include <functional>           /* greater() */

using namespace std;

const int INF = 1e9;
int start = 1;

int main() {

    int V = 5;
    /* pq: min heap 기반 우선순위 큐 마련 (최솟값이 먼저나오는 오름차순으로 자동 정렬하기 위함) */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    /* distance: 첫번째 노드에서 각 index의 번호까지 걸리는 최단거리를 저장한 vector */
    vector<int> distance(V+1, INF);                 /* vector<int> xxx(크기, 초기화할 값) */
    
    /* graph[nodes]: nodes에서 first(노드값)으로 가는데 걸리는 비용(second(weight)) */
    vector<pair<int, int>> graph[V+1];              /* ==> stack 구조로, push나 pop은 back에서밖에 이루어지지 않음. */

    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 1});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 3});
    graph[4].push_back({5, 1});

    /* 다익스트라 알고리즘 적용 전 distance */
    cout << "BEFORE" << endl;
    for (int i = 0; i < distance.size(); i++)
    {
        cout << "distance[" << i << "] = " << distance[i] << endl;
    }
    cout << "\n" << endl;

    /* 1. 시작노드를 최소 힙(우선순위 큐)에 넣음 */
    pq.push({0, start});        /* 첫번째 노드에서 첫번째 노드로 가는 것은 비용이 0이 든다. */
    distance[start] = 0;        /* 첫번째 노드 실제 거리를 0으로 초기화 <-- 이 과정이 반드시 필요함. */

    /* return해야 할 것은 distance, 실제 최단 거리를 distance에 기록하는 logic */

    /* 5. 최소 힙이 빌 때까지 반복 */
    while (!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int dist = top.first;
        int cur  = top.second;

        if (dist > distance[cur]) continue; // 이미 더 좋은 경로 처리됨

        // cur의 모든 이웃 순회 (auto/범위 for 대신 iterator)
        for (vector<pair<int,int> >::const_iterator it = graph[cur].begin();
             it != graph[cur].end(); ++it) {
            int next = it->first;
            int cost = it->second;

            int newDist = dist + cost;
            if (newDist < distance[next]) {
                distance[next] = newDist;
                pq.push(make_pair(newDist, next));
            }
        }
    }


    /* 결과 확인 */
    cout << "AFTER" << endl;
    for (int i = 0; i < distance.size(); i++){
        cout << "distance[" << i << "] = " << distance[i] << endl;
    }
    

    return 0;

}