#pragma once
#include <vector>
#include<iostream>

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