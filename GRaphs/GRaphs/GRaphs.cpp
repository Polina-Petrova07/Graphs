// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
#if defined (INPUT)   //make graph

	/*int num;
	std::cout << "enter the number of vertices" << std::endl;
	std::cin >> num;
	matrixType G(num);
	G.printMatrix();
	std::cout << std::endl;
	NUMVERTEX = G.getNumVert();
	std::cout << "NUMVERTEX: " << NUMVERTEX << std::endl;
	std::vector<bool> used_dfs(NUMVERTEX);
	usedd = used_dfs;

	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = G(i, j);
		}
	}
	std::cout << std::endl;*/
	
#else
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
#endif
	int start = 0;

	/*bool f;
	f = false;
	int* mas;
	mas = G.getMasColor();

	for (int i = 0; i < num; i++)
	{
		if (mas[i] == 0)
		  f= G.loopSearch(i,f);
	}
	if (f == true)
		std::cout << "yea" << std::endl;
	else
		std::cout << "no" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;

	Bfs(start);
	std::cout << std::endl;
	std::cout << std::endl;
	Dfs(start);
	std::cout << std::endl;
	std::cout << std::endl;
	int n = 0, k;
	k = G.NComp(n);
	std::cout <<"Ncomp"<< k;
	std::cout << std::endl;
	std::cout << std::endl;*/

	//srand(time(NULL));
	matrixType G;
	G.printMatrix();
	std::cout << std::endl;
	std::cout << std::endl;
	NUMVERTEX = G.getNumVert(); //!!!
	std::cout << "NUMVERTEX: " << NUMVERTEX << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	G.Dijkstra(start);
	
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
