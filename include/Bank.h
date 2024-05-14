#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "Customer.h"
#include "teller.h"
#include <queue>
#include <string>
using namespace std;

class Bank
{
    Teller Tellers[4];
    public:
        Bank()
        {
            Tellers[0]=Teller(1,"Soha");
            Tellers[1]=Teller(2,"samy");
            Tellers[2]=Teller(3,"mayar");
            Tellers[3]=Teller(4,"kamel");

        }
        void simulaion(priority_queue<Customer> clients){
            double avergWaiting=0;
            int customerNumbers= clients.size();
            while(!clients.empty())
            {
                Customer client=clients.top();
                clients.pop();

                int minTime=Tellers[0].getFinishTime();
                int index=0;
                for (int i=0;i<4;i++)
                {
                    if (minTime>Tellers[i].getFinishTime())
                    {
                        minTime=Tellers[i].getFinishTime();
                        index=i;
                    }
                }
                if (!Tellers[index].getStatus()){
                    avergWaiting+=client.getWaitingTime();
                    Tellers[index].setFinishTime(client.getServiceTime()+client.getArriveTime()+client.getWaitingTime());
                    Tellers[index].setStatus(true);
                    Tellers[index].serviceCount++;
                    cout<<" The Customer : "<<client.getName()<<" Service Time = "<<client.getServiceTime()<<" Waiting Time = "<< client.getWaitingTime()<<" Minutes "<<" Age : "<<client.getAge()<<endl<<endl;
                }
                else
                {
                    if(Tellers[index].getFinishTime()<=client.getArriveTime())
                    {
                        client.setWaitingTime(0);

                    }
                    else
                    {

                        client.setWaitingTime(Tellers[index].getFinishTime() - client.getArriveTime());

                    }
                    Tellers[index].setStatus(false);
                    avergWaiting+=client.getWaitingTime();
                    clients.push(client);

                }

            }
            cout<<" The Average Waiting Time = " <<avergWaiting/customerNumbers << " Mintues \n \nTotal numbers of Customers Serviced = " <<customerNumbers <<" customers"<<endl<<endl;
            for (int i=0;i<4;i++)
            {
                cout<<" Teller : "<<Tellers[i].getId()<<" Name : "<<Tellers[i].getName()
                    <<" Total Service Time = "<<Tellers[i].getFinishTime()<<" minutes Utilization Service = " <<((Tellers[i].serviceCount)/customerNumbers)*100<<"%"<<endl;
            }
        }


};

#endif // BANK_H
