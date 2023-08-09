/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* ans;
TreeNode<int>* dfs(TreeNode<int>* root,int q,int p){
    if(!root)  return NULL;

    if(ans)  return NULL;

    auto l = dfs(root->left,q,p);
    auto r = dfs(root->right,q,p); 
    if(root->data==q or root->data==p){
        if(ans==NULL and (l or r)){
            ans = root;
            return NULL;
        }
        else return root; 
    }
    if(ans==NULL and l and r)  ans = root;
    return l==NULL?r:l;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	
    ans = NULL;
    dfs(root,x,y)->data;
    return ans->data;
}
