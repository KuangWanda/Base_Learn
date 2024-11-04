#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <queue>
#include <stack>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++二叉树
*/

class TreeNode
{
public:
    TreeNode(int val)
        : data(val), left(nullptr), right(nullptr) {}

    void GetData() // 因为data声明为私有成员变量，因此在Tree结构体中不能直接访问，需要在TreeNode中创建一个公共方法
    {
        LOG(this->data);
    }

    TreeNode *GetLeft()
    {
        return this->left;
    }

    TreeNode *GetRight()
    {
        return this->right;
    }

    void InsertLeft(int val)
    {
        if (left == nullptr)
        {
            this->left = new TreeNode(val);
        }
    }

    void InsertRight(int val)
    {
        if (right == nullptr)
        {
            this->right = new TreeNode(val);
        }
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }

private:
    int data;
    TreeNode *left;
    TreeNode *right;
};

class Tree
{
public:
    Tree(int val)
        : root(new TreeNode(val)) {}

    void InsertLeft(TreeNode *node, int val)
    {
        if (node->GetLeft())
        {
            LOG("已有左孩子");
            return;
        }
        node->InsertLeft(val);
    }

    void InsertRight(TreeNode *node, int val)
    {
        if (node->GetRight())
        {
            LOG("已有右孩子");
            return;
        }
        node->InsertRight(val);
    }

    TreeNode *GetRoot()
    {
        return root;
    }

    void PreorderTraversal_Recursion(TreeNode *node) // 递归进行先序、中序、后序遍历
    {
        if (node)
        {
            node->GetData();
            PreorderTraversal_Recursion(node->GetLeft());
            PreorderTraversal_Recursion(node->GetRight());
        }
    }

    void InorderTraversal_Recursion(TreeNode *node)
    {
        if (node == nullptr)
            return;
        PreorderTraversal_Recursion(node->GetLeft());
        node->GetData();
        PreorderTraversal_Recursion(node->GetRight());
    }

    void PostorderTraversal_Recursion(TreeNode *node)
    {
        if (node == nullptr)
            return;
        PostorderTraversal_Recursion(node->GetLeft());
        PostorderTraversal_Recursion(node->GetRight());
        node->GetData();
    }

    void PreorderTraversal() // 非递归方法遍历二叉树
    {
        if(!root)
        {
            LOG("二叉树为空，无法非递归前序遍历！");
            return;
        }
        std::stack<TreeNode*> node_s;
        TreeNode* top;
        node_s.push(root);
        while(!node_s.empty())
        {
            top = node_s.top();
            top->GetData();
            node_s.pop();
            if (top->GetRight())
                node_s.push(top->GetRight());
            if (top->GetLeft())
                node_s.push(top->GetLeft());
        }
    }

    void InorderTraversal()
    {
        std::stack<TreeNode *> node_s;
        if (!root)
        {
            LOG("二叉树为空，无法非递归中序遍历！");
            return;
        }
        TreeNode *current = root;
        while (current || !node_s.empty())
        {
            while (current)
            {
                node_s.push(current);
                current = current->GetLeft();
            }
            node_s.top()->GetData();
            current = node_s.top()->GetRight();
            node_s.pop();
        }
    }

    void PostorderTraversal()
    {
        std::stack<TreeNode *> node_s;
        if (!root)
        {
            LOG("二叉树为空，无法非递归后序遍历！");
            return;
        }
        TreeNode *current = root;
        TreeNode *last = nullptr;
        while (current || !node_s.empty())
        {
            while (current)
            {
                node_s.push(current);
                current = current->GetLeft();
            }

            current = node_s.top();

            if (!current->GetRight() || current->GetRight() == last)
            {
                current->GetData();
                node_s.pop();
                last = current;
                current = nullptr;
            }
            else
            {
                current = current->GetRight();
            }
        }
    }

    void LevelTraversal()
    {
        std::queue<TreeNode *> node_q;
        if (!root)
        {
            LOG("二叉树为空！");
            return;
        }
        node_q.push(root);
        while (node_q.size())
        {
            node_q.front()->GetData();
            if (node_q.front()->GetLeft())
                node_q.push(node_q.front()->GetLeft());

            if (node_q.front()->GetRight())
                node_q.push(node_q.front()->GetRight());

            node_q.pop();
        }
    }

    ~Tree()
    {
        delete root;
    }

private:
    TreeNode *root;
};

int main()
{
    // Tree *tree = new Tree(5);
    std::unique_ptr<Tree> tree(new Tree(5)); // 使用智能指针
    tree->InsertLeft(tree->GetRoot(), 10);
    tree->InsertRight(tree->GetRoot(), 20);
    // tree->PreorderTraversal_Recursion(tree->GetRoot());
    tree->InsertLeft(tree->GetRoot()->GetLeft(), 25);
    tree->InsertLeft(tree->GetRoot()->GetLeft()->GetLeft(), 40);
    tree->PreorderTraversal();
    // tree->LevelTraversal();
}