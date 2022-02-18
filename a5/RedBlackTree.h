/* code referenced from geeksforgeeks
https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/ */

#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class NodeT
{
public:
	T data;
	NodeT* left;
	NodeT* right;
	NodeT* parent;
	bool isBlack;
	
	NodeT()
	{
		left = nullptr;
		right = nullptr;
	}

	NodeT(T key)
	{
		data = key;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		isBlack = false;
	}
	~NodeT()
	{
		delete left;
		delete right;
	}
};

template <class T>
class RedBlackTree
{
public:

	RedBlackTree();
	RedBlackTree(const RedBlackTree & tree);
	~RedBlackTree();
	RedBlackTree& operator=(const RedBlackTree & tree);
	bool insert(T key);
	bool remove(T key);
	bool search(T key) const;
	vector<T> search(T key1, T key2) const;
	vector<T> dump() const;
	int size() const;
	NodeT<T>* getRoot() const;
	
	void inOrder()
	{
		inOrder(root);
	}

private:

	NodeT<T>* root;
	int currentSize;
	void copyTree(const RedBlackTree & tree);
	void deleteTree(NodeT<T>* root);
	void rotateLeft(NodeT<T>* node);
	void rotateRight(NodeT<T>* node);
	void fixTree(NodeT<T>* node);
	void inOrder(NodeT<T>* root);
	void dumpHelper(NodeT<T>* root, vector<T> & v) const;
	NodeT<T>* successor(NodeT<T>* node);
	void fixDoubleBlack(NodeT<T>* node);
	bool redChild(NodeT<T>* node);
	void searchHelper(NodeT<T>* root, T key1, T key2, vector<T> & v) const;
	
};

/* initialize root to a nullptr with left, right and parent to nullptr and set currentSize = 0 */ 
template <class T>
RedBlackTree<T>::RedBlackTree()
{
	root = new NodeT<T>;
	root->parent = nullptr;
	root = nullptr;
	currentSize = 0;
}

/* gets tree as paramater and call copy method */
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree & tree)
{
	copyTree(tree);
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{
	/* call helper function */
	deleteTree(root);
}

template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree & tree)
{
	if(this != &tree)
	{
		deleteTree(root);
		copyTree(tree);
	}
	return *this;
}

template <class T>
/* gets a tree as paramater, set size equal to paramater's tree and values */
void RedBlackTree<T>::copyTree(const RedBlackTree & tree)
{
	currentSize = tree.size();
	root = tree.root;
	NodeT<T>* left = root->left;
	NodeT<T>* right = root->right;

	NodeT<T>* temp = new NodeT<T>(tree.root->data);

	root = temp;
	root->isBlack = true;
	root->left = left;
	root->right = right;
	
}

template <class T>
/* gets root and delete left and right pointers as well as root */
void RedBlackTree<T>::deleteTree(NodeT<T>* root)
{
	if(root == nullptr)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);

}

template <class T>
NodeT<T>* RedBlackTree<T>::getRoot() const
{
	return root;
}

template <class T>
int RedBlackTree<T>::size() const
{
	return currentSize;
}

