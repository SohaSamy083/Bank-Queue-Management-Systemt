#ifndef TELLER_H
#define TELLER_H
#include<string>

class Teller
{
    int finishTime;
    bool status;
    string name;
    int id;
    public:
        double serviceCount;
        Teller() {
            serviceCount=0;
              setFinishTime(0);
        }
        Teller(int id, string name)
        {
            serviceCount=0;
            setStatus(false);
            setName(name);
            setId(id);
           setFinishTime(0);
        }
        void setName(string name)
        {
            this->name;
        }
        void setId(int id)
        {
            this->id=id;
        }
        void setFinishTime(int finishTime)
        {
            this->finishTime=finishTime;
        }
        void setStatus(bool status)
        {
            this->status=status;
        }
        string getName()
        {
            return this->name;
        }
        int getId()
        {
            return this->id;
        }
        int getFinishTime()
        {
            return this->finishTime;
        }
        bool getStatus()
        {
            return this->status;
        }


};

#endif // TELLER_H
