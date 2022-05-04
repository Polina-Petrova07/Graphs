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
		std::vector<bool> used(this->numVert);
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
			f = 0;
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
			ff = 0;
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
class pairType {
private:
	std::vector< std::vector <std::pair <int, double> > > Graph;
	std::vector< std::vector <std::pair <int, double> > > minOstov;
	std::vector< std::vector <std::pair <int, double> > > minOstovForKruskal; // ?
	int numVert;
public:
	std::vector<bool> used;
	int GenerateRandomWeight()
	{
		int k;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, 100);
		k = dist(gen);
		return k;
	}
	pairType(int n)
	{
		this->numVert = n;
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector< std::pair<int, double> >());
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
	pairType(int n, bool f)  // f - check for weight (if f == true - weight for each equals 0 )
	{
		
		if (f == false)
		{
			// call pairType(int n)
		}
			
		if (f == true)
		{	
			this->numVert = n;
			for (int i = 0; i < numVert; i++)
			{
				Graph.push_back(std::vector< std::pair<int, double> >());
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
						Graph[i][j].second = 0;
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

	}
	pairType(matrixType G)
	{
		this->numVert = G.getNumVert();
		for (int i = 0; i < numVert; i++)
		{
			Graph.push_back(std::vector< std::pair<int, double> >());
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
	void Prima()  // trubles with int and double
	{
		for (int i = 0; i < numVert; i++)
		{
			minOstov.push_back(std::vector< std::pair<int, double> >());
			for (int j = 0; j < numVert; j++)
			{
				minOstov[i].push_back(std::make_pair(0, 0));
				minOstov[i][j].first = j;
				minOstov[i][j].second = 0;
				
			}
		}
		
		const int INF = 1e9 + 7;
		std::vector<bool> used(this->numVert);
		double mst_weight = 0.0;
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
		q.push({ 0, 0 });
		int saveV = 0;
		std::vector<std::pair<int, int>> minOst;
		while (!q.empty()) 
		{
			std::pair<double, int> c = q.top();
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
			for (std::pair<int,double> e: this->Graph[v])
			{
				int u = e.first;
				double len_vu = e.second;
				if (!used[u])
				{
					q.push({ len_vu,u });
					saveV = v;
				}
			}
		}
		std::cout << "(alg. PRIMA) Minimum spanning tree wight: " << mst_weight << std::endl;
		for (int i = 0; i < minOst.size(); i++)
		{
			minOstov[minOst[i].first][minOst[i].second].second = this->Graph[minOst[i].first][minOst[i].second].second;
		}

		std::cout << std::endl;
		// for (int i = 0; i < minOst.size(); i++)  enters minOstov
			// std::cout << minOst[i].first << ";"<< minOst[i].second<<"  ";
		std::cout << std::endl << std::endl;
	}
	std::vector<std::pair<double, std::pair<int, int>>> convertInthisType()  // вес - вершина 1 - вершина 2
	{
		std::vector<std::pair<double, std::pair<int, int>>> g;
		for (int i = 0; i < this->numVert; i++)
		{
			for (int j = 0; j < this->numVert; j++)
			{
				std::pair<double, std::pair<int, int>> tmp;
				tmp.first = this->Graph[i][j].second;
				tmp.second.first = i;
				tmp.second.second = j;
				g.push_back(tmp);
			}
		}
		return g;
	}
	void add_edge(int i,int j, double distance)
	{
		this->Graph[i][j].second = distance;
	}
	void Kruskal()   
	{
		this->minOstovForKruskal = this->Graph;
		std::vector<std::pair<double, std::pair<int, int>>> g; // w from a to b
		for (int i = 0; i < this->numVert; i++)
		{
			for (int j = 0; j < this->numVert; j++)
			{
				std::pair<double, std::pair<int, int>> tmp;
				tmp.first = this->Graph[i][j].second;
				tmp.second.first = i;
				tmp.second.second = j;
				g.push_back(tmp);
			}
		}
		double cost = 0;
		std::vector<std::pair<int, int>> res;
		std::sort(g.begin(), g.end());
		std::vector<int> tree_id(this->numVert);
		for (int i = 0; i < this->numVert; ++i)
			tree_id[i] = i;
		for (int i = 0; i < g.size(); ++i)
		{
			int a = g[i].second.first;
			int b = g[i].second.second;
			double l = g[i].first;
			if (tree_id[a] != tree_id[b])
			{
				cost += l;
				res.push_back(std::make_pair(a, b));
				int old_id = tree_id[b];
				int new_id = tree_id[a];
				for (int j = 0; j < this->numVert; ++j)
					if (tree_id[j] == old_id)
						tree_id[j] = new_id;
			}
		}
		std::cout << "(alg. KRUSKALA) Minimum spanning tree wight: " << cost << std::endl;
	}
	std::vector< std::vector <std::pair <int, double> > > GetminOstov()  // can only be called after function "Prima"
	{
		return this->minOstov;
	}
	void setMinOstov(std::vector<std::vector<std::pair<int, double>>> minOstovNew)
	{
		this->minOstov = minOstovNew;
	}
	void DFS(int start, int f)  // dfs for minOstov
	{
		if (f != 0)  //  crutch
		{
			for (int i = 0; i < this->minOstov.size(); i++)
				used.push_back(false);
			f = 0;  
		}
		used[start] = true;
		for (int i = 0; i < this->minOstov.size(); i++)
			if (!used[i] && (this->minOstov[start][i].second != 0))
				DFS(i, f);
	}
	int numComponents(int n,int f) // for minOstov (check algoritm clustering)
	{
		if (f != 0)  // crutch
		{
			for (int i = 0; i < this->minOstov.size(); i++)
				used.push_back(false);
			f = 0;
		}
		n = 0;
		for (int i = 0; i < this->minOstov.size(); i++)
		{
			if (!used[i])
			{
				++n;
				DFS(i,f);
			}
		}
		return n;
	}
	void createNewMinOstov(std::vector<std::vector<std::pair<int, double>>> newMinOstov)
	{
		this->minOstov = newMinOstov;
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
	void printMinOstov()
	{
		std::cout << std::endl;
		std::cout << "minOstov from this graph:" << std::endl << std::endl;
		for (int i = 0; i < numVert; i++)
		{
			for (int j = 0; j < numVert; j++)
			{
				std::cout << "(" << minOstov[i][j].first << "," << minOstov[i][j].second << ") ";
			}
			std::cout << std::endl;
		}
	}


};
/* =============== this class nafig unnecessary ===================*/
class newTypeForIris
{
private:
	std::vector<std::pair<double, std::pair<int, int>>> Graph;
	int numVert;
public:

	newTypeForIris(int n)
	{
		this->numVert = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::pair<double, std::pair<int, int>> tmp;
				tmp.first = 0; // weight = 0
				tmp.second.first = i;
				tmp.second.second = j;
				this->Graph.push_back(tmp);
			}
		}
	}
	std::vector<std::pair<int, int>> res; // min ostov
	void Kruskal()
	{
		double cost = 0;
		std::sort(this->Graph.begin(), this->Graph.end());
		std::vector<int> tree_id(this->numVert);
		for (int i = 0; i < this->numVert; ++i)
			tree_id[i] = i;
		for (int i = 0; i < this->Graph.size(); ++i)
		{
			int a = this->Graph[i].second.first;
			int b = this->Graph[i].second.second;
			double l = this->Graph[i].first;
			if (tree_id[a] != tree_id[b])
			{
				cost += l;
				res.push_back(std::make_pair(a, b));
				int old_id = tree_id[b];
				int new_id = tree_id[a];
				for (int j = 0; j < this->numVert; ++j)
					if (tree_id[j] == old_id)
						tree_id[j] = new_id;
			}
		}
		std::cout << "(alg. KRUSKALA) Minimum spanning tree wight: " << cost << std::endl;
	}
	void add_edge(int i, int j, double distance)
	{
		this->Graph;
	}
	void print()  // need fix;
	{
		for (int i = 0; i < this->numVert; i++)
		{
			std::cout << "Between " << this->Graph[i].second.first << " and " << this->Graph[i].second.second << " weight is: " << this->Graph[i].first;
			std::cout << std::endl;
		}
	}

};

void clusteringg(pairType G, int n)  // !only after algoritm Prima for G (used minOstov, which generate in alg Prima)
{
	double maxEg = -10.0;
	std::vector<std::vector<std::pair<int, double>>> saveMinOstov = G.GetminOstov();
	int currentComp = 0;
	for (int k = 0; k < n - 1; k++)
	{
		int currentI = 0, currentJ = 0;
		for (int i = 0; i < saveMinOstov.size(); i++)
		{
			for (int j = 0; j < saveMinOstov.size(); j++)
			{
				if (saveMinOstov[i][j].second > maxEg)
				{
					maxEg = saveMinOstov[i][j].second;
					currentI = i;
					currentJ = j;
				}
			}
		}
		saveMinOstov[currentI][currentJ].second = 0;  // delete max edge
		maxEg = 0;
	}
	/*for (int i = 0; i < saveMinOstov.size(); i++)
	{
		for (int j = 0; j < saveMinOstov.size(); j++)
		{
			std::cout << "(" << saveMinOstov[i][j].first << "," << saveMinOstov[i][j].second << ") ";
		}
		std::cout << std::endl;
	}*/

	//G.setMinOstov(saveMinOstov);
	/*while (currentComp <= n)
	{
		int currentI = 0, currentJ = 0;
		for (int i = 0; i < saveMinOstov.size(); i++)
			for (int j = 0; j < saveMinOstov.size(); j++)
			{
				if (saveMinOstov[i][j].second > maxEg)
				{
					maxEg = saveMinOstov[i][j].second;
					currentI = i;
					currentJ = j;
				}
			}
		saveMinOstov[currentI][currentJ].second = 0;  // delete max edge
		G.createNewMinOstov(saveMinOstov);
		currentComp = G.numComponents(0, 7);
	}
	std::cout << "I DO ALL, NUM CLASTERS = " << currentComp;*/
}

