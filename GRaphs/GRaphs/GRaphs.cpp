// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define INPUT = true
#undef INPUT

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "stdio.h"

#if !defined (INPUT)
const int NUMVERTEX = 5;
#else
int NUMVERTEX;
#endif
std::vector < std::vector<int> > Graph;
//std::vector<bool> used(NUMVERTEX);
#if defined(INPUT)
//custom graph look main
#else
int mas[NUMVERTEX][NUMVERTEX] = {
	{0,1,1,0,1},
	{1,0,0,1,0},
	{1,0,0,0,0},
	{0,1,0,0,0},
	{1,0,0,0,0}
};
#endif

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
			if (!used[i] && Graph[vertex][i])
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
	for (int i = 0; i < NUMVERTEX; i++)
		std::cout << dist[i] << " ";
	std::cout << std::endl;
	std::cout << "parents: ";
	for (int i = 0; i < NUMVERTEX; i++)
		std::cout << par[i] << " ";
	std::cout << std::endl;
}
std::vector<bool> usedd(NUMVERTEX);
void Dfs(int start)
{
	std::cout << start <<" ";
	usedd[start] = true;
	for (int i = 0; i < NUMVERTEX; i++)
		if (!usedd[i] && Graph[start][i]!=0)
			Dfs(i);
}
int main()
{
#if defined (INPUT)
	std::cout << "enter the number of vertices" << std::endl;
	int numVert;
	bool f;
	std::cin >> numVert;
	NUMVERTEX = numVert;
	std::vector<bool> used_dfs(NUMVERTEX);
	usedd = used_dfs;
	for (int i = 0; i < numVert; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < numVert; j++)
		{
			std::cout << "is there a rib between: " << i << " and " << j << std::endl;
			std::cin >> f;
			if (f == true)
			{
				Graph[i].push_back(0);
				Graph[i][j] = 1;
			}
			else
			{
				Graph[i].push_back(0);
				Graph[i][j] = 0;
			}
				
		}
	}
	std::cout << std::endl;
	std::cout << "adjacency matrix:" << std::endl << std::endl;
	for (int i = 0; i < numVert; i++)
	{
		for (int j = 0; j < numVert; j++)
		{
			std::cout << " "<<Graph[i][j]<<" ";
		}
		std::cout << std::endl;
	}
#else
	/*for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}*/
#endif
	/*int start = 0;
	std::cout << std::endl << std::endl << "BFS: " << std::endl;
	Bfs(start);
	std::cout << std::endl << "DFS: " << std::endl;
	Dfs(start);*/

	int numVert, k, l;
	std::vector<int> mas;
	std::vector<int> mas1;
	mas1.push_back(0);
	std::cout << "enter the number of vertices" << std::endl;
	std::cin >> numVert;
	for (int i = 0; i < numVert; i++)
	{
		std::cout << "with how many connection vertices? " <<i<< std::endl; //сколько от i
		std::cin >> l;
		for (int j = 0; j < l; j++)
		{
			std::cout << "what is connected with " << i << std::endl; //какие от i
			std::cin >> k;
			mas.push_back(k);
		}
		mas1.push_back(mas.size()+1);
	}

	std::cout << "mas connectes vertex: ";
	for (int i = 0; i < mas.size(); i++)
	{
	std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "mas index vertex: ";
	for (int i = 0; i < mas1.size(); i++)
	{
		std::cout<< mas1[i] << " ";
	}

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
