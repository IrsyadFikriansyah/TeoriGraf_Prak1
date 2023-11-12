#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
   public:
    int val;
    vector<Node *> child;

    Node(int value) : val(value), child({}) {}
};

class Tree {
   public:
    Node *root;
    Tree() : root(nullptr) {}

    // Function to get every node on level n
    vector<int> getLevel(int level) {
        vector<int> result;
        if (this->root == nullptr || level < 0)
            return {};

        queue<Node *> q;
        q.push(this->root);

        int currentLevel = 0;

        while(!q.empty()){
            int numOfNodes = q.size();

            for (int i = 0; i < numOfNodes; i++){
                Node *currentNode = q.front();
                q.pop();

                if (currentLevel == level)
                    result.push_back(currentNode->val);

                for (Node *childNode : currentNode->child)
                    q.push(childNode);
            }

            // Nodes at the desired level found, stop the traversal
            if (result.size() > 0)
                break;

            currentLevel++;
        }

        return result;
    }

    // Longest Increasing Subsequence
    void lis(int n) {
        vector<int> v = getLevel(n);
        vector<int> LIS(v.size(), 1);

        for (int i = v.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i] < v[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        cout << "LIS: " << *max_element(LIS.begin(), LIS.end()) << endl;
    }

    // Longest Decreasing Subsequence
    void lds(int n) {
        vector<int> v = getLevel(n);
        vector<int> LDS(v.size(), 1);

        for (int i = v.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i] > v[j]) {
                    LDS[i] = max(LDS[i], 1 + LDS[j]);
                }
            }
        }
        cout << "LDS: " << *max_element(LDS.begin(), LDS.end()) << endl;
    }

    // Function to print the tree at level n
    void printLevel(int n) {
        vector<int> result = getLevel(n);
        cout << "len:" << result.size() << endl;
        for (int i = 0; i < result.size() - 1; i++)
            cout << result.at(i) << ", ";
        cout << result.at(result.size() - 1) << endl;
    }

    // Function to print the tree
    void printTree(Node *node, int level = 0) {
        if (node != nullptr) {
            cout << string(level * 4, ' ') << node->val << endl;
            for (Node *childNode : node->child) {
                printTree(childNode, level + 1);
            }
        }
    }
};

int main() {
    Tree mytree = Tree();
    mytree.root = new Node(0);

    mytree.root->child.push_back(new Node(4));
    mytree.root->child.push_back(new Node(1));
    mytree.root->child.push_back(new Node(13));
    mytree.root->child.push_back(new Node(7));
    mytree.root->child.push_back(new Node(0));
    mytree.root->child.push_back(new Node(2));
    mytree.root->child.push_back(new Node(8));
    mytree.root->child.push_back(new Node(11));
    mytree.root->child.push_back(new Node(3));

    mytree.root->child[0]->child.push_back(new Node(13));
    mytree.root->child[0]->child.push_back(new Node(7));
    mytree.root->child[0]->child.push_back(new Node(8));
    mytree.root->child[0]->child.push_back(new Node(11));

    mytree.root->child[1]->child.push_back(new Node(13));
    mytree.root->child[1]->child.push_back(new Node(7));
    mytree.root->child[1]->child.push_back(new Node(2));
    mytree.root->child[1]->child.push_back(new Node(8));
    mytree.root->child[1]->child.push_back(new Node(11));
    mytree.root->child[1]->child.push_back(new Node(3));

    mytree.root->child[3]->child.push_back(new Node(8));
    mytree.root->child[3]->child.push_back(new Node(11));

    mytree.root->child[4]->child.push_back(new Node(2));
    mytree.root->child[4]->child.push_back(new Node(8));
    mytree.root->child[4]->child.push_back(new Node(11));
    mytree.root->child[4]->child.push_back(new Node(3));

    mytree.root->child[5]->child.push_back(new Node(8));
    mytree.root->child[5]->child.push_back(new Node(11));
    mytree.root->child[5]->child.push_back(new Node(3));

    mytree.root->child[6]->child.push_back(new Node(11));

    mytree.root->child[0]->child[1]->child.push_back(new Node(8));
    mytree.root->child[0]->child[1]->child.push_back(new Node(11));

    mytree.root->child[0]->child[2]->child.push_back(new Node(11));

    mytree.root->child[1]->child[1]->child.push_back(new Node(8));
    mytree.root->child[1]->child[1]->child.push_back(new Node(11));

    mytree.root->child[1]->child[2]->child.push_back(new Node(8));
    mytree.root->child[1]->child[2]->child.push_back(new Node(11));
    mytree.root->child[1]->child[2]->child.push_back(new Node(3));

    mytree.root->child[1]->child[3]->child.push_back(new Node(11));

    mytree.root->child[3]->child[0]->child.push_back(new Node(11));

    mytree.root->child[4]->child[0]->child.push_back(new Node(8));
    mytree.root->child[4]->child[0]->child.push_back(new Node(11));
    mytree.root->child[4]->child[0]->child.push_back(new Node(3));

    mytree.root->child[4]->child[1]->child.push_back(new Node(11));

    mytree.root->child[5]->child[0]->child.push_back(new Node(11));

    mytree.root->child[0]->child[1]->child[0]->child.push_back(new Node(11));

    mytree.root->child[1]->child[1]->child[0]->child.push_back(new Node(11));

    mytree.root->child[1]->child[2]->child[0]->child.push_back(new Node(11));


    int level = 3;
    // Print Level
    mytree.printLevel(level);

    // LIS
    mytree.lis(level);
    
    // LDS
    mytree.lds(level);

    // mytree.printTree(mytree.root);
    return 0;
}