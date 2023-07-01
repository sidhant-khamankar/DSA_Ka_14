/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Codebix inorder + preorder or
    // like my solution

    // gfg solution
    // This function stores a tree in a file pointed by fp
    void serialize(Node *root, FILE *fp)
    {
        // If current node is NULL, store marker
        if (root == NULL)
        {
            fprintf(fp, "%d ", MARKER);
            return;
        }

        // Else, store current node and recur for its children
        fprintf(fp, "%d ", root->key);
        serialize(root->left, fp);
        serialize(root->right, fp);
    }

    // This function constructs a tree from a file pointed by 'fp'
    void deSerialize(Node *&root, FILE *fp)
    {
        // Read next item from file. If theere are no more items or next
        // item is marker, then return
        int val;
        if (!fscanf(fp, "%d ", &val) || val == MARKER)
            return;

        // Else create node with this item and recur for children
        root = newNode(val);
        deSerialize(root->left, fp);
        deSerialize(root->right, fp);
    }
    // My solution On time On space
    // Encodes a tree to a single string.
    // string serialize(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return "N";
    //     string ans;

    //     queue<TreeNode *> q;
    //     q.push(root);
    //     ans += to_string(root->val);
    //     ans += ',';

    //     while (q.empty() == false)
    //     {
    //         TreeNode *curr = q.front();

    //         q.pop();

    //         if (curr->left != NULL)
    //         {
    //             q.push(curr->left);
    //             ans += to_string(curr->left->val);
    //             ans += ',';
    //         }
    //         else
    //             ans += "N,";

    //         if (curr->right != NULL)
    //         {
    //             q.push(curr->right);
    //             ans += to_string(curr->right->val);
    //             ans += ',';
    //         }
    //         else
    //             ans += "N,";

    //         // cout << ans << endl;
    //     }

    //     if (ans[ans.size() - 1] == ',')
    //         ans.pop_back();

    //     // cout << ans << endl;
    //     return ans;
    // }

    // // Decodes your encoded data to tree.
    // TreeNode *deserialize(string data)
    // {

    //     stringstream ss(data);
    //     vector<string> tokens;
    //     string token;
    //     while (getline(ss, token, ','))
    //         tokens.push_back(token);

    //     if (tokens[0] == "N")
    //         return NULL;
    //     TreeNode *root = new TreeNode(stoi(tokens[0]));
    //     int i = 1;
    //     queue<TreeNode *> q;
    //     q.push(root);
    //     while (i < tokens.size() && q.empty() == false)
    //     {
    //         TreeNode *curr = q.front();
    //         q.pop();
    //         if (tokens[i] != "N")
    //         {
    //             curr->left = new TreeNode(stoi(tokens[i]));
    //             q.push(curr->left);
    //         }
    //         i++;
    //         if (i >= tokens.size())
    //             break;
    //         if (tokens[i] != "N")
    //         {
    //             curr->right = new TreeNode(stoi(tokens[i]));
    //             q.push(curr->right);
    //         }
    //         i++;
    //     }

    //     return root;
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
