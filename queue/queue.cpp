// queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

struct queue_node {
	int data;
	struct queue_node *next;
};
typedef struct queue_node queue_list;
typedef queue_list *queue_link;

class queue {

private:
	queue_link _front;
	queue_link _rear;

public:
	queue();
	int enqueue(int value);
	int dequeue();
	void print();
};

queue::queue()
{
	_front = NULL;
	_rear = NULL;
}

int queue::enqueue(int value)
{
	queue_link new_node;

	new_node = (queue_link)malloc(sizeof(queue_list));
	if (!new_node) {
		printf("allocate memory failed.\n");
		return -1;
	}

	new_node->data = value;
	new_node->next = NULL;
	if (NULL == _rear) {
		_front = new_node;
	}
	else {
		_rear->next = new_node;
	}
	_rear = new_node;
}

int queue::dequeue()
{
	queue_link top;
	int temp;

	if (NULL == _front) {
		return -1;
	}

	top = _front;
	_front = _front->next;
	temp = top->data;
	free(top);
	return temp;
}

void queue::print()
{
	queue_link ptr = _front;

	printf("queue: ");
	while (ptr) {
		printf("[%d]", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	queue q;
	int temp;

	q.enqueue(3);
	q.print();

	q.enqueue(7);
	q.print();
	
	q.enqueue(18);
	q.print();

	temp = q.dequeue();
	printf("dequeue [%d] from queue\n", temp);
	q.print();
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
