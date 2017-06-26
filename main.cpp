#include "Person.h"
#include "TutorialConfig.h"

int main(int argc, char** argv)
{
	Person p;
	string name = "Stuart";
	p.setName((char*)name.c_str());
}
