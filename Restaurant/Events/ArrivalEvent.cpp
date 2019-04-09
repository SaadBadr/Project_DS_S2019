#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
}

void ArrivalEvent::Execute(Restaurant* pRest)const{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1

	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phase 1&2

	Order* pOrd = new Order(OrderID,OrdType,OrdRegion);
	
	if(OrdType == TYPE_VIP){
	
		if(OrdRegion == A_REG)
			pRest->AddtoVIPQueueA(pOrd);
		
		else if(OrdRegion == B_REG)
			pRest->AddtoVIPQueueB(pOrd);

		else if(OrdRegion == C_REG)
			pRest->AddtoVIPQueueC(pOrd);

		else if(OrdRegion == D_REG)
			pRest->AddtoVIPQueueD(pOrd);
	
	}else if(OrdType == TYPE_FROZ){
	
		if(OrdRegion == A_REG)
			pRest->AddtoFrozenQueueA(pOrd);
		
		else if(OrdRegion == B_REG)
			pRest->AddtoFrozenQueueB(pOrd);

		else if(OrdRegion == C_REG)
			pRest->AddtoFrozenQueueC(pOrd);

		else if(OrdRegion == D_REG)
			pRest->AddtoFrozenQueueD(pOrd);

	}else if(OrdType == TYPE_NRM){
	
		if(OrdRegion == A_REG)
			pRest->AddtoNormalQueueA(pOrd);
		
		else if(OrdRegion == B_REG)
			pRest->AddtoNormalQueueB(pOrd);

		else if(OrdRegion == C_REG)
			pRest->AddtoNormalQueueC(pOrd);

		else if(OrdRegion == D_REG)
			pRest->AddtoNormalQueueD(pOrd);

	}





}


REGION ArrivalEvent :: get_region() 
{return OrdRegion;}

ORD_TYPE ArrivalEvent :: get_type() 
{return OrdType;}
