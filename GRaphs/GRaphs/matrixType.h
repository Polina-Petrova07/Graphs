#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <cstdlib>
#include <random>
//#include <bits/stdc++.h>

int NUMVERTEX;
std::vector < std::vector<int> > Graph;
//std::vector<bool> usedd(NUMVERTEX);

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
/*
void Dfs(int start)
{
	std::cout << start << " ";
	usedd[start] = true;
	for (int i = 0; i < NUMVERTEX; i++)
		if (!usedd[i] && ((Graph[start][i] != 0) || (Graph[start][i] != -1)))
			Dfs(i);
}*/

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

	int getNumVert()
	{
		return numVert;
	}
	int* getMasColor()
	{
		return color;
	}
	std::vector<bool> used;
	//used.resize(this->numVert);
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
		//std::cout << "i generate" << std::endl;
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
	std::vector<int> get_neighbords(int vertex)
	{
		std::vector<int> neighbords(numVert, 0);
		for (int i = 0; i < this->numVert; i++)
		{
			if (this->Graph[vertex][i] != -1)
				neighbords[i] = 1;
		}
		return neighbords;
	}
	void BFS_bottom_up(int start)
	{
		//this->numVert = this->numVert * 3;  // !
		std::set<int> inFrontier, next;
		std::vector<int> par(this->numVert, -1);
		std::vector<int> dist(this->numVert,-1);
		par[start] = start;
		dist[start] = 0;
		inFrontier.insert(start);
		while (!inFrontier.empty())
		{
			for (size_t i = 0; i < this->numVert; ++i)
			{
				if (par[i] == -1)
				{
					for (int j=0; j < this->numVert; ++j)
					{
						if (this->Graph[i][j] && inFrontier.find(j) != inFrontier.end())
						{
							next.insert(i);
							par[i] = j;
							dist[i] = dist[j] + 1;
						}
					}
				}
			}
			inFrontier = next;
			next.clear();
		}
		/*std::cout << "distance: ";
		for (int i = 0; i < dist.size(); i++)
			std::cout << dist[i] << " ";
		std::cout << std::endl;
		std::cout << "parents: ";
		for (int i = 0; i < par.size(); i++)
			std::cout << par[i] << " ";
		std::cout << std::endl;*/

	}
	void BFSHibrid(int start)
	{
		int f = this->numVert / 2;
		int iter = 0;
		std::set<int> inFrontier, next;
		std::vector<int> par(this->numVert, -1);
		std::vector<int> dist(this->numVert, -1);
		std::queue <int> queue;
		par[start] = start;
		dist[start] = 0;
		inFrontier.insert(start);
		while (!inFrontier.empty())
		{
			if (iter > f)
			{
				queue.pop();
				for (size_t i = 0; i < this->numVert; ++i)
				{
					if (par[i] == -1)
					{
						for (int j = 0; j < this->numVert; ++j)
						{
							if (this->Graph[i][j] && inFrontier.find(j) != inFrontier.end())
							{
								next.insert(i);
								par[i] = j;
								dist[i] = dist[j] + 1;
								queue.push (Graph[i][j]);
							}
						}
					}
				}
				iter++;
				inFrontier = next;
				next.clear();
			}
			else if (iter <= f)
			{

			}
				
		}
	}
	void BFSMTgraf(int start)
	{
		this->numVert = this->numVert * 3;  // !
		std::queue <int> queue;
		queue.push(start);
		std::vector<int> dist(this->numVert);
		std::vector<int> par(this->numVert);
		std::vector<bool> used(this->numVert+1);
		used[start] = true;
		par[start] = -1;
		while (!queue.empty())
		{
			int vertex = queue.front();
			for (int i = 0; i < this->Graph[vertex].size(); ++i)
			{
				if (!used[i] && this->Graph[vertex][i])// (this->Graph[vertex][i] != -1) && this->Graph[vertex][i] != 0)
				{
					used[i] = true;
					queue.push(i);
					dist[i] = dist[vertex] + 1;
					par[i] = vertex;
				}
			}
			queue.pop();
		}
		/*
		std::cout << "distance: ";
		for (int i = 0; i < dist.size(); i++)
			std::cout << dist[i] << " ";
		std::cout << std::endl;
		std::cout << "parents: ";
		for (int i = 0; i < par.size(); i++)
			std::cout << par[i] << " ";
		std::cout << std::endl;*/
	}
	int f = 5;
	void DfsMTgraf(int start)
	{
		if (f == 5)  //  костыль
		{
			for (int i = 0; i < this->numVert; i++)
				used.push_back(false);
			f == 0;
		}
		std::cout << start << " ";
		used[start] = true;
		for (int i = 0; i < this->numVert; i++)
			if (!used[i] && ((Graph[start][i] != 0) || (Graph[start][i] != -1)))
				DfsMTgraf(i);
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
	int ff = 5;
	int NComp(int n)
	{
		if (ff == 5)  //  костыль
		{
			for (int i = 0; i < this->numVert; i++)
				used.push_back(false);
			ff == 0;
		}
		n = 0;
		for (int i = 0; i < numVert; i++)
		{
			if (!used[i])
			{
				++n;
				DfsMTgraf(i);
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
	matrixType& operator= (const std::vector< std::vector<int> >& v)
	{
		this->Graph = v;
		this -> numVert = v.size();
		return *this;
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
	std::vector< std::vector <std::pair <int, int> > > minOstov;
	int numVert;
public:
	int GenerateRandomWeight()
	{
		int k;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, 100);
		k = dist(gen);
		return k;
	}
	pairTipe(int n)
	{
		this->numVert = n;
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector< std::pair<int, int> >());
			for (int j = 0; j < numVert; j++)
			{
				Graph[i].push_back(std::make_pair(0, 0));
				if (i == j) 
				{
					Graph[i][j].first = j;
					Graph[i][j].second = 0;
				}
				else
				{
					Graph[i][j].first = j;
					Graph[i][j].second = GenerateRandomWeight();
				}
				
			}
		}
		for (int i = 0; i < numVert; i++)
		{
			for (int j = 0; j < numVert; j++)
			{
				Graph[i][j].second = Graph[j][i].second;
			}
		}
	}
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
	int getNumVert()
	{
		return (this->numVert);
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
	void Prima(int start) 
	{
		for (int i = 0; i < numVert; i++)
		{
			minOstov.push_back(std::vector< std::pair<int, int> >());
			for (int j = 0; j < numVert; j++)
			{
				minOstov[i].push_back(std::make_pair(0, 0));
				minOstov[i][j].first = j;
				minOstov[i][j].second = 0;
				
			}
		}
		
		const int INF = 1e9 + 7;
		std::vector<bool> used(this->numVert + 1);
		int mst_weight = 0;
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
		q.push({ 0, 0 });
		int saveV = 0;
		std::vector<std::pair<int, int>> minOst;
		while (!q.empty()) 
		{
			std::pair<int, int> c = q.top();
			q.pop();
			int dst = c.first, v = c.second;
			if (used[v])
			{
				continue;
			}
			//this->minOstov[line][chek].first = v;
			//this->minOstov[v][pos].second = dst;
			used[v] = true;
			mst_weight += dst;
			minOst.push_back({ saveV,v });
			for (std::pair<int,int> e: this->Graph[v])
			{
				int u = e.first;
				int len_vu = e.second;
				if (!used[u])
				{
					q.push({ len_vu,u });
					saveV = v;
				}
			}
		}
		std::cout << "Minimum spanning tree wight: " << mst_weight << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < minOst.size(); i++)
			std::cout << minOst[i].first << ";"<< minOst[i].second<<"  ";
	}
	std::vector< std::vector <std::pair <int, int> > > GetminOstov()  // can only be called after function "Prima"
	{
		std::vector< std::vector <std::pair <int, int> > > returnOstov = this->minOstov;
		return(returnOstov);
	}
	void clustering(int n)  // can only be called after function "Prima"
	{
		int numClasters = 0;
		int DelEg = 0;
		int maxEg = INT_MIN;
		while (DelEg < n)
		{
			int rememberI = 0;
			int rememberJ = 0;
			for (int i = 0; i < this->numVert; i++)
			{
				for (int j = 0; j < this->numVert; j++)
				{
					int currentW = minOstov[i][j].second;
					if (currentW > maxEg)
					{
						maxEg = currentW;
						//  remeber this vertex
						rememberI = i;
						rememberJ = j;
					}
				}
			}
			//  delete this ege
			minOstov[rememberI][rememberJ].first = rememberJ;
			minOstov[rememberI][rememberJ].second = 0;
			DelEg++;
			numClasters++;
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

