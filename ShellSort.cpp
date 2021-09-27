#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#define MyArrayNums 10
using namespace std;
//ϣ������
//�������Թ̶��ĵݼ�������, ��ÿһ��������������������һ��
//���������ǲ��������һ��,���O(n^2)��ʱ�临�ӶȻ��һ��
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