#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

struct TreeNode {
    int weight;
    char ch = ' ';
    string code;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

struct Compare {
    bool operator()(TreeNode *a, TreeNode *b) {
        return a->weight > b->weight;
    }
}; // 添加分号

TreeNode* Huffman(priority_queue<TreeNode*, vector<TreeNode*>, Compare> &pq, vector<int> &precin, vector<char> &characters) {
    for (int i = 0; i < precin.size(); i++) {
        TreeNode *node = new TreeNode;
        node->weight = precin[i];
        node->ch = characters[i];
        pq.push(node);
    }
    while (pq.size() > 1) {
        TreeNode *T = new TreeNode;
        T->left = pq.top();
        pq.pop();
        T->right = pq.top();
        pq.pop();
        T->weight = T->left->weight + T->right->weight;
        pq.push(T);
    }
    return pq.top();
}

void GetCode(TreeNode *Huff, const string &code, unordered_map<char, string> &codeMap) {  
    if (Huff) {  
        if (Huff->ch != ' ') {  
            codeMap[Huff->ch] = code;  
        }  
        GetCode(Huff->left, code + '0', codeMap);  
        GetCode(Huff->right, code + '1', codeMap);  
    }  
}  

int main() {
    int k;
    cin>>k;
    while (k--) {
        int m;
        cin >> m;
        vector<int> precin(m);
        vector<char> characters(m); // 存储字符
        for (int i = 0; i < m; i++) {
            cin >> characters[i]; // 读取字符
            cin >> precin[i]; // 读取权重
        }
        string putin;
        cin.ignore();
        getline(cin, putin);
        priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;  
        TreeNode *Huff = Huffman(pq, precin, characters);  
        unordered_map<char, string> codeMap;  
        GetCode(Huff, "", codeMap);  
        int sum = 0;  
        for (char c : putin) {  
            if (codeMap.find(c) != codeMap.end()) {  
                sum += codeMap[c].length();  
            } else {  
                // 处理未在字符集中找到的字符（可选）  
                cerr << "Character " << c << " not found in Huffman tree!" << endl;  
            }  
        }  
        cout << sum << endl;  
}
}
