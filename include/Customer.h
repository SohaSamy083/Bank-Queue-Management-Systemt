#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;
class Customer

{
    string name;
    int arriveTime;
    int serviceTime;
    int waitingTime;
    int age;
    public:
     //   Customer() {}
        Customer(string name,int arriveTime,int serviceTime,int age){
            setName(name);
            setAge(age);
            setArriveTime(arriveTime);
            setServiceTime(serviceTime);
            this->waitingTime=0;
        }
        void setName(string name)
        {
            this->name=name;
        }
        void setAge(int age)
        {
            this->age=age;
        }
        void setArriveTime(int arriveTime)
        {
            this->arriveTime=arriveTime;
        }
        void setServiceTime(int serviceTime)
        {
            this->serviceTime=serviceTime;
        }
         void setWaitingTime(int waitingTime)
        {
            this->waitingTime=waitingTime;
        }
        string getName()
        {
            return this->name;
        }
        int getArriveTime()
        {
            return this->arriveTime;
        }
        int getServiceTime()
        {
            return this->serviceTime;
        }
        int getWaitingTime()
        {
            return this->waitingTime;
        }
        int getAge()
        {
            return this->age;
        }
        bool operator<(const Customer& customer)const{
            if(this->arriveTime==customer.arriveTime)
            {
                return this-> age< customer.age && customer.age>=60;
            }
            else{
                return this->arriveTime > customer.arriveTime;
            }
        }


        };

#endif // CUSTOMER_H
