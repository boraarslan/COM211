#include <iostream>

using namespace std;

class clockType{
    private:
        int hr;
        int min;
        int sec;
    public:
        clockType(int = 0 , int = 0 , int = 0);
        void setTime(int, int ,int);
        void getTime(int& , int& , int&);
        void printTime() const;
        void printTime(const clockType&);
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const clockType& otherTime) const;
};

clockType::clockType(int hours , int minutes , int seconds){
    this->hr = hours;
    this->min = minutes;
    this->sec = seconds;
}

void clockType::setTime(int lhr , int lmin , int lsec){
    this->hr = (lhr < 0 || lhr > 23 ) ? 0 : lhr;
    this->min = (lmin < 0 || lmin > 60 ) ? 0 : lmin;
    this->sec = (lsec < 0 || lsec > 60 ) ? 0 : lsec;
}

void clockType::getTime(int& phr , int& pmin , int& psec){
    phr = this->hr;
    pmin = this->min;
    psec = this->sec;
}

void clockType::printTime()const{
    cout << this->hr << ":" << this->min << ":" << this->sec << endl;
}


void clockType::incrementSeconds(){
    if(++(this->sec) == 60){
        this->sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes(){
    if(++(this->min) == 60){
        this->min = 0;
        incrementHours();
    }
}

void clockType::incrementHours(){
    if(++(this->hr) == 24){
        this->hr = 0;
    }
}

bool clockType::equalTime(const clockType& otherTime) const {
    return (this->hr == otherTime.hr && this->min == otherTime.min && this->sec == otherTime.sec) ?  1 : 0;
}

void clockType::printTime(const clockType& otherTime){
    while(!(equalTime(otherTime))){
        printTime();
        incrementSeconds();
    }
}