# 二分法的原则和概述

二分查找的涉及的很多边界条件, 逻辑比较简单, 但要注意到底是 `while(left < right)` 还是 `while(left <= right)`，到底是`right == middle`呢，还是要`right == middle - 1`

所以就要坚持一种:==循环不变量==的原则, 写二分法, 区间的定义一般为两种, 左闭右闭即[left, right], 或者左闭有开即[left, right).





# LC704.二分查找

以这道题举例二分查找的两种写法

```c++
//左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right)//left = right时有意义
        {
            mid = (left+right)/2;
            //此时的mid肯定不是target了
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1; 
            }
            else 
            {
                return mid;
            }

        }
        return -1;
    }
};
```

```c++
//左闭右开
class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size();
        int mid = 0;

        while(left < right) //此时left = right已经没有意义了
        {
            mid = (left+right)/2;
            //此时nums[mid]一定不是target, 要去左区间找, 由于			   //是左闭右开, right = mid
            if(nums[mid] > target)
            {
                right = mid;
            }
            else if(nums[mid] < target)
            {
                left = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
```



下面是几道二分查找的模板题.



# LC35.搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

 

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4



暴力解法:

```c++
class Solution {
public:
    //其实只需要找到比target大或者等于的数字就可以了, 如果找不到    就返回最后一个
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= target)
            {
                cout<<i<<endl;
                break;
            }
                
        }
        return  i;
    }
};
```



二分法:

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //左闭右闭
        int left = 0; 
        int right = nums.size()-1;
        int mid = 0;
        
        while(left <= right)
        {
            mid = (left+right)/2;
            
            if(nums[mid] > target)
            {
                right = mid-1;
            }
            else if(nums[mid] < target)
            {
                left = mid+1;
            }
            else 
                return mid;
        }
        // 目标值在数组所有元素之后的情况 [left, right]，             return right + 1
        return right+1;
    }
};
```



# LC34. 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？


示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]



```c++
class Solution {
public:
    //创建一个函数专门用来查找元素
    int binarySearch(const vector<int>& vec, int& left, int& right, const int target)
    {
        int mid = 0;
        while(left <= right)
        {
            mid = (left+right)/2;
            if(target > vec[mid])
                left = mid+1;
            else if(target < vec[mid])
                right = mid-1;
            else 
                return mid;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec(2, 0);

        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        if(binarySearch(nums, left, right, target) == -1)
        {
            vec[0] = ans;
            vec[1] = ans;
            return vec;
        }
        else
        {
            ans = binarySearch(nums, left, right, target);
        }
        // cout <<"ans = "<<ans<<endl;
        // cout<<"left = "<<left<<endl;
        // cout<<"right = "<<right<<endl;
        vec[0] = ans;
        vec[1] = ans;
        
        //用二分法搜索[left, ans-1]和[ans+1, right]中与    target相等的元素
        int right2 = ans-1;
        while(binarySearch(nums, left, right2, target) != -1)
        {
            vec[0] = binarySearch(nums, left, right2, target);
            right2--;
        }

        int left2 = ans+1;
        while(binarySearch(nums, left2, right, target) != -1)
        {
            vec[1] = binarySearch(nums, left2, right, target);
            left2++;   
        }

        return vec;
    }
};
```





# LC367.有效的完全平方数

给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false



```c++
class Solution {
public:
    //本题二分法时要注意精度和0
    bool isPerfectSquare(int num) {
        if(num == 0) return 0;
        unsigned long long mid = 0;
        unsigned long long left = 1;
        unsigned long long right = num;
        while(left <= right)
        {
            mid = (right+left)/2;
            if(mid*mid > num)
                right = mid-1;
            else if(mid*mid < num)
                left = mid+1;
            else 
                return true;
        }

        return false;
    }
};
```



# LC69.Sqrt(x)

给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

 

示例 1：

输入：x = 4
输出：2
示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。



```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        unsigned long long mid = 0;
        unsigned long long left = 1;
        unsigned long long right = x;

     
        while(left <= right)
        {
            mid = (right+left)/2;
            if(mid*mid > x)
                right = mid-1;
            else if(mid*mid < x && (mid+1)*(mid+1) <= x) //易错点在于这里(mid+1)*(mid+1)<=x,通过模拟容易知道当x = 9, mid = 2时, 需要进入下一层才能得到结果          
                left = mid+1;
            else
            {
                //cout<<"mid"<<endl;
                return mid; 
            }  
        }
        return mid;
    }
};
```



