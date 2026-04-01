#ifndef MY_LIST_HPP
#define MY_LIST_HPP

#include <iosfwd>
#include <string>
/* 你可以添加任意标准库头文件 */

class List {
public:
	List();
	bool is_exist(const  std::string& a);
	List(std::string* data, int size);
	auto operator+=(List const& other) -> List&;
	List(const List& p);
	List& operator=(const List& p);
	friend auto operator+(List const& lhs, List const& rhs) -> List;
	friend auto operator<<(std::ostream& ostream, List const& list) -> std::ostream&;


private:
	std::string* data_;
	int size_;
};

#endif