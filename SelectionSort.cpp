#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//ѡ������
//ÿһ��ѭ���ҵ���С���Ǹ���, �ŵ���ǰ��.
void test(vector<int>&vec, const int& nums)
{
	for (int i = 0; i < nums; ++i)
	{
		for (int j = i + 1; j < nums; ++j)
		{
			if (vec[i] > vec[j])
			{
				swap(vec[i], vec[j]);
			}
		}
	}
	//��ӡ���������
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int>vec;
	srand((int)time(0));
	int nums = MyArrayNums;

	for (int i = 0; i < nums; i++)
	{
		vec.push_back(rand());
	}

	//��ӡ����ǰ����
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	test(vec, nums);

	system("pause");
	return 0;
}