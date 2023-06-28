class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        if(root==NULL)  return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
