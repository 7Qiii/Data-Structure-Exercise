#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// �������� start �� end ���������Ƿ���϶����������������������
bool verifySubArray(const vector<int>& arr, int start, int end) {
    if (start >= end) return true; // �������ֻ��һ��Ԫ�أ���������

    int root = arr[end]; // ���һ��Ԫ���Ǹ��ڵ�
    int i;
    // �ҵ���һ�����ڸ��ڵ��Ԫ�أ����Ԫ��������������ʼ
    for (i = start; i < end; ++i) {
        if (arr[i] > root) {
            // ���������������Ԫ���Ƿ�С�ڸ��ڵ�
            for (int j = start; j < i; ++j) {
                if (arr[j] >= root) return false;
            }
            // ���������������Ԫ���Ƿ񶼴��ڸ��ڵ�
            for (int j = i; j < end; ++j) {
                if (arr[j] <= root) return false;
            }
            break;
        }
    }
    // �ݹ�����������������
    return verifySubArray(arr, start, i - 1) && verifySubArray(arr, i, end - 1);
}

bool search(const vector<int>& arr) {
    if (arr.empty()) return false;
    // ������������Ƿ���϶����������������������
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

