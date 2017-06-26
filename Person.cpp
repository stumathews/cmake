#include "Person.h"
#include "TutorialConfig.h"

void Person::setName(char* name)
{
#ifdef USE_MYLIB
		cout << "My library support enabled." << endl;
#else
		cout << "My library support disabled." << endl;
#endif
}

void Person::setAge(int age)
{
}

char* Person::getName()
{
}

int Person::getAge()
{
}
