/*


NOTE: This project is UNFINISHED! updates to come soon!

classes exercise with some STL container data usage

*/


#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class serialCode{
    public: char regionInitials[2];
            std::string number;
    serialCode (){

    }
    ~serialCode (){

    }
};

class person{
    private:
        std::vector<char> CNP;// special ID code, unique for each person
        serialCode series;
        
        
    protected:
        std::vector<std::string> hobbies;
    public:
        unsigned short age;
        double height;
        std::vector<char> firstName;
        std::vector<char> lastName;
        std::vector<char> middleName;

    person()
    {
        memcpy(series.regionInitials, "\0\0\0",3);
        series.number="";
    }
    ~person()
    {

    }
};

class adult:person{
    private:

    public: 
        bool maritalStatus;
};


int main()
{
    std::vector<person> personArray;
    return 0;
}