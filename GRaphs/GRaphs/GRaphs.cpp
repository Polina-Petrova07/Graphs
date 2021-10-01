﻿// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define INPUT = true
#undef INPUT

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "stdio.h"

const int NUMVERTEX = 5;
std::vector < std::vector<int> > Graph;
std::vector<bool> used(NUMVERTEX);
#if defined(INPUT)
//custom graph look main
#else
int mas[NUMVERTEX][NUMVERTEX] = {
	{0,1,0,1,0},
	{1,0,1,0,0},
	{0,1,0,1,0},
	{1,0,1,0,1},
	{0,0,0,1,0}
};
void masGraph(int mas[NUMVERTEX][NUMVERTEX], std::vector < std::vector<int> > Graph)
{
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
}
#endif

void Bfs(int start)
{
#if !defined(INPUT)
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
	std::queue <int> queue;
	queue.push(start);
	//std::vector<bool> used(NUMVERTEX);
	std::vector<int> dist(NUMVERTEX);
	std::vector<int> par(NUMVERTEX);
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
void Dfs(int start)
{
	std::cout << start <<" ";
	used[start] = true;
	for (int i = 0; i < NUMVERTEX; i++)
		if (!used[i] && Graph[start][i])
			Dfs(i);
}
int main()
{
	//std::vector < std::vector<int> > Graph;
	//for (int i = 0; i < 5; i++)
	//{
	//	Graph.push_back(std::vector <int>());
	//	for (int j = 0; j < NUMVERTEX; j++)
	//	{
	//		Graph[i].push_back(0);
	//		Graph[i][j] = 1;
	//	}
	//}
#if defined (INPUT)
	std::cout << "enter the number of vertices" << std::endl;
	int numVert;
	bool f;
	std::cin >> numVert;
	//std::vector < std::vector<int> > Graph;

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
#endif
	int start = 0;
	//std::cout << std::endl << std::endl << "BFS: "<<std::endl;
	//Bfs(start);
	masGraph(mas, Graph);
	std::cout << std::endl << std::endl << "DFS: " << std::endl;
	Dfs(start);
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
