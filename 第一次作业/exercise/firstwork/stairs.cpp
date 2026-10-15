#include <iostream>
using namespace std;

// 计算爬到第 n 阶楼梯的方法数（用迭代实现）
long long climbStairsIter(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    long long a = 1; // f(n-2)
    long long b = 1; // f(n-1)
    long long c = 0;
    
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// 计算爬到第 n 阶楼梯的方法数（用递归实现）
long long climbStairsRecur(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return climbStairsRecur(n - 1) + climbStairsRecur(n - 2);
}

int main() {
    int n;
    cout << "请输入 n (0-40): ";
    cin >> n;
    //限定n的范围
    if (n < 0 || n > 40) {
        cout << "输入超出范围" << endl;
        return 0;
    }

    long long iterResult = climbStairsIter(n);
    long long recurResult = climbStairsRecur(n);

    cout << "迭代结果: " << iterResult << endl;
    cout << "递归结果: " << recurResult << endl;

    if (iterResult == recurResult) {
        cout << "两种方法结果一致" << endl;
    } else {
        cout << "结果不一致！" << endl;
    }

    return 0;
}
/*
总结：迭代进行的运算效率较高，不会导致发生栈溢出现象，但是代码不够直观，较为复杂
      递归进行的运算代码逻辑较为清晰，但是随着次数的增多，会出现运行内存不够的情况
      故大部分情况下，能用迭代就尽量用迭代
*/