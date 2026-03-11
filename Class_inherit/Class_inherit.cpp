
#include <iostream>


class human
{
public:
    int h_age;
private:
    int weight;
};

class student : virtual private human
{
public:
    int scores;
};


class athletes : virtual protected human
{
public:
    int strength;
};

class student_athlete :public athletes,public student
{
public:
    student_athlete(int a)
    {
        h_age = a;
    }
private:
    int award;
};



int main()
{
    std::cout << "Hello World!\n";
    student_athlete Zyq(2);
    Zyq.student::scores;

    
}
