/*
Data structure 
Linear - arrays, LL, stacks, queues
Non-Linear - tree, graph

tree - hierarchical
Root, nodes, parent node, child node
leaf node - no chold node
path
ancestor node - any predecessor node
sibling
degree - no of childrens of a node
depth of a node - no of edges from root to the node
Height of a node -  longest path from that node to leaf node
level of a tree is height of root node

no des means n-1 edges. in tree we can not have cycle

Binary tree
//each node can have max 2 nodes
max childrens at level 2 = 2^2
max nodes at height h(all nodes till height h) = 2^(h+1) -1

types of BT 
1  Full/proper/strict - each node has either 0 or 2 children
2. Complete BT - all the levels are completely filled except last level. and last level has left aligned nodes
3. perfect BT - all internal nodes excactly 2 childrens and all leaves are at same level
4. Degenrate BT - all internal nodes have only one child or left sckewed BT or tight skewed BT

*/
struct node{
	int data;
	struct node *left;
	struct node *right;
};

int main()
{
	struct node *root;
	root = create();
	teturn 0;
}

struct node *create()
{
	int x;
	printf("Enter value");
	scanf("%", &x);
	if(x == -1)
	{
		return 0;
	}
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	printf("Enter left child of %d", x)
	newnode->left = create();
	printf("Enter right child of %d", x)
	newnode->right = create();
	
	return newnode;
}


##
Binary represenattion using array
node at ith locaiton:
	left child position = (2*i) + 1
	left right position = (2*i) + 2
	Parent              = ((i-1)/2)
Representation	A B C D E F G - - H I
##

binary tree traversal

int main()
{
	
	struct node *root;
	printf("pre-order");
	preorder(root);
	printf("\n");
	printf(in-order);
	preorder(root);
}
void preorder(struct node *root)
{
	if(root == null) return;
	prinf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(root == null) return;
	inorder(root->left);
	prinf("%d ", root->data);
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(root == null) return;
	inorder(root->left);
	inorder(root->right);
	prinf("%d ", root->data)
}


Bnary Search tree



Graph

BFS - Queue
DFS - Stack















