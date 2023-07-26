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
	// �켱����ť �켱���� �ݴ��
	priority_queue<pair<unsigned int, unsigned int>
		, vector<pair<unsigned int, unsigned int>>
		, greater<pair<unsigned int, unsigned int>>> NodeQueue;

	NodeQueue.push(make_pair(0, _StartVertex));
	NodeTable[_StartVertex] = 0;

	// queue�� ����� ���� ������ ��ȯ
	while (!NodeQueue.empty())
	{
		// ���� ���� ����ġ
		unsigned int CurrentNode = NodeQueue.top().second;
		unsigned int CurrentWeight = NodeQueue.top().first;

		NodeQueue.pop();

		// ��尡 �̾��� �ִ��� 
		for (int i = 0; i < NodeMap[CurrentNode].size(); i++)
		{
			// �̿� ���� ����ġ
			unsigned int AroundNode = NodeMap[CurrentNode][i].first;
			unsigned int ArountWeight = NodeMap[CurrentNode][i].second;

			// ��� ����ġ�� ���� ���̺� ����Ǿ� �ִ� ������ ������ queue�� push
			// ��� ���̺� �� ������Ʈ
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

		// �̿� ���� ����ġ ������Ʈ
		pair<unsigned int, unsigned int> a;
		a = make_pair(v, w);
		NodeMap[u].push_back(a);
	}

	// ���ͽ�Ʈ�� �Լ� ����
	Dijkstra(VertexCount, StartVertex);

	// ��� ���̺��� �ִܰ�� ���
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