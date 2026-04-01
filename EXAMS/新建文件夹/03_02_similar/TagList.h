#ifndef TAGLIST_H
#define TAGLIST_H

#include <string>
#include <iostream>

class TagList {
public:
    // 构造与析构
    TagList();
    TagList(const std::string* tags, int count);
    TagList(const TagList& other);
    TagList& operator=(const TagList& other);
    ~TagList();

    // 集合运算
    auto operator-=(const TagList& other) -> TagList&;
    friend auto operator-(const TagList& lhs, const TagList& rhs) -> TagList;

    // 自增自减
    auto operator++() -> TagList&;       // 前置 ++
    auto operator++(int) -> TagList;     // 后置 ++
    auto operator--() -> TagList&;       // 前置 --
    auto operator--(int) -> TagList;     // 后置 --

    // 输出流
    friend auto operator<<(std::ostream& os, const TagList& list) -> std::ostream&;

private:
    std::string* tags_;
    int count_;


    bool contains(const std::string& tag) const;
};

#endif // TAGLIST_H
