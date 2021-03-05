#include"set_operators.h"

bool Set::empty()							//是否为空
{
	return set_ordered_list.List<Record>::size() == 0;
}

int Set::size()								//元素个数
{
	return set_ordered_list.List<Record>::size();
}

Set Set::intersection_Set(Set& set1, Set& set2)	//并集
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1和set2的元素没在set3中出现过就插入set3
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

Set Set::union_Set(Set& set1, Set& set2)		//交集
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1中的元素在set2中找到并且在set3中还没有就插入set3
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

Set operator -(Set& set1, Set& set2)	//差集
{
	Key data_key;
	Record data;
	Set set3;
	int position;
	//set1中有的元素在set2中没找到且在set3中还没有就插入set3
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

void Set::display()						//显示
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

Error_code Set::insert(const Record& data)					//有序插入，已有就失败
{
	Key data_key(data);
	int position_;
	if (binary_search(set_ordered_list, data_key, position_) == success) return fail;
	else return set_ordered_list.insert(data);
}

Error_code Set::insert(int position, const Record& data)	//有序插入，已有就失败
{
	Key data_key(data);
	int position_;
	if (binary_search(set_ordered_list, data_key, position_) == success) return fail;
	else return set_ordered_list.insert(position, data);
}