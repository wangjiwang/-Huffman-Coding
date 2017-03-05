#include <stdio.h>
#include<stdlib.h>
#include "tree.h"
void Initiate(TreeNode **root) {
  *root = (TreeNode *)malloc(sizeof(TreeNode));
  (*root)->leftChild = NULL;
  (*root)->rightChild = NULL;
}

/* currָ����ָ�������Ӵ������½�㣬��ǰ�����ӱ���½ڵ������ */
TreeNode *InsertLeftNode(TreeNode *curr, DataType x) {
  TreeNode *s, *t;
  if (curr == NULL)  // ��ǰָ��Ϊ�գ�û��ָ����Ч���
    return NULL;
  t = curr->leftChild;
  s = (TreeNode *)malloc(sizeof(TreeNode));
  s->data = x;
  s->leftChild = t;
  s->rightChild = NULL;
  curr->leftChild = s;
  return curr->leftChild;
}

/* currָ����ָ�����Һ��Ӵ������½�㣬��ǰ���Һ��ӱ���½ڵ���Һ��� */
TreeNode *InsertRightNode(TreeNode *curr, DataType x) {
  // �ڴ˴���Ӻ�������
  TreeNode *s;
  if (curr == NULL)  // ��ǰָ��Ϊ�գ�û��ָ����Ч���
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
