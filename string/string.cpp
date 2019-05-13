// string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

class String 
{
private:
	char str[81];

public:
	String(const char *ch);
	int length();
	void display(){ cout << str << endl; }
	int pos(String s);
	int pos(char *s);
	String getSubStr(int index, int count);
};

String::String(const char *s)
{
	strncpy_s(str, s, 80);
	str[80] = 0;
}

int String::length()
{
	return strlen(str);
}

int String::pos(String s)
{
	int found = 0;
	int i = 0;

	if (str == "" || s.length() > length()) {
		return -1;
	}

	while (!found && i < length()) {
		if (strncmp(&str[i], s.str, s.length()) == 0) {
			found = 1;
		}
		else {
			i++;
		}
	}

	if (found) {
		return i + 1;
	}

	return -1;
}

int String::pos(char *s)
{
	String s1(s);

	return pos(s1);
}

String String::getSubStr(int index, int count)
{
	String str1("");
	int temp;

	if (index <= strlen(str) && index > 0 && count > 0) {
		temp = length() - index + 1;
		if (count > temp) {
			count = temp;
		}
		strncpy_s(str1.str, &str[index - 1], count);
		str1.str[count] = 0;
	}

	return str1;
}

int main()
{
	String s1("数据结构是一门重要的课程");
	String s2("This is a book.");
	String s3("is");

	cout << "原始中文字符串：";
	s1.display();

	cout << "原始英文字符串：";
	s2.display();

	cout << "中文字符串共：" << s1.length() << "字符" << endl;
	cout << "英文字符串共：" << s2.length() << "字符" << endl;

	cout << "'一门'子字符串在中文字符串的位置：" << s1.pos("一门") << endl;
	cout << "'is'子字符串在中文字符串的位置：" << s2.pos(s3) << endl;

	cout << "取出中文字符串15开始共 6字符：";
	s3 = s1.getSubStr(15, 6);
	s3.display();
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
