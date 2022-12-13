#include<malloc.h>
#include<stdio.h>
typedef struct BSTNodeStructure
{
	struct BSTNodeStructure *left;
	int data;
	struct BSTNodeStructure *right;
}BSTNode;
typedef struct 
{
	int found;
	BSTNode *parent,*self;
	int isLeftChild,isRightChild;
	int isSelfRoot;
	int totalChildOfSelf;
	
} SearchResult;
int isAVL(BSTNode* root,BSTNode **imBalancedNode)
{
	if(root==NULL)
	return 1;
	
	printf("\nChecking node having data %d having balance factor %d",root->data,balanceFactorOf(root));
	printf("its address is %u",root);
	if(isBalanced(root))
	{
		if(isAVL(root->left,imBalancedNode))
		{
			if( isAVL(root->right,imBalancedNode))
			return 1;
			else
			{
				*imBalancedNode=root->right;
				printf(" returning address is %u",*imBalancedNode);
				return 0;
			}
		}
		else
		{
			*imBalancedNode=root->left;
			printf(" returning address is %u",*imBalancedNode);
			return 0;
		}
	}
	else
	{
		*imBalancedNode=root;
		printf(" returning address is %u",*imBalancedNode);
		return 0;
	}
	
}

int isBalanced(BSTNode* root)
{
	int balanceFactor;
	balanceFactor=balanceFactorOf(root);
	
	return balanceFactor>=-1&&balanceFactor<=1?1:0;
}
int balanceFactorOf(BSTNode *root)
{
	int leftBalanceFactor=0,rightBalanceFactor=0;
	
	if(!root)
	return 1;
	
	// find height left sub-tree .	
	leftBalanceFactor=FindHeight(root->left);
	//find height of right sub tree.
	rightBalanceFactor=FindHeight(root->right);
	
	return (leftBalanceFactor-rightBalanceFactor);
	
}
int FindHeight(BSTNode *root)
{
	int leftChild=0,rightChild=0;
	if(!root)
	return 0;
	
	//find height of left child.
	leftChild=FindHeight(root->left);
	//findheight of right child.
	rightChild=FindHeight(root->right);
	
	//return maximum height of a tree.
	if(leftChild>rightChild)
	return leftChild+1;
	else
	return rightChild+1;
}
SearchResult search(BSTNode *root,int data)
{
	SearchResult result;
	
	BSTNode *parent=root;
	while(root!=NULL)
	{
		if(data==root->data)
		{
			result.found=1;
			result.parent=parent;
			result.self=root;
			if(root==parent)
			{
				result.isSelfRoot=1;
				result.isLeftChild=result.isRightChild=0;
			}
			else if(parent->left==root)
			{
				result.isSelfRoot=0;
				result.isLeftChild=1;
				result.isRightChild=0;
			}
			else
			{
				result.isSelfRoot=0;
				result.isLeftChild=0;
				result.isRightChild=1;
			}
			if(result.self->left&&result.self->right)
			result.totalChildOfSelf=2;
			else if(result.self->left||result.self->right)
			result.totalChildOfSelf=1;
			else
			result.totalChildOfSelf=0;
			
			return result;
		}
		parent=root;
		if(data>root->data)
			//make root root's right
			root=root->right;
		else
			//make root root's left
			root=root->left;
			
	}
	result.found=0;
	result.parent=NULL;
	result.isLeftChild=result.isRightChild=0;
	result.self=NULL;
	return result;
}
SearchResult findInOrderSuccessor(BSTNode *root)
{
	SearchResult inOrderSuccessor;
	inOrderSuccessor.parent=root;
	inOrderSuccessor.self=root->right;
	
	while(inOrderSuccessor.self->left)
	{
		inOrderSuccessor.parent=inOrderSuccessor.self;
		inOrderSuccessor.self=inOrderSuccessor.self->left;
	}
	//assign the details of node in inOrderSuccessor.
	inOrderSuccessor.isSelfRoot=0;
	inOrderSuccessor.isLeftChild=0;
	inOrderSuccessor.isRightChild=0;
	
	//check if the node is left or right child. of parent
	/*if(inOrderSuccessor.parent->left==inOrderSuccessor.self)
	inOrderSuccessor.isLeftChild=1;
	else
	inOrderSuccessor.isRightChild=1;
	*/
	if(inOrderSuccessor.parent==root)
		inOrderSuccessor.isRightChild=1;
	else
		inOrderSuccessor.isLeftChild=1;
		
    // find the total child of self
	if(inOrderSuccessor.self->right)
		inOrderSuccessor.totalChildOfSelf=1;
	else
		inOrderSuccessor.totalChildOfSelf=0;	
	
	inOrderSuccessor.found=1;
	return inOrderSuccessor;
}

