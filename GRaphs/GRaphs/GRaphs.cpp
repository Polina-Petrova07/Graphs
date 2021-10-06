// GRaphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define INPUT = true
//#undef INPUT

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "stdio.h"

#if defined(INPUT)
int NUMVERTEX;
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

std::vector < std::vector<int> > Graph;
std::vector<bool> usedd(NUMVERTEX);

class crsType {
private:
	std::vector<int> mas;
	std::vector<int> mas1;
public:
	crsType()
	{
		int numVert, k, l;
		mas1.push_back(0);
		std::cout << "enter the number of vertices" << std::endl;
		std::cin >> numVert;
		for (int i = 0; i < numVert; i++)
		{
			std::cout << "with how many connection vertices? " << i << std::endl; //сколько от i
			std::cin >> l;
			for (int j = 0; j < l; j++)
			{
				std::cout << "what is connected with " << i << std::endl; //какие от i
				std::cin >> k;
				mas.push_back(k);
			}
			mas1.push_back(mas.size() + 1);
		}
	}
	crsType(std::vector<int> mas, std::vector<int> mas1)
	{
		this->mas = mas;
		this->mas1 = mas1;
	}
	~crsType()
	{

	}
	void print()
	{
		std::cout << "mas connectes vertex: ";
		for (int i = 0; i < mas.size(); i++)
		{
			std::cout << mas[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "mas index vertex: ";
		for (int i = 0; i < mas1.size(); i++)
		{
			std::cout << mas1[i] << " ";
		}
	}
};
class matrixType {
private:
	int numVert;
	std::vector< std::vector<int> > Graph;
	int* color;
public:
	matrixType(int numVert)
	{
		//std::cout << "enter the number of vertices" << std::endl;
		bool f;
		//int num;
		//std::cin >> num;
		this->numVert = numVert;
		color = new int[numVert];
		//NUMVERTEX = numVert;
		//std::vector<bool> used_dfs(NUMVERTEX);
		//usedd = used_dfs;
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
	void loopSearch(int start, bool f)
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
				color[start] = 2;
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
	std::cout << start <<" ";
	usedd[start] = true;
	for (int i = 0; i < NUMVERTEX; i++)
		if (!usedd[i] && Graph[start][i]!=0)
			Dfs(i);
}

int main()
{
#if defined (INPUT)
	int num;
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
	std::cout << std::endl;

	
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
	//std::cout << std::endl << std::endl << "BFS: " << std::endl;
	//Bfs(start);
	//std::cout << std::endl << "DFS: " << std::endl;
	//Dfs(start);

	bool f,f1;
	f = false;
	int* mas;
	mas = G.getMasColor();
	for (int i = 0; i < num; i++)
	{
		if (mas[i] == 0)
		   G.loopSearch(i,f);
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	if (f == true)
		std::cout << "YEA";
	else
		std::cout << "NO";
	std::cout << std::endl;
	std::cout << std::endl;
	G.printMasColor();

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
