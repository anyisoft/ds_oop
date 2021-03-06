// dlinklist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// doubly linked lists

#include "pch.h"
#include <iostream>

struct dlist {
	int data;
	struct dlist *front;
	struct dlist *back;
};
typedef struct dlist dnode;
typedef dnode *dlink;

class dlinklist {
private:
	dlink _head;
	dlink _cur;

public:
	dlinklist(int *array, int len);
	void print();

	dlink findnode(int value);
	dlink forward();
	dlink back();
	void insertnode(dlink ptr, int value);
	void deletenode(dlink ptr);
};

dlinklist::dlinklist(int *array, int len)
{
	dlink	before;
	dlink	new_node;

	int i;

	if (NULL == array || len < 1) {
		_head = NULL;
		_cur = NULL;
		return;
	}

	_head = (dlink)malloc(sizeof(dnode));
	if (!_head) {
		_cur = NULL;
		return;
	}

	_head->data = array[0];
	_head->front = NULL;
	_head->back = NULL;
	_cur = _head;

	before = _head;

	for (i = 1; i < len; i++) {
		new_node = (dlink)malloc(sizeof(dnode));
		if (!new_node) {
			return ;
		}

		new_node->data = array[i];
		new_node->front = NULL;
		new_node->back = before;
		before->front = new_node;
		before = new_node;
	}
}

void dlinklist::print()
{
	dlink ptr = _head;

	while (ptr != NULL) {
		if (ptr == _cur) {
			printf("#%d#", ptr->data);
		}
		else {
			printf("[%d]", ptr->data);
		}

		ptr = ptr->front;
	}

	printf("\n");
}

dlink dlinklist::findnode(int value)
{
	dlink ptr;

	ptr = _head;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return ptr;
		}

		ptr = ptr->front;
	}

	return NULL;
}

dlink dlinklist::forward()
{
	if (_cur->front) {
		_cur = _cur->front;
	}

	return _cur;
}

dlink dlinklist::back()
{
	if (_cur->back) {
		_cur = _cur->back;
	}

	return _cur;
}

void dlinklist::insertnode(dlink ptr, int value)
{
	dlink new_node;

	new_node = (dlink)malloc(sizeof(dnode));
	if (!new_node) {
		return ;
	}
	new_node->data = value;
	new_node->front = NULL;
	new_node->back = NULL;

	if (NULL == _head) {
		_head = new_node;
		_cur = _head;
		return;
	}

	if (NULL == ptr) {
		new_node->front = _head;
		_head->back = new_node;
		_head = new_node;
		_cur = _head;
	}
	else {
		if (NULL == ptr->front) {
			ptr->front = new_node;
			new_node->back = ptr;
		}
		else {
			ptr->front->back = new_node;
			new_node->front = ptr->front;
			new_node->back = ptr;
			ptr->front = new_node;
		}
	}
}

void dlinklist::deletenode(dlink ptr)
{
	if (NULL == ptr) {
		return;
	}
	
	if (NULL == ptr->back) {
		if (_cur == _head) {
			_cur = _head->front;
		}
		_head = _head->front;
		_head->back = NULL;
	}
	else {
		if (_cur == ptr) {
			_cur = ptr->back;
		}
		if (NULL == ptr->front) {
			ptr->back->front = NULL;
		}
		else {
			ptr->back->front = ptr->front;
			ptr->front->back = ptr->back;
		}
	}

	free(ptr);
}

int main()
{
	int list[6] = { 1, 2, 3, 4, 5, 6 };
	dlinklist dll(list, 6);

	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.forward();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dll.back();
	dll.print();

	dlink ptr = dll.findnode(1);
	dll.insertnode(ptr, 21);
	dll.print();

	ptr = dll.findnode(3);
	dll.insertnode(ptr, 22);
	dll.print();

	ptr = dll.findnode(6);
	dll.insertnode(ptr, 23);
	dll.print();

	dll.insertnode(NULL, 24);
	dll.print();

	ptr = dll.findnode(3);
	dll.deletenode(ptr);
	dll.print();

	ptr = dll.findnode(6);
	dll.deletenode(ptr);
	dll.print();

	ptr = dll.findnode(24);
	dll.deletenode(ptr);
	dll.print();

	ptr = dll.findnode(23);
	dll.deletenode(ptr);
	dll.print();
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
