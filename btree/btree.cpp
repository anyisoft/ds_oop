// btree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node treenode;
typedef treenode *treelink;

class binaryTree {

private:
	treelink _head;
	void inorder(treelink ptr);
	void preorder(treelink ptr);
	void postorder(treelink ptr);

public:
	binaryTree() { _head = NULL; }
	void insertNode(int d);
	void print();
	int search(int d);

};

void binaryTree::inorder(treenode *ptr)
{
	if (ptr) {
		inorder(ptr->left);
		cout << "[" << ptr->data << "]";
		inorder(ptr->right);
	}
}

void binaryTree::preorder(treenode *ptr)
{
	if (ptr) {
		cout << "[" << ptr->data << "]";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void binaryTree::postorder(treenode *ptr)
{
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << "[" << ptr->data << "]";
	}
}

void binaryTree::insertNode(int d)
{
	treelink temp = new treenode();
	treelink current;
	int inserted = 0;

	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	if (_head == NULL) {
		_head = temp;
	}
	else {
		current = _head;
		while (!inserted) {
			if (current->data > temp->data) {
				if (current->left == NULL) {
					current->left = temp;
					inserted = 1;
				}
				else {
					current = current->left;
				}
			}
			else {
				if (current->right == NULL) {
					current->right = temp;
					inserted = 1;
				}
				else {
					current = current->right;
				}
			}
		}
	}
}

int binaryTree::search(int d)
{
	treelink temp = _head;
	while (temp) {
		if (temp->data == d) {
			return 1;
		}

		if (temp->data > d) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}

	return 0;
}

void binaryTree::print()
{
	cout << "tree: ";
	//inorder(_head);
	//preorder(_head);
	postorder(_head);
	cout << endl;
}

int main()
{
	binaryTree btree;
	int i;

	int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
	for (i = 0; i < 9; i++) {
		btree.insertNode(data[i]);
	}
	btree.print();

	cout << "Please input the value for search: ";
	cin >> i;
	if (btree.search(i)) {
		cout << "Have found the node" << endl;
	}
	else {
		cout << "Have NOT found the node" << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
