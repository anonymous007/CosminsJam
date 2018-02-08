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
#include <time.h>

#define f 0
#define t !f
//because too lazy to type "true, or false"


const char* serialRegions[]{
    "IF",
    "OT",
    "NT",
    "BC",
    "BT",
    (const char*)NULL
};

const char* serialNumbers[]{
    "562701",
    "155423",
    "562701",
    "132435",
    "654734",
    (const char*)NULL
};
//will be choosing randomly combinations of these when we create serialCodes


class serialCode{
    public: char regionInitials[2];
            std::string number;

    static std::string getNumber(serialCode *x)
    {
        return x->number;
    }
    char* getRegionInitials(serialCode *x)
    {
        return x->regionInitials;
    }
    serialCode ()
    {
        srand(time(NULL));
        unsigned int random=rand()%5;//since we have only 5 items in serialNumbers & serialRegions arrays, it will generate a random number from 0 to 4. Perfect!

        memcpy(regionInitials, serialRegions[random],3);
        memcpy(&number[0], serialNumbers[random], strlen(serialNumbers[random]));
        //copy functions, straight outta Compton. I meant C. 

    }
    ~serialCode (){
        memset(this->regionInitials, '\0', 3);
        number="";
    }
};

void doNothing(){} 
//void doNothing(){ do{ }while(f); }//this one also works just fine, and it's more explicit


void relaxing()
{
    doNothing();
}
void playGames(){
    std::cout<<"you won't beat my score!\n";
    relaxing();
}
bool goingToSchool()
{
    goto school;
    school:;
    return t;
}


class person;
class adult;
class kid;//Dota2 players kinda hate this class


class person{
    private:
        bool life;
        //my dear friend, when this variable goes "false"... it means you're dead & RIP
        //it's private... at least, we used to have it that way... 
        //until Google, Facebook & friends came out.

        std::vector<std::string> secrets;
        //if they're not private, they're protected. But are shared secrets...
        //secrets anymore?

    protected:
        std::vector<char> CNP;
        // special ID code, unique for each person, by Romanian standards
        
        serialCode series;
        std::vector<std::string> hobbies;
        //may or may not have 'em, if not, sorry for ya.
    public:
        char sex;
        /*
            m = masculine
            f = feminine
            o = other
            b = binary executable (I think I'm that. Just kidding, I'm masculine)
        */
        unsigned short age;
        //hope you'll live until the max size of this variable on a x64 platform
        double height;
        // in metric, not imperial, please. We like precision in Europe.
        // we also don't like to use sentences like "My arm is one foot long.", or
        // "I once ate a 2 foot pizza in diameter"
        
        std::vector<char> firstName;
        std::vector<char> lastName;
        std::vector<char> middleName;

        virtual void favoriteActivity()
        {
            doNothing();
        }
        virtual void mostUsedSentencePerDay()
        {
            std::cout<<"Peesha!? I love peesha!\n";
            //by peesha I obviously meant pizza.
        }

        void setLife(bool x);

        void setSecrets(std::vector<std::string>);

        void clonePerson(person, person);


        std::vector<char> getCNP();

        person( std::vector<char> CNP,                  \
                serialCode series,                      \
                std::vector<std::string>secret,         \
                std::vector<char> firstName,            \
                std::vector<char> lastName,             \
                std::vector<char> middleName,           \
                unsigned short age);                    \
        person()
        {
            life=t;
            memcpy(series.regionInitials, "IF\0",3);//IF stands for "ILFOV"
            series.number="";
        }
        ~person()
        {
            setLife(f);
        }
};


void person::setLife(bool x)
{
    this->life=x;
}

void person::setSecrets(std::vector<std::string> x)
{
    this->secrets=x;
}

void person::clonePerson(person a, person b)
{
    a.life=b.life;
    a.age=b.age;
    a.sex=b.sex;
    a.height=b.height;
    a.firstName=b.firstName;
    a.middleName=b.middleName;
    a.lastName=b.lastName;
    a.CNP=b.CNP;
    a.series=b.series;
    a.hobbies=b.hobbies;
}//legally forbidden in real life, but not in programming

std::vector<char> person::getCNP()
{
    return this->CNP;
}

class kid:person{
    //kids are persons too. LOL.I know often the case my seem different but...
    private:

    protected:

    public:
        void favoriteActivity()
        {
            playGames();
            !goingToSchool();
            doNothing();
        }

        void mostUsedSentencePerDay(){
            std::cout<<"I hate school! Can't wait for the vacation to come...\n";
        }
};


class adult:person{//adults are persons, so... inheritance!
    private:
        unsigned short numberOfMarriages;
        // oh, the failure counter! lol. Let's be optimistic and
        // keep it in within the range [0, 2^16 -1] ([0, 65535]) 



    public: 
        bool maritalStatus;
        /*a.k.a semaphore for happiness. true = happy, false = unhappy, 
        but that really depends on the wife's(if exists) mood. 
        This variable cannot be precise, since the wife can be both happy
        and unhappy in the same time, exceeding the capabilities of C++'s
        abstractions. Guess we need a Quantum Computer for precision 
        in that direction. For other sorts of marriage than traditional, 
        probably the case of abstraction does not apply.
        */

        std::vector<kid> kids;
        //some may prefer having pets, and I understand why...


        void favoriteActivity(){
            relaxing();
        }

        void mostUsedSentencePerDay(){
            std::cout<<"I don't have time!\n";
        }

    adult()
    {
        memcpy(series.regionInitials, "IF\0",3);
        series.number="";
        maritalStatus=f;
    }


    ~adult(){// how to destroy an adult
        setLife(f);//you set his life to false
    }
};


int main()
{

    std::vector<person> personArray;
    std::vector<kid> kidsArray;
    std::vector<adult> adultArray;

    std::vector<serialCode>serialArray(10);
    for(unsigned int i=0;i<10;++i)
    {
        serialCode *x=new serialCode;
        serialArray.push_back(*x);
        std::string k=serialCode::getNumber(&serialArray[i]);
        std::cout<<k<<'\n';
        std::cout<<serialArray[i].regionInitials<<'\n';
        // delete(x);
    }
    
    return 0;
}