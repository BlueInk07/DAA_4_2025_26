#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    struct TreeNode {
        int weight;
        TreeNode *lc, *rc;

        TreeNode(int w) {
            weight = w;
            lc = rc = nullptr;
        }
    };

    struct MinHeap {
        bool operator()(TreeNode* x, TreeNode* y) {
            return x->weight > y->weight;
        }
    };

    void buildCodes(TreeNode* node, string path, vector<string> &res) {
        if (!node) return;

        if (node->lc == nullptr && node->rc == nullptr) {
            res.push_back(path);
            return;
        }

        buildCodes(node->lc, path + "0", res);
        buildCodes(node->rc, path + "1", res);
    }

    vector<string> huffmanCodes(string S, vector<int> freq, int N) {
        priority_queue<TreeNode*, vector<TreeNode*>, MinHeap> heap;

        for (int i = 0; i < N; i++) {
            heap.push(new TreeNode(freq[i]));
        }

        while (heap.size() > 1) {
            TreeNode* a = heap.top(); heap.pop();
            TreeNode* b = heap.top(); heap.pop();

            TreeNode* parent = new TreeNode(a->weight + b->weight);
            parent->lc = a;
            parent->rc = b;

            heap.push(parent);
        }

        vector<string> result;
        buildCodes(heap.top(), "", result);
        return result;
    }
};

int main() {
    Solution sol;

    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> freq(N);
    for (int i = 0; i < N; i++) {
        cin >> freq[i];
    }

    vector<string> codes = sol.huffmanCodes(S, freq, N);

    for (auto &code : codes) {
        cout << code << " ";
    }

    cout << endl;
    return 0;
}
