#include<stdio.h>
#include<malloc.h>
#include<process.h>

typedef struct BSTNodeStructure
{
    struct BSTNodeStructure *left;
    int data;
    struct BSTNodeStructure *right;
}BSTNode;

typedef struct 
{
	int found;
	BSTNode* parent,*self;
	int isLeftChild,isRightChild;
	int isSelfRoot;
	int totalChildOfSelf;
} SearchResult;

int insert(BSTNode **root,int data)
{
    BSTNode *nnode,*tnode;
    int inserted;
    //allocating memory for nnode
    nnode=(BSTNode*)malloc(sizeof(BSTNode));
    //check memory is allocated or not
    if(nnode==NULL)
    {
        printf("\nUnable to create new node!");
        return 0;
    }

    nnode->data=data;
    nnode->left=nnode->right=NULL;

    //check tree empty or not
    if(!(*root))
    {
        *root=nnode;
        return 1;
    }
    
    tnode=*root;
    inserted=0;
    while (!inserted)
    {
        if(nnode->data<tnode->data)
        {
            if(tnode->left==NULL)
            {
                //put new node at left child
                tnode->left=nnode;
                inserted=1;
            }
            else
            tnode=tnode->left;
        }
        else
        {
            if(tnode->right==NULL)
            {
                //put new node at right child
                tnode->right=nnode;
                inserted=1;
            }
            else
            tnode=tnode->right;
        }
    }
    return 1; 
}

void preOrder(BSTNode *root)
{
    if(root==NULL)
    return;
    printf("%d, ",root->data);
    //traverse left child in pre order
    preOrder(root->left);
    //traverse right child in pre order
    preOrder(root->right);
}

void InOrder(BSTNode *root)
{
    if(root==NULL)
    return;
    //traverse left child of root inOrder
    InOrder(root->left);
    printf("%d, ",root->data);
    //traverse right child of root inOrder
    InOrder(root->right);
}

void PostOrder(BSTNode *root)
{
    if(root==NULL)
    return;
    //traverse left child of root PostOrder
    PostOrder(root->left);
    //traverse Right child of root PostOrder
    PostOrder(root->right);
    printf("%d, ",root->data);
}

//Searching in BST(Recusive method)
int Search(BSTNode *root,int searchdata)
{
	static int i=0;
	
	if(!root)
	{
		return i;
	}
	if(root->data==searchdata)
	{
		return 1;
	}
	else if(searchdata<root->data)
	{
		//search in left sub tree
		Search(root->left,searchdata);
	}
	else
	{
		//search in right sub tree
		Search(root->right,searchdata);
		
	}
	
}

SearchResult search2(BSTNode *root,int data)
{
	SearchResult result;
	
	BSTNode *parent=root;
	while(root!=NULL)
	{
		if(data==root->data)
		{
			result.found=1;
			result.parent=parent;
			result.self=parent;
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
}

int deleteInBST(BSTNode **root,int data)
{
	SearchResult searchResult,inOrderSuccessor;
	//search the given data is available in tree or not.
	searchResult=search2(*root,data);
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
	if(inOrderSuccessor.self->left)
	{
		if(inOrderSuccessor.isLeftChild)
		inOrderSuccessor.parent->left=inOrderSuccessor.self->left;
		else
		inOrderSuccessor.parent->left=inOrderSuccessor.self->right;
	}
	else
	{
		if(inOrderSuccessor.isLeftChild)
		inOrderSuccessor.parent->right=inOrderSuccessor.self->left;
		else
		inOrderSuccessor.parent->right=inOrderSuccessor.self->right;
	}
	free(inOrderSuccessor.self);
	return 1;
	
}

int main()
{
	SearchResult searchResult;
    BSTNode *root=NULL,*node;
    int data,choice,searchdata,SearchElement;
    int found;
    
    do
    {
    	system("cls");
        printf("-------------MENU------------");
        printf("\n1.Insert Data\n2.Delete Data\n3.Print Data\n4.Search Data(Recursive)\n5.Search Data (Linear Search)\n6.Seacrh Data with child info\n0.Exit");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                /* code */
                do
                {
                    /* code */
                    printf("\nEnter Data:");
                    scanf("%d",&data);
                    if(insert(&root,data))
                    printf("\nData has inserted successfully in tree.");
                    printf("\nYou Want to Add more data(Y==1/N==0)");
                    scanf("%d",&choice);
                } while (choice==1);
                break;
            
            case 2:
                //code for deletion
                printf("\nEnter data:");
                scanf("%d",&data);
                if(deleteInBST(&root,data));
                printf("\nDelete successfully.");
                break;
            case 3:
                //Code for Print data
                system("cls");
                printf("\nPre Order= ");
                preOrder(root);
                if(root==NULL)
                printf("List is empty!");
                printf("\nIn Order= ");
                InOrder(root);
                if(root==NULL)
                printf("List is empty!");
                printf("\nPost Order= ");
                PostOrder(root);
                if(root==NULL)
                printf("List is empty!");
                break;
            case 4:
            	printf("\nEnter search Element:");
            	scanf("%d",&searchdata);
            	
            	if(root==NULL)
            	printf("\nList is Empty");
				else if(Search(root,searchdata))
				{
					printf("\ndata found");
				}
				else
				printf("\nNot Found");
				
				break;

            case 5:
            	//Searching in BST (Linear Search)
	            printf("\nEnter Search Element:");
	            scanf("%d",&SearchElement);
	            node=root;
	            found=0;
	            while (node!=NULL)
	            {
	                /* code */
	                if(SearchElement==node->data)
	                {
						printf("\nData Found");
						found=1;
	                	break;
	                }
	                else
	                if (SearchElement<node->data)
	                {
	                    /* code */
	                    node=node->left;
	                }
	                else
	                node=node->right;
	                
	            }
	            if(found==0)
	            printf("\nRecord not found");
	            break;
            case 6:
            	printf("\nEnter search Element:");
            	scanf("%d",&searchdata);
            	
            	searchResult=search2(root,searchdata);
				if(!searchResult.found)
				printf("\nNot found");
				else
				{
					printf("\n%d is available in tree.Its node's address is %u, its parent address is %u. It is the ",searchdata,searchResult.self,searchResult.parent);
					if(searchResult.isSelfRoot)
					printf("itself root.");
					else if(searchResult.isLeftChild)
					printf("left child of its parent.");
					else
					printf("right child of its parent.");
					printf(" It has ");
					if(searchResult.self->left&&searchResult.self->right)
					printf("two children.");
					else if(searchResult.self->left)
					printf("One (left) child");
					else  if(searchResult.self->right)
					printf("One (right) child");
					else
					printf("no child.");
				}
				break;
            case 0:
            exit(0);    
        }
        printf("\n\n");
        system("pause");
    } while (1);
    
}