#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _left, _right, _mid;
int _cnt;

struct TreeNode {
    int num = -1;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
}treeNodes[10001];

TreeNode* root = nullptr;

int postorder_traverse(TreeNode* tr) {
    int left = 0; int right = 0; int curr = tr->num;
    if (tr->left != nullptr) left = postorder_traverse(tr->left);
    if (tr->right != nullptr) right = postorder_traverse(tr->right);
    int total = left + right + curr;
    if (left + curr > _mid) {
        total -= left;
        _cnt++;
    }
    if (right + curr > _mid) {
        total -= right;
        _cnt++;
    }
    if (total > _mid) {
        int group = max(left, right);
        total -= group;
        _cnt++;
    }

    return total;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    int nodeCnt = num.size();
    _right = 100000000;
    for (int i = 0; i < nodeCnt; i++) {
        treeNodes[i].num = num[i];
        if (_left < num[i]) _left = num[i];
    }
    for (int i = 0; i < nodeCnt; i++) {
        int parent = i; int left = links[i][0]; int right = links[i][1];
        if (left != -1) {
            treeNodes[parent].left = &treeNodes[left];
            treeNodes[left].parent = &treeNodes[parent];
        }
        if (right != -1) {
            treeNodes[parent].right = &treeNodes[right];
            treeNodes[right].parent = &treeNodes[parent];
        }
    }
    for (int i = 0; i < nodeCnt; i++) {
        if (treeNodes[i].parent == nullptr) {
            root = &treeNodes[i];
            break;
        }
    }

    while (_left <= _right) {
        _mid = (_left + _right) / 2;
        _cnt = 1;

        postorder_traverse(root);

        if (_cnt <= k) {
            answer = _mid;
            _right = _mid - 1;
        }
        else if (_cnt > k) {
            _left = _mid + 1;
        }
    }
    return answer;
}


int main() {
    int ret = solution(1, { 6, 9, 7, 5 }, { {-1, -1}, {-1, -1}, {-1, 0}, {2, 1} });
    cout << ret;
}