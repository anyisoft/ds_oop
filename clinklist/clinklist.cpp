// clinklist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 循环链表

#include "pch.h"
#include <iostream>

using namespace std;

struct clist {
	int data;
	struct clist *next;
};
typedef	struct clist cnode;
typedef cnode *clink;

class clinklist {
private:
	clink _head;

public:
	clinklist(int *array, int len);
	void insertnode(clink ptr, int value);
	void deletenode(clink ptr);
	void print();

	clink findnode(int value);
};

clinklist::clinklist(int *array, int len)
{
	clink	before, new_node = NULL;
	int i;

	if (NULL == array || len < 1) {
		_head = NULL;
		return;
	}

	_head = (clink)malloc(sizeof(cnode));
	if (!_head) {
		return;
	}

	_head->data = array[0];
	_head->next = NULL;
	before = _head;

	for (i = 1; i < len; i++) {
		new_node = (clink)malloc(sizeof(cnode));
		if (!new_node) {
			return;
		}

		new_node->data = array[i];
		new_node->next = NULL;

		before->next = new_node;
		before = new_node;
	}

	new_node->next = _head; // cycle link
}

void clinklist::print()
{
	clink ptr;

	ptr = _head;

	do {
		cout << "["  << ptr->data << "]";
		ptr = ptr->next;
	} while (_head != ptr && _head != _head->next);

	cout << endl;
}

void clinklist::insertnode(clink ptr, int value)
{
	clink new_node;
	clink previous;

	new_node = (clink)malloc(sizeof(cnode));
	if (!new_node) {
		return;
	}

	new_node->data = value;
	new_node->next = NULL;

	if (NULL == _head) {
		new_node->next = new_node;
		_head = new_node;
		return;
	}

	if (NULL == ptr) {
		new_node->next = _head;
		previous = _head;
		while (previous->next != _head) {
			previous = previous->next;
		}
		previous->next = new_node;
		_head = new_node;
	}
	else {
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

clink clinklist::findnode(int value)
{
	clink ptr;

	ptr = _head;
	do {
		if (ptr->data == value) {
			return ptr;
		}

		ptr = ptr->next;
	} while (_head != ptr && _head != _head->next);

	return NULL;
}

void clinklist::deletenode(clink ptr)
{
	clink previous, current;

	if (NULL == _head || NULL == ptr) {
		return;
	}

	previous = _head;

	current = _head;
	while (current && current != ptr) {
		previous = current;
		current = current->next;
	}

	if (current == ptr) {
		if (current == previous) {
			_head = NULL;
		}
		else {
			previous->next = current->next;
		}

		free(ptr);
	}
}

int main()
{
	int list[6] = { 9, 7, 3, 4, 5, 6 };

	clinklist	cll(list, 6);

	cll.print();

	cll.insertnode(NULL, 17);
	cll.print();

	clink ptr = cll.findnode(3);
	cll.insertnode(ptr, 27);
	cll.print();

	ptr = cll.findnode(6);
	cll.deletenode(ptr);
	cll.print();
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
