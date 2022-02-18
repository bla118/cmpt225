#include <iostream>
#include <vector>
#include "RedBlackTree.h"

void simpleTest(){
//IntTreeTests
	RedBlackTree<int>rb1;
	if(rb1.insert(42))
		cout<<"inserted42" << endl;
	rb1.insert(71);
	rb1.insert(13);
	NodeT<int>* r = rb1.getRoot();
	cout << "root = " << r->data << endl;
	RedBlackTree<int> rb2(rb1);
	rb2.inOrder();
	cout << endl;
	if(rb1.remove(42))
		cout<<"removed 42"<<endl;
	rb1.inOrder();
	cout << endl;
	NodeT<int>* rt = rb1.getRoot();
	cout << "root data = " << rt->data << endl;
	cout << endl;
	if(rb1.search(42))
		cout<<"found42"<<endl;
	vector<int>v1=rb1.search(50,100);
	for(int i = 0; i < v1.size(); i ++)
		cout << v1[i] <<  " " ;
	cout << endl;
	//should contain 71 
	vector<int>v2=rb1.dump();
	for(int i = 0; i < v2.size(); i ++)
		cout << v2[i] << " ";
	cout << endl;
	//should contain {42,71}
	cout<<"size="<<rb1.size()<<endl;
	//should be 2 
	NodeT<int>*pRoot=rb1.getRoot();
	cout << "root = " << pRoot->data << endl;
	cout << "root colour 1 = " << pRoot->isBlack << endl;
	//BADdesign-forourtestingonly
}

int main()
{
	RedBlackTree<int> a;
	a.insert(5);
	a.insert(4);
	a.insert(3);
	a.insert(5);
	a.insert(7);
	NodeT<int>* temp = a.getRoot();
	a.inOrder();
	cout << "size of tree 4 = " << a.size() << endl;

	cout << "root: " << temp->data << " color 1 = " << temp->isBlack << endl;
	cout << "right 0 = " << temp->right->isBlack << endl;
	cout << "left " << temp->left->data << " 0 = " << temp->left->isBlack << endl;

	RedBlackTree<int> b(a);
	NodeT<int>* cpy = b.getRoot();
	b.inOrder();
	cout << "size of copied tree 4 = " << b.size() << endl;
	cout << "copied root color 1 = " << cpy->isBlack << endl;
	cout << "color of root's children: " << endl;
	cout << "right child 0 = " << cpy->right->isBlack << endl;
	cout << "left child 0 = " << cpy->left->isBlack << endl;

	RedBlackTree<int> c;
	c.insert(32);
	c.insert(47);
	c.insert(13);
	c.insert(40);
	c.insert(37);
	c.insert(44);
	c.insert(81);



	RedBlackTree<int> t;
	for(int i =0; i < 50; i++)
  {
    t.insert(i);
    for(int j = i - 1; j < 100; j ++)
      t.insert(j);
  }
	t.insert(55);
	t.insert(20);
	t.inOrder();

	cout << endl;

	
	cout << endl;

	vector<int> r = t.dump();
	for(int i = 0; i < r.size(); i ++)
	{
		cout << r[i] << " ";
	}
	cout << endl;

	RedBlackTree<int> test(t);
	test.inOrder();
	cout << endl;

	cout << "----------------------------" << endl;

	RedBlackTree<int> del;
	del.insert(2);
	del.insert(1);
	del.insert(5);
	del.insert(6);
	del.inOrder();
	
	cout << endl;
	vector<int> search = del.search(2, 6);
	for(int i = 0; i < search.size(); i ++)
		cout << search[i] << " ";

	
	cout << endl;

	/*
	cout << "given test" << endl;
	cout << endl;
	cout << "______________________________________" << endl;

	simpleTest();
	cout << endl;

	RedBlackTree<string> a;
	a.insert("hi");
	a.insert("hello");
	a.insert("name");
	//a.insert("yes");
	a.inOrder();
	cout << endl;
	NodeT<string>* aRoot = a.getRoot();
	cout << "root = " << aRoot->data << endl;
	cout << "1 = " << aRoot->isBlack<< endl;

	cout << endl;
	RedBlackTree<string> b(a);
	b.inOrder();
	cout << endl;

	RedBlackTree<string> c;
	c = b;
	c.inOrder();
	cout << endl;

	NodeT<string>* cRoot = c.getRoot();
	cout << "root = " << cRoot->data << endl;
	cout << "root color 1 = " << cRoot->isBlack << endl;

	RedBlackTree<int> d;
	d.insert(5);
	d.insert(10);
	d.insert(15);
	d.insert(1);
	d.insert(3);

	d.inOrder();*/
}