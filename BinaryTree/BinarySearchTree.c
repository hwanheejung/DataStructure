#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot)
{
    *pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode *bst)
{
    return GetData(bst);
}

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode *pNode = NULL;   // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL;   // new node

    while (cNode != NULL)
    {
        if (data == GetData(cNode))
        {
            return;
        }

        pNode = cNode;
        if (data < GetData(cNode))
        {
            cNode = GetLeftSubTree(cNode);
        }
        else
        {
            cNode = GetRightSubTree(cNode);
        }
    }
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if (pNode != NULL)
    {
        if (data < GetData(pNode))
        {
            MakeLeftSubTree(pNode, nNode);
        }
        else
        {
            MakeRightSubTree(pNode, nNode);
        }
    }
    else
    {
        *pRoot = nNode;
    }
}

// BST를 대상으로 데이터 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst; // current node
    BSTData cd;             // current data

    while (cNode != NULL)
    {
        cd = GetData(cNode);
        if (target == cd)
        {
            return cNode;
        }
        else if (target < cd)
        {
            cNode = GetLeftSubTree(cNode);
        }
        else
        {
            cNode = GetRightSubTree(cNode);
        }
    }
    return NULL;
}

// 트리에서 노드를 제거하고 제거된 노드의 주소값 반환
BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target)
{
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드;

    BTreeNode *pNode = pVRoot; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *dNode;          // delete node

    ChangeRightSubTree(pVRoot, *pRoot);
    while (cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        if (target < GetData(cNode))
        {
            cNode = GetLeftSubTree(cNode);
        }
        else
        {
            cNode = GetRightSubTree(cNode);
        }
    }
    if (cNode == NULL)
    {
        return NULL;
    }
    dNode = cNode;

    // 1. No child node
    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if (GetLeftSubTree(pNode) == dNode)
        {
            RemoveLeftSubTree(pNode);
        }
        else
        {
            RemoveRightSubTree(pNode);
        }
    }

    // 2. One child node
    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode *dcNode = NULL;

        if (GetLeftSubTree(dNode) != NULL)
        {
            dcNode = GetLeftSubTree(dNode);
        }
        else if (GetRightSubTree(dNode) != NULL)
        {
            dcNode = GetRightSubTree(dNode);
        }

        if (GetLeftSubTree(pNode) == dNode)
        {
            ChangeLeftSubTree(pNode, dcNode);
        }
        else if (GetRightSubTree(pNode) == dNode)
        {
            ChangeRightSubTree(pNode, dcNode);
        }
    }

    // 3. Two children
    else if (GetLeftSubTree(dNode) != NULL && GetRightSubTree(dNode) != NULL)
    {
        BTreeNode *mNode = GetRightSubTree(dNode); // minimum node
        BTreeNode *mpNode = dNode;
        int delData;

        while (GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        if (GetLeftSubTree(mpNode) == mNode)
        {
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }
        else
        {
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }

        dNode = mNode;
        SetData(dNode, delData);
    }
    // 삭제될 노드가 root node
    if (GetRightSubTree(pVRoot) != *pRoot)
    {
        *pRoot = GetRightSubTree(pVRoot);
    }
    free(pVRoot);
    return dNode;
}
void ShowIntData(int data)
{
    printf("%d", data);
}
// 이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode *bst)
{
    InorderTraverse(bst, ShowIntData);
}
