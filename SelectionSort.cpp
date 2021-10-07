#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//选择排序
//每一轮循环找到最小的那个数, 排到最前面.
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
	//打印排序后数组
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

	//打印排序前数组
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	test(vec, nums);

	system("pause");
	return 0;
}