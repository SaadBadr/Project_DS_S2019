#include "Order.h"
#include <type_traits>


//*************************************************Constructors************************************************


Order::Order(int id, ORD_TYPE r_Type, REGION r_region, double totmoney, int dist , int arrTime , int WT ){

	SetDistance(dist);
	SetMoney(totmoney);

	ID = (id > 0 && id < 1000) ? id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	if (r_Type == TYPE_VIP)
		priority = 10000 + totalMoney  -  ArrTime  -  Distance;
	else 
		priority = 10000 - ArrTime;
}

Order::~Order(){
}

int Order::GetID(){
	
	return ID;
}


void Order::SetST(int x) {
	
	ServTime = x;

}
void Order::SetFT(int x) {

	FinishTime = x;
}

void Order::SetWT(int x){
	WaitingTime = x;
}

int Order::GetWT(){
	return WaitingTime;
}


//*************************************************Getters************************************************


int Order::GetType() const{
	
	return type;
}

REGION Order::GetRegion() const{
	
	return Region;
}

int Order::GetMoney(){

	return totalMoney;
}

int Order::GetArrTime(){

	return ArrTime;
}

int Order::GetServTime()
{
	return ServTime;
}

int Order::GetFinishTime()
{
	return FinishTime;
}

int Order::GetDistance() const{

	return Distance;
}

//*************************************************Setters************************************************


void Order::SetDistance(int d){
	
	Distance = d > 0 ? d:0;
}


void Order::SetMoney(double m){
	
	totalMoney = m;
}


//*************************************************Operators Overloading************************************************

bool Order::operator<(const Order o){

	if (o.priority > priority)
		return true;
	
	else
		return false;
}

bool Order::operator>(const  Order o){

	if (o.priority < priority)
		return true;
	
	else
		return false;
}


bool Order::operator==(const  Order o){

	if (o.priority==priority)
		return true;
	
	else
		return false;
}

void Order::operator=(const Order o){

	ID = o.ID;       
	type = type;		
	Region = Region;  
	Distance = Distance;
	totalMoney =  totalMoney ;
	ArrTime = ArrTime ;
	ServTime = o.ServTime ;
	FinishTime = o.FinishTime ;
	priority = o.priority ;
}


