#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//快速排序
//快速排序就是分治算法的一种.
//每次按住一个标准值:
//从右向左扫描比标准值小的数字, 与其交换.
//从左向右扫描比标准值大的数字, 与其交换.
void QuickSort(vector<int>&vec, int begin, int end)
{
	if (begin == end || begin > end) return;
	int i = begin;
	int j = end;
	int StaNum = vec[begin];

	while (i < j)
	{
		while (vec[j] > StaNum && i < j)//从右向左扫描
		{
			j--;
		}
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}

		while (vec[i] < StaNum && i < j)//从左向右扫描
		{
			i++;
		}
		if (i < j)
		{
			vec[j] = vec[i];
			j--;
		}
	}
	vec[i] = StaNum;//将标准值加入下表为i的位置
	//打印排序后数组
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	QuickSort(vec, begin, i - 1);
	QuickSort(vec, i + 1, end);
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

	QuickSort(vec, 0, vec.size()-1);

	system("pause");
	return 0;
}