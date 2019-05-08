#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg,int dist,double money):Event(eTime, oID)
{
	OrdDistance = dist;
	OrdType = oType;
	OrdRegion = reg;
	OrdMoney = money;
}

void ArrivalEvent::Execute(Restaurant* pRest)const{
	Order* pOrd = new Order(OrderID, OrdType, OrdRegion, OrdMoney, OrdDistance, EventTime);
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