template <class T>
void RedBlackTree<T>::inOrder(NodeT<T>* root)
{	
	if(root == nullptr)
		return;	
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

template <class T>
/* gets a key, and search left or right correspondingly */
bool RedBlackTree<T>::search(T key) const
{
	NodeT<T>* current = root;
	/* iterate while pointer is not nullptr */
	while(current != nullptr)
	{
		if(current->data == key)
			return true;
		else if(current->data > key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return false;
}

template <class T>
/* create a vector and call copy method */
vector<T> RedBlackTree<T>::dump() const
{
	vector<T> result;
	dumpHelper(root, result);
	return result;
}

template <class T>
/* using inorder traversal to push data to vector */
void RedBlackTree<T>::dumpHelper(NodeT<T>* root, vector<T> & v) const
{
	if(root == nullptr)
		return;
	dumpHelper(root->left, v);
	v.push_back(root->data);
	dumpHelper(root->right, v);
}

template <class T>
/* create vector and call helper */
vector<T> RedBlackTree<T>::search(T key1, T key2) const
{
	vector<T> result;
	searchHelper(root, key1, key2, result);
	return result;
}

template <class T>
void RedBlackTree<T>::searchHelper(NodeT<T>* root, T key1, T key2, vector<T> & v) const
{
	/* if no root simply return */
	if(root == nullptr)
		return;

	/* recurse left side */
	if(key1 < root->data)
		searchHelper(root->left, key1, key2, v);

	/* if value is between given range, push onto vector */
	if(key1 <= root->data && key2 >= root->data)
		v.push_back(root->data);

	/* recurse right side */
	if(key2 > root->data)
		searchHelper(root->right, key1, key2, v);
}

template <typename T>
/* gets node as parameter to be rotated */
void RedBlackTree<T>::rotateLeft(NodeT<T>* node)
{
	/* pointer to right child */
	NodeT<T>* temp = node->right;

	/* set right child of node to right child's left child */
	node->right = temp->left;

	/* set pointer's left child's parent to node if not nullptr */
	if(temp->left != nullptr)
		temp->left->parent = node;

	/* set node's right child to be child of node's parent */
	temp->parent = node->parent;

	/* if node is root */
	if(node->parent == nullptr)
		root = temp;

	/* if left child */
	else if(node == node->parent->left)
		node->parent->left = temp;
	
	/* if right child */
	else
		node->parent->right = temp;

	/* make node temp's left child */
	temp->left = node;
	node->parent = temp;
}

template <class T>
void RedBlackTree<T>::rotateRight(NodeT<T>* node)
{
	/* pointer to left child */
	NodeT<T>* temp = node->left;

	/* set left child of node to left child's right child */
	node->left = temp->right;

	/* set pointer's right child's parent to node if not nullptr */
	if(temp->right != nullptr)
		temp->right->parent = node;

	/* set node's left child to be child of node's parent */
	temp->parent = node->parent;

	/* if node is root */
	if(node->parent == nullptr)
		root = temp;

	/* if left child */
	else if(node == node->parent->left)
		node->parent->left = temp;
	
	/* if right child */
	else
		node->parent->right = temp;

	/* make node temp's right child */
	temp->right = node;
	node->parent = temp;
}

template <class T>
void RedBlackTree<T>::fixTree(NodeT<T>* node)
{
	NodeT<T>* temp;

	/* do the following until node is root or node's parent is black */
	while(node != root && node->parent->isBlack == false)
	{
		/* if node's parent is left child of grandparent */
		if(node->parent == node->parent->parent->left)
		{
			/* pointer to node's uncle */
			temp = node->parent->parent->right;
			/* if uncle is red */
			if(temp != nullptr && temp->isBlack == false)
			{
				/* set uncle pointer and node's parent to be red and grandparent to be red */
				temp->isBlack = true;
				node->parent->isBlack = true;
				node->parent->parent->isBlack = false;
				/* make node point to grandparent and repeat */
				node = node->parent->parent;
			}
			/* uncle is black */
			else
			{
				/* node's grandparent must be black, so arrange node and parent and rotate grandparent and fix colours */
				if(node == node->parent->right)
				{
					node = node->parent;
					rotateLeft(node);
				}
				node->parent->isBlack = true;
				node->parent->parent->isBlack = false;
				rotateRight(node->parent->parent);
			}
		}
		/* node's parent is right child */
		else
		{
			/* pointer to node's uncle */
			temp = node->parent->parent->left;
			/* if uncle is red */
			if(temp != nullptr && temp->isBlack == false)
			{
				/* set uncle pointer and node's parent to be red and grandparent to be red */
				temp->isBlack = true;
				node->parent->isBlack = true;
				node->parent->parent->isBlack = false;
				/* make node point to grandparent and repeat */
				node = node->parent->parent;
			}
			else
			{
				/* node's grandparent must be black, so arrange node and parent and rotate grandparent and fix colours */
				if(node == node->parent->left)
				{
					node = node->parent;
					rotateRight(node);
				}
				node->parent->isBlack = true;
				node->parent->parent->isBlack = false;
				rotateLeft(node->parent->parent);
			}
		}
	}
	/* set root to be black */
	root->isBlack = true;

	
}

template <class T>
bool RedBlackTree<T>::insert(T key)
{
	if(search(key) == 1)
	{
		return false;
	}

	/* new node is red */
	NodeT<T>* temp = new NodeT<T>(key);
	if(root == nullptr)
	{
		root = temp;
		root->isBlack = true;
		currentSize ++;
		return true;
	}

	
	NodeT<T>* current = root;

	/* temp pointer for parent of new node */
	
	NodeT<T>* par = nullptr;
	while(current != nullptr)
	{
		par = current;
		if(current->data > temp->data)
		{
			current = current->left;
		}
		else
			current = current->right;
	}
	temp->parent = par;
	
	
	/* determine left or right child of parent */
	if(temp->data > par->data)
	{
		par->right = temp;
	}
	else
	{
		par->left = temp;
	}
	currentSize ++;

	

	/* if no grandparent node, return true */
	if(temp->parent->parent == nullptr)
	{
		return true;
	}
		
	/* fix tree colours */
	fixTree(temp);
	return true;
}

template <class T>
/* get node as parameter and return return successor */ 
NodeT<T>* RedBlackTree<T>::successor(NodeT<T>* node)
{
	NodeT<T>* current = node->right;
	NodeT<T>* temp = nullptr;
	while(current != nullptr)
	{
		temp = current;
		current = current->left;
	}
	return temp;
}


template <class T>
bool RedBlackTree<T>::remove(T key)
{
	/* return false if value is not found */
	if(search(key) == 0)
		return false;
	
	NodeT<T>* temp = root;
	NodeT<T>* ptr = nullptr;

	/* search tree for pointer to value */
	while(temp != nullptr)
	{
		if(temp->data == key)
		{
			ptr = temp;
			break;
		}
		else if(temp->data > key)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	NodeT<T>* ss;

	if(ptr->left != nullptr && ptr->right != nullptr)
		ss = successor(ptr);

	else if(ptr->left != nullptr)
		ss = ptr->left;
	else
		ss = ptr->right;

	
	/* determines if fixing tree is required */
	bool black = ((ss == nullptr || ss->isBlack == true) && ptr->isBlack == true);

	/* get parent and sibling pointer */
	NodeT<T>* par = ptr->parent;

	NodeT<T>* sibling = nullptr;
	if(ptr->parent == nullptr)
		sibling = nullptr;
	else if(ptr->parent->left == ptr)
		sibling = ptr->parent->right;
	else
		sibling = ptr->parent->left;

	currentSize -- ;

	/* if no children */
	if(ptr->left == nullptr && ptr->right == nullptr)
	{
		if(par == root)
		{
			if(par->left == ptr)
			{
				par->left = nullptr;
			}
			else 
				par->right = nullptr;
		}
		/* not root */
		else
		{
			if(black)
				fixDoubleBlack(ptr);
			else
			{
				if(sibling != nullptr)
					sibling->isBlack = false;
			}

		}
		ptr = nullptr;
		return true;
	}

	/* if one child */
	if(ptr->left == nullptr || ptr->right == nullptr)
	{
		if(ptr == root)
		{
			if(ptr->right == nullptr)
			{
				root = ptr->left;
				root->right = nullptr;
			}
			else
			{
				root = ptr->right;
				root->left = nullptr;
			}
		}
		/* not root */
		else
		{
			if(par->left == ptr)
				par->left = ss;

			else
				par->right = ss;

			ss->parent = par;
			
			if(black)
				fixDoubleBlack(ss);

			else
				ss->isBlack = true;
		}
		return true;
	}

	/* 2 children */
	else
	{
		if(ptr == root)
		{
			ptr->data = ss->data;
			if(ss->parent == root)
				root->right = ss->right;

			else
				ss->parent->left = nullptr;
			
		}
		else
		{
			ptr->data = ss->data;
			if(ss->parent == ptr)
				ptr->right = ss->right;

			else
				ss->parent->left = nullptr;
		}

	}
	return true;

}

template <class T>
/* takes  node as parameter and returns true if it has a red child */
bool RedBlackTree<T>::redChild(NodeT<T>* node)
{
	return (node->left != nullptr && node->left->isBlack == false) || (node->right != nullptr && node->right->isBlack == false);
}


template <class T>
/* function to fix doubly black nodes */
void RedBlackTree<T>::fixDoubleBlack(NodeT<T>* node)
{
	/* return if node is the root */
	if(node->parent == nullptr)
		return;


	/* get sibling and parent pointers */
	NodeT<T>* sibling;
	NodeT<T>* par = node->parent;
	if(par == nullptr)
		sibling = nullptr;
	else if(par->left == node)
		sibling = par->right;
	else
		sibling = par->left;

	/* recurse on parent */
	if(sibling == nullptr)
		fixDoubleBlack(par);
	else
	{
		/* if sibling is red */
		if(sibling->isBlack == false)
		{
			par->isBlack = false;
			sibling->isBlack = true;
			if(sibling->parent->left == sibling)
				rotateRight(par);
			else
				rotateLeft(par);
		
			fixDoubleBlack(node);
		}
		/* if sibling is black */
		else
		{
			/* if sibling has red child */
			bool rChild = redChild(sibling);
			if(rChild)
			{
				if(sibling->left != nullptr && sibling->left->isBlack == false)
				{
					/* left left case */
					if(sibling->parent->left == sibling)
					{
						sibling->left->isBlack = sibling->isBlack;
						sibling->isBlack = par->isBlack;
						rotateRight(par);
					}
					/* right left case */
					else
					{
						sibling->left->isBlack = par->isBlack;
						rotateRight(sibling);
						rotateLeft(par);
					}
				}
				
				else
				{
					/* left right case */
					if(sibling->parent->left == sibling)
					{
						sibling->right->isBlack = par->isBlack;
						rotateLeft(sibling);
						rotateRight(par);
					}
					/* right right case */
					else
					{
						sibling->right->isBlack = sibling->isBlack;
						sibling->isBlack = par->isBlack;
						rotateLeft(par);
					}
				}
				par->isBlack = true;
			}
			/* 2 black children */
			else
			{
				sibling->isBlack = false;
				if(par->isBlack == true)
					fixDoubleBlack(par);
				else
					par->isBlack = true;
			}
		}
	}

}
