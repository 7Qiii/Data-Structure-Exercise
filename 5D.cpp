#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left=NULL;
    TreeNode *right=NULL;
    TreeNode(int x) :val(x),left(NULL),right(NULL) {}
};

int strToInt(string &str) {
    if( str!="-") {
        return stoi(str);
    }
}

TreeNode *buildBSt(vector<string>&pre,int &index){
    if(pre[index]=="-"){
        index++;
        return NULL;
    }
    TreeNode *node=new TreeNode(strToInt(pre[index++]));
    node->left=buildBSt(pre,index);
    node->right=buildBSt(pre,index);
    return node;
}

void inorderTraversal(TreeNode *root,vector<int>&result) {
    if(root==NULL) {
        return;
    }
    inorderTraversal(root->left,result);
    result.push_back(root->val);
    inorderTraversal(root->right,result);
}

int main() {
    string input;
    getline(cin,input);
    istringstream iss(input);
    string value;
    vector<string>ans;
    vector<int>rightans;
    while(iss>>value) {
        ans.push_back(value);
    }
    int index=0;
    TreeNode *root=buildBSt(ans,index);
    inorderTraversal(root,rightans);
    vector<int> last(rightans);
    sort(last.begin(),last.end());
    int ri1=0;
    int ri2=0;

    for(int i=0;i<rightans.size();i++) {
        for(int j=0;j<last.size();j++) {
            if(rightans[i]==last[j]&&i==j) break;
            if(rightans[i]==last[j]) {
                ri1=rightans[i];
                ri2=rightans[j];
            }   
        }
    }
    
    for(int i=0;i<ans.size();i++) {
        if(ans[i]==to_string(ri1)) 
        {
            ans[i]=to_string(ri2);
            continue;
        }
        if(ans[i]==to_string(ri2)) ans[i]=to_string(ri1);
    }

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    
    
}