#ifndef _tree_H

typedef struct TreeNode *PtrToTree;
typedef PtrToTree Tree;
typedef int ElementType;
typedef PtrToTree SearchTree;

SearchTree CreateTree();
Tree Find(ElementType X, SearchTree T);
Tree FindMaxTree(SearchTree T);
Tree FindMinTree(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
#endif // _tree_H

struct TreeNode
{
	ElementType Element;
	Tree Right;
	Tree Left;
};
