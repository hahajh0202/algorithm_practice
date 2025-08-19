#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {

    /* 2차원 배열 선언 */
    int V = 3;    /* 노드 개수 */
    vector<vector<int>> adj(V + 1, vector<int>(V + 1, INF));

    /* 2차원 배열 정리: 자기 자신으로 가는 weight은 0 */
    for (int i = 1; i <= V; ++i)
    {
        adj[i][i] = 0;
    }

    /* 2차원 배열 정리: 문제에서 주어진 노드로 가는 weight 입력 */
    adj[1][2] = 5;
    adj[2][3] = 2;

    /* 2차원 배열 확인 */
    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (adj[i][j] == INF){
                cout << "INF ";
            }
            else {
                cout << adj[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}