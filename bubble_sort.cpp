// bubble_sort.cpp
// 功能：把 8 3 6 2 7 1 这六个数用「冒泡排序」从小到大排好序并输出。
// 说明：不使用 <algorithm> 里的 sort，冒泡排序的过程全部自己写，方便理解算法。
//
// 编译（MSVC）：cl /nologo /EHsc /utf-8 /std:c++17 /W4 bubble_sort.cpp
// 编译（GCC） ：g++ -std=c++17 -Wall -Wextra -o bubble_sort bubble_sort.cpp

#include <iostream>

// 交换两个整数
static void swapValue(int& a, int& b) {
    const int tmp = a;
    a = b;
    b = tmp;
}

// 冒泡排序（升序）：每一轮把「当前未排序部分的最大值」冒到后面
static void bubbleSort(int a[], int n) {
    // 外层循环：一共比较 n-1 轮
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;  // 记录本轮有没有发生交换

        // 内层循环：在还没排好的前 n-1-i 个数里，两两比较相邻元素
        for (int j = 0; j + 1 < n - i; ++j) {
            // 升序要求「小的在前」：如果前一个比后一个大，就交换它们
            if (a[j] > a[j + 1]) {
                swapValue(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // 本轮一次交换都没发生，说明已经有序，可以提前结束
        if (!swapped) {
            break;
        }

        // 打印每一轮的结果，方便观察排序过程
        std::cout << "第 " << (i + 1) << " 轮后：";
        for (int k = 0; k < n; ++k) {
            std::cout << a[k] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int a[] = {8, 3, 6, 2, 7, 1};
    const int n = static_cast<int>(sizeof(a) / sizeof(a[0]));

    std::cout << "排序前：";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    bubbleSort(a, n);  // 调用冒泡排序，从小到大

    std::cout << "排序后：";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
