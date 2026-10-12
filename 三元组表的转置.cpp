#include<bits/stdc++.h>
using namespace std;

struct Triple{
    int row;
    int col;
    int val;
};
void buildTransfer(Triple a[], int n, int t,Triple b[],int rowSize[], int start[]) {
    //初始化rowSize数组,遍历a组表的时候得到每列的元素个数
    for(int i = 0; i < t; i++) {
        int k = a[i].col;
        rowSize[k]++;
    }

    //初始化start数组,第一行的起始位置一定是0
    for(int i = 2; i <= n; i++) {
        //这一行的起始位置等于上一行的起始位置加上上一行的元素个数
        start[i] = start[i - 1] + rowSize[i - 1];
    }

    //开始转置，初始化b数组
    for(int i = 0; i < t; i++) {
        //遍历a数组得到每个元素的列，即转之后的行
        int k = a[i].col;
        //这个元素需要放的位置对应b数组
        int j = start[k];

        //映射
        b[j].col = a[i].row;
        b[j].row = a[i].col;
        b[j].val = a[i].val;

        //这一行的起始位置加一，因为放了一个元素
        start[k]++;
    }
}
int main() {
    //原矩阵的列和ab的元素个数
    int n, t;
    cin >> n >> t;
    Triple* a = new Triple[t];
    Triple* b = new Triple[t];
    int* rowSize = new int[n + 1];
    int* start = new int[n + 1];
    //全都初始化为0
    for(int i = 0; i < n + 1; i++) {
        rowSize[i] = 0;
        start[i] = 0;
    }

    for(int i = 0; i < t; i++) {
        cin >> a[i].row >> a[i].col >> a[i].val;
    }

    buildTransfer(a, n, t, b, rowSize, start);
    return 0;
}