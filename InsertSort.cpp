#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//��������
//��һ������ҵ���ǰһ��Ԫ��С��
//С����ǰ��, ֱ���ҵ����Լ�С��, �����.
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