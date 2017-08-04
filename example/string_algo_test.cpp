#include "string_algo_test.h"

#include <boost/algorithm/string.hpp>
#include <vector>

//#pragma once

using namespace std;
using namespace boost;

void string_algo_test()
{
	//string str1(" hello World! ");

	//// to_upper(xxx):��string xxx�������ַ�����Ϊ��д��ĸ��ʽ
	//// to_lower(xxx):��string xxx�������ַ�����ΪСд��ĸ��ʽ
	//to_upper(str1);

	//// ȥ���ַ����ж���Ŀո�
	//trim(str1);

	//string str2 = to_lower_copy(
	//	ireplace_first_copy(
	//		str1, "hello", "goodbye"
	//	)
	//);

	string str("readme.txt");

	//if (ends_with(str, "txt"))
	//{
	//	cout << to_upper_copy(str) + " UPPER " << endl;
	//	assert(ends_with(str, "txt"));
	//}

	replace_first(str, "readme", "followme");
	cout << str << endl;

	vector<char> v(str.begin(),str.end());
	vector<char> v2 = to_upper_copy( erase_first_copy(v,"txt")	);

	for(auto ch:v2)
	{
		cout << ch;
	}
}