int InsertData(BSTNode **root,int data)
{
	// creating new node
	BSTNode *nnode,*tnode;
	int inserted;
	//allocating memory for nnode
	nnode=(BSTNode*)malloc(sizeof(BSTNode));
	//check memory is allocated or not
	if(nnode==NULL)
	{
		printf("\nUnable to create memory!");
		return 0;
	}
	//inserting data
	nnode->data=data;
	nnode->left=nnode->right=NULL;
	//check tree is empty or not. 
	if(!(*root))
	{
		*root=nnode;
		printf("\ninserted at root");
		return 1;
	}
	
	tnode=*root;
	inserted=0;
	while(!inserted)
	{
		if(nnode->data < tnode->data)
		{
			if(tnode->left==NULL)
			{
				//insert data at left node.
				tnode->left=nnode;
				inserted=1;
			}
			else //move on left node.
			tnode=tnode->left;	
		}
		else
		{
			if(tnode->right==NULL)
			{
				//insert at right node.
				tnode->right=nnode;
				inserted=1;
			}
			else//move on right node.
			tnode=tnode->right;
		}
	}
	return 1;
}
void PreOrderDisplay(BSTNode *root)
{
	if(root==NULL)
	return;
	printf("%d, ",root->data);
	PreOrderDisplay(root->left);
	PreOrderDisplay(root->right);
}
void InOrderDisplay(BSTNode *root)
{
	if(root==NULL)
	return;
	InOrderDisplay(root->left);
	printf("%d, ",root->data);
	InOrderDisplay(root->right);
}
void PostOrderDisplay(BSTNode *root)
{
	if(root==NULL)
	return;
	PostOrderDisplay(root->left);
	PostOrderDisplay(root->right);
	printf("%d, ",root->data);
}
BSTNode* searchDataParent(BSTNode *root,int sData)
{
	BSTNode *ParentNode=root;
	while(root!=NULL)
	{
		//check data found or not.
		if(sData==root->data)
		{
			return ParentNode;
		}
		//check sData is greater that root's data or not.
		if(sData<root->data)
		{
			ParentNode=root;
			root=root->left;//if sData smaller than root's data then move on left node 
		}
		else
		{
			ParentNode=root;
			root=root->right;//if sData greater than root's data then move on left node
		}
	}
	return NULL;
}
int deleteData(BSTNode **root,int data)
{
	
	BSTNode *parentNode,*searchData=NULL,*tnode,*tnodeParent;
	parentNode=searchDataParent(*root,data);
	//for data not found.
	if(!parentNode)
	return 0;
	
	//check searched node is root or not.
	if(parentNode==(*root)&&data==(*root)->data)
	{
		if(!((*root)->left&&(*root)->right))
		{
			free(*root);
			*root=NULL;
			return 1;
		}
			
	}
	//give the address of searched data.
	if(parentNode->left)
	{
		if(parentNode->left->data==data)
		searchData=parentNode->left;
	}
	else
		searchData=parentNode->right;
	
	// for data has both child.
	if(searchData->left&&searchData->right)
	{
		tnode=searchData->right;
		tnodeParent=searchData;
		//find in order next node after searched node.
		while(tnode)
		{
			if(tnode->left)
			{
				tnodeParent=tnode;
				tnode=tnode->left;
			}
		}
		searchData->data=tnode->data;
		
		searchData=tnode;
		parentNode=tnodeParent;
	}
	
	//for data node is leaf.
	if(!(searchData->left||searchData->right))
	{
		if(parentNode->left->data==data)
		parentNode->left=NULL;
		else
		parentNode->right=NULL;
	}
	
	//for data has only one left child.
	if(searchData->left&&searchData->right==NULL)
	{
		if(parentNode->left->data==data)
		parentNode->left=searchData->left;
		else
		parentNode->right=searchData->left;
	}
	
	//for data has only one right child.
	if(searchData->right&&searchData->left==NULL)
	{
		if(parentNode->left->data==data)
		parentNode->left=searchData->right;
		else
		parentNode->right=searchData->right;
	}
	free(searchData);
	return 1;
}
int deleteInBST(BSTNode **root,int data)
{
	SearchResult searchResult,inOrderSuccessor;
	//search the given data is available in tree or not.
	searchResult=search(*root,data);
	//return if data not found.
	if(!searchResult.found)return 0;
	
	//check if node is root node having no child.
	if(searchResult.isSelfRoot&&!searchResult.totalChildOfSelf)
	{
		free(*root);
		*root=NULL;
		return 1;
	}
	
	//check if node is leaf node.
	if(!searchResult.totalChildOfSelf)
	{
		//put null in parent address part and delete node.
		if(searchResult.isLeftChild)
		searchResult.parent->left=NULL;
		else
		searchResult.parent->right=NULL;
		
		free(searchResult.self);
		return 1;
	}
	
	//check if node has only one child.
	if(searchResult.totalChildOfSelf==1)
	{
		//if the node to be deleted is root itself.
		if(searchResult.isSelfRoot)
		{
			//put the address of ots child at the palace of root address.
			/*if(serachResult.self->left)
			*root=searchResult.self->left;
			else
			*root=searchResult.self->right;*/
			
			*root=searchResult.self->left?searchResult.self->left:searchResult.self->right;
			free(searchResult.self);
			return 1;
		}
		//put the address of child in parent where node to be deleted is stored.
		
		if(searchResult.isLeftChild)
		{
			if(searchResult.self->left)
			searchResult.parent->left=searchResult.self->left;
			else
			searchResult.parent->left=searchResult.self->right;
		}
		else
		{
			if(searchResult.self->left)
			searchResult.parent->right=searchResult.self->left;
			else
			searchResult.parent->right=searchResult.self->right;
			
		}
		free(searchResult.self);
		return 1;
	}
	
	//now the node has two child.
	//find the in order successor of node to be deleted.
	inOrderSuccessor=findInOrderSuccessor(searchResult.self);
	
	//copy the value of inorder successor in node to be deleted.
	searchResult.self->data=inOrderSuccessor.self->data;
	
	//now delete in order successor node.
	//it may be leaf node or node having one child.
	// if it is leaf node then simply delete the node.
	if(!inOrderSuccessor.totalChildOfSelf)
	{
		if(inOrderSuccessor.isLeftChild)
		inOrderSuccessor.parent->left=NULL;
		else
		inOrderSuccessor.parent->right=NULL;
		
		free(inOrderSuccessor.self);
		return 1;
	}
	
	//now inorder successor has one child.
	if(inOrderSuccessor.isLeftChild)  //if(inOrderSuccessor.self->left)
	{
		if(inOrderSuccessor.self->left) //if(inOrderSuccessor.isLeftChild)
		inOrderSuccessor.parent->left=inOrderSuccessor.self->left;
		else
		inOrderSuccessor.parent->left=inOrderSuccessor.self->right;
	}
	else
	{
		if(inOrderSuccessor.self->left) //if(inOrderSuccessor.isLeftChild)
		inOrderSuccessor.parent->right=inOrderSuccessor.self->left;
		else
		inOrderSuccessor.parent->right=inOrderSuccessor.self->right;
	}
	free(inOrderSuccessor.self);
	return 1;
	
}
int searchDataRecursively(BSTNode*root,int sData)
{
	static int level=0,i=0;
	//check root is null or not
	if(root==NULL)
	return 0;
	
	//check root's data is equal or not to sData.
	if(root->data==sData)
	{
		if(!(level||i))
		i=1;
		else
		{
			i=level;
			level=0;
		}
		
		return i;
	}
	
	else if(sData<root->data)
	{
		//if sData less than root's data then move on left node.
		level++;
		searchDataRecursively(root->left,sData);		
	}
	else
	{
		//if sData greater than root's data then move on right node.
		level++;
		 searchDataRecursively(root->right,sData);
	}
	
}
int FindHeight2(BSTNode *root)
{
	static int height=0,i=1;
	if(!root)
	return height;
	
	if(root->left)
	{
		i++;
		FindHeight(root->left);
	}
	
	if(root->right)
	{
		i++;
		FindHeight(root->right);
	}
	
	if(height<i)
	height=i;
		
	i--;
	
	return height;
}
/*int searchDataRecursively(BSTNode*root,int sData)
{
	static int i=0,level=0;
	//check root is null or not
	if(root==NULL)
	return i;
	
	//check root's data is equal or not to sData.
	if(root->data==sData)
	{
		level=++i;
		i=0;
		return level;
	}
	
	else if(sData<root->data)
	{
		//if sData less than root's data then move on left node.
		i++;
		searchDataRcursively(root->left,sData);		
	}
	else
	{
		//if sData greater than root's data then move on right node.
		i++;
		 searchDataRcursively(root->right,sData);
	}
	if(i!=0)
	i=level=0;
	
	return level;
}*/
/*int searchData(BSTNode *root,int sData)
{
	int level=0;
	while(root!=NULL)
	{
		//check data found or not.
		if(sData==root->data)
		{
			level++;
			return level;
		}
		//check sData is greater that root's data or not.
		if(sData<root->data)
		root=root->left;//if sData smaller than root's data then move on left node 
		else
		root=root->right;//if sData greater than root's data then move on left node
		 
		level++;// increase the level
	}
	return 0;
}*/
/*SearchResult search(BSTNode *root,int data)
{
	SearchResult result;
	
	BSTNode *parent=root;
	while(root!=NULL)
	{
		if(data==root->data)
		{
			result.found=1;
			result.parent=parent;
			result.self=root;//1.error result.self=parent;
			if(root==parent)
			{
				result.isSelfRoot=1;
				result.isLeftChild=result.isRightChild=0;
				
			}
			else if(parent->left==root)
			{
				result.isSelfRoot=0;
				result.isLeftChild=1;
				result.isRightChild=0;
			}
			else
			{
				result.isSelfRoot=0;
				result.isLeftChild=0;
				result.isRightChild=1;
			}
			
			if(result.self->left&&result.self->right)
			result.totalChildOfSelf=2;
			else if(result.self->left||result.self->right)
			result.totalChildOfSelf=1;
			else
			result.totalChildOfSelf=0;
			
			return result;
		}
		parent=root;
		if(data>root->data)
			//make root root's right
			root=root->right;
		else
			//make root root's left
			root=root->left;
			
	}
	result.found=0;
	result.parent=NULL;
	result.isLeftChild=result.isRightChild=0;
	result.self=NULL;
	return result;
}*/
/*SearchResult findInOrderSuccessor(BSTNode *root)
{
	SearchResult inOrderSuccessor;
	inOrderSuccessor.parent=root;
	inOrderSuccessor.self=root->right;
	
	while(inOrderSuccessor.self->left)
	{
		inOrderSuccessor.parent=inOrderSuccessor.self;
		inOrderSuccessor.self=inOrderSuccessor.self->left;
	}
	//assign the deatails of node in inOrderSuccessor.
	inOrderSuccessor.isSelfRoot=0;
	inOrderSuccessor.isLeftChild=0;
	inOrderSuccessor.isRightChild=0;
	
	//check if the node is left or right child.
	if(inOrderSuccessor.parent->left==inOrderSuccessor.self)
	inOrderSuccessor.isLeftChild=1;
	else
	inOrderSuccessor.isRightChild=1;

    // find the total child of self
	if(inOrderSuccessor.isLeftChild&&inOrderSuccessor.isRightChild)
	inOrderSuccessor.totalChildOfSelf=2;
	else if(inOrderSuccessor.isLeftChild||inOrderSuccessor.isRightChild)
	inOrderSuccessor.totalChildOfSelf=1;
	else
	inOrderSuccessor.totalChildOfSelf=0;
	
	inOrderSuccessor.found=1;
	return inOrderSuccessor;
}*/

