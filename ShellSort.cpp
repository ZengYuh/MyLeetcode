#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//希尔排序
//将序列以固定的递减间距分组, 待每一组排序完后组成整体再排一次
//该排序算是插入排序的一种,相对O(n^2)的时间复杂度会好一点
void test(vector<int>&vec, const int& nums)
{
	int increasement = nums;
	int tips = 0;

	while (increasement >= 1)
	{
		if (tips == 1) break;
		increasement = increasement / 3 + 1;
		if (increasement == 1)
			tips = 1;

		for (int i = 0; i < increasement; ++i)
		{
			for (int j = i + increasement; j < nums; j+= increasement)
			{
				if (vec[j] < vec[j - increasement])
				{
					int temp = vec[j];
					int k = 0;
					for (k = j - increasement; k >= 0 && temp < vec[k]; k -= increasement)
					{
						vec[k + increasement] = vec[k];
					}
					vec[k + increasement] = temp;
				}
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