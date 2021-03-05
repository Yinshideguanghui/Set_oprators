#include"ordered_list.h"

Error_code ordered_list::insert(const Record& data)					//有序插入
{
	Record list_data;
	Key key_list_data;
	Key key_data(data);
	int s = List<Record>::size();
	int position;
	for (position = 0; position < s; position++)
	{
		List<Record>::retrieve(position, list_data);
		key_list_data = Key(list_data);
		if (key_data <= key_list_data)break;
	}
	return List<Record>::insert(position, data);
}

Error_code ordered_list::insert(int position, const Record& data)	//有序插入
{
	Record list_data;
	Key key_list_data;
	Key key_data(data);
	if (position > 0)
	{
		List<Record>::retrieve(position - 1, list_data);
		key_list_data = Key(list_data);
		if (key_data < key_list_data) return fail;
	}
	if (position < List<Record>::size())
	{
		List<Record>::retrieve(position, list_data);
		key_list_data = Key(list_data);
		if (key_data > key_list_data) return fail;
	}
	return List<Record>::insert(position, data);
}

//Error_code ordered_list::replace(int position, const Record& data)

//有序表中二分查找
Error_code binary_search(ordered_list& list_, Key& target, int& position)
{
	Record data;
	Key data_key;
	int left = 0;
	int right = list_.List<Record>::size() - 1;
	int mid = (left + right) / 2;
	while (left < right)
	{
		mid = (left + right) / 2;
		list_.List<Record>::retrieve(mid, data);
		data_key = Key(data);
		if (target > data_key) left = mid + 1;
		else right = mid;
	}
	if (left > right)return not_present;
	list_.List<Record>::retrieve(left, data);
	data_key = Key(data);
	if (data_key == target)return success;
	return not_present;
}