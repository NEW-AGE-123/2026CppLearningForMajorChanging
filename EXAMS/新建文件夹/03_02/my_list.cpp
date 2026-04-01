#include "my_list.hpp"
#include<iostream>
#include<string>


bool List::is_exist(const std::string & a)
{
	for (int i = 0; i < size_; i++)
	{
		if (data_[i] == a)
		{
			return 1;
		}
	}
	return 0;
}


List::List(std::string* data, int size)
{
	this->size_ = 0;
	data_ = new std::string[20];
	for (int i = 0; i < size; i++)
	{
		if(!is_exist(data[i]))
		data_[size_++] = data[i];
	}
}
auto List::operator+=(List const& other) -> List&
{
	for (int i = 0; i < other.size_; i++)
	{
		if (!is_exist(other.data_[i]))
		{
			data_[size_++] = other.data_[i];
		}
	}
	return *this;
}
List::List(const List& p)
{
	size_ = p.size_;
	data_ = new std::string[20];
	for (int i = 0; i < p.size_; i++)
	{
		data_[i] = p.data_[i];
	}
}
auto operator+(List const& lhs, List const& rhs) -> List
{
	List temp(lhs);
	for (int i = 0; i < rhs.size_; i++)
	{
		if (!temp.is_exist(rhs.data_[i]))
		{
			temp.data_[temp.size_++] = rhs.data_[i];
		}
	}
	return temp;
}
auto operator<<(std::ostream& ostream, List const& list) -> std::ostream&
{
	if (list.size_ == 0)
		return ostream;
	ostream << "[";
	for (int i = 0; i < list.size_-1; i++)
	{
		ostream << list.data_[i] << ",";
	}
	ostream << list.data_[list.size_-1] << "]" << std::endl;
	return ostream;

}
List& List::operator=(const List& p)
{
	size_ = p.size_;
	delete[]data_;
	data_ = new std::string[20];
	for (int i = 0; i < size_; i++)
	{
		data_[i] = p.data_[i];
	}
	return *this;
}



List::List()
{
	size_ = 0;
	data_ = new std::string[20];
}
