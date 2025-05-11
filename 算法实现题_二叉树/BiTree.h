#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

using namespace std;
typedef struct BiTNode {
	char data;
	int LTag = 0;
	int RTag = 0;
	struct BiTNode* lchild = nullptr;
	struct BiTNode* rchild = nullptr;
	struct BiTNode* parent = nullptr;
}BiTNode, * BiTree;


BiTree pre = new BiTNode;
BiTree NewT = new BiTNode;
BiTree parent = NULL;
BiTree T;
BiTree P = nullptr;
BiTree Thrt;

//创建二叉树
int CreateBiTree(BiTree& T, BiTree P,int& i,char* cs) {
	int length = strlen(cs);
	char ch = cs[i];
	i++;
	if (ch == '#') T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		T->parent = P;
		CreateBiTree(T->lchild, T,i,cs);
		CreateBiTree(T->rchild, T,i,cs);
	}
	return 0;
}

//复制树
void Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return;
	}
	else
	{
		NewT = new BiTNode;
		NewT->data = T->data;
		NewT->parent = T->parent;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}


//先序遍历
void PreOrderTraverse(BiTree T,wxString& abc ) {
	if (T) {
		abc = abc + T->data;
		PreOrderTraverse(T->lchild,abc);
		PreOrderTraverse(T->rchild,abc);
	}
}

//中序遍历
void InOrderTraverse(BiTree T,wxString& abc) {
	if (T) {
		InOrderTraverse(T->lchild,abc);
		abc = abc + T->data;
		InOrderTraverse(T->rchild,abc);
	}
}

//后序遍历
void PosOrderTraverse(BiTree T,wxString& abc) {
	if (T) {
		PosOrderTraverse(T->lchild,abc);
		PosOrderTraverse(T->rchild,abc);
		abc = abc + T->data;
	}
}

//统计叶子结点个数
int Leaf(BiTree T)
{
	int count;
	if (T == NULL)
		count = 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		count = 1;
	else
		count = Leaf(T->lchild) + Leaf(T->rchild);
	return count;
}

//以结点T为根的子树先序线索化
void PreThreading(BiTree& T)
{
	if (T)//T非空
	{
		if (!T->lchild)//左子树为空
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
		if (T->LTag == 0)
		{
			PreThreading(T->lchild);//遍历左子树
		}
		if (T->RTag == 0)
		{
			PreThreading(T->rchild);//遍历右子树
		}
	}
}

//带头节点的二叉树先序线索化
void PreOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	NewT = new BiTNode;
	Copy(T, NewT);
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = Thrt;
	if (!NewT)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = NewT;
		pre = Thrt;
		PreThreading(NewT);
		pre->rchild = Thrt;
		pre->RTag = 1;
		Thrt->rchild = pre;
	}
}

//遍历先序线索二叉树
void PreTraverse_Thr(BiTree T)
{
	BiTree p = T->lchild;
	while (p != T)
	{
		cout << p->data;
		if (p->LTag == 0)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	cout << endl;
}

//以结点T为根的子树中序线索化
void InThreading(BiTree& T)
{
	if (T)//T非空
	{
		InThreading(T->lchild);//遍历左子树
		if (!T->lchild)//左子树为空
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

//带头节点的二叉树中序线索化
void InOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	NewT = new BiTNode;
	Copy(T, NewT);
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = Thrt;
	if (!NewT)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = NewT;
		pre = Thrt;
		InThreading(NewT);
		pre->rchild = Thrt;
		pre->RTag = 1;
		Thrt->rchild = pre;
	}
}

//遍历中序线索二叉树
void InTraverse_Thr(BiTree T)
{
	BiTree p = T->lchild;//
	while (p != T)
	{
		while (p->LTag == 0)
		{
			p = p->lchild;
		}
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;
	}
	cout << endl;
}

//以结点T为根的子树后序线索化
void PosThreading(BiTree& T)
{
	if (T)//T非空
	{
		PosThreading(T->lchild);//遍历左子树
		PosThreading(T->rchild);//遍历右子树
		if (!T->lchild)//左子树为空
		{
			T->LTag = 1;
			T->lchild = pre;
		}
		else
		{
			T->LTag = 0;
		}
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = T;
		}
		else
		{
			T->RTag = 0;
		}
		pre = T;
	}
}

//带头节点的二叉树后序线索化
void PosOrderThreading(BiTree& Thrt, BiTree T)
{
	pre = new BiTNode;
	Thrt = new BiTNode;
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = T;
	if (!T)
	{
		Thrt->lchild = Thrt;
	}
	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		PosThreading(T);
	}
}

//遍历后序线索二叉树
void PosTraverse_Thr(BiTree T)
{
	BiTree root = T->lchild;//初始节点
	BiTree prev = nullptr;//记录上一个节点
	while (root)
	{
		if (root->lchild == root->rchild)//如果双亲没有左子树或者右子树
		{
			root = root->rchild;
		}
		while (root->LTag == 0 && root->lchild != prev)//找到最左边的节点
		{
			root = root->lchild;
		}
		while (root->RTag == 1)//输出并遍历节点的后继
		{
			cout << root->data;
			prev = root;//记录上一个节点
			root = root->rchild;
		}
		if (root == T->lchild)//判断是不是根节点
		{
			cout << root->data;
			return;
		}
		while (root->rchild == prev)//不是根节点，访问当前节点的双亲节点
		{
			cout << root->data;
			prev = root;
			root = root->parent;
			if (root == nullptr)//遍历到根节点，退出
			{
				return;
			}
		}
		if (root->RTag == 0)//遍历右子树
		{
			root = root->rchild;
		}
	}
	cout << endl;
}


#pragma once
