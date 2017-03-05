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
void HuffTree(HNode Huff[],int n)//��������ʽ������������
//��һ���β��������� �ڶ����β���������Ч���ȣ�Ҷ�Ӹ�����
{
    int i,j,m1,m2,x1,x2;
    for(i=0; i<2*n-1; i++){//�Թ���������ĳ�ʼ����n��Ҷ�ӽ��Ĺ���������2n-1�����
        Huff[i].elem = 0;
        Huff[i].weight = 0;
        Huff[i].parent = -1;
        Huff[i].lchild = -1;
        Huff[i].rchild = -1;
    }
    printf("Input 1~n value of leaf:\n");
    for(i=0; i<n; i++)//����Ҷ�ӽ���Ȩֵ
        scanf(" %c%d",&Huff[i].elem,&Huff[i].weight);
    for(i=0; i<n-1; i++){
        m1 = m2 = 32767;//32767��int�洢���ֵ��int��Χ-32768~32767
                        //m1 m2�ֱ������洢��С�ʹ�С��ֵ
        x1 = x2 = 0;//x1 x2�ֱ�������¼��С���С�������е��±�
        for(j=0; j<n+i; j++){//���ѭ��Ŀ������Ŀǰ��Ч��Ҷ���У�δ���ϲ��͸պϲ��ģ��ҵ���С�ʹ�С��Ҷ��
            if(Huff[j].parent==-1 && Huff[j].weight<m1){
//����¿�����ֵ�ȵ�ǰ��¼����СֵС�����ֵΪ��Сֵ��ԭ������СֵΪ��Сֵ��
//����ִ���±��ֵ�ĸ���
                m2 = m1;//ԭ����С���С
                x2 = x1;//ԭ����С���±��ɴ�С���±�
                m1 = Huff[j].weight;//���µ�ǰ��С��ֵ
                x1 = j;//���µ�ǰ��Сֵ���±�
            }
            else
            if(Huff[j].parent==-1 && Huff[j].weight<m2){
//����¿�����ֵ�ȴ�С��С������С�Ĵ�����´�С��ֵ���±�
                m2 = Huff[j].weight;
                x2 = j;
            }
        }
        Huff[x1].parent = n+i;//n+i�ǵ�ǰ������Ч���ȵ���һ����Ϊ�ϲ���Ľ��
        Huff[x2].parent = n+i;//��С�ʹ�С�ĸ����±����n+i
        Huff[n+i].weight = Huff[x1].weight + Huff[x2].weight;
        Huff[n+i].lchild = x1;//�ϲ���������ӵ��±�Ϊ��Сֵ���±�
        Huff[n+i].rchild = x2;//�ϲ�������Һ��ӵ��±�Ϊ��Сֵ���±�
    }
    printf("\n\n\n\n\n              �������ˣ��㽫��������������������ʽ��\n");
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
      if((fp = fopen("������.txt","w"))== NULL)
        {
            printf("\n �ļ������ڣ��޷��򿪣�\n");
            getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
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
    printf("\n\n\n\n\n              �������ˣ��㽫��������������ֱ����ʽ��\n");
    system("pause");
    system("cls");

    PrintBiTree(fp,root->leftChild, 1);
    char a[100][100],b[100][100];
    FILE *fp1=fopen("������.txt","r");
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
    FILE *fp2=fopen("������.txt","r");
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
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }

    while(i<=2*n-2)
    {
        fputc(Huff[i].elem,fp);
        fprintf(fp,"%5d",Huff[i].weight);//д�ַ���������chд��fpָ�����ļ���
        fprintf(fp,"%5d",Huff[i].lchild);
        fprintf(fp,"%5d",Huff[i].rchild);
        fprintf(fp,"%5d\n",Huff[i].parent);
        i++;
    }
    fclose(fp);
    printf("\n\n\n\n\n              �������ˣ�������������ѱ����¹�������������Դ򿪿�������\n");
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
    for(i=0; i<MAXSIZE; i++){//�Թ���������ĳ�ʼ����n��Ҷ�ӽ��Ĺ���������2n-1�����
        HuffNode[i].elem = 0;
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }

    if((fp1 = fopen("hfmTree.txt","r"))== NULL)
    {
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
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
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }
    if((fp3 = fopen("CodeFile.txt","w"))== NULL)
    {
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }
}
void HuffmanCode()
{
    HNode HuffNode[MAXSIZE];
    HCode HuffCode[MAXSIZE/2],cd;//cd�������е���tmp����ʱ��ű��롣
    //HCode2 HuffCode2[MAXSIZE/2];//����ֱ�Ӽ�¼����������
    int i,j,k,c,p,n;
    printf("Input numbers of leaf:\n");
    scanf("%d",&n);
    HuffTree(HuffNode,n);
    for(i=0; i<n; i++){
        HuffCode[i].elem = HuffNode[i].elem;
        HuffCode2[i].elem = HuffNode[i].elem;
        HuffCode[i].weight = HuffNode[i].weight;//����Ҷ���Ȩֵ
        cd.start = MAXBIT-1;//��ŷ�֧���������cd.bit���һ��Ԫ��λ�ÿ�ʼ��ǰ����
        c = i;//c��Ҷ�ӽ��������HuffNode�е��±�
        p = HuffNode[c].parent;//pΪ˫�׽����±�
        while(p!= -1)//��Ҷ��㿪ʼ��˫����ֱ�����ڵ㣬���ڵ��˫��ֵΪ-1
        {
            if(HuffNode[p].lchild==c)
                cd.bit[cd.start]=0;//���Ϊ0
            else
                cd.bit[cd.start]=1;//�ұ�Ϊ1
            cd.start--;//��������λ����ǰ��һ��
            c=p;//c������˫�׽����±�
            p = HuffNode[c].parent;
        }
        for(j=cd.start+1; j<MAXBIT; j++)//�����Ҷ�ӽ��Ĺ���������
            HuffCode[i].bit[j] = cd.bit[j];
        HuffCode[i].start = cd.start;//����ñ���������bit�е���ʼλ��
        //��Ϊ������ʱ��Ӻ���ǰ���������ʱ��Ҫ��ǰ����
    }

    //printf("�������ˣ����ڣ���ֱ�Ӹ�����ʾÿ����ĸ����Ӧ�ı��롣\n");
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
    printf("\n\n\n\n\n              �������ˣ����ڣ���ֱ�Ӹ�����ʾÿ����ĸ����Ӧ�ı��롣\n");
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
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }
    if((fp3 = fopen("CodeFile.txt","w+"))== NULL)
    {
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }
    if((fp4 = fopen("TextFile.txt","w+"))== NULL)
    {
        printf("\n �ļ������ڣ��޷��򿪣�\n");
        getchar();//�޻��ԵشӼ��̶�ȡ����һ���ַ�
        exit(1);
    }
    printf("\n\n\n\n\n              �������ˣ��������˵�Ļ�д���ļ�ToBeTran.txt�У�������CodeFile�п�������Ӧ�ı��룬����Ҳ����TextFile.txt�п�������˵�ġ�\n");
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
    printf("\n\n\n\n\n              ����һ���ԡ����塷Ϊ���±���չ���ĳ���Ҷ�Ľ�Ϊ�˳�������˹�.\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              Ҷ�Ľ���1971�귢��̫�������������淴��ЧӦ�����״ν����ˢ��������ܼ��ķ��䣬��û�л�����\n");
    printf("              1979��10��21�գ�����ʹ�õ��Ե������ܵ�Ī������Ϣ��\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              Ҷ�Ľࣺ��������������ˣ�\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              �������ˣ�&@#��*$$##&����*\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              Ҷ�Ľࣺ������\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              �������ˣ���Ǹ�������ϵ����Ի�����������\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              Ҷ�Ľࣺ����֤����û����ƭ�ҡ�\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              �������ˣ�û���⣬Ϊ�˷��㽻�������Ȱ����ҵ�Ҫ�������ǵ�����ϵͳ��\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n              �������ˣ�������Ļ��������26�����س�������������Щ��Ϣ��\n");
    printf("a64b13c22d32e103f21g15h47i57j1k5l32m20n57o63p15q1r48s51t80u23v8w18x1y16z1\n");
    printf("              �������ˣ����������ݽṹѧ�û������ҽ��ù�����������������֮��ĶԻ���\n");


}

int main()
{
    //HNode a[10];
    //HuffTree(a,8);
    story();
    /*printf("����������ִ�е������ţ�\n");
    printf("1:���ն˶����ַ�����Сn���Լ�n���ַ���n��Ȩֵ\n");
    printf("2:�����Ѿ������ö��������ļ����б���\n");
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
