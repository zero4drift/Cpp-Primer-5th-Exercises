// recursive widely used here.
#include <string>

using std::string;

class BinStrTree;

class TreeNode
{
private:
  string value;
  int count;
  TreeNode *left;
  TreeNode *right;
public:
  TreeNode(): count(0) {}
  TreeNode(const TreeNode &t);
  TreeNode &operator=(const TreeNode &t);
  ~TreeNode();
};

TreeNode::TreeNode(const TreeNode &t): value(t.value), count(t.count)
{
  if(t.left)
    left = new TreeNode(*t.left);
  if(t.right)
    right = new TreeNode(*t.right);
}

TreeNode &TreeNode::operator=(const TreeNode &t)
{
  auto new_left = new TreeNode(*t.left);
  auto new_right = new TreeNode(*t.right);
  delete left;
  delete right;
  left = new_left;
  right = new_right;
  value = t.value;
  count = t.count;
  return *this;
}

TreeNode::~TreeNode()
{
  delete left;
  delete right;
}

class BinStrTree
{
private:
  TreeNode *root;
public:
  BinStrTree() = default;
  BinStrTree(const BinStrTree &b): root(new TreeNode(*b.root)) {}
  BinStrTree(const TreeNode &t): root(new TreeNode(t)) {}
  BinStrTree &operator=(const BinStrTree &b);
  ~BinStrTree();
};

BinStrTree &BinStrTree::operator=(const BinStrTree &b)
{
  auto new_root = new TreeNode(*b.root);
  delete root;
  root = new_root;
  return *this;
}

BinStrTree::~BinStrTree()
{
  delete root;
}
