#include <iostream>
#include "Customer.h"
#include "teller.h"
#include "Bank.h"
#include <queue>
#include<fstream>
using namespace std;
int main()
{
priority_queue<Customer> Customer_Queue;
string name;
int arriveTime, serviceTime, age;
ifstream Infile("Data_Clients.txt");
while(Infile>>name>>arriveTime>>serviceTime>>age)
{
     Customer_Queue.push(Customer(name,arriveTime,serviceTime,age));

}
Infile.close();
Bank bank1;
bank1.simulaion(Customer_Queue);







    return 0;
}
