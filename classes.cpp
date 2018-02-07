/*


NOTE: This project is UNFINISHED! updates to come soon!
      - Some of the commentaries are jokes and must be treated likewise. 
      - I DID NOT INTEND TO OFFEND ANYONE.
      - Enjoy reading the code!

classes exercise with some STL container data usage

*/


#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define false 0
#define true !false


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
        
        
    protected:
        std::vector<char> CNP;// special ID code, unique for each person, by Romanian standards
        serialCode series;
        std::vector<std::string> hobbies;
    public:
        char sex;
        unsigned short age;
        double height;
        std::vector<char> firstName;
        std::vector<char> lastName;
        std::vector<char> middleName;


        virtual void mostUsedSentencePerDay()
        {
            std::cout<<"Peesha!? I love peesha!\n";//by peesha I obviously meant pizza.
        }
    person()
    {
        memcpy(series.regionInitials, "\0\0\0",3);
        series.number="";
    }
    ~person()
    {

    }
};


class kid:person{//kids are persons too. LOL.
    private:

    protected:

    public:

        void mostUsedSentencePerDay(){
            std::cout<<"I hate school!\n";
        }
};


class adult:person{//adults are persons, so... inheritance!
    private:
        unsigned short numberOfMarriages;// oh, the failure counter! lol. Let's be optimistic and keep it in within the range [0, 2^16 -1] ([0, 65535]) 



    public: 
        bool maritalStatus;// semaphore for happiness. true = happy, false = unhappy, but that really depends on the wife's(if exists) mood. This variable cannot be precise, since the wife can be both happy and unhappy in the same time, exceeding the capabilities of C++ 's abstractions. Guess we need a Quantum Computer for precision in that direction. For other sorts of marriage than traditional, probably the case of abstraction does not apply.

        std::vector<kid> kids;//some prefer having pets, and I understand why...

        void mostUsedSentencePerDay(){
            std::cout<<"I don't have time!\n";
        }

    adult()
    {
        memcpy(series.regionInitials, "\0\0\0",3);
        series.number="";
        maritalStatus=false;
    }


    ~adult(){

    }
};


int main()
{
    std::vector<person> personArray;
    unsigned short k=3000;
    printf("%u", (unsigned int)k);
    return 0;
}