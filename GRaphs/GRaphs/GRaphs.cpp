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
#include <fstream>
#include <string>
#include <utility>
#include <sstream>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <chrono>

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


int target(std::string& s) {
	if (s == "Iris_setosa") {
		return 1;
	}
	else if (s == "Iris_versicolor") {
		return 2;
	}
	else {
		return 3;
	}
}

class Iris_dataset {
public:
	float sepal_len, sepal_width, petal_len, petal_width;
	int target;
	Iris_dataset(float sepal_len, float sepal_width, float petal_len, float petal_width, int target) {
		this->sepal_len = sepal_len;
		this->sepal_width = sepal_width;
		this->petal_len = petal_len;
		this->petal_width = petal_width;
		this->target = target;
	}
	friend std::ostream& operator<< (std::ostream& out, const Iris_dataset& data);
};

std::ostream& operator<<(std::ostream& out, const Iris_dataset& data) {
	out << data.sepal_len << " " << data.sepal_width << " " << data.petal_len << " " << data.petal_width << " " << data.target << "\n";
	return out;
}

float distance(Iris_dataset p, Iris_dataset q)  // считать евклидово расстояние 
{
	float res = 0.0;
	float firstCoordinate = 0.0;
	float secondCoordinate = 0.0;
	float thirdCoordinate = 0.0;
	float forthCoordinate = 0.0;

	firstCoordinate = p.sepal_len - q.sepal_len;
	secondCoordinate = p.sepal_width - q.sepal_width;
	thirdCoordinate = p.petal_len - q.petal_len;
	forthCoordinate = p.petal_width - q.petal_width;
	res = sqrtf(firstCoordinate * firstCoordinate + secondCoordinate * secondCoordinate + thirdCoordinate * thirdCoordinate + forthCoordinate * forthCoordinate);
	return res;
}

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

	pairType G(4);
	G.printPair();
	std::cout << std::endl;
	G.Kruskal();
	std::cout << std::endl;

	/*G.Prima();
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
	std::cout << std::endl << std::endl;*/
	
	G.Prima();
	std::cout << std::endl << std::endl;
	std::vector< std::vector <std::pair <int, double> > > minOstov;
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
	std::cout << std::endl << std::endl;
		std::cout << "TEST CLUSTERING: " << std::endl << std::endl;
	clusteringg(G, 2);
	//int n = G.numComponents(0, 7); //incoorect!	//нужен фикс подсчета компонент связности!!!!
	//std::cout << std::endl << std::endl;
	//std::cout << n;


	system("cls");

	pairType DT(3, true);
	DT.printPair();
	std::cout << std::endl << std::endl;
	DT.add_edge(0, 1, 7);
	DT.add_edge(2, 2, 17.7);
	DT.printPair();

	system("cls");

	std::ifstream myfile("C:\\Users\\user\\Desktop\\iris.data");
	std::vector <Iris_dataset> iris;
	if (myfile.is_open()) {
		std::cout << "The file is open" << "\n";
		std::string str;
		while (std::getline(myfile, str)) {
			std::replace(str.begin(), str.end(), ',', ' ');
			std::replace(str.begin(), str.end(), '-', '_');
			std::istringstream ss(str);
			float sepal_len, sepal_width, petal_len, petal_width;
			std::string temp;
			ss >> sepal_len >> sepal_width >> petal_len >> petal_width >> temp;
			Iris_dataset x(sepal_len, sepal_width, petal_len, petal_width, target(temp));
			iris.push_back(x);
		}
		int n = (int)iris.size();
		pairType GI(n, true);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					GI.add_edge(i, j, distance(iris[i], iris[j]));
				}
			}
		}
		
		std::cout << std::endl;
		GI.Kruskal();
		clusteringg(GI, 3);
		//GI.printMinOstov();
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
