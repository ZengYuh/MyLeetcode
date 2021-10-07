#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//冒泡排序
//大泡下沉, 小泡上浮
//每一轮最大的元素都会排到数组的末端.
void test(vector<int>&vec, const int& height)
{
	//冒泡排序
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < height - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
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