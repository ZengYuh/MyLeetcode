#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//ð������
//�����³�, С���ϸ�
//ÿһ������Ԫ�ض����ŵ������ĩ��.
void test(vector<int>&vec, const int& height)
{
	//ð������
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