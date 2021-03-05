#include"set_operators.h"

bool Set::empty()							//�Ƿ�Ϊ��
{
	return set_ordered_list.List<Record>::size() == 0;
}

int Set::size()								//Ԫ�ظ���
{
	return set_ordered_list.List<Record>::size();
}

Set Set::intersection_Set(Set& set1, Set& set2)	//����
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1��set2��Ԫ��û��set3�г��ֹ��Ͳ���set3
	for (int i = 0; i < set1.size(); i++)
	{
		set1.set_ordered_list.List<Record>::retrieve(i, data);
		data_key = Key(data);
		if (binary_search(set3.set_ordered_list, data_key, position) == not_present)
			set3.insert(data);
	}
	for (int i = 0; i < set2.size(); i++)
	{
		set2.set_ordered_list.List<Record>::retrieve(i, data);
		data_key = Key(data);
		if (binary_search(set3.set_ordered_list, data_key, position) == not_present)
			set3.insert(data);
	}
	return set3;
}

Set Set::union_Set(Set& set1, Set& set2)		//����
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1�е�Ԫ����set2���ҵ�������set3�л�û�оͲ���set3
	for (int i = 0; i < set1.size(); i++)
	{
		set1.set_ordered_list.List<Record>::retrieve(i, data);
		data_key = Key(data);
		if ((binary_search(set2.set_ordered_list, data_key, position) == success)
			&& (binary_search(set3.set_ordered_list, data_key, position) == not_present))
			set3.set_ordered_list.insert(data);
	}
	return set3;
}

Set operator -(Set& set1, Set& set2)	//�
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1���е�Ԫ����set2��û�ҵ�����set3�л�û�оͲ���set3
	for (int i = 0; i < set1.size(); i++)
	{
		set1.set_ordered_list.List<Record>::retrieve(i, data);
		data_key = Key(data);
		if (binary_search(set2.set_ordered_list, data_key, position) == not_present
			&& binary_search(set3.set_ordered_list, data_key, position) == not_present)
			set3.set_ordered_list.insert(data);
	}
	return set3;
}

void Set::display()						//��ʾ
{
	Record list_data;
	char data;
	for (int i = 0; i < size(); i++)
	{
		set_ordered_list.List<Record>::retrieve(i, list_data);
		data = list_data.retrieve_item();
		cout << data;
	}
}

Error_code Set::insert(const Record& data)					//������룬���о�ʧ��
{
	Key data_key(data);
	int position_;
	if (binary_search(set_ordered_list, data_key, position_) == success) return fail;
	else return set_ordered_list.insert(data);
}

Error_code Set::insert(int position, const Record& data)	//������룬���о�ʧ��
{
	Key data_key(data);
	int position_;
	if (binary_search(set_ordered_list, data_key, position_) == success) return fail;
	else return set_ordered_list.insert(position, data);
}