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
	ASSERT_NO_THROW();
}