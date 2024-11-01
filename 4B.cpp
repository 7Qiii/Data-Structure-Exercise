#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// 检查从索引 start 到 end 的子数组是否符合二叉搜索树后序遍历的条件
bool verifySubArray(const vector<int>& arr, int start, int end) {
    if (start >= end) return true; // 空数组或只有一个元素，满足条件

    int root = arr[end]; // 最后一个元素是根节点
    int i;
    // 找到第一个大于根节点的元素，这个元素是右子树的起始
    for (i = start; i < end; ++i) {
        if (arr[i] > root) {
            // 检查左子树的所有元素是否都小于根节点
            for (int j = start; j < i; ++j) {
                if (arr[j] >= root) return false;
            }
            // 检查右子树的所有元素是否都大于根节点
            for (int j = i; j < end; ++j) {
                if (arr[j] <= root) return false;
            }
            break;
        }
    }
    // 递归检查左子树和右子树
    return verifySubArray(arr, start, i - 1) && verifySubArray(arr, i, end - 1);
}

bool search(const vector<int>& arr) {
    if (arr.empty()) return false;
    // 检查整个数组是否符合二叉搜索树后序遍历的条件
    return verifySubArray(arr, 0, arr.size() - 1);
}

int main() {
    string input;
    getline(cin, input);
    vector<int> ans;
    istringstream iss(input);
    string value;
    while (iss >> value) {
        ans.push_back(stoi(value));
    }
    if (search(ans)) cout << "true" << endl;
    else cout << "false" << endl;
}

