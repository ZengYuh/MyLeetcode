#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
//�鲢����
//1.�����е�ÿ�����ַ�Ϊһ��
//2.�����ɸ��������ϲ�, ��֤�ϲ�������������
//3.�ظ��ڶ�������ֱ��ֻʣ��һ��, �������
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

	//����������
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
	//����ǰ������
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;

	MergeSort(0, ans.size() - 1, temp, ans);

	//����������
	for (auto j : ans)
	{
		cout << j << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}