
#include "TagList.h"
#include<iostream>

TagList::TagList()
{
	tags_ = new std::string[20];
	count_ = 0;
}
TagList::TagList(const std::string* tags, int count)
{
	tags_ = new std::string[20];
	count_ = 0;
	for (int i = 0; i < count; i++)
	{
		if ((!contains(tags[i])) && tags[i] != "")
		{
			tags_[count_++] = tags[i];
		}
	}
}

TagList::TagList(const TagList& other)
{
	tags_ = new std::string[20];
	count_ = 0;
	for (int i = 0; i < other.count_; i++)
	{
		if (!contains(other.tags_[i]))
		{
			tags_[count_++] = other.tags_[i];
		}
	}
}
TagList& TagList::operator=(const TagList& other)
{
	count_ = other.count_;
	for (int i = 0; i < other.count_; i++)
	{
		tags_[i] = other.tags_[i];
	}
	return *this;
}
TagList::~TagList()
{
	delete[]tags_;
}


// 集合运算
auto TagList::operator-=(const TagList& other) -> TagList&
{
	TagList temp;
	temp = (*this - other);
	*this = temp;
	return *this;
}

auto operator-(const TagList& lhs, const TagList& rhs) -> TagList
{
	TagList temp(lhs);
	for (int i = 0; i < rhs.count_; i++)
	{
		for (int k = 0; k < lhs.count_; k++)
		{
			if (temp.tags_[k] == rhs.tags_[i]) {
				temp.tags_[k] = "";
				temp.count_--;
			}
		}
	}
	std::string *temp_tags_ = new std::string[temp.count_];
	int k = 0;
	for (int i = 0; i < temp.count_; i++)
	{
		while (temp.tags_[k] == "")
		{
			k++;
		}
		temp_tags_[i] = temp.tags_[k++];
	}
	temp.tags_ = temp_tags_;
	//delete[]temp_tags_;
	return temp;
}
// 自增自减
auto TagList::operator++() -> TagList&
{
	if (tags_[count_ - 1] == "Mastered")
	{
		return *this;
	}
	std::string* temp_tags = new std::string[++count_];
	for (int i = 0; i < count_-1; i++)
	{
		temp_tags[i] = tags_[i];
	}
	temp_tags[count_-1] = "Mastered";
	tags_ = temp_tags;
	return *this;
}
auto TagList::operator++(int) -> TagList
{
	if (tags_[count_-1]=="Mastered")
	{
		return *this;
	}
	TagList temp(*this);
	std::string* temp_tags = new std::string[++count_];
	for (int i = 0; i < count_ - 1; i++)
	{
		temp_tags[i] = tags_[i];
	}
	temp_tags[count_-1] = "Mastered";
	tags_ = temp_tags;
	return temp;
}
auto TagList::operator--() -> TagList&
{
	std::string* temp_tags = new std::string[--count_];
	for (int i = 0; i < count_; i++)
	{
		temp_tags[i] = tags_[i];
	}
	tags_ = temp_tags;
	//delete[]temp_tags;
	return *this;
}

auto TagList::operator--(int) -> TagList
{
	TagList temp(*this);
	
	std::string* temp_tags = new std::string[--count_];
	for (int i = 0; i < count_; i++)
	{
		temp_tags[i] = tags_[i];
	}
	tags_ = temp_tags;
	//delete[]temp_tags; why
	return temp;
}

// 输出流
auto operator<<(std::ostream& os, const TagList& list) -> std::ostream&
{
	if (list.count_==0)
	{
		return os;
	}
	os << "<";
	for (int i = 0; i < list.count_-1; i++)
	{
		os << list.tags_[i] << ",";
	}
	os << list.tags_[list.count_-1] << ">" << std::endl;
	return os;
}


bool TagList::contains(const std::string& tag) const
{
	for (int i = 0; i < count_; i++)
	{
		if (tags_[i] == tag)return 1;
	}
	return 0;
}