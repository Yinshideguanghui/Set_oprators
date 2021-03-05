#include"test_command.h"

void help()
{
	cout << endl
		<< "�ó��������û�ÿ������һ����ĸ�������һ����\n"
		<< "��Ч���������\n"
		<< "X-��ʾ��ǰ����1\n"
		<< "x-��ʾ��ǰ����2\n"
		<< "I-��������������ַ�������Ӣ��Сд��ĸ���������֣����뼯��1\n"
		<< "i-��������������ַ�������Ӣ��Сд��ĸ���������֣����뼯��2\n"
		<< "K-�жϵ�ǰ����1�Ƿ�Ϊ��\n"
		<< "k-�жϵ�ǰ����2�Ƿ�Ϊ��\n"
		<< "B-����ʾ��ǰ����1�ͼ���2�Ĳ���\n"
		<< "J-����ʾ��ǰ����1�ͼ���2�Ľ���\n"
		<< "C-����ʾ��ǰ����1�ͼ���2�Ĳ\n"
		<< "H-��ʾ������\n"
		<< "Q-�˳�\n"
		<< "��һ�� <Enter> �Լ���" << flush;
	char c;
	do {
		cin.get(c);
	} while (c != '\n');
}

char get_command()
{
	char command;
	bool waiting = true;
	cout << "\n��������� <Enter>:";
	while (waiting)
	{
		cin.get(command);
		if (command == 'X' || command == 'x' || command == 'I' ||
			command == 'i' || command == 'K' || command == 'k' ||
			command == 'B' || command == 'J' || command == 'C' ||
			command == 'H' || command == 'Q')
			waiting = false;
		else
			cout << "��������Ч����: ";
	}
	while ((getchar()) != '\n');//���ն�������
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
	{	cout << "��������Ŀ:";
		cin >> x;
		Error_code err_cd;
		if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
		{
			cout << "������ַ�" << x << "����һ��Ӣ��Сд��ĸ��һλ���������֣����ܲ���\n";
		}
		else
		{
			Record data(x);
			err_cd = set1.insert(data);
			if (err_cd == overflow)
				cout << "���磺�ڴ����޷����ɸ�����Ŀ" << endl;
			else if (err_cd == fail)
				cout << "ʧ�ܣ����������и�Ԫ�أ�" << x << "��" << endl;
		}
		while ((x = getchar()) != '\n')
		{
			if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
			{
				cout << "������ַ�" << x << "����һ��Ӣ��Сд��ĸ��һλ���������֣����ܲ���\n";
			}
			else
			{
				Record data(x);
				err_cd = set1.insert(data);
				if (err_cd == overflow)
					cout << "���磺�ڴ����޷����ɸ�����Ŀ" << endl;
				else if (err_cd == fail)
					cout << "ʧ�ܣ����������и�Ԫ�أ�" << x << "��" << endl;
			}
		}
		break;
	}
	case 'i':
	{	cout << "��������Ŀ:";
		cin >> x;
		Error_code err_cd;
		if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
		{
			cout << "������ַ�" << x << "����һ��Ӣ��Сд��ĸ��һλ���������֣����ܲ���\n";
		}
		else
		{
			Record data(x);
			err_cd = set2.insert(data);
			if (err_cd == overflow)
				cout << "���磺�ڴ����޷����ɸ�����Ŀ" << endl;
			else if (err_cd == fail)
				cout << "ʧ�ܣ����������и�Ԫ�أ�" << x << "��" << endl;
		}
		while ((x = getchar()) != '\n')
		{
			if (!(((x >= 'a') && (x <= 'z')) || ((x >= '0') && (x <= '9'))))
			{
				cout << "������ַ�" << x << "����һ��Ӣ��Сд��ĸ��һλ���������֣����ܲ���\n";
			}
			else
			{
				Record data(x);
				err_cd = set2.insert(data);
				if (err_cd == overflow)
					cout << "���磺�ڴ����޷����ɸ�����Ŀ" << endl;
				else if (err_cd == fail)
					cout << "ʧ�ܣ����������и�Ԫ�أ�" << x << "��" << endl;
			}
		}
		break;
	}
	case 'K':
		if (set1.empty()) cout << "����1Ϊ��" << endl;
		else cout << "����1�ǿ�" << endl;
		break;
	case 'k':
		if (set2.empty()) cout << "����2Ϊ��" << endl;
		else cout << "����2�ǿ�" << endl;
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
		cout << "���Խ���" << endl;
		continue_input = false;
		break;
	}
	return continue_input;
}