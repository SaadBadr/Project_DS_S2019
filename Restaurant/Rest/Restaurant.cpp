#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
using namespace std;




Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		InteractiveMode();
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		//Just_A_Demo();
		break;

	};

}



//////////////////////////////////  Event handling functions  /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current time
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}




Restaurant::~Restaurant()
{
		delete pGUI;
}





// *************************************************ADDING TO ORDERS QUEUES*************************************************

//// ADD TO NORMAL QUEUES
/*
void Restaurant::EventsQueueLoop(int TimeStep){

	if(EventsQueue.isEmpty()) return;

	Event* currentEvent;
	EventsQueue.peekFront(currentEvent);

	while(!EventsQueue.isEmpty() && currentEvent->getEventTime() <= TimeStep){

		EventsQueue.dequeue(currentEvent);

		ArrivalEvent	 * R_ptr = dynamic_cast<ArrivalEvent*>(currentEvent);	   // the event is Arrival
		CancelationEvent * X_ptr = dynamic_cast<CancelationEvent*>(currentEvent);	 // the event is Cancelation
		PromotionEvent	 * P_ptr = dynamic_cast<PromotionEvent*>(currentEvent);		// the event is Promotion

		if(R_ptr)
			R_ptr->Execute(this);

		else if(X_ptr)
			X_ptr->Execute(this);
		
		else if(P_ptr)
			P_ptr->Execute(this);

		
		EventsQueue.peekFront(currentEvent);

	
	}
		




}
*/


void Restaurant::InteractiveMode(){
	int CurrentTimeStep = 1;

	Io* Test = new Io(this,pGUI);
	
	pGUI->PrintMessage("Welcome To interactive mode,click to continue");
	
	pGUI->waitForClick();
	
	Test->load();
	
	
	while(!EventsQueue.isEmpty()){


		Order* order;

		Queue<Order*>* FRZ_NRM[8] = { &FrozenQueueA, &FrozenQueueB, &FrozenQueueC, &FrozenQueueD, &NormalQueueA, &NormalQueueB, &NormalQueueC, &NormalQueueD} ;
		PriorityQueue<Order*>* VIP[4] = { &VIPQueueA , &VIPQueueB, &VIPQueueC, &VIPQueueD} ;



		if(CurrentTimeStep > 1){

			for (int i = 0; i < 4; i++)
			{
				if(VIP[i]->dequeue(order))
					delete order;
			}	

			for (int i = 0; i < 8; i++)
			{
				if(FRZ_NRM[i]->dequeue(order))
					delete order;
			}	
			
			order = NULL;
		}

		ExecuteEvents(CurrentTimeStep);


		//********************************DRAWING VIP ORDERS************************************

		for(int i = 0 ; i < 4 ; i++){

			if(VIP[i]->isEmpty()) continue;

			Order* front;
			VIP[i]->frontpeek(front);
			
			do {

				VIP[i]->dequeue(order);
				pGUI->AddOrderForDrawing(order);
				pGUI->UpdateInterface();
				VIP[i]->enqueue(order);
				VIP[i]->frontpeek(order);

			}while(order != front);
		
	
	}

		//********************************DRAWING Frozen & Normal ORDERS************************************


		for(int i = 0 ; i < 8 ; i++){
			
			if(FRZ_NRM[i]->isEmpty()) continue;

			Order* front;
			FRZ_NRM[i]->peekFront(front);

			do {

				FRZ_NRM[i]->dequeue(order);
				pGUI->AddOrderForDrawing(order);
				pGUI->UpdateInterface();
				FRZ_NRM[i]->enqueue(order);
				FRZ_NRM[i]->peekFront(order);

			}while(order != front);
			
	}	


		pGUI->waitForClick();
		CurrentTimeStep++;
		pGUI->ResetDrawingList();

	}


}

void Restaurant::AddtoNormalQueueA(Order *pOrd)
{
	NormalQueueA.enqueue(pOrd) ;
}

void Restaurant::AddtoNormalQueueB(Order *pOrd)
{
	NormalQueueA.enqueue(pOrd) ;
}

void Restaurant::AddtoNormalQueueC(Order *pOrd)
{
	NormalQueueA.enqueue(pOrd) ;
}

void Restaurant::AddtoNormalQueueD(Order *pOrd)
{
	NormalQueueD.enqueue(pOrd) ;
}

//// ADD TO Frozen QUEUES


void Restaurant::AddtoFrozenQueueA(Order *pOrd)
{
	FrozenQueueA.enqueue(pOrd) ;
}

void Restaurant::AddtoFrozenQueueB(Order *pOrd)
{
	FrozenQueueB.enqueue(pOrd) ;
}

void Restaurant::AddtoFrozenQueueC(Order *pOrd)
{
	FrozenQueueC.enqueue(pOrd) ;
}

void Restaurant::AddtoFrozenQueueD(Order *pOrd)
{
	FrozenQueueD.enqueue(pOrd) ;
}

//// ADD TO VIP QUEUES

