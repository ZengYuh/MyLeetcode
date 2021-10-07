#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//插入排序
//第一层遍历找到比前一个元素小的
//小的往前找, 直到找到比自己小的, 便插入.
void test(vector<int>&vec, const int& nums)
{
	for (int i = 1; i < nums; ++i)
	{
		if (vec[i] < vec[i - 1])
		{
			int temp = vec[i];
			int j = 0;
			for (j = i - 1; j > 0 && temp < vec[j]; j--)
			{
				vec[j + 1] = vec[j];
			}
			vec[j] = temp;
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