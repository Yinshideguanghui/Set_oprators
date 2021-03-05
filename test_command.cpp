#include"test_command.h"

void help()
{
	cout << endl
		<< "该程序允许用户每次输入一个字母命令（仅限一个）\n"
		<< "有效命令包括：\n"
		<< "X-显示当前集合1\n"
		<< "x-显示当前集合2\n"
		<< "I-将接下来输入的字符（仅限英文小写字母或阿拉伯数字）插入集合1\n"
		<< "i-将接下来输入的字符（仅限英文小写字母或阿拉伯数字）插入集合2\n"
		<< "K-判断当前集合1是否为空\n"
		<< "k-判断当前集合2是否为空\n"
		<< "B-求并显示当前集合1和集合2的并集\n"
		<< "J-求并显示当前集合1和集合2的交集\n"
		<< "C-求并显示当前集合1和集合2的差集\n"
		<< "H-显示本帮助\n"
		<< "Q-退出\n"
		<< "按一次 <Enter> 以继续" << flush;
	char c;
	do {
		cin.get(c);
	} while (c != '\n');
}

char get_command()
{
	char command;
	bool waiting = true;
	cout << "\n输入命令后按 <Enter>:";
	while (waiting)
	{
		cin.get(command);
		if (command == 'X' || command == 'x' || command == 'I' ||
			command == 'i' || command == 'K' || command == 'k' ||
			command == 'B' || command == 'J' || command == 'C' ||
			command == 'H' || command == 'Q')
			waiting = false;
		else
			cout << "请输入有效命令: ";
	}
	while ((getchar()) != '\n');//吸收多余输入
	return command;
}

bool do_command(char c, Set& set1, Set& set2)
{
	bool continue_input = true;
	char x;
	switch (c)
	{
	case 'X':
		set1.display();
		break;
	case 'x':
		set2.display();
		break;
	case 'I':
	{	cout << "请输入项目:";
		cin >> x;
		Error_code err_cd;
		if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
		{
			cout << "输入的字符" << x << "不是一个英文小写字母或一位阿拉伯数字，不能插入\n";
		}
		else
		{
			Record data(x);
			err_cd = set1.insert(data);
			if (err_cd == overflow)
				cout << "上溢：内存已无法容纳更多项目" << endl;
			else if (err_cd == fail)
				cout << "失败：集合中已有该元素（" << x << "）" << endl;
		}
		while ((x = getchar()) != '\n')
		{
			if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
			{
				cout << "输入的字符" << x << "不是一个英文小写字母或一位阿拉伯数字，不能插入\n";
			}
			else
			{
				Record data(x);
				err_cd = set1.insert(data);
				if (err_cd == overflow)
					cout << "上溢：内存已无法容纳更多项目" << endl;
				else if (err_cd == fail)
					cout << "失败：集合中已有该元素（" << x << "）" << endl;
			}
		}
		break;
	}
	case 'i':
	{	cout << "请输入项目:";
		cin >> x;
		Error_code err_cd;
		if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
		{
			cout << "输入的字符" << x << "不是一个英文小写字母或一位阿拉伯数字，不能插入\n";
		}
		else
		{
			Record data(x);
			err_cd = set2.insert(data);
			if (err_cd == overflow)
				cout << "上溢：内存已无法容纳更多项目" << endl;
			else if (err_cd == fail)
				cout << "失败：集合中已有该元素（" << x << "）" << endl;
		}
		while ((x = getchar()) != '\n')
		{
			if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
			{
				cout << "输入的字符" << x << "不是一个英文小写字母或一位阿拉伯数字，不能插入\n";
			}
			else
			{
				Record data(x);
				err_cd = set2.insert(data);
				if (err_cd == overflow)
					cout << "上溢：内存已无法容纳更多项目" << endl;
				else if (err_cd == fail)
					cout << "失败：集合中已有该元素（" << x << "）" << endl;
			}
		}
		break;
	}
	case 'K':
		if (set1.empty()) cout << "集合1为空" << endl;
		else cout << "集合1非空" << endl;
		break;
	case 'k':
		if (set2.empty()) cout << "集合2为空" << endl;
		else cout << "集合2非空" << endl;
		break;
	case 'B':
	{	Set set3;
		set3 = Set::intersection_Set(set1, set2);
		set3.display(); cout << endl;
		break; 
	}
	case 'J':
	{	Set set3;
		set3 = Set::union_Set(set1, set2);
		set3.display(); cout << endl;
		break;
	}
	case 'C':
	{	Set set3;
		set3 = set1 - set2;
		set3.display(); cout << endl;
		break;
	}
	case 'H':
		help();
		break;
	case 'Q':
		cout << "测试结束" << endl;
		continue_input = false;
		break;
	}
	return continue_input;
}