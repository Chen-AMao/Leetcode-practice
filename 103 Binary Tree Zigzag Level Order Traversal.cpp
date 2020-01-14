/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		
		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root,0));
		while(!q.empty()) {
			TreeNode* node = q.front().first;
			int level = q.front().second;
			q.pop();
			if (level == res.size()) res.push_back(vector<int> ());
			res[level].push_back(node->val);
			if (node->left) q.push(make_pair(node->left, level+1));
			if (node->right) q.push(make_pair(node->right, level+1));
		}
		for (int i=1; i<res.size(); i+=2) {
			reverse(res[i].begin(), res[i].end());
		}
		return res;
    }
};
