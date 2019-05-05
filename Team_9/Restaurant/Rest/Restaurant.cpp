#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
using namespace std;




bool Restaurant::assign(Order * ord, int timestep){
	Motorcycle* M_ptr = NULL;
	if (ord->GetRegion() == A_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorA.isEmpty())
				NormalMotorA.dequeue(M_ptr);
			else if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);
			else
				return false;
		}
		if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;

		}
		if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);
			else if (!NormalMotorA.isEmpty())
				NormalMotorA.dequeue(M_ptr);
			else if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;
		}
	}
	else if (ord->GetRegion() == B_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorA.isEmpty())

				NormalMotorA.dequeue(M_ptr);

			else if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);

			else
				return false;

		}
		if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;

		}
		if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);
			else if (!NormalMotorA.isEmpty())
				NormalMotorA.dequeue(M_ptr);
			else if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;
		}
	}
	else if (ord->GetRegion() == C_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorA.isEmpty())

				NormalMotorA.dequeue(M_ptr);

			else if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);

			else
				return false;

		}
		if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;

		}
		if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorA.isEmpty())
				VIPMotorA.dequeue(M_ptr);
			else if (!NormalMotorA.isEmpty())
				NormalMotorA.dequeue(M_ptr);
			else if (!FrozenMotorA.isEmpty())
				FrozenMotorA.dequeue(M_ptr);
			else
				return false;
		}
	}
	else
	{
	if (ord->GetType() == TYPE_NRM)
	{
		if (!NormalMotorA.isEmpty())

			NormalMotorA.dequeue(M_ptr);

		else if (!VIPMotorA.isEmpty())
			VIPMotorA.dequeue(M_ptr);

		else
			return false;

	}
	if (ord->GetType() == TYPE_FROZ) {
		if (!FrozenMotorA.isEmpty())
			FrozenMotorA.dequeue(M_ptr);
		else
			return false;

	}
	if (ord->GetType() == TYPE_VIP) {
		if (!VIPMotorA.isEmpty())
			VIPMotorA.dequeue(M_ptr);
		else if (!NormalMotorA.isEmpty())
			NormalMotorA.dequeue(M_ptr);
		else if (!FrozenMotorA.isEmpty())
			FrozenMotorA.dequeue(M_ptr);
		else
			return false;
	}
	}
	M_ptr->setID(ord->GetID());
	M_ptr->setStatus(SERV);
	ord->SetST(ceil((float)ord->GetDistance() / (M_ptr->GetSpeed())));
	ord->SetFT(ord->GetWT() + ord->GetArrTime() + ord->GetServTime());
	M_ptr->SetReturnTime(ord->GetServTime() + ord->GetFinishTime());
	InServiceMotorA.enqueue(M_ptr);
	return true;
}

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


