#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//BubbleSort    O(n^2)
void BubbleSort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp;
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//SelectionSort   O(n^2)
void SelectionSort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        int minval = i;
        for (int j = i+1; j < length; j++) {
            if (arr[j] < arr[i])
                minval = j;
        }
        int tmp;
        tmp = arr[minval];
        arr[minval] = arr[i];
        arr[i] = tmp;
    }
}

//InsertSort  O(n^2)
void InsertSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int j;
        if (arr[i] < arr[i-1]) {
            int tmp = arr[i];
            for (j = i-1 ; j > 0 && tmp < arr[j]; j--) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = tmp;
        }
    }
}

//Quicksort
void QuickSort(int arr[], int start, int endn) {
    if (start >= endn) return;
    int i = start;
    int j = endn;

    int base = arr[start];
    while (i < j) {
        //find number smaller than base
        while (i < j && arr[j] >= base) {
            j--;
        }
        if (i < j) {
            arr[i++] = arr[j];
        }

        while (i < j && arr[i] < base) {
            i++;
        }
        if (i < j) {
            arr[j--] = arr[i];
        }
    }
    arr[i] = base;
    QuickSort(arr, start, i-1);
    QuickSort(arr, i+1, endn);
}


//MergeSort
/*
void mergearrary(int a[], int first, int mid, int last, int temp[]) {
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= m)
        temp[k++] = a[i++];
    while (j <= n)
        temp[k++] = a[j++];

    for (int i = 0; i < k; i++) {
        a[first+i] = temp[i];
    }
}


void mergesort(int a[], int first, int last, int temp[]) {
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);
        mergesort(a, mid+1, last, temp);
        mergearrary(a, first, mid, last, temp);
    }
}

void MergeSort(int arr[],int length) {
    int *p = new int[length];
    if (p == NULL)
        return;
    mergesort(arr, 0, length-1, p);
    delete[] p;
}
*/

void MergeSort(int arr[], int first, int last, int temp[]) {
    if (first >= last) return;
    int mid = (first + last)/2;
    MergeSort(arr, first, mid, temp);
    MergeSort(arr, mid+1, last, temp);


    int k = 0;
    int i = first;
    int m = mid;
    int j = mid + 1;
    int n = last;
    while (i <= m && j <= n) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= n)
        temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[first + i] = temp[i];
}

//HeapSort
void HeapAdjust(int arr[], int i, int length) {
    //调整i的位置
    //保存当前结点下标
    int maxn = i;
    //当前结点左右子节点下标
    int lchild = i*2 + 1;
    int rchild = i*2 + 2;
    if (lchild < length && arr[lchild] > arr[maxn])
        maxn = lchild;
    if (rchild < length && arr[rchild] > arr[maxn])
        maxn = rchild;

    //若i处的值比其左右子结点小，就将它和最大值进行交换
    if (maxn != i) {
        int tmp;
        tmp = arr[i];
        arr[i] = arr[maxn];
        arr[maxn] = tmp;
        HeapAdjust(arr, maxn, length);
    }
}

void HeapSort(int arr[], int length) {
    //初始化堆
    //length/2-1是二叉树中最后一个非子叶结点的序号
    for (int i = length/2 - 1; i >= 0; i--) {
        HeapAdjust(arr, i, length);
    }

    //交换栈顶元素和最后一个元素
    for (int i = length - 1 ; i >= 0; i--) {
        int tmp;
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        HeapAdjust(arr, 0, i);
    }
}



int main()
{
    int arr[] = {1, 6, 5, 7, 2, 9};
    int *p = new int[6];
    for (int i = 0; i < 6; i++)
        cout << arr[i];
    cout << "\nafter sort" << endl;
    //BubbleSort(arr, 6);
    //SelectionSort(arr, 6);
    //InsertSort(arr, 6);
    QuickSort(arr, 0, 5);
    //MergeSort(arr, 0, 5, p);
    //HeapSort(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i];
    delete[] p;
    return 0;
}
