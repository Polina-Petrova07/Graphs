// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// https://www.cplusplus.com/reference/chrono/high_resolution_clock/now/

#define INPUT = true
//#undef INPUT

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "stdio.h"
#include "matrixType.h"
#include "crsType.h"

#if defined(INPUT)
//int NUMVERTEX;
//custom graph look main
#else
const int NUMVERTEX = 5;
int mas[NUMVERTEX][NUMVERTEX] = {
	{0,1,1,0,1},
	{1,0,0,1,0},
	{1,0,0,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0}
};
#endif

//std::vector < std::vector<int> > Graph;
//std::vector<bool> usedd(NUMVERTEX);

//void Bfs(int start)
//{
//	std::queue <int> queue;
//	queue.push(start);
//	std::vector<int> dist(NUMVERTEX);
//	std::vector<int> par(NUMVERTEX);
//	std::vector<bool> used(NUMVERTEX);
//	used[start] = true;
//	par[start] = -1;
//	while (!queue.empty())
//	{
//		int vertex = queue.front();
//		for (int i = 0; i < Graph[vertex].size(); ++i)
//		{
//			if (!used[i] && Graph[vertex][i])
//			{
//				used[i] = true;
//				queue.push(i);
//				dist[i] = dist[vertex] + 1;
//				par[i] = vertex;
//			}
//		}
//		queue.pop();
//	}
//	std::cout << "distance: ";
//	for (int i = 0; i < dist.size(); i++)
//		std::cout << dist[i] << " ";
//	std::cout << std::endl;
//	std::cout << "parents: ";
//	for (int i = 0; i < par.size(); i++)
//		std::cout << par[i] << " ";
//	std::cout << std::endl;
//}
//
//void Dfs(int start)
//{
//	std::cout << start << " ";
//	usedd[start] = true;
//	for (int i = 0; i < NUMVERTEX; i++)
//		if (!usedd[i] && Graph[start][i] != 0)
//			Dfs(i);
//}

//class crsType {
//private:
//	std::vector<int> mas;
//	std::vector<int> mas1;
//public:
//	crsType()
//	{
//		int numVert, k, l;
//		mas1.push_back(0);
//		std::cout << "enter the number of vertices" << std::endl;
//		std::cin >> numVert;
//		for (int i = 0; i < numVert; i++)
//		{
//			std::cout << "with how many connection vertices? " << i << std::endl; //сколько от i
//			std::cin >> l;
//			for (int j = 0; j < l; j++)
//			{
//				std::cout << "what is connected with " << i << std::endl; //какие от i
//				std::cin >> k;
//				mas.push_back(k);
//			}
//			mas1.push_back(mas.size() + 1);
//		}
//	}
//	crsType(std::vector<int> mas, std::vector<int> mas1)
//	{
//		this->mas = mas;
//		this->mas1 = mas1;
//	}
//	~crsType()
//	{
//
//	}
//	void print()
//	{
//		std::cout << "mas connectes vertex: ";
//		for (int i = 0; i < mas.size(); i++)
//		{
//			std::cout << mas[i] << " ";
//		}
//		std::cout << std::endl;
//		std::cout << "mas index vertex: ";
//		for (int i = 0; i < mas1.size(); i++)
//		{
//			std::cout << mas1[i] << " ";
//		}
//	}
//};

//class matrixType {
//private:
//	int numVert;
//	std::vector< std::vector<int> > Graph;
//	int* color;
//public:
//	matrixType(int numVert)
//	{
//		std::cout << "if the graph is weight-bearing, for a nonexistent edge, put -1 " << std::endl;
//		int f;
//		this->numVert = numVert;
//		color = new int[numVert];
//		for (int i = 0; i < numVert; i++)
//		{
//			Graph.push_back(std::vector <int>());
//			for (int j = 0; j < numVert; j++)
//			{
//				std::cout << "is there a rib between: " << i << " and " << j << std::endl;
//				std::cin >> f;
//				Graph[i].push_back(0);
//				Graph[i][j] = f;
//				/*if (f == true)
//				{
//					Graph[i].push_back(0);
//					Graph[i][j] = 1;
//				}
//				else
//				{
//					Graph[i].push_back(0);
//					Graph[i][j] = 0;
//				}*/
//			}
//			color[i] = 0;
//		}
//	}
//	int getNumVert()
//	{
//		return numVert;
//	}
//	int* getMasColor()
//	{
//		return color;
//	}
//	bool loopSearch(int start,bool f)
//	{
//		std::cout << start << " ";
//		color[start] = 1;
//		for (int i = 0; i < Graph[start].size(); ++i)
//			if (color[Graph[start][i]] == 0)
//				loopSearch(Graph[start][i], f);
//			else
//			{
//				if (color[Graph[start][i]] == 1)
//					f = true;
//			}
//		color[start] = 2;
//		return f;
//	}
//	int NComp(int n)
//	{
//		n = 0;
//		for (int i = 0; i < numVert; i++)
//		{
//			if (!usedd[i])
//			{
//				++n;
//				Dfs(i);
//			}
//		}
//		return n;
//	}
//	void Dijkstra(int start)
//	{
//		int* dist = new int[numVert];
//		int* used = new int[numVert];
//		for (int i = 0; i < numVert; i++)
//		{
//			dist[i] = INT_MAX;
//			used[i] = 0;
//		}
//		dist[start] = 0;
//		for (int i = 0; i < numVert; i++)
//		{
//			int c = INT_MAX, min;
//			for (int j = 0; j < numVert; j++)
//			{
//				if ((dist[j] < c) && (!used[j]))
//				{
//					min = j;
//					c = dist[j];
//				}
//			}
//			for (int j = 0; j < numVert; j++)
//			{
//				if (Graph[min][j] != -1)
//					if ((dist[j] > Graph[min][j] + c) && !used[j])
//						dist[j] = Graph[min][j] + c;
//			}
//			used[min] = 1;
//		}
//		for (int i = 0; i < NUMVERTEX; i++)
//		{
//
//			if (dist[i] != INT_MAX)
//			{
//				std::cout << "distance from " << start << " to " << i << " :" << dist[i];
//				std::cout << std::endl;
//			}
//			else
//			{
//				std::cout << "form " << start << " to " << i << " no way";
//				std::cout << std::endl;
//			}
//		}
//	}
//	int& operator ()(int i, int j)
//	{
//		return Graph[i][j];
//	}
//	void printMatrix()
//	{
//		std::cout << std::endl;
//		std::cout << "adjacency matrix:" << std::endl << std::endl;
//		for (int i = 0; i < numVert; i++)
//		{
//			for (int j = 0; j < numVert; j++)
//			{
//				std::cout << " " << Graph[i][j] << " ";
//			}
//			std::cout << std::endl;
//		}
//	}
//	void printMasColor()
//	{
//		for (int i = 0; i < numVert; i++)
//		{
//			std::cout << "color " << i << ": " << color[i] << std::endl;;
//		}
//	}
//};