void Restaurant::InteractiveMode(){
	int CurrentTimeStep = 1;


	int    VIPcounterA =0    , VIPcounterB =0     ,VIPcounterC =0     ,VIPcounterD =0  ,
		FROZENcounterA = 0 ,FROZENcounterB = 0 ,FROZENcounterC = 0 ,FROZENcounterD = 0  ,
		NORMALcounterA = 0 ,NORMALcounterB = 0 ,NORMALcounterC = 0 ,NORMALcounterD = 0  ;



	Io* Test = new Io(this,pGUI);
	
	pGUI->PrintMessage("Welcome To interactive mode,click to continue");
	
	pGUI->waitForClick();
	
	Test->load();
	
	
	while(!EventsQueue.isEmpty()){

		Motorcycle* M_ptrA, *M_ptrB, *M_ptrC, *M_ptrD;
		InServiceMotorA.frontpeek(M_ptrA);
		InServiceMotorA.frontpeek(M_ptrB);
		InServiceMotorA.frontpeek(M_ptrC);
		InServiceMotorA.frontpeek(M_ptrD);
		while (!InServiceMotorA.isEmpty() && M_ptrA->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrA);
			InServiceMotorA.dequeue(M_ptrA);
			InServiceMotorA.frontpeek(M_ptrA);
		}
		while (!InServiceMotorB.isEmpty() && M_ptrB->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrB);
			InServiceMotorB.dequeue(M_ptrB);
			InServiceMotorB.frontpeek(M_ptrB);
		}
		while (!InServiceMotorC.isEmpty() && M_ptrC->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrC);
			InServiceMotorC.dequeue(M_ptrC);
			InServiceMotorC.frontpeek(M_ptrC);
		}
		while (!InServiceMotorD.isEmpty() && M_ptrD->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrD);
			InServiceMotorD.dequeue(M_ptrD);
			InServiceMotorD.frontpeek(M_ptrD);
		}
		Order* order;
		 
		Queue<Order*>* FRZ_NRM[8] = { &FrozenQueueA, &FrozenQueueB, &FrozenQueueC, &FrozenQueueD, &NormalQueueA, &NormalQueueB, &NormalQueueC, &NormalQueueD} ;
		PriorityQueue<Order*>* VIP[4] = { &VIPQueueA , &VIPQueueB, &VIPQueueC, &VIPQueueD} ;

		

		/*if(CurrentTimeStep > 1){

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
*/
		ExecuteEvents(CurrentTimeStep);


		//********************************DRAWING VIP ORDERS************************************

		for(int i = 0 ; i < 4 ; i++){

			if(VIP[i]->isEmpty())
				continue;

			Order* front;
			VIP[i]->frontpeek(front);
			
			do {

				if      (front->GetRegion()== A_REG && front->GetType()==TYPE_VIP)  VIPcounterA++;		//  A
				else if (front->GetRegion()== B_REG && front->GetType()==TYPE_VIP)  VIPcounterB++;		// 	B					
				else if (front->GetRegion()== C_REG && front->GetType()==TYPE_VIP)  VIPcounterC++;		//  C				
				else if (front->GetRegion()== D_REG && front->GetType()==TYPE_VIP)  VIPcounterD++;		// 	D	

				VIP[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					delete order;
					order = NULL;
				}

				else {
					order->SetWT(order->GetWT()+1);
					pGUI->AddOrderForDrawing(order);
					VIP[i]->enqueue(order);

				}

				VIP[i]->frontpeek(order);

			}while(order != front);
		
	
	}

		//********************************DRAWING Frozen & Normal ORDERS************************************


		for(int i = 0 ; i < 8 ; i++){
			
			if(FRZ_NRM[i]->isEmpty()) continue;

			Order* front;
			FRZ_NRM[i]->peekFront(front);

			do {

				if      (front->GetRegion()== A_REG && front->GetType()==TYPE_FROZ) FROZENcounterA++;		// A
				else if (front->GetRegion()== A_REG && front->GetType()==TYPE_NRM)  NORMALcounterA++;
				
				else if (front->GetRegion()== B_REG && front->GetType()==TYPE_FROZ) FROZENcounterB++;		// B
				else if (front->GetRegion()== B_REG && front->GetType()==TYPE_NRM)  NORMALcounterB++;		
				
				else if (front->GetRegion()== C_REG && front->GetType()==TYPE_FROZ) FROZENcounterC++;		// C
				else if (front->GetRegion()== C_REG && front->GetType()==TYPE_NRM)  NORMALcounterC++;		
				
				else if (front->GetRegion()== D_REG && front->GetType()==TYPE_FROZ) FROZENcounterD++;		// D
				else if (front->GetRegion()== D_REG && front->GetType()==TYPE_NRM)  NORMALcounterD++;		


				FRZ_NRM[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					delete order;
					order = NULL;
				}

				else {
					order->SetWT(order->GetWT() + 1);
					pGUI->AddOrderForDrawing(order);
					FRZ_NRM[i]->enqueue(order);
					if (order->GetType() == TYPE_NRM && order->GetWT() >= Test->getEventsNum()){
						//auto_promotion :
						VIPQueueA.enqueue(new Order(order->GetID(), TYPE_VIP, order->GetRegion(), order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
						delete order;
						}
						
					}

				FRZ_NRM[i]->peekFront(order);

			}while(order != front);
			
	}	

		pGUI->UpdateInterface();
		Test->PrintStatusBar(VIPcounterA,VIPcounterB,VIPcounterC,VIPcounterD,
							 FROZENcounterA,FROZENcounterB,FROZENcounterC,FROZENcounterD,
							 NORMALcounterA,NORMALcounterB,NORMALcounterC,NORMALcounterD);
		pGUI->waitForClick();
		CurrentTimeStep++;
		pGUI->ResetDrawingList();

	}
	Test->print(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD,FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD,NORMALcounterA,NORMALcounterB, NORMALcounterC, NORMALcounterD);
	delete Test ;
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

void Restaurant :: SetInitialNumOfMOTR(int Av ,int Af ,int An , int Bv ,int Bf ,int Bn , int Cv ,int Cf ,int Cn, int Dv ,int Df ,int Dn){

	ABCD_VFN_motorcycle[0]	= Av , 
	ABCD_VFN_motorcycle[1]	= Af , 
	ABCD_VFN_motorcycle[2]	= An , 
	ABCD_VFN_motorcycle[3]	= Bv , 
	ABCD_VFN_motorcycle[4]	= Bf , 
	ABCD_VFN_motorcycle[5]	= Bn , 
	ABCD_VFN_motorcycle[6]	= Cv , 
	ABCD_VFN_motorcycle[7]	= Cf , 
	ABCD_VFN_motorcycle[8]	= Cn , 
	ABCD_VFN_motorcycle[9]	= Av , 
	ABCD_VFN_motorcycle[10] = Af , 
	ABCD_VFN_motorcycle[11] = An ;
}

int Restaurant :: GetInitialNumOfMOTR(int i){

	return ABCD_VFN_motorcycle[i] ;
}

