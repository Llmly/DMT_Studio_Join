#include <iostream>

// 让 MSVC 正确识别本文件里的中文（文件本身是 UTF-8 编码）
#if defined(_MSC_VER)
#  pragma execution_character_set("utf-8")
#endif

// 交换两个整数
static void swapValue(int& a, int& b) {
	const int tmp = a;
	a = b;
	b = tmp;
}

// 冒泡排序（升序）
static void bubbleSort(int a[], int n) {
	// 外层循环：一共比较 n-1 轮
	for (int i = 0; i < n - 1; ++i) {
		bool swapped = false;  // 记录本轮有没有交换

		// 内层循环：在还没排好的前 n-1-i 个数里，两两比较相邻元素
		for (int j = 0; j + 1 < n - i; ++j) {
			// 升序要求小的在前：如果前一个比后一个大，就交换它们
			if (a[j] > a[j + 1]) {
				swapValue(a[j], a[j + 1]);
				swapped = true;
			}
		}

		// 本轮一次交换都没发生，说明已经有序，可以提前结束
		if (!swapped) {
			break;
		}

		// 打印每一轮结果，方便观察排序过程
		std::cout << "第 " << (i + 1) << " 轮后：";
		for (int k = 0; k < n; ++k) {
			std::cout << a[k] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	int a[] = { 8, 3, 6, 2, 7, 1 };
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
