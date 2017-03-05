#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef int DataType;
typedef int ElmType;
typedef struct treenode {
  DataType data;
  struct treenode * leftChild;
  struct treenode * rightChild;
}TreeNode;
void Initiate(TreeNode **root);
TreeNode *InsertLeftNode(TreeNode *curr, DataType x);
TreeNode *InsertRightNode(TreeNode *curr, DataType x);
void PrintBiTree(FILE *fp,TreeNode *bt, int n);
#endif // TREE_H_INCLUDED
