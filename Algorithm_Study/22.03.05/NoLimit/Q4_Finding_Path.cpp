//0.01ms ~ 24.63ms

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//노드의 위치와 번호를 저장할 배열
vector<pair<vector<int>, int>> _nodeinfo;
//반환할 정답을 저장할 배열
vector<vector<int>> _answer = { {}, {} };
//_nodeinfo를 정렬할 때 사용. x값 기준 오름차순 정렬
bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
    return a.first[0] < b.first[0];
}

struct treeNode {
    int num = 0;
    treeNode* left = nullptr;
    treeNode* right = nullptr;
};
//left번째 노드부터 right번째 노드 중 y값이 최대인 노드를 반환
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
//전위순회 함수
void preorder(treeNode* node) {
    _answer[0].push_back(node->num);
    if (node->left != nullptr) preorder(node->left);
    if (node->right != nullptr) preorder(node->right);
}
//후위순회 함수
void postorder(treeNode* node) {
    if (node->left != nullptr) postorder(node->left);
    if (node->right != nullptr) postorder(node->right);
    _answer[1].push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    //노드의 위치와 번호를 _nodeinfo에 저장
    for (int i = 0; i < nodeinfo.size(); i++) {
        _nodeinfo.push_back({ nodeinfo[i], i + 1 });
    }
    //노드를 x값 기준 오름차순 정렬
    sort(_nodeinfo.begin(), _nodeinfo.end(), comp);
    int left = 0, right = nodeinfo.size() - 1;
    //이진트리를 구성
    treeNode* root = binarySearch(left, right);

    preorder(root);
    postorder(root);

    return _answer;
}