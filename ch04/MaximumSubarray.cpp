#include<iostream>

using std::cout;
using std::endl;

#define SIZE 16

int max_subarray1(int []);
int max_subarray2(int []);
int max_subarray3(int []);

//分治法
int find_max_crossing_subarray(int [], int, int, int);
int find_maximum_subarray(int [], int, int);


int main()
{
    int array[SIZE] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    cout << find_maximum_subarray(array, 0, SIZE-1) << endl;

    return 0;
}

int find_max_crossing_subarray(int array[], int left, int mid, int high)
{
    int left_sum =-9999, right_sum =-9999, sum = 0;
    
    for (int i = mid; i >= left; --i) {
        sum += array[i];
        if (left_sum < sum) {
            left_sum = sum;
        }
    }
    
    sum = 0; //bug出处
    for (int i = mid+1; i <= high; ++i) {
        sum += array[i];
        if (right_sum < sum) {
            right_sum = sum;
        }
    }
    
    return left_sum + right_sum;
}

int find_maximum_subarray(int array[], int low, int high)
{
    int left_sum = 0, right_sum = 0, cross_sum = 0;
    int mid = 0;

    if (high == low) {
        return array[low];
    } else {
        mid = (low + high)/2;
        left_sum = find_maximum_subarray(array, low, mid);
        right_sum = find_maximum_subarray(array, mid+1, high);
        cross_sum = find_max_crossing_subarray(array, low, mid, high); 
        if (left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}

/**
 * 暴力求解1.0, 不简洁
 */
int max_subarray1(int array[SIZE])
{
    int max = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = i; j < SIZE; ++j) {
            int result = 0;
            //赘余
            for (int k = i; k <= j; ++k)
                result += array[k];
            if (max < result)
                max = result;
            cout << "[ " << i << ", " << j << " ] " << result << endl;
        }
    }

    return max;
}

/**
 * 暴力求解2.0, 简洁
 */
int max_subarray2(int array[])
{
    int max = 0, sum = 0;
    
    for (int i = 0; i < SIZE; ++i) {
        sum = 0;
        for (int j = i; j < SIZE; ++j) {
            sum += array[j];
            if (max < sum)
                max = sum;
        }
    } 
    
    return max;
}

/**
 * 线性时间求解
 */
int max_subarray3(int array[])
{
    int max = 0, sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += array[i];
        if (max < sum)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
}