int main()
{
	int start = 0;
	/*matrixType G(4);   // 20/10
	G.printMatrix();
	NUMVERTEX = G.getNumVert(); //!!!
	std::cout << "NUMVERTEX: " << NUMVERTEX << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	G.Dijkstra(start);
	std::cout << std::endl;
	std::cout << std::endl;
	pairTipe Gp(G);
	Gp.printPair();
	std::cout << std::endl;
	std::cout << std::endl;
	Gp.Dijkstra(start);*/

	/*
	std::cout << "==========" << "first check" << "==========" << std::endl;
	std::vector< std::vector <int>> v {
		{0,1,1,0},
		{1,0,1,1},
		{1,1,0,1},
		{0,1,1,0}
	};
	matrixType g(v,4);
	g.printMatrix();
	std::cout << std::endl << "standart BFS:" << std::endl;
	g.BFSMTgraf(0);
	std::cout << std::endl;
	std::cout << std::endl << "bottom up BFS:" << std::endl;
	g.BFS_bottom_up(start);
	std::cout << std::endl << std::endl;
	std::cout << "==========" << "second check" << "==========" << std::endl;
	std::vector< std::vector <int>> v1 {
		{0,1,1,1},
		{1,0,1,0},
		{1,1,0,1},
		{1,1,1,0}
	};
	matrixType g1(v1, 4);
	g1.printMatrix();
	std::cout << std::endl << "standart BFS:" << std::endl;
	g1.BFSMTgraf(0);
	std::cout << std::endl;
	std::cout << std::endl << "bottom up BFS:" << std::endl;
	g1.BFS_bottom_up(start);
	std::cout << std::endl << std::endl;
	std::cout << "==========" << "third check" << "==========" << std::endl;
	std::vector< std::vector <int>> v2{
		{0,1,0,0,0},
		{1,0,1,1,0},
		{0,1,0,0,0},
		{0,1,0,0,1},
		{0,0,0,1,0}
	};
	matrixType g2(v2, 5);
	g2.printMatrix();
	std::cout << std::endl << "standart BFS:" << std::endl;
	g2.BFSMTgraf(0);
	std::cout << std::endl;
	std::cout << std::endl << "bottom up BFS:" << std::endl;
	g2.BFS_bottom_up(start);
	std::cout << std::endl << std::endl;
	std::vector< std::vector <int>> v3{
		{0,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,0}
	};
	matrixType g3(v3, 4);
	pairTipe GG(g3);
	GG.printPair();*/

	//matrixType G;
	//std::cout << std::endl;
	//G.generateG();
	//double t1, t2, t3, t4;
	//t1 = clock();
	//G.BFS_bottom_up(start);
	//t2 = clock();
	//std::cout << std::endl;
	//std::cout <<"bottom up BFS time: "<< (t2 - t1)/1000<<" sec" << std::endl;
	//t3 = clock();
	//G.BFSMTgraf(start);
	//t4 = clock();
	//std::cout << std::endl;
	//std::cout << "BFS standart  time: " << (t4 - t3) / 1000 << " sec" << std::endl;

	
	pairTipe G(4);
	G.printPair();
	std::cout << std::endl << std::endl;
	G.Prima(0);
	std::cout << std::endl << std::endl;
	std::vector< std::vector <std::pair <int, int> > > minOstov;
	minOstov = G.GetminOstov();
	std::cout << "minOstov:" << std::endl << std::endl;
	for (int i = 0; i < G.getNumVert(); i++)
	{
		for (int j = 0; j < G.getNumVert(); j++)
		{
			std::cout << "(" << minOstov[i][j].first << "," << minOstov[i][j].second << ") ";
		}
		std::cout << std::endl;
	}
	

	/*std::vector<std::vector<int>> Graph;
	for (int i = 0; i < 4; i++)
	{
		int n = 0;
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < 4; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = n;
			n++;
		}
		//n++;
	}
	for (int i : Graph[1])
	{
		std::cout << Graph[1][i] << " ";
	}*/
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
