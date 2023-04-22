#include "Heap.h"
#include <iostream>
#include <vector>

const int Inf = INT_MAX;

void Dijkstra()
{
	int n = 0;
	int s = 0;
	std::cout << "Введите кол-во вершин:";
	std::cin >> n;
	std::cout << "Введите исток: ";
	std::cin >> s; s--;


	std::vector <std::vector <int> > AdjMatrix(n, std::vector <int>(n));
	std::cout << "Матрица смежности:";
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			std::cin >> AdjMatrix[i][j];


	std::vector <int> minDist(n, Inf);
	minDist[s] = 0;

	std::vector <bool> visited(n, false);

	BinaryHeap <std::pair <int, int>> keeping;	
	keeping.addelem(std::make_pair(0, s));


	int count = 0;


	while (count != n && keeping.getsize() != 0)
	{
		int orglen = keeping.top().first;
		int vertex = keeping.top().second;
		visited[vertex] = true;
		count++;
		keeping.pop_forward();

		if (orglen > minDist[vertex])
			continue;
		for (int i = 0; i < n; i++)
		{
			if (visited[i])
				continue;
			int to = i;
			int len = AdjMatrix[vertex][i];
			
			if (minDist[to] > minDist[vertex] + len)
			{
				minDist[to] = minDist[vertex] + len;
				keeping.addelem(std::make_pair(minDist[i], to));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (minDist[i] != Inf)
		{
			std::cout << s + 1 << "-> " << i + 1 << " = " << minDist[i] << std::endl;
		}
		else
			std::cout << s + 1 << " -> " << i + 1 << " = " << "маршрут недоступен" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	Dijkstra();
	/*tech.addelem();
	tech.getmax();
	tech.heapify(0);
	tech.outHeap();*/
}

//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i] == false)
//			continue;
//		else
//			flag = 1;
//	}
//	if (flag = 1)
//		break;
//}