#pragma once
#include <vector>
#include <iostream>
#include <queue>

int NUMVERTEX;
std::vector < std::vector<int> > Graph;
std::vector<bool> usedd(NUMVERTEX);

void Bfs(int start)
{
	std::queue <int> queue;
	queue.push(start);
	std::vector<int> dist(NUMVERTEX);
	std::vector<int> par(NUMVERTEX);
	std::vector<bool> used(NUMVERTEX);
	used[start] = true;
	par[start] = -1;
	while (!queue.empty())
	{
		int vertex = queue.front();
		for (int i = 0; i < Graph[vertex].size(); ++i)
		{
			if (!used[i] && Graph[vertex][i]!=-1)
			{
				used[i] = true;
				queue.push(i);
				dist[i] = dist[vertex] + 1;
				par[i] = vertex;
			}
		}
		queue.pop();
	}
	std::cout << "distance: ";
	for (int i = 0; i < dist.size(); i++)
		std::cout << dist[i] << " ";
	std::cout << std::endl;
	std::cout << "parents: ";
	for (int i = 0; i < par.size(); i++)
		std::cout << par[i] << " ";
	std::cout << std::endl;
}

void Dfs(int start)
{
	std::cout << start << " ";
	usedd[start] = true;
	for (int i = 0; i < NUMVERTEX; i++)
		if (!usedd[i] && ((Graph[start][i] != 0)||(Graph[start][i] != -1)))
			Dfs(i);
}

class matrixType {
private:
	int numVert;
	std::vector< std::vector<int> > Graph;
	int* color;
public:
	matrixType(int numVert)
	{
		std::cout << "if the graph is weight-bearing, for a nonexistent edge, put -1 " << std::endl;
		int f;
		this->numVert = numVert;
		color = new int[numVert];
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector <int>());
			for (int j = 0; j < numVert; j++)
			{
				std::cout << "is there a rib between: " << i << " and " << j << std::endl;
				std::cin >> f;
				Graph[i].push_back(0);
				Graph[i][j] = f;
				/*if (f == true)
				{
					Graph[i].push_back(0);
					Graph[i][j] = 1;
				}
				else
				{
					Graph[i].push_back(0);
					Graph[i][j] = 0;
				}*/
			}
			color[i] = 0;
		}
	}
	int getNumVert()
	{
		return numVert;
	}
	int* getMasColor()
	{
		return color;
	}
	bool loopSearch(int start, bool f)
	{
		std::cout << start << " ";
		color[start] = 1;
		for (int i = 0; i < Graph[start].size(); ++i)
			if (color[Graph[start][i]] == 0)
				loopSearch(Graph[start][i], f);
			else
			{
				if (color[Graph[start][i]] == 1)
					f = true;
			}
		color[start] = 2;
		return f;
	}
	int NComp(int n)
	{
		n = 0;
		for (int i = 0; i < numVert; i++)
		{
			if (!usedd[i])
			{
				++n;
				Dfs(i);
			}
		}
		return n;
	}
	void Dijkstra(int start)
	{
		int* dist = new int[numVert];
		int* used = new int[numVert];
		for (int i = 0; i < numVert; i++)
		{
			dist[i] = INT_MAX;
			used[i] = 0;
		}
		dist[start] = 0;
		for (int i = 0; i < numVert; i++)
		{
			int c = INT_MAX, min;
			for (int j = 0; j < numVert; j++)
			{
				if ((dist[j] < c) && (!used[j]))
				{
					min = j;
					c = dist[j];
				}
			}
			for (int j = 0; j < numVert; j++)
			{
				if (Graph[min][j] != -1)
					if ((dist[j] > Graph[min][j] + c) && !used[j])
						dist[j] = Graph[min][j] + c;
			}
			used[min] = 1;
		}
		for (int i = 0; i < NUMVERTEX; i++)
		{

			if (dist[i] != INT_MAX)
			{
				std::cout << "distance from " << start << " to " << i << " :" << dist[i];
				std::cout << std::endl;
			}
			else
			{
				std::cout << "form " << start << " to " << i << " no way";
				std::cout << std::endl;
			}
		}
	}
	int& operator ()(int i, int j)
	{
		return Graph[i][j];
	}
	void printMatrix()
	{
		std::cout << std::endl;
		std::cout << "adjacency matrix:" << std::endl << std::endl;
		for (int i = 0; i < numVert; i++)
		{
			for (int j = 0; j < numVert; j++)
			{
				std::cout << " " << Graph[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	void printMasColor()
	{
		for (int i = 0; i < numVert; i++)
		{
			std::cout << "color " << i << ": " << color[i] << std::endl;;
		}
	}
};
