#include <bits/stdc++.h>
using namespace std;
//structure for the tree data structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    int largestSet;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->largestSet = 0;
    return temp;
}
int findLargestSet(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->largestSet)
        return root->largestSet;
    //if the node is a leaf node the Largest Set for that node alone is 1
    if (root->left == NULL && root->right == NULL)
    {
        root->largestSet = 1;
        return root->largestSet;
    }
    //At every step there are two choices that you can make
    //1) Including the ith node- If included then only the grandchildren of the node can be considered in the solution
    //2)Not including the ith node- The children of this node can be included in the solution
    //We take the max of both the cases to get the maximum length of the set
    int nodeExcluded = 0, nodeInculded = 0;
    nodeExcluded = findLargestSet(root->left) + findLargestSet(root->right);
    nodeInculded = 1;
    if (root->left)
        nodeInculded += (findLargestSet(root->left->left) + findLargestSet(root->left->right));
    if (root->right)
        nodeInculded += (findLargestSet(root->right->left) + findLargestSet(root->right->right));
    root->largestSet = max(nodeExcluded, nodeInculded);
    return root->largestSet;
}
int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    cout << findLargestSet(root) << '\n';
    return 0;
}