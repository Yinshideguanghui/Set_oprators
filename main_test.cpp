#include"test_command.h"

int main()
{
	cout << "���Կ�ʼ\n";
	Set set1, set2;
	help();
	while (do_command(get_command(), set1, set2)) {}
	return 0;
}