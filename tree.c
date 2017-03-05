#include <stdio.h>
#include<stdlib.h>
#include "tree.h"
void Initiate(TreeNode **root) {
  *root = (TreeNode *)malloc(sizeof(TreeNode));
  (*root)->leftChild = NULL;
  (*root)->rightChild = NULL;
}

/* curr指针所指结点的左孩子处插入新结点，以前的左孩子变成新节点的左孩子 */
TreeNode *InsertLeftNode(TreeNode *curr, DataType x) {
  TreeNode *s, *t;
  if (curr == NULL)  // 当前指针为空，没有指向有效结点
    return NULL;
  t = curr->leftChild;
  s = (TreeNode *)malloc(sizeof(TreeNode));
  s->data = x;
  s->leftChild = t;
  s->rightChild = NULL;
  curr->leftChild = s;
  return curr->leftChild;
}

/* curr指针所指结点的右孩子处插入新结点，以前的右孩子变成新节点的右孩子 */
TreeNode *InsertRightNode(TreeNode *curr, DataType x) {
  // 在此处添加函数代码
  TreeNode *s;
  if (curr == NULL)  // 当前指针为空，没有指向有效结点
    return NULL;
  s = (TreeNode *)malloc(sizeof(TreeNode));
  s->data = x;
  s->rightChild = curr->rightChild;
  s->leftChild = NULL;
  curr->rightChild = s;
  return curr->rightChild;

}
void PrintBiTree(FILE *fp, TreeNode *bt, int n) {
  int i;
  if (bt == NULL) return;
  PrintBiTree(fp,bt->rightChild, n+1);
  for (i = 0; i < n-1; i++)
  {
      printf("   ");
      fprintf(fp,"   ");
  }
  if (n > 0) {
    printf("|||");
    fprintf(fp,"|||");
    printf("%d\n", bt->data);
    fprintf(fp,"%d\n", bt->data);
  }
  PrintBiTree(fp,bt->leftChild, n+1);
}
