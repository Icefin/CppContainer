/*
* problem : 길 찾기 게임 (https://programmers.co.kr/learn/courses/30/lessons/42892)
*/

//이진트리 입력 처리가 관건
//y값이 가장 큰게 root, 이하로 subtree를 구성
// 임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
// 임의의 노드 V의 오른쪽 서브 트리(right subtree)에 있는 모든 노드의 x값은 V의 x값보다 크다.
//root를 기준으로 갈라서 각자의 root를 찾을 수 있을듯

//Solving Time : 1hour

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<vector<int>, int>> _nodeinfo;
vector<vector<int>> _answer = { {}, {} };       //answer처리에 시간이 좀 할애되었다..

bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    return a.first[0] < b.first[0];
}

struct treeNode {
    int num = 0;
    treeNode* left = nullptr;
    treeNode* right = nullptr;
};

treeNode* binarySearch(int left, int right) {
    if (right < left) return nullptr;
    int ypos = -1;
    int num = 0;
    int idx = 0;
    for (int i = left; i <= right; i++) {
        if (_nodeinfo[i].first[1] > ypos) {
            ypos = _nodeinfo[i].first[1];
            num = _nodeinfo[i].second;
            idx = i;
        }
    }
    treeNode* tree = new treeNode();
    tree->num = num;
    tree->left = binarySearch(left, idx - 1);
    tree->right = binarySearch(idx + 1, right);
    return tree;
}

void preorder(treeNode* node) {
    _answer[0].push_back(node->num);
    if (node->left != nullptr) preorder(node->left);
    if (node->right != nullptr) preorder(node->right);
}

void postorder(treeNode* node) {
    if (node->left != nullptr) postorder(node->left);
    if (node->right != nullptr) postorder(node->right);
    _answer[1].push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for (int i = 0; i < nodeinfo.size(); i++) {
        _nodeinfo.push_back({ nodeinfo[i], i + 1 });
    }
    sort(_nodeinfo.begin(), _nodeinfo.end(), comp);
    int left = 0, right = nodeinfo.size() - 1;
    treeNode* root = binarySearch(left, right);

    preorder(root);
    postorder(root);

    return _answer;
}