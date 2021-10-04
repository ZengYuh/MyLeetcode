#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
//归并排序
//1.将序列的每个数字分为一组
//2.将若干个组两两合并, 保证合并后的组是有序的
//3.重复第二步操作直到只剩下一组, 排序完成
void MergeSort(int begin, int end, vector<int>temp, vector<int>&ans)
{
	if (begin >= end)
		return ;
	int l_begin = begin; 
	int l_end = (begin + end) / 2;
	int r_begin = l_end + 1;
	int r_end = end;
	
	MergeSort(l_begin, l_end, temp, ans);
	MergeSort(r_begin, r_end, temp, ans);

	while (l_begin <= l_end && r_begin <= r_end)
	{
		if (ans[l_begin] >= ans[r_begin])
		{
			temp.push_back(ans[r_begin]);
			r_begin++;
		}
		else if (ans[l_begin] < ans[r_begin])
		{
			temp.push_back(ans[l_begin]);
			l_begin++;
		}
	}
	while (l_begin <= l_end)
	{
		temp.push_back(ans[l_begin]);
		l_begin++;
	}
	while (r_begin <= r_end)
	{
		temp.push_back(ans[r_begin]);
		r_begin++;
	}

	for (int i = 0; i < temp.size(); ++i)
	{
		ans[begin + i] = temp[i];
	}

	//排序后的数组
	for (auto j : ans)
	{
		cout << j << " ";
	}
	cout << endl;
}

int main()
{
	srand((int)time(0));
	vector<int>ans;
	for (int i = 0; i < 10; ++i)
	{
		ans.push_back(rand());
	}
	vector<int>temp;
	//排序前的数组
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;

	MergeSort(0, ans.size() - 1, temp, ans);

	//排序后的数组
	for (auto j : ans)
	{
		cout << j << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}