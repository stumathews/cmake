#include <iostream>
#include "TutorialConfig.h"

using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Default constructor called." << endl;
	}
	Person(char*name, int age)
	{
		this->name = name;
		this->age = age;
	}
	~Person(){}
	char* name;
	int age;
	void setName(char* name);
	void setAge(int age);
	char* getName();
	int getAge();
private:
	char* password;

};
