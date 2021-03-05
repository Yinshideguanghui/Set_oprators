#pragma once

#include"ordered_list.h"

class Set
{
public:
	Set() {}

	bool empty();
	int size();
	static Set intersection_Set(Set& set1, Set& set2);
	static Set union_Set(Set& set1, Set& set2);
	friend Set operator -(Set& set1, Set& set2);

	Error_code insert(const Record& data);
	Error_code insert(int position, const Record& data);

	void display();
protected:
	ordered_list set_ordered_list;
};