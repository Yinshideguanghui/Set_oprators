#pragma once

#include"list_simply_linked_no_remembering.h"
#include"list_simply_linked_no_remembering.cpp"

class ordered_list :public List<Record>
{
public:
	ordered_list() :List() {}
	Error_code insert(const Record& data);
	Error_code insert(int position, const Record& data);
	//Error_code replace(int position, const Record& data);
};

Error_code binary_search(ordered_list& list_, Key& target, int& position);