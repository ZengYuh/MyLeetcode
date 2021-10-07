#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//��������
//����������Ƿ����㷨��һ��.
//ÿ�ΰ�סһ����׼ֵ:
//��������ɨ��ȱ�׼ֵС������, ���佻��.
//��������ɨ��ȱ�׼ֵ�������, ���佻��.
void QuickSort(vector<int>&vec, int begin, int end)
{
	if (begin == end || begin > end) return;
	int i = begin;
	int j = end;
	int StaNum = vec[begin];

	while (i < j)
	{
		while (vec[j] > StaNum && i < j)//��������ɨ��
		{
			j--;
		}
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}

		while (vec[i] < StaNum && i < j)//��������ɨ��
		{
			i++;
		}
		if (i < j)
		{
			vec[j] = vec[i];
			j--;
		}
	}
	vec[i] = StaNum;//����׼ֵ�����±�Ϊi��λ��
	//��ӡ���������
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

	//��ӡ����ǰ����
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	QuickSort(vec, 0, vec.size()-1);

	system("pause");
	return 0;
}