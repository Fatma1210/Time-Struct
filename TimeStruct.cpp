#include <iostream>
using namespace std ;
struct Time{
    int hours ;
    int minutes ;
    int seconds ;
    Time() {}
    Time(int hrs , int mn , int sec) : hours(hrs) , minutes(mn) , seconds(sec){

    }
    void displayTime(){
        cout << hours << " : " << minutes << " : " << seconds << endl;
    }
    void setHours (int hrs){
        hours = hrs ;
    }
    void setMinutes(int mn){
        hours += mn / 60 ;
        minutes = mn % 60 ;
    }
    void setSeconds(int sec){
        hours += sec / 3600 ;
        sec -= sec / 3600 ;
        minutes += sec / 60 ;
        seconds = sec % 60 ;
    }
    int getHours() const {
        return hours ;
    }
    int getMinutes() const {
        return minutes ;
    }
    int getSeconds() const {
        return seconds ;
    }
    bool IsBefore(Time t){
        if(t.hours < hours) return false ;
        if(t.hours > hours) return true ;
        if(t.minutes > minutes) return true ;
        if(t.seconds > seconds) return true ;
    }
    bool IsAfter(Time t){
        if(t.hours > hours) return false ;
        if(t.hours < hours) return true ;
        if(t.minutes < minutes) return true ;
        if(t.seconds < seconds) return true ;
    }
    bool IsEqual(Time t){
       if(t.hours == hours and t.minutes == minutes and t.seconds == seconds)
           return true ;
        return false ;
    }
    void AddHours(int HoursToAdd){
        hours += HoursToAdd ;
    }
    void AddMinutes(int MinutesToAdd){
        int mns = MinutesToAdd + minutes ;
        hours += mns / 60 ;
        minutes = mns % 60 ;
    }
    void AddSeconds(int SecondsToAdd){
        int secs = SecondsToAdd + seconds ;
        hours += secs / 3600 ;
        secs -= secs / 3600 ;
        minutes += secs / 60 ;
        seconds = secs % 60 ;
    }
    void MinusHours(int HoursToMinus){
        hours -= HoursToMinus ;
    }
    void MinusMinutes(int MinutesToMinus){
        hours -= MinutesToMinus / 60 ;
        minutes -= MinutesToMinus % 60 ;
    }
    void MinusSeconds(int SecondsToMinus){
        hours -= SecondsToMinus / 3600 ;
        seconds -= SecondsToMinus / 3600 ;
        minutes += SecondsToMinus / 60 ;
        seconds += SecondsToMinus % 60 ;
    }
    void CountDown(Time t){
        int Hours = t.hours - hours ;
        int Minutes = t.minutes - minutes ;
        int Seconds = t.seconds - seconds ;
        cout << Hours << " Hours ..." << Minutes << " Minutes ..." << Seconds << " Seconds \n" ;
    }
};

int main() {
   Time t1(10 , 30 , 10) , t2 ;
   t2.setHours(11) ;
   t2.setMinutes(25) ;
   t2.setSeconds(15) ;
   t1.displayTime() ;
   t2.displayTime() ;
   cout << t1.IsBefore(t2) << endl;
   cout << t1.IsAfter(t2) << endl;
   cout << t1.IsEqual(t2) << endl;
   t1.AddHours(1) ;
   t1.AddMinutes(5) ;
   t1.AddSeconds(20) ;
   t1.displayTime() ;
   t2.MinusHours(5) ;
   t2.MinusMinutes(10) ;
   t2.MinusSeconds(40) ;
   t2.displayTime() ;
   Time t3(5 , 30 , 0) , t4(10 , 45 , 30) ;
   t3.CountDown(t4) ;
    return 0;
}
