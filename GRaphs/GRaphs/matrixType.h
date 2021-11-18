#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>

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
		if (!usedd[i] && ((Graph[start][i] != 0) || (Graph[start][i] != -1)))
			Dfs(i);
}

class matrixType {
private:
	int numVert;
	std::vector< std::vector<int> > Graph;
	int* color;
public:
	/*matrixType()
	{
		std::cout << "enter number of vertix " << std::endl;
		std::cin >> this->numVert;
		color = new int[numVert];
		int f;
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector <int>());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(0);
				if (i == j)
					Graph[i][j] = -1;
				else
				{
					int f = rand() % 2 + 1;
					if (f == 1)
					{
						Graph[i][j] = -1;
					}
					else
					{
						int k = rand() % 100 + 1;
						Graph[i][j] = k;
					}
				}
				//Graph[j][i] = Graph[i][j];
			}
			color[i] = 0;
		}
		for (int i = numVert-1; i >=0; i--)
		{
			Graph.push_back(std::vector<int>());
		    for (int j =numVert-1; j >=0; j--)
		    {
				//Graph[i].push_back(0);
				Graph[j][i] = Graph[i][j];
			}
		}
	}*/
	matrixType()
	{
		int n;
		std::cout << "enter n " << std::endl;
		std::cin >> n;
		this->numVert = n;
		color = new int[numVert];
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector <int>());
				for (int j = 0; j < numVert; j++)
				{
					Graph[i].push_back(0);
					Graph[i][j] = 0;
				}
		}
	}

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
			}
			color[i] = 0;
		}
	}
	matrixType(std::vector< std::vector<int>> G, int numVert)
	{
		this->Graph = G;
		this->numVert = numVert;
		color = new int[numVert];
		for (int i = 0; i < numVert; i++)
		{
			color[i] = 0;
		}
	}
	void addRib(int i, int j, int w)
	{
		Graph[i][j] = w;
	}
	int generateW()
	{
		return (rand()%100+1);
	}
	void generateG()
	{
		//this->numVert = 3 * this->numVert + 3;
		int memN = this->numVert;
		int n = this->numVert * 3 + 3;
		this->numVert = n;
		Graph = std::vector<std::vector<int> >(n, std::vector<int>(n));
		//Graph.push_back(std::vector <int>());
		for (int i = 0; i < n; i++)
		{
			Graph.push_back(std::vector <int>());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(0);
				Graph[i][j] = generateW();
			}
		}
		for (int i = 0; i < memN; i++)
		{
			Graph.push_back(std::vector <int>());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(i);
				Graph[i][j] = generateW();
			}
		}
		for (int i = memN+2; i < n; i++)
		{
			Graph.push_back(std::vector <int>());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(i);
				Graph[i][j] = generateW();
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			Graph.push_back(std::vector<int>());
			for (int j = n - 1; j >= 0; j--)
			{
				if (i == j)
					Graph[i][j] = 0;
				else
				    Graph[j][i] = Graph[i][j];
			}
		}
	}
	void BFS_bottom_up(int start)
	{
		std::vector<int> par(this->numVert, -1);
		par[start] = start;
		std::queue<int> queue;
		std::vector<int> masAns(this->numVert);
		queue.push(start);
		while (!queue.empty())
		{
			int vertex = queue.front();
			queue.pop();
			for (int i = 0; i < this->Graph[vertex].size(); ++i)
			{
				if (par[i]==-1 && this->Graph[vertex][i] != -1)
				{
					queue.push(i);
					masAns[i] = masAns[vertex] + 1;
					par[i] = vertex;
				}
			}
		}
		std::cout << "distance: ";
		for (int i = 0; i < masAns.size(); i++)
			std::cout << masAns[i] << " ";
		std::cout << std::endl;
		std::cout << "parents: ";
		for (int i = 0; i < par.size(); i++)
			std::cout << par[i] << " ";
		std::cout << std::endl;

	}
	void BFSMTgraf(int start)
	{
		std::queue <int> queue;
		queue.push(start);
		std::vector<int> dist(this->numVert);
		std::vector<int> par(this->numVert);
		std::vector<bool> used(this->numVert);
		used[start] = true;
		par[start] = -1;
		while (!queue.empty())
		{
			int vertex = queue.front();
			for (int i = 0; i < this->Graph[vertex].size(); ++i)
			{
				if (!used[i] && this->Graph[vertex][i] != -1)
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
		for (int i = 0; i < this->numVert; i++)
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
		//return dist;
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
class pairTipe {
private:
	std::vector< std::vector <std::pair <int, int> > > Graph;
	int numVert;
public:
	pairTipe(matrixType G)
	{
		this->numVert = G.getNumVert();
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector< std::pair<int, int> >());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(std::make_pair(0,0));
				Graph[i][j].second = G(i, j);
				Graph[i][j].first = j;
			}
		}
	}
	void Dijkstra(int start)   //при ручном задании графа
	{
		std::vector<int> d(numVert, INT_MAX), p(numVert);
		d[start] = 0;
		std::priority_queue< std::pair <int, int> > q;
		q.push(std::make_pair(0, start));
		while (!q.empty())
		{
			int v = q.top().second, cur_d = -q.top().first;
			q.pop();
			if (cur_d > d[v]) continue;
			for (size_t j = 0; j < Graph[v].size(); ++j)
			{
				int to = Graph[v][j].first, len = Graph[v][j].second;
				if (d[v] + len < d[to])
				{
					d[to] = d[v] + len;
					p[to] = v;
					q.push(std::make_pair(-d[to], to));
				}
			}
		}
		for (int i = 0; i < this->numVert; i++)
		{
			if (d[i] != INT_MAX)
			{
				std::cout << "distance from " << start << " to " << i << " :" << d[i];
				std::cout << std::endl;
			}
			else
			{
				std::cout << "form " << start << " to " << i << " no way";
				std::cout << std::endl;
			}
		}
	}
	void printPair()
	{
		std::cout << std::endl;
		std::cout << "pairType matrix:" << std::endl << std::endl;
		for (int i = 0; i < numVert; i++)
		{
			for (int j = 0; j < numVert; j++)
			{
				std::cout << "(" << Graph[i][j].first << "," << Graph[i][j].second << ") ";
			}
			std::cout << std::endl;
		}
	}
};

