#include <iostream>
#include <vector>
using namespace std;

// 填充测试树数组，数组大小设为7以覆盖所有下标
void buildTestTree(int* tree, int n) {
    // 题目给出的树数据：1, 2, 3, 4, 5, -1, -1
    int data[] = {1, 2, 3, 4, 5, -1, -1};
    for (int i = 0; i < n; ++i) {
        tree[i] = data[i];
    }
}

// 前序遍历：根 -> 左 -> 右
void preorderTraversal(const int* tree, int n, int i) {
    // 边界处理：下标越界或为空节点
    if (i >= n || tree[i] == -1) return;

    cout << tree[i] << " "; // 访问当前节点
    preorderTraversal(tree, n, 2 * i + 1); // 递归遍历左孩子
    preorderTraversal(tree, n, 2 * i + 2); // 递归遍历右孩子
}

// 中序遍历：左 -> 根 -> 右
void inorderTraversal(const int* tree, int n, int i) {
    // 边界处理
    if (i >= n || tree[i] == -1) return;

    inorderTraversal(tree, n, 2 * i + 1); // 递归遍历左孩子
    cout << tree[i] << " "; // 访问当前节点
    inorderTraversal(tree, n, 2 * i + 2); // 递归遍历右孩子
}

// 后序遍历：左 -> 右 -> 根
void postorderTraversal(const int* tree, int n, int i) {
    // 边界处理
    if (i >= n || tree[i] == -1) return;

    postorderTraversal(tree, n, 2 * i + 1); // 递归遍历左孩子
    postorderTraversal(tree, n, 2 * i + 2); // 递归遍历右孩子
    cout << tree[i] << " "; // 访问当前节点
}

int main() {
    // 数组大小至少为7，以覆盖到最深处的空节点下标
    int n = 7;
    int tree[n];

    // 构建测试树
    buildTestTree(tree, n);

    // 执行三种遍历方式并输出结果
    cout << "前序遍历: ";
    preorderTraversal(tree, n, 0);
    cout << endl;

    cout << "中序遍历: ";
    inorderTraversal(tree, n, 0);
    cout << endl;

    cout << "后序遍历: ";
    postorderTraversal(tree, n, 0);
    cout << endl;

    return 0;
//7为n的最小安全值，为了使代码不严格依托于系统的种植条件，15为更为稳妥的值
}
