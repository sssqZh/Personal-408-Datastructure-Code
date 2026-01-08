void PreOrder(TreeNode *root){
    if (root!=NULL){          //若根结点存在
        visit(root->data);     //访问根结点
        PreOrder(root->left);  //递归遍历左子树
        PreOrder(root->right); //递归遍历右子树
    }
}