void Restaurant::AddtoVIPQueueA(Order *pOrd)
{
	VIPQueueA.enqueue(pOrd) ;
}

void Restaurant::AddtoVIPQueueB(Order *pOrd)
{
	VIPQueueB.enqueue(pOrd) ;
}

void Restaurant::AddtoVIPQueueC(Order *pOrd)
{
	VIPQueueC.enqueue(pOrd) ;
}

void Restaurant::AddtoVIPQueueD(Order *pOrd)
{
	VIPQueueD.enqueue(pOrd) ;
}

// *************************************************Dequeuing from Normal QUEUES*************************************************


Order* Restaurant::DequeueNormalQueueA(){

	Order * p;

	if(NormalQueueA.dequeue(p))
		return p;
	else
		return NULL;

}

Order* Restaurant::DequeueNormalQueueB(){

	Order * p;

	if(NormalQueueB.dequeue(p))
		return p;
	else
		return NULL;

}
Order* Restaurant::DequeueNormalQueueC(){

	Order * p;

	if(NormalQueueC.dequeue(p))
		return p;
	else
		return NULL;


}

Order* Restaurant::DequeueNormalQueueD(){

	Order * p;

	if(NormalQueueD.dequeue(p))
		return p;
	else
		return NULL;

}

// *************************************************Peek from Normal QUEUES*************************************************


Order* Restaurant::PeekNormalQueueA(){
	
	Order * p;

	if(NormalQueueA.peekFront(p))
		return p;
	else
		return NULL;

}

Order* Restaurant::PeekNormalQueueB(){
	
	Order * p;
	
	if(NormalQueueB.peekFront(p))
		return p;
	else
		return NULL;

}

Order* Restaurant::PeekNormalQueueC(){
	
	Order * p;

	if(NormalQueueC.peekFront(p))
		return p;
	else
		return NULL;

}

Order* Restaurant::PeekNormalQueueD(){
	
	Order * p;

	if(NormalQueueD.peekFront(p))
		return p;
	else
		return NULL;

}

/// ==> end of DEMO-related function

void Restaurant :: StoreInputFile () 
{
	string name ;
	cin >> name ;
	InputFile.open(name) ;
}

void Restaurant::AddMototrcycle(Motorcycle * po){
	switch (po->GetRegion())
	{
	case A_REG:
		switch (po->GetType())
		{
		case TYPE_NRM:
			NormalMotorA.enqueue(po);
			break;
		case TYPE_VIP:
			VIPMotorA.enqueue(po);
			break;
		case TYPE_FROZ:
			FrozenMotorA.enqueue(po);
			break;
		default:
			break;
		}
		break;
	case B_REG:
		switch (po->GetType())
		{
		case TYPE_NRM:
			NormalMotorB.enqueue(po);
			break;
		case TYPE_VIP:
			VIPMotorB.enqueue(po);
			break;
		case TYPE_FROZ:
			FrozenMotorB.enqueue(po);
			break;
		default:
			break;
		}
		break;
	case C_REG:
		switch (po->GetType())
		{
		case TYPE_NRM:
			NormalMotorC.enqueue(po);
			break;
		case TYPE_VIP:
			VIPMotorC.enqueue(po);
			break;
		case TYPE_FROZ:
			FrozenMotorC.enqueue(po);
			break;
		default:
			break;
		}
		break;
	case D_REG:
		switch (po->GetType())
		{
		case TYPE_NRM:
			NormalMotorD.enqueue(po);
			break;
		case TYPE_VIP:
			VIPMotorD.enqueue(po);
			break;
		case TYPE_FROZ:
			FrozenMotorD.enqueue(po);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

Motorcycle * Restaurant::GetNormalMotorcycleA(){
	Motorcycle* x;
	NormalMotorA.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetNormalMotorcycleB(){
	Motorcycle* x;
	NormalMotorB.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetNormalMotorcycleC(){
	Motorcycle* x;
	NormalMotorC.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetNormalMotorcycleD(){
	Motorcycle* x;
	NormalMotorD.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetFrozenMotorcycleA(){
	Motorcycle* x;
	FrozenMotorA.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetFrozenMotorcycleB(){
	Motorcycle* x;
	FrozenMotorB.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetFrozenMotorcycleC(){
	Motorcycle* x;
	FrozenMotorC.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetFrozenMotorcycleD(){
	Motorcycle* x;
	FrozenMotorD.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetVIPMotorcycleA(){
	Motorcycle* x;
	VIPMotorA.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetVIPMotorcycleB()
{
	Motorcycle* x;
	VIPMotorA.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetVIPMotorcycleC()
{
	Motorcycle* x;
	VIPMotorA.dequeue(x);
	return x;
}

Motorcycle * Restaurant::GetVIPMotorcycleD()
{
	Motorcycle* x;
	VIPMotorA.dequeue(x);
	return x;
}

void Restaurant::SetAutoPromTime(int time){
	AutoPromotionTimeLimit = time;
}

int Restaurant::GetAutoPromTime()
{
	return AutoPromotionTimeLimit;
}
