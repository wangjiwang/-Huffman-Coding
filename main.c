#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define MAXBIT 10
#define MAXSIZE 100
typedef struct
{
    char elem;
    int weight,parent,lchild,rchild;
}HNode;
typedef struct
{
    char elem;
    int weight;
    int bit[MAXBIT];
    int start;
}HCode;
typedef struct
{
    char elem;
    int bit[MAXBIT];
}HCode2;
HCode2 HuffCode2[MAXSIZE/2];
void HuffTree(HNode Huff[],int n)//以数组形式创建哈夫曼数
//第一个形参是数组名 第二个形参是数组有效长度（叶子个数）
{
    int i,j,m1,m2,x1,x2;
    for(i=0; i<2*n-1; i++){//对哈夫曼数组的初始化，n个叶子结点的哈夫曼树有2n-1个结点
        Huff[i].elem = 0;
        Huff[i].weight = 0;
        Huff[i].parent = -1;
        Huff[i].lchild = -1;
        Huff[i].rchild = -1;
    }
    printf("Input 1~n value of leaf:\n");
    for(i=0; i<n; i++)//输入叶子结点的权值
        scanf(" %c%d",&Huff[i].elem,&Huff[i].weight);
    for(i=0; i<n-1; i++){
        m1 = m2 = 32767;//32767是int存储最大值，int范围-32768~32767
                        //m1 m2分别用来存储最小和次小的值
        x1 = x2 = 0;//x1 x2分别用来记录最小与次小在数组中的下标
        for(j=0; j<n+i; j++){//这个循环目的是在目前有效的叶子中（未被合并和刚合并的）找到最小和次小的叶子
            if(Huff[j].parent==-1 && Huff[j].weight<m1){
//如果新看到的值比当前记录的最小值小，则该值为最小值，原来的最小值为次小值，
//并且执行下标和值的更新
                m2 = m1;//原先最小变次小
                x2 = x1;//原先最小的下标变成次小的下标
                m1 = Huff[j].weight;//更新当前最小的值
                x1 = j;//更新当前最小值的下标
            }
            else
            if(Huff[j].parent==-1 && Huff[j].weight<m2){
//如果新看到的值比次小的小，比最小的大，则更新次小的值和下标
                m2 = Huff[j].weight;
                x2 = j;
            }
        }
        Huff[x1].parent = n+i;//n+i是当前数组有效长度的下一个，为合并后的结点
        Huff[x2].parent = n+i;//最小和次小的父亲下标就是n+i
        Huff[n+i].weight = Huff[x1].weight + Huff[x2].weight;
        Huff[n+i].lchild = x1;//合并后结点的左孩子的下标为最小值的下标
        Huff[n+i].rchild = x2;//合并后结点的右孩子的下标为次小值的下标
    }
    printf("\n\n\n\n\n              三体星人：你将看到哈夫曼树的数组形式。\n");
    system("pause");
    system("cls");
    printf("Huff weight   lchild    rchild    parent\n");
    for(i=0; i<2*n-1; i++)
        printf("%2d %4c%5d %8d%8d%8d\n",i,Huff[i].elem,Huff[i].weight,Huff[i].lchild,Huff[i].rchild,Huff[i].parent);
    putchar('\n');
    system("pause");
    system("cls");
   /* int swap;
    HNode tmp;
    for(i=0; i<2*n-2;i++){
        swap = 0;
        for(j=0; j<=2*n-2-i; j++){
            if(Huff[j].weight > Huff[j+1].weight){
                tmp= Huff[j];
                Huff[j] = Huff[j+1];
                Huff[j+1] = tmp;
                swap = 1;
            }
        }
         if(swap==0)
                break;
    }
    printf("Huff weight   lchild    rchild    parent\n");
    for(i=0; i<2*n-1; i++)
        printf("%3d %5d %10d%10d%10d\n",i,Huff[i].weight,Huff[i].lchild,Huff[i].rchild,Huff[i].parent);

*/
    /*TreeNode Node[MAXSIZE];
    for(i=0; i<2*n-1; i++){
            Node[i].data = Huff[i].weight;
            Node[i].leftChild = NULL;
            Node[i].rightChild = NULL;
    }
    TreeNode *root,*curr ,*p,*l, *r;
    Initiate(&root);
    i=2*n-2;
    //l=InsertLeftNode(root, Huff[i].weight);
    root->leftChild = &Node[i];
    for(i=2*n-2; i>n-1;i--){
        curr = &Node[i];
        if(Huff[i].lchild!=-1)
            //l=InsertLeftNode(curr, Huff[Huff[i].lchild].weight);
            //Node[i].leftChild = l;
            //curr->leftChild = l;
            curr->leftChild = &Node[Huff[i].lchild];
        if(Huff[i].rchild!=-1)
            //r=InsertRightNode(curr, Huff[Huff[i].rchild].weight);
            //Node[i].rightChild = r;
            //curr->rightChild = r;
            curr->rightChild = &Node[Huff[i].rchild];
    }
    PrintBiTree(root->leftChild, 1);
    putchar('\n');
    FILE_hfmTree( Huff, n);*/
    maketree(Huff,n);

}
void maketree(HNode Huff[],int n)
{
      FILE *fp;
      if((fp = fopen("横向树.txt","w"))== NULL)
        {
            printf("\n 文件不存在，无法打开！\n");
            getchar();//无回显地从键盘读取任意一个字符
            exit(1);
        }
    int i;
    TreeNode Node[MAXSIZE];
    for(i=0; i<2*n-1; i++){
            Node[i].data = Huff[i].weight;
            Node[i].leftChild = NULL;
            Node[i].rightChild = NULL;
    }
    TreeNode *root,*curr ,*p,*l, *r;
    Initiate(&root);
    i=2*n-2;
    //l=InsertLeftNode(root, Huff[i].weight);
    root->leftChild = &Node[i];
    for(i=2*n-2; i>n-1;i--){
        curr = &Node[i];
        if(Huff[i].lchild!=-1)
            //l=InsertLeftNode(curr, Huff[Huff[i].lchild].weight);
            //Node[i].leftChild = l;
            //curr->leftChild = l;
            curr->leftChild = &Node[Huff[i].lchild];
        if(Huff[i].rchild!=-1)
            //r=InsertRightNode(curr, Huff[Huff[i].rchild].weight);
            //Node[i].rightChild = r;
            //curr->rightChild = r;
            curr->rightChild = &Node[Huff[i].rchild];
    }
    printf("\n\n\n\n\n              三体星人：你将看到哈夫曼树的直观形式。\n");
    system("pause");
    system("cls");

    PrintBiTree(fp,root->leftChild, 1);
    char a[100][100],b[100][100];
    FILE *fp1=fopen("横向树.txt","r");
    i=0;
    int j,k,m=0;
    while (fgets(a[i],100,fp1)!=NULL)
    {
        //if (m<strlen(a[i])) m=strlen(a[i]);
        i++;
    };
    for (j=0;j<i;j++)
        puts(a[j]);
    for (k=0;k<100;k++)
    {
        for (j=0;j<100;j++)
            b[j][k]=a[k][j];
    }
    for (j=0;j<100;j++)
        puts(b[j]);
    FILE *fp2=fopen("竖向树.txt","r");
    putchar('\n');
    system("pause");
    system("cls");
    FILE_hfmTree( Huff, n);
}
void FILE_hfmTree(HNode Huff[],int n)
{
    FILE *fp;
    int i = 0;
    if((fp = fopen("hfmTree.txt","w"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }

    while(i<=2*n-2)
    {
        fputc(Huff[i].elem,fp);
        fprintf(fp,"%5d",Huff[i].weight);//写字符函数，把ch写到fp指定的文件中
        fprintf(fp,"%5d",Huff[i].lchild);
        fprintf(fp,"%5d",Huff[i].rchild);
        fprintf(fp,"%5d\n",Huff[i].parent);
        i++;
    }
    fclose(fp);
    printf("\n\n\n\n\n              三体星人：我在你电脑里已保存下哈夫曼树，你可以打开看看！。\n");
    system("pause");
    system("cls");
}
void FILE_CodeFile()
{
    HNode HuffNode[MAXSIZE];
    FILE *fp1,*fp2,*fp3;
    int i = 0,data;
    char elem;
    int weight,lchild,rchild,parent;
    for(i=0; i<MAXSIZE; i++){//对哈夫曼数组的初始化，n个叶子结点的哈夫曼树有2n-1个结点
        HuffNode[i].elem = 0;
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }

    if((fp1 = fopen("hfmTree.txt","r"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
     data = fgetc(fp1);
    while(data != EOF)
    {
        HuffNode[i].elem = fgetc(fp1);
        HuffNode[i].weight = fgetc(fp1);
        HuffNode[i].parent = fgetc(fp1);
        HuffNode[i].lchild = fgetc(fp1);
        HuffNode[i].rchild = fgetc(fp1);
        i++;
        data = fgetc(fp1);
    }

    if((fp2 = fopen("ToBeTran.txt","w"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
    if((fp3 = fopen("CodeFile.txt","w"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
}
void HuffmanCode()
{
    HNode HuffNode[MAXSIZE];
    HCode HuffCode[MAXSIZE/2],cd;//cd的作用有点像tmp，临时存放编码。
    //HCode2 HuffCode2[MAXSIZE/2];//用来直接记录哈夫曼编码
    int i,j,k,c,p,n;
    printf("Input numbers of leaf:\n");
    scanf("%d",&n);
    HuffTree(HuffNode,n);
    for(i=0; i<n; i++){
        HuffCode[i].elem = HuffNode[i].elem;
        HuffCode2[i].elem = HuffNode[i].elem;
        HuffCode[i].weight = HuffNode[i].weight;//保存叶结点权值
        cd.start = MAXBIT-1;//存放分支编码从数组cd.bit最后一个元素位置开始向前进行
        c = i;//c是叶子结点在数组HuffNode中的下标
        p = HuffNode[c].parent;//p为双亲结点的下标
        while(p!= -1)//从叶结点开始沿双亲链直到根节点，根节点的双亲值为-1
        {
            if(HuffNode[p].lchild==c)
                cd.bit[cd.start]=0;//左边为0
            else
                cd.bit[cd.start]=1;//右边为1
            cd.start--;//保存编码的位置向前进一步
            c=p;//c移至其双亲结点的下标
            p = HuffNode[c].parent;
        }
        for(j=cd.start+1; j<MAXBIT; j++)//保存该叶子结点的哈夫曼编码
            HuffCode[i].bit[j] = cd.bit[j];
        HuffCode[i].start = cd.start;//保存该编码在数组bit中的起始位置
        //因为存编码的时候从后往前，读编码的时候要从前往后
    }

    //printf("三体星人：现在，我直接给你显示每个字母所对应的编码。\n");
    //printf("HuffCode weight   bit\n");
    for(i=0; i<n; i++){
        k = 1;
        //printf("%d%4c%8d    ",i,HuffCode[i].elem,HuffCode[i].weight);
        for(j=HuffCode[i].start+1; j<MAXBIT; j++)
        {
            //printf("%d",HuffCode[i].bit[j]);
            HuffCode2[i].bit[k] = HuffCode[i].bit[j];
            HuffCode2[i].bit[0] = MAXBIT - HuffCode[i].start;
            k++;
        }
        //printf("\n");
    }
    printf("\n\n\n\n\n              三体星人：现在，我直接给你显示每个字母所对应的编码。\n");
    system("pause");
    system("cls");
    for(i=0; i<n; i++){
        printf("%c",HuffCode2[i]);
        for(j=1; j<HuffCode2[i].bit[0]; j++)
        {
            printf("%d",HuffCode2[i].bit[j]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
    FILE *fp2,*fp3,*fp4;
    char ch;
    if((fp2 = fopen("ToBeTran.txt","r"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
    if((fp3 = fopen("CodeFile.txt","w+"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
    if((fp4 = fopen("TextFile.txt","w+"))== NULL)
    {
        printf("\n 文件不存在，无法打开！\n");
        getchar();//无回显地从键盘读取任意一个字符
        exit(1);
    }
    printf("\n\n\n\n\n              三体星人：你把你想说的话写在文件ToBeTran.txt中，就能在CodeFile中看到所对应的编码，而我也能在TextFile.txt中看到你想说的。\n");
    ch = fgetc(fp2);
    while(ch != EOF)
    {
        for(i=0;i<n;i++)
        {
            if(ch == HuffCode2[i].elem)
            {
                fputc(ch,fp4);
                for(j=1; j<HuffCode2[i].bit[0]; j++)
                {
                    fprintf(fp3,"%d",HuffCode2[i].bit[j]);
                    k = 1;
                    if(k<=50){
                        printf("%d",HuffCode2[i].bit[j]);
                        k++;
                    }
                    else
                    {
                        printf("\n");
                        k = 1;
                        printf("%d",HuffCode2[i].bit[j]);
                        k++;
                    }
                }
            }
        }
        ch = fgetc(fp2);
    }
    fclose(fp3);
    fclose(fp4);


}
void story()
{
    printf("\n\n\n\n\n              这是一个以《三体》为故事背景展开的程序。叶文洁为此程序的主人公.\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              叶文洁在1971年发现太阳能量镜面增益反射效应，并首次进行了Ⅱ型文明能级的发射，但没有回音。\n");
    printf("              1979年10月21日，正在使用电脑的她接受到莫名的信息。\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              叶文洁：你真的是三体星人？\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              三体星人：&@#￥*$$##&……*\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              叶文洁：？？？\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              三体星人：抱歉，地球上的语言还不大熟练。\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              叶文洁：向我证明你没有欺骗我。\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              三体星人：没问题，为了方便交流，你先按照我的要求建立我们的语言系统！\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              三体星人：请在屏幕输入数字26，按回车后，输入以下这些信息。\n");
    printf("a64b13c22d32e103f21g15h47i57j1k5l32m20n57o63p15q1r48s51t80u23v8w18x1y16z1\n");
    printf("              三体星人：相信你数据结构学得还不错，我将用哈夫曼树来进行我们之间的对话。\n");


}

int main()
{
    //HNode a[10];
    //HuffTree(a,8);
    story();
    /*printf("请输入你想执行的情况序号：\n");
    printf("1:从终端读入字符集大小n，以及n个字符和n个权值\n");
    printf("2:利用已经制作好二叉树对文件进行编码\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            HuffmanCode();
        break;
        case 2:
        break;
    Default:printf("xiexieshiyong!");
    }*/
    HuffmanCode();


    return 0;
}
