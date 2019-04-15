

//请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。


//举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

//如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

//如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。



void ordertraversal(struct TreeNode* root, int* leaf, int* count){
    if(root) {
        if(root->left == NULL && root->right == NULL) {
            leaf[*count] = root->val;
            (*count)++;
        }
        ordertraversal(root->left, leaf, count); //这里的count就不用&count，因为这里的count相当于指针了
        ordertraversal(root->right, leaf, count);
    } 
    return;
}
    
  
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaf1[100] = {0}, leaf2[100] = {0}, i = 0, j = 0, count1 = 0, count2 = 0;
    ordertraversal(root1, leaf1, &count1);  //这种一般都要传地址，count的地址，传值就会出错
    ordertraversal(root2, leaf2, &count2); 
    while(leaf1[i++] == leaf2[j++] && i < 100 && j < 100);
    if(i < 100) 
        return false;
    else 
        return true;
}
