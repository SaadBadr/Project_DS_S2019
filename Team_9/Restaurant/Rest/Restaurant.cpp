#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
using namespace std;




bool Restaurant::assign(Order * ord, int timestep){
	Motorcycle* M_ptr = NULL;
	//Modifying Motor Numbers
	if (ord->GetRegion() == A_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorA.isEmpty()) {
				NormalMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[2]--;
			}
			else if (!VIPMotorA.isEmpty()) {
				VIPMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[0]--;
			}
			else
				return false;
		}
		else if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorA.isEmpty()) {
				FrozenMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[1]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorA.isEmpty()) {
				VIPMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[0]--;
			}
			else if (!NormalMotorA.isEmpty()) {
				NormalMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[2]--;
			}
			else if (!FrozenMotorA.isEmpty()) {
				FrozenMotorA.dequeue(M_ptr);
				ABCD_VFN_motorcycle[1]--;
			}
			else
				return false;
		}
		M_ptr->setID(ord->GetID());
		M_ptr->setStatus(SERV);
		ord->SetST(ceil((float)ord->GetDistance() / (M_ptr->GetSpeed())));
		ord->SetFT(ord->GetWT() + ord->GetArrTime() + ord->GetServTime());
		M_ptr->SetReturnTime(ord->GetServTime() + ord->GetFinishTime());
		InServiceMotorA.enqueue(M_ptr);
	}
	else if (ord->GetRegion() == B_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorB.isEmpty()) {
				NormalMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[5]--;
			}
			else if (!VIPMotorB.isEmpty()) {
				VIPMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[3]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorB.isEmpty()) {
				FrozenMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[4]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorB.isEmpty()) {
				VIPMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[3]--;
			}
			else if (!NormalMotorB.isEmpty()) {
				NormalMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[5]--;
			}
			else if (!FrozenMotorB.isEmpty()) {
				FrozenMotorB.dequeue(M_ptr);
				ABCD_VFN_motorcycle[4]--;
			}
			else
				return false;
		}
		M_ptr->setID(ord->GetID());
		M_ptr->setStatus(SERV);
		ord->SetST(ceil((float)ord->GetDistance() / (M_ptr->GetSpeed())));
		ord->SetFT(ord->GetWT() + ord->GetArrTime() + ord->GetServTime());
		M_ptr->SetReturnTime(ord->GetServTime() + ord->GetFinishTime());
		InServiceMotorB.enqueue(M_ptr);
	}
	else if (ord->GetRegion() == C_REG)
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorC.isEmpty()) {
				NormalMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[8]--;
			}
			else if (!VIPMotorC.isEmpty()) {
				VIPMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[6]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorC.isEmpty()) {
				FrozenMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[7]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorC.isEmpty()) {
				VIPMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[6]--;
			}
			else if (!NormalMotorC.isEmpty()) {
				NormalMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[8]--;
			}
			else if (!FrozenMotorC.isEmpty()) {
				FrozenMotorC.dequeue(M_ptr);
				ABCD_VFN_motorcycle[7]--;
			}
			else
				return false;
		}
		M_ptr->setID(ord->GetID());
		M_ptr->setStatus(SERV);
		ord->SetST(ceil((float)ord->GetDistance() / (M_ptr->GetSpeed())));
		ord->SetFT(ord->GetWT() + ord->GetArrTime() + ord->GetServTime());
		M_ptr->SetReturnTime(ord->GetServTime() + ord->GetFinishTime());
		InServiceMotorC.enqueue(M_ptr);
	}
	else
	{
		if (ord->GetType() == TYPE_NRM)
		{
			if (!NormalMotorD.isEmpty()) {
				NormalMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[11]--;
			}
			else if (!VIPMotorD.isEmpty()) {
				VIPMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[9]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_FROZ) {
			if (!FrozenMotorD.isEmpty()) {
				FrozenMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[10]--;
			}
			else
				return false;

		}
		else if (ord->GetType() == TYPE_VIP) {
			if (!VIPMotorD.isEmpty()) {
				VIPMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[9]--;
			}
			else if (!NormalMotorD.isEmpty()) {
				NormalMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[11]--;
			}
			else if (!FrozenMotorD.isEmpty()) {
				FrozenMotorD.dequeue(M_ptr);
				ABCD_VFN_motorcycle[10]--;
			}
			else
				return false;
		}
		M_ptr->setID(ord->GetID());
		M_ptr->setStatus(SERV);
		ord->SetST(ceil((float)ord->GetDistance() / (M_ptr->GetSpeed())));
		ord->SetFT(ord->GetWT() + ord->GetArrTime() + ord->GetServTime());
		M_ptr->SetReturnTime(ord->GetServTime() + ord->GetFinishTime());
		InServiceMotorD.enqueue(M_ptr);
	}
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
		StepByStepMode();
		break;
	case MODE_SLNT:
		SilentMode();
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




Restaurant::~Restaurant(){
	Order* x;	Motorcycle* y;
	AllOrders.clear();
	while (!NormalQueueA.isEmpty()){
		NormalQueueA.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!NormalQueueB.isEmpty()) {
		NormalQueueB.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!NormalQueueC.isEmpty()) {
		NormalQueueC.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!NormalQueueD.isEmpty()) {
		NormalQueueD.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!FrozenQueueA.isEmpty()) {
		FrozenQueueA.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!FrozenQueueB.isEmpty()) {
		FrozenQueueB.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!FrozenQueueC.isEmpty()) {
		FrozenQueueC.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!FrozenQueueD.isEmpty()) {
		FrozenQueueD.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!VIPQueueA.isEmpty()) {
		VIPQueueA.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!VIPQueueB.isEmpty()) {
		VIPQueueB.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!VIPQueueC.isEmpty()) {
		VIPQueueC.dequeue(x);
		delete x;
		x = NULL;
	}
	while (!VIPQueueD.isEmpty()) {
		VIPQueueD.dequeue(x);
		delete x;
		x = NULL;
	}
	// freeing motorcycle's queues
	while (!NormalMotorA.isEmpty()) {
		NormalMotorA.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!NormalMotorB.isEmpty()) {
		NormalMotorB.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!NormalMotorC.isEmpty()) {
		NormalMotorC.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!NormalMotorD.isEmpty()) {
		NormalMotorD.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!FrozenMotorA.isEmpty()) {
		FrozenMotorA.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!FrozenMotorB.isEmpty()) {
		FrozenMotorB.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!FrozenMotorC.isEmpty()) {
		FrozenMotorC.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!FrozenMotorD.isEmpty()) {
		FrozenMotorD.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!VIPMotorA.isEmpty()) {
		VIPMotorA.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!VIPMotorB.isEmpty()) {
		VIPMotorB.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!VIPMotorC.isEmpty()) {
		VIPMotorC.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!VIPMotorD.isEmpty()) {
		VIPMotorD.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!InServiceMotorA.isEmpty()) {
		InServiceMotorA.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!InServiceMotorB.isEmpty()) {
		InServiceMotorB.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!InServiceMotorC.isEmpty()) {
		InServiceMotorC.dequeue(y);
		delete y;
		y = NULL;
	}
	while (!InServiceMotorD.isEmpty()) {
		InServiceMotorD.dequeue(y);
		delete y;
		y = NULL;
	}
	delete pGUI;
}





// *************************************************ADDING TO ORDERS QUEUES*************************************************

//// ADD TO NORMAL QUEUES


void Restaurant::InteractiveMode() {
	int CurrentTimeStep = 1;
	int Listcount = 1;

	VIPcounterA = 0, VIPcounterB = 0, VIPcounterC = 0, VIPcounterD = 0,	
	FROZENcounterA = 0, FROZENcounterB = 0, FROZENcounterC = 0, FROZENcounterD = 0,		
	NORMALcounterA = 0, NORMALcounterB = 0, NORMALcounterC = 0, NORMALcounterD = 0;

	Io* Test = new Io(this, pGUI);

	pGUI->PrintMessage("Welcome To interactive mode,click to continue");

	pGUI->waitForClick();

	Test->load();


	while (!EventsQueue.isEmpty()) {

		Motorcycle* M_ptrA, *M_ptrB, *M_ptrC, *M_ptrD;
		InServiceMotorA.frontpeek(M_ptrA);
		InServiceMotorB.frontpeek(M_ptrB);
		InServiceMotorC.frontpeek(M_ptrC);
		InServiceMotorD.frontpeek(M_ptrD);
		while (!InServiceMotorA.isEmpty() && M_ptrA->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrA,true);
			InServiceMotorA.dequeue(M_ptrA);
			InServiceMotorA.frontpeek(M_ptrA);
		}
		while (!InServiceMotorB.isEmpty() && M_ptrB->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrB, true);
			InServiceMotorB.dequeue(M_ptrB);
			InServiceMotorB.frontpeek(M_ptrB);
		}
		while (!InServiceMotorC.isEmpty() && M_ptrC->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrC, true);
			InServiceMotorC.dequeue(M_ptrC);
			InServiceMotorC.frontpeek(M_ptrC);
		}
		while (!InServiceMotorD.isEmpty() && M_ptrD->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrD, true);
			InServiceMotorD.dequeue(M_ptrD);
			InServiceMotorD.frontpeek(M_ptrD);
		}
		Order* order;

		Queue<Order*>* FRZ_NRM[8] = { &FrozenQueueA, &FrozenQueueB, &FrozenQueueC, &FrozenQueueD, &NormalQueueA, &NormalQueueB, &NormalQueueC, &NormalQueueD };
		PriorityQueue<Order*>* VIP[4] = { &VIPQueueA , &VIPQueueB, &VIPQueueC, &VIPQueueD };



		ExecuteEvents(CurrentTimeStep);


		//********************************DRAWING VIP ORDERS************************************

		for (int i = 0; i < 4; i++) {

			if (VIP[i]->isEmpty())
				continue;

			Order* front;
			VIP[i]->frontpeek(front);

			do {

				if (front->GetRegion() == A_REG)  VIPcounterA++;		//  A
				else if (front->GetRegion() == B_REG)  VIPcounterB++;		// 	B
				else if (front->GetRegion() == C_REG)  VIPcounterC++;		//  C				
				else if (front->GetRegion() == D_REG)  VIPcounterD++;		// 	D	

				VIP[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						VIP[i]->frontpeek(front);
					}
					delete order;
					order = NULL;
					continue;

				}

				else {
					order->SetWT(order->GetWT() + 1);
					pGUI->AddOrderForDrawing(order);
					VIP[i]->enqueue(order);
				}

				VIP[i]->frontpeek(order);

			} while (!VIP[i]->isEmpty() && order != front);


		}

		//********************************DRAWING Frozen & Normal ORDERS************************************


		for (int i = 0; i < 8; i++) {

			if (FRZ_NRM[i]->isEmpty()) continue;

			Order* front;
			FRZ_NRM[i]->peekFront(front);
			do {


				if (front->GetRegion() == A_REG && front->GetType() == TYPE_FROZ) FROZENcounterA++;		// A
				else if (front->GetRegion() == A_REG && front->GetType() == TYPE_NRM)  NORMALcounterA++;

				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_FROZ) FROZENcounterB++;		// B
				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_NRM)  NORMALcounterB++;

				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_FROZ) FROZENcounterC++;		// C
				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_NRM)  NORMALcounterC++;

				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_FROZ) FROZENcounterD++;		// D
				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_NRM)  NORMALcounterD++;

				FRZ_NRM[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						FRZ_NRM[i]->peekFront(front);
					}
					delete order;
					order = NULL;
					continue;
				}

				else {
					order->SetWT(order->GetWT() + 1);
					pGUI->AddOrderForDrawing(order);
					FRZ_NRM[i]->enqueue(order);
					if (order->GetType() == TYPE_NRM && order->GetWT() >= AutoPromotionTimeLimit) {
						//auto_promotion :
						if (order->GetRegion() == A_REG) {
							VIPQueueA.enqueue(new Order(order->GetID(), TYPE_VIP, A_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else if (order->GetRegion() == B_REG) {
							VIPQueueB.enqueue(new Order(order->GetID(), TYPE_VIP, B_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							
							delete order;
						}
						else if (order->GetRegion() == C_REG) {
							VIPQueueC.enqueue(new Order(order->GetID(), TYPE_VIP, C_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else {
							VIPQueueD.enqueue(new Order(order->GetID(), TYPE_VIP, D_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
					}
				}
				FRZ_NRM[i]->peekFront(order);
			} while (!FRZ_NRM[i]->isEmpty() && order != front);

		}

		pGUI->UpdateInterface();
		Test->PrintStatusBar(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD,
			ABCD_VFN_motorcycle[0], ABCD_VFN_motorcycle[1], ABCD_VFN_motorcycle[2],
			ABCD_VFN_motorcycle[3], ABCD_VFN_motorcycle[4], ABCD_VFN_motorcycle[5],
			ABCD_VFN_motorcycle[6], ABCD_VFN_motorcycle[7], ABCD_VFN_motorcycle[8],
			ABCD_VFN_motorcycle[9], ABCD_VFN_motorcycle[10], ABCD_VFN_motorcycle[11]);
		pGUI->waitForClick();
		CurrentTimeStep++;
		pGUI->ResetDrawingList();
	}
	SortAllOrders(AllOrders);
	Test->print(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD);
	delete Test;
}

void Restaurant::StepByStepMode() {
	int CurrentTimeStep = 1;
	int Listcount = 1;

		VIPcounterA = 0, VIPcounterB = 0, VIPcounterC = 0, VIPcounterD = 0,
		FROZENcounterA = 0, FROZENcounterB = 0, FROZENcounterC = 0, FROZENcounterD = 0,
		NORMALcounterA = 0, NORMALcounterB = 0, NORMALcounterC = 0, NORMALcounterD = 0;

	Io* Test = new Io(this, pGUI);

	pGUI->PrintMessage("Welcome To StepByStep mode,click to continue");

	pGUI->waitForClick();

	Test->load();


	while (!EventsQueue.isEmpty()) {

		Motorcycle* M_ptrA, *M_ptrB, *M_ptrC, *M_ptrD;
		InServiceMotorA.frontpeek(M_ptrA);
		InServiceMotorB.frontpeek(M_ptrB);
		InServiceMotorC.frontpeek(M_ptrC);
		InServiceMotorD.frontpeek(M_ptrD);
		while (!InServiceMotorA.isEmpty() && M_ptrA->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrA, true);
			InServiceMotorA.dequeue(M_ptrA);
			InServiceMotorA.frontpeek(M_ptrA);
		}
		while (!InServiceMotorB.isEmpty() && M_ptrB->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrB, true);
			InServiceMotorB.dequeue(M_ptrB);
			InServiceMotorB.frontpeek(M_ptrB);
		}
		while (!InServiceMotorC.isEmpty() && M_ptrC->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrC, true);
			InServiceMotorC.dequeue(M_ptrC);
			InServiceMotorC.frontpeek(M_ptrC);
		}
		while (!InServiceMotorD.isEmpty() && M_ptrD->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrD, true);
			InServiceMotorD.dequeue(M_ptrD);
			InServiceMotorD.frontpeek(M_ptrD);
		}
		Order* order;

		Queue<Order*>* FRZ_NRM[8] = { &FrozenQueueA, &FrozenQueueB, &FrozenQueueC, &FrozenQueueD, &NormalQueueA, &NormalQueueB, &NormalQueueC, &NormalQueueD };
		PriorityQueue<Order*>* VIP[4] = { &VIPQueueA , &VIPQueueB, &VIPQueueC, &VIPQueueD };



		ExecuteEvents(CurrentTimeStep);


		//********************************DRAWING VIP ORDERS************************************

		for (int i = 0; i < 4; i++) {

			if (VIP[i]->isEmpty())
				continue;

			Order* front;
			VIP[i]->frontpeek(front);

			do {

				if (front->GetRegion() == A_REG)  VIPcounterA++;		//  A
				else if (front->GetRegion() == B_REG)  VIPcounterB++;		// 	B
				else if (front->GetRegion() == C_REG)  VIPcounterC++;		//  C				
				else if (front->GetRegion() == D_REG)  VIPcounterD++;		// 	D	

				VIP[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						VIP[i]->frontpeek(front);
					}
					delete order;
					order = NULL;
					continue;

				}

				else {
					order->SetWT(order->GetWT() + 1);
					pGUI->AddOrderForDrawing(order);
					VIP[i]->enqueue(order);
				}

				VIP[i]->frontpeek(order);

			} while (!VIP[i]->isEmpty() && order != front);


		}

		//********************************DRAWING Frozen & Normal ORDERS************************************


		for (int i = 0; i < 8; i++) {

			if (FRZ_NRM[i]->isEmpty()) continue;

			Order* front;
			FRZ_NRM[i]->peekFront(front);
			do {


				if (front->GetRegion() == A_REG && front->GetType() == TYPE_FROZ) FROZENcounterA++;		// A
				else if (front->GetRegion() == A_REG && front->GetType() == TYPE_NRM)  NORMALcounterA++;

				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_FROZ) FROZENcounterB++;		// B
				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_NRM)  NORMALcounterB++;

				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_FROZ) FROZENcounterC++;		// C
				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_NRM)  NORMALcounterC++;

				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_FROZ) FROZENcounterD++;		// D
				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_NRM)  NORMALcounterD++;

				FRZ_NRM[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						FRZ_NRM[i]->peekFront(front);
					}
					delete order;
					order = NULL;
					continue;
				}

				else {
					order->SetWT(order->GetWT() + 1);
					pGUI->AddOrderForDrawing(order);
					FRZ_NRM[i]->enqueue(order);
					if (order->GetType() == TYPE_NRM && order->GetWT() >= AutoPromotionTimeLimit) {
						//auto_promotion :
						if (order->GetRegion() == A_REG) {
							VIPQueueA.enqueue(new Order(order->GetID(), TYPE_VIP, A_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else if (order->GetRegion() == B_REG) {
							VIPQueueB.enqueue(new Order(order->GetID(), TYPE_VIP, B_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else if (order->GetRegion() == C_REG) {
							VIPQueueC.enqueue(new Order(order->GetID(), TYPE_VIP, C_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else {
							VIPQueueD.enqueue(new Order(order->GetID(), TYPE_VIP, D_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
					}
				}
				FRZ_NRM[i]->peekFront(order);
			} while (!FRZ_NRM[i]->isEmpty() && order != front);

		}

		pGUI->UpdateInterface();
		Test->PrintStatusBar(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD,
			ABCD_VFN_motorcycle[0], ABCD_VFN_motorcycle[1], ABCD_VFN_motorcycle[2],
			ABCD_VFN_motorcycle[3], ABCD_VFN_motorcycle[4], ABCD_VFN_motorcycle[5],
			ABCD_VFN_motorcycle[6], ABCD_VFN_motorcycle[7], ABCD_VFN_motorcycle[8],
			ABCD_VFN_motorcycle[9], ABCD_VFN_motorcycle[10], ABCD_VFN_motorcycle[11]);
		
		Sleep(1000);

		CurrentTimeStep++;
		pGUI->ResetDrawingList();
	}
	SortAllOrders(AllOrders);
	Test->print(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD);
	delete Test;
}

void Restaurant::SilentMode() {
	int CurrentTimeStep = 1;
	int Listcount = 1;

		VIPcounterA = 0, VIPcounterB = 0, VIPcounterC = 0, VIPcounterD = 0,
		FROZENcounterA = 0, FROZENcounterB = 0, FROZENcounterC = 0, FROZENcounterD = 0,
		NORMALcounterA = 0, NORMALcounterB = 0, NORMALcounterC = 0, NORMALcounterD = 0;

	Io* Test = new Io(this, pGUI);

	pGUI->PrintMessage("Welcome To Silent mode,click to continue");

	pGUI->waitForClick();

	Test->load();


	while (!EventsQueue.isEmpty()) {

		Motorcycle* M_ptrA, *M_ptrB, *M_ptrC, *M_ptrD;
		InServiceMotorA.frontpeek(M_ptrA);
		InServiceMotorB.frontpeek(M_ptrB);
		InServiceMotorC.frontpeek(M_ptrC);
		InServiceMotorD.frontpeek(M_ptrD);
		while (!InServiceMotorA.isEmpty() && M_ptrA->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrA, true);
			InServiceMotorA.dequeue(M_ptrA);
			InServiceMotorA.frontpeek(M_ptrA);
		}
		while (!InServiceMotorB.isEmpty() && M_ptrB->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrB , true);
			InServiceMotorB.dequeue(M_ptrB);
			InServiceMotorB.frontpeek(M_ptrB);
		}
		while (!InServiceMotorC.isEmpty() && M_ptrC->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrC, true);
			InServiceMotorC.dequeue(M_ptrC);
			InServiceMotorC.frontpeek(M_ptrC);
		}
		while (!InServiceMotorD.isEmpty() && M_ptrD->getRT() <= CurrentTimeStep) {
			AddMototrcycle(M_ptrD, true);
			InServiceMotorD.dequeue(M_ptrD);
			InServiceMotorD.frontpeek(M_ptrD);
		}
		Order* order;

		Queue<Order*>* FRZ_NRM[8] = { &FrozenQueueA, &FrozenQueueB, &FrozenQueueC, &FrozenQueueD, &NormalQueueA, &NormalQueueB, &NormalQueueC, &NormalQueueD };
		PriorityQueue<Order*>* VIP[4] = { &VIPQueueA , &VIPQueueB, &VIPQueueC, &VIPQueueD };



		ExecuteEvents(CurrentTimeStep);


		//********************************DRAWING VIP ORDERS************************************

		for (int i = 0; i < 4; i++) {

			if (VIP[i]->isEmpty())
				continue;

			Order* front;
			VIP[i]->frontpeek(front);

			do {

				if (front->GetRegion() == A_REG)  VIPcounterA++;		//  A
				else if (front->GetRegion() == B_REG)  VIPcounterB++;		// 	B
				else if (front->GetRegion() == C_REG)  VIPcounterC++;		//  C				
				else if (front->GetRegion() == D_REG)  VIPcounterD++;		// 	D	

				VIP[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						VIP[i]->frontpeek(front);
					}
					delete order;
					order = NULL;
					continue;

				}

				else {
					order->SetWT(order->GetWT() + 1);
					//pGUI->AddOrderForDrawing(order);
					VIP[i]->enqueue(order);
				}

				VIP[i]->frontpeek(order);

			} while (!VIP[i]->isEmpty() && order != front);


		}

		//********************************DRAWING Frozen & Normal ORDERS************************************


		for (int i = 0; i < 8; i++) {

			if (FRZ_NRM[i]->isEmpty()) continue;

			Order* front;
			FRZ_NRM[i]->peekFront(front);
			do {


				if (front->GetRegion() == A_REG && front->GetType() == TYPE_FROZ) FROZENcounterA++;		// A
				else if (front->GetRegion() == A_REG && front->GetType() == TYPE_NRM)  NORMALcounterA++;

				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_FROZ) FROZENcounterB++;		// B
				else if (front->GetRegion() == B_REG && front->GetType() == TYPE_NRM)  NORMALcounterB++;

				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_FROZ) FROZENcounterC++;		// C
				else if (front->GetRegion() == C_REG && front->GetType() == TYPE_NRM)  NORMALcounterC++;

				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_FROZ) FROZENcounterD++;		// D
				else if (front->GetRegion() == D_REG && front->GetType() == TYPE_NRM)  NORMALcounterD++;

				FRZ_NRM[i]->dequeue(order);

				if (assign(order, CurrentTimeStep)) {
					AllOrders.Insert(*(order), Listcount);
					Listcount++;
					if (order == front) {
						FRZ_NRM[i]->peekFront(front);
					}
					delete order;
					order = NULL;
					continue;
				}

				else {
					order->SetWT(order->GetWT() + 1);
					//pGUI->AddOrderForDrawing(order);
					FRZ_NRM[i]->enqueue(order);
					if (order->GetType() == TYPE_NRM && order->GetWT() >= AutoPromotionTimeLimit) {
						//auto_promotion :
						if (order->GetRegion() == A_REG) {
							VIPQueueA.enqueue(new Order(order->GetID(), TYPE_VIP, A_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else if (order->GetRegion() == B_REG) {
							VIPQueueB.enqueue(new Order(order->GetID(), TYPE_VIP, B_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else if (order->GetRegion() == C_REG) {
							VIPQueueC.enqueue(new Order(order->GetID(), TYPE_VIP, C_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
						else {
							VIPQueueD.enqueue(new Order(order->GetID(), TYPE_VIP, D_REG, order->GetMoney(), order->GetDistance(), order->GetArrTime(), order->GetWT()));
							
							delete order;
						}
					}
				}
				FRZ_NRM[i]->peekFront(order);
			} while (!FRZ_NRM[i]->isEmpty() && order != front);

		}

		//pGUI->UpdateInterface();
	/*	Test->PrintStatusBar(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD,
			ABCD_VFN_motorcycle[0], ABCD_VFN_motorcycle[1], ABCD_VFN_motorcycle[2],
			ABCD_VFN_motorcycle[3], ABCD_VFN_motorcycle[4], ABCD_VFN_motorcycle[5],
			ABCD_VFN_motorcycle[6], ABCD_VFN_motorcycle[7], ABCD_VFN_motorcycle[8],
			ABCD_VFN_motorcycle[9], ABCD_VFN_motorcycle[10], ABCD_VFN_motorcycle[11]);
		pGUI->waitForClick();
		*/
		CurrentTimeStep++;
		//pGUI->ResetDrawingList();
	}
	SortAllOrders(AllOrders);
	Test->print(VIPcounterA, VIPcounterB, VIPcounterC, VIPcounterD, FROZENcounterA, FROZENcounterB, FROZENcounterC, FROZENcounterD, NORMALcounterA, NORMALcounterB, NORMALcounterC, NORMALcounterD);
	delete Test;
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

void Restaurant::AddMototrcycle(Motorcycle * po, bool increment){
	switch (po->GetRegion())
	{
	case A_REG:
		switch (po->GetType())
		{
		case TYPE_NRM:
			NormalMotorA.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[2]++;
			break;
		case TYPE_VIP:
			VIPMotorA.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[0]++;
			break;
		case TYPE_FROZ:
			FrozenMotorA.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[1]++;
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
			if (increment) ABCD_VFN_motorcycle[5]++;
			break;
		case TYPE_VIP:
			VIPMotorB.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[3]++;
			break;
		case TYPE_FROZ:
			FrozenMotorB.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[4]++;
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
			if (increment) ABCD_VFN_motorcycle[8]++;
			break;
		case TYPE_VIP:
			VIPMotorC.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[6]++;
			break;
		case TYPE_FROZ:
			FrozenMotorC.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[7]++;
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
			if (increment) ABCD_VFN_motorcycle[11]++;
			break;
		case TYPE_VIP:
			VIPMotorD.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[9]++;
			break;
		case TYPE_FROZ:
			FrozenMotorD.enqueue(po);
			if (increment) ABCD_VFN_motorcycle[10]++;
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
	ABCD_VFN_motorcycle[9]	= Dv , 
	ABCD_VFN_motorcycle[10] = Df , 
	ABCD_VFN_motorcycle[11] = Dn ;
}

void Restaurant::SortAllOrders(List<Order>& list){
	int size = list.getLength();
	Order t1 ,t2 ;
	for (int i = 1; i < size; i++) {
		list.GetItmeAt(i,t1);
		for (int j = i+1; j <= size; j++) {
			list.GetItmeAt(j,t2);
			if (t1.GetFinishTime() > t2.GetFinishTime()) {
				list.replace(t1, j);
				list.replace(t2, i);
			}
			else if (t1.GetFinishTime() == t2.GetFinishTime()) {
				if (t1.GetServTime() > t2.GetServTime()) {
					list.replace(t1, j);
					list.replace(t2, i);
				}
			}
		}
	}
}

Order Restaurant::GetListFisrtItem(){
	if (AllOrders.getLength() > 0) {
		Order  x; 
		if (AllOrders.GetItmeAt(1, x)) {
			AllOrders.remove(1);
			return x;
		}
	}
	else {
		Order x(0, TYPE_NRM, A_REG);
		return x;
	}
}

int Restaurant :: GetInitialNumOfMOTR(int i){

	return ABCD_VFN_motorcycle[i] ;
}

