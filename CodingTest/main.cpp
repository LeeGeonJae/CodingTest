#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

const int INF = 10000000;

vector<vector<pair<unsigned int, unsigned int>>> NodeMap;
vector<unsigned int> NodeTable;

void Dijkstra(const int& _VertexCount, const int& _StartVertex)
{
	// 우선순위큐 우선순위 반대로
	priority_queue<pair<unsigned int, unsigned int>
		, vector<pair<unsigned int, unsigned int>>
		, greater<pair<unsigned int, unsigned int>>> NodeQueue;

	NodeQueue.push(make_pair(0, _StartVertex));
	NodeTable[_StartVertex] = 0;

	// queue가 비워져 있을 때까지 순환
	while (!NodeQueue.empty())
	{
		// 현재 노드와 가중치
		unsigned int CurrentNode = NodeQueue.top().second;
		unsigned int CurrentWeight = NodeQueue.top().first;

		NodeQueue.pop();

		// 노드가 이어져 있는지 
		for (int i = 0; i < NodeMap[CurrentNode].size(); i++)
		{
			// 이웃 노드와 가중치
			unsigned int AroundNode = NodeMap[CurrentNode][i].first;
			unsigned int ArountWeight = NodeMap[CurrentNode][i].second;

			// 노드 가중치가 현재 테이블에 저장되어 있는 값보다 작으면 queue에 push
			// 노드 테이블에 값 업데이트
			if (CurrentWeight + ArountWeight < NodeTable[AroundNode])
			{
				NodeQueue.push(make_pair(CurrentWeight + ArountWeight, AroundNode));
				NodeTable[AroundNode] = CurrentWeight + ArountWeight;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int VertexCount, EdgeCount, StartVertex;

	cin >> VertexCount >> EdgeCount >> StartVertex;

	NodeTable.resize(VertexCount + 1, INF);
	NodeMap.resize(VertexCount + 1);

	for (int i = 0; i < EdgeCount; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		// 이웃 노드와 가중치 업데이트
		pair<unsigned int, unsigned int> a;
		a = make_pair(v, w);
		NodeMap[u].push_back(a);
	}

	// 다익스트라 함수 실행
	Dijkstra(VertexCount, StartVertex);

	// 노드 테이블의 최단경로 출력
	for (int i = 1; i < VertexCount + 1; i++)
	{
		if (NodeTable[i] == INF)
		{
			printf("INF\n");
			continue;
		}
		printf("%d\n", NodeTable[i]);
	}

	return 0;
}