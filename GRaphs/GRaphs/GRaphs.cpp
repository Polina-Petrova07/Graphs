// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
#if defined(INPUT)
//custom graph
#else
int mas[NUMVERTEX][NUMVERTEX] = {
	{0,1,0,1,0},
	{1,0,1,1,1},
	{0,1,0,1,0},
	{1,1,1,0,0},
	{0,1,0,0,0}
};
#endif
std::vector<bool> used(NUMVERTEX);
void Bfs(int start)
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
		if (!used[i])
			Dfs(i);
}
int main()
{
	int start = 0;
	//Bfs(start);
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
