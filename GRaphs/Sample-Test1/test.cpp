#include "pch.h"
#include <vector>
#include"../GRaphs/matrixType.h"
#include"../GRaphs/crsType.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(crsType, can_create_crsType_0)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_NO_THROW();
}
TEST(crsType, can_create_crsType_1)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_EQ(mas1[1], 4);
}
TEST(crsType, can_create_crsType_2)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_EQ(mas1[4], 11);
}
TEST(crsType, can_create_crsType_3)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_EQ(mas[1], 2);
}
TEST(crsType, can_create_crsType_4)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_EQ(mas[9], 2);
}
TEST(crsType, can_create_crsType_5)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_NE(mas[0], 20);
}
TEST(crsType, can_create_crsType_6)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_NE(mas, mas1);
}
TEST(crsType, can_create_crsType_7)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_NE(mas.size(), mas1.size());
}
TEST(crsType, can_create_crsType_8)
{
	std::vector <int> mas;
	std::vector <int> mas1;
	mas.push_back(1);
	mas.push_back(2);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(3);
	mas.push_back(0);
	mas.push_back(1);
	mas.push_back(2);
	mas1.push_back(0);
	mas1.push_back(4);
	mas1.push_back(6);
	mas1.push_back(8);
	mas1.push_back(11);
	crsType G(mas, mas1);
	EXPECT_GT(mas.size(), mas1.size());
}
TEST(matrixType, can_create_matrixType_0)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 5;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1,0,1},
		{1,0,0,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	EXPECT_NO_THROW();
}
TEST(matrixType, right_getNumVert_0)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 5;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1,0,1},
		{1,0,0,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph,NUMVERTEX);
	int k = 0;
	k = G.getNumVert();
	EXPECT_EQ(k, 5);
}
TEST(matrixType, right_getNumVert_1)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 5;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1,0,1},
		{1,0,0,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	int k;
	k = G.getNumVert();
	EXPECT_NE(k, -5);
}
TEST(matrixType, right_getNumVert_2)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 5;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1,0,1},
		{1,0,0,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	matrixType G1(Graph, NUMVERTEX);
	int k, k1;
	k = G.getNumVert();
	k1 = G1.getNumVert();
	EXPECT_EQ(k, k1);
}
TEST(matrixType, right_mas_color_0)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 5;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1,0,1},
		{1,0,0,1,0},
		{1,0,0,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	int* masColor;
	masColor = G.getMasColor();
	int i = masColor[0];
	EXPECT_EQ(i, 0);
}
TEST(matrixType, right_searchloop_0)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 3;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,0},
		{0,0,1},
		{1,0,0},
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	bool f=false;
	int* masColor = G.getMasColor();
	for (int i = 0; i < G.getNumVert(); i++)
	{
		if(masColor[i]==0)
		   f = G.loopSearch(i, f);
	}
	EXPECT_EQ(f, true);
}
TEST(matrixType, right_searchloop_1)
{
	std::vector< std::vector<int> > Graph;
	const int NUMVERTEX = 3;
	int mas[NUMVERTEX][NUMVERTEX] = {
		{0,1,1},
		{1,0,0},
		{1,0,0},
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = mas[i][j];
		}
	}
	matrixType G(Graph, NUMVERTEX);
	bool f = false;
	int* masColor = G.getMasColor();
	for (int i = 1; i <= NUMVERTEX; ++i)
	{
		if (masColor[i] == 0)
			f = G.loopSearch(i, f);
	}
	EXPECT_EQ(f, true);
}



