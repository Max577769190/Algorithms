#include<iostream>

using std::cout;
using std::endl;

#define SIZE 16

int max_subarray1(int []);
int max_subarray2(int []);


int main()
{
    int array[SIZE] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    cout << max_subarray2(array) << endl;

    return 0;
}

/**
 * 暴力求解, 不简洁
 */
int max_subarray1(int array[SIZE])
{
    int max = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = i; j < SIZE; ++j) {
            int result = 0;
            for (int k = i; k <= j; ++k) {
                result += array[k];
            }
            if (max < result) {
                max = result;
            }
            cout << "[ " << i << ", " << j << " ] " << result << endl;
        }
    }

    return max;
}

/**
 * 暴力求解2 简洁
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