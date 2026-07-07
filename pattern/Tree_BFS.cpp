//不需要處理每一個level
vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> vec;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();              
        vec.push_back(node->val); 
        if (node->left) q.push(node->left); 
       	if (node->right) q.push(node->right); 
    }
    return vec;
}


//需要處理每一個level
vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> vec;
    while (!q.empty()) {
        // 每一個level 開始
	      for(int = q.size() - 1; i >=0; i--) {
            TreeNode *node = q.front();
            q.pop();              
            vec.push_back(node->val); 
            if (node->left) q.push(node->left); 
       	    if (node->right) q.push(node->right); 
	      }
    }
    return vec;
}
