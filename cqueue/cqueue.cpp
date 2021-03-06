// cqueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#define	MAXQUEUE	10

class cqueue {

private:
	int _queue[MAXQUEUE];
	int _front;
	int _rear;

public:
	cqueue();
	int enqueue(int value);
	int dequeue();
	void print();
};

cqueue::cqueue()
{
	_front = -1;
	_rear = -1;
}

int cqueue::enqueue(int value)
{
	if (_rear + 1 == _front || (_rear == (MAXQUEUE - 1) && _front <= 0)) {
		return -1;
	}

	_rear++;
	if (_rear >= MAXQUEUE) {
		_rear = 0;
	}
	_queue[_rear] = value;

	return _rear;
}

int cqueue::dequeue()
{
	if (_front == _rear) {
		return -1;
	}
	_front++;
	if (_front >= MAXQUEUE) {
		_front = 0;
	}

	return _queue[_front];
}

void cqueue::print()
{
	int cur = _front;

	printf("queue: ");
	while (cur != _rear) {
		cur++;
		if (cur == MAXQUEUE) {
			cur = 0;
		}
		printf("[%d]", _queue[cur]);
	}
	printf("\n");
}

int main()
{
	cqueue cq;

	cq.print();

	cq.enqueue(100);
	cq.print();

	cq.enqueue(200);
	cq.print();

	cq.enqueue(188);
	cq.print();

	cq.enqueue(360);
	cq.print();

	cq.dequeue();
	cq.print();

	cq.dequeue();
	cq.print();

	cq.dequeue();
	cq.print();

	cq.dequeue();
	cq.print();

	cq.dequeue();
	cq.print();
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
