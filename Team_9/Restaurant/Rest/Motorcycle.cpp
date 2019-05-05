#include "Motorcycle.h"

//*************************************************Constructors************************************************


Motorcycle::Motorcycle()
{
}

Motorcycle::Motorcycle(int sp, REGION rg, STATUS s ):speed(sp),region(rg),status(s){}


//*************************************************Getters************************************************


int Motorcycle::GetID(){

	return ID;
}

int Motorcycle::GetSpeed(){

	return speed;
}

REGION Motorcycle::GetRegion(){

	return region;
}

STATUS Motorcycle::GetStatus(){

	return status;
}

ORD_TYPE Motorcycle::GetType(){

	return type;
}

//*************************************************Setters************************************************


void Motorcycle::setID(int id){
	
	ID = id;
}

void Motorcycle::setType(ORD_TYPE  typ){
	
	type = typ;
}

void Motorcycle::setStatus(STATUS  st){
	
	status = st;
}

void Motorcycle::SetReturnTime(int x){
	ReturnTime = x;
}

//*************************************************Destractor************************************************


Motorcycle::~Motorcycle(){

}

int Motorcycle::getRT()
{
	return ReturnTime;
}

bool Motorcycle::operator>(Motorcycle x){
	return ReturnTime < x.ReturnTime;
}

bool Motorcycle::operator<(Motorcycle x){
	return ReturnTime > x.ReturnTime;
}

bool Motorcycle::operator==(Motorcycle x){
	return ReturnTime == x.ReturnTime;
}

