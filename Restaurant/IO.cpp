#include "IO.h"

Io::Io(Restaurant * pR, GUI * pG):pRest(pR),pGUI(pG){}

void Io::load(){
	pGUI->PrintMessage("Enter file name:");
	FileName = pGUI->GetString();
	fileIN.open(FileName + ".txt");
	while (!fileIN.is_open()) {
		pGUI->PrintMessage("cannot open file!, please reEnter the file name correctly");
		FileName = pGUI->GetString();
		fileIN.open(FileName + ".txt");
	}
	
	int sn, sf, sv, n[4], f[4], v[4],autolimit;
	Motorcycle*motornorm, *motorfroz, *motorvip;
	fileIN >> sn >> sf >> sv; //speed of each type of motorcycle

	//Number of motorcycles or each type for the 4 regions
	fileIN >> n[0] >> f[0] >> v[0]; 
	fileIN >> n[1] >> f[1] >> v[1];
	fileIN >> n[2] >> f[2] >> v[2];
	fileIN >> n[3] >> f[3] >> v[3];

	pRest->SetInitialNumOfMOTR(v[0],f[0],n[0],v[1],f[1],n[1],v[2],f[2],n[2],v[3],f[3],n[3]);

	fileIN >> autolimit;	//Auto-promotion time limit(the max time for order to stay in the waiting list)
	fileIN >> NmberEvent; //Number of expected lines coming after that(it corresponding to number of events
	pRest->SetAutoPromTime(abs(autolimit));
	
	for (int i = 0; i < abs(n[0]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(n[1]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(n[2]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(n[3]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
						
	for (int i = 0; i < abs(f[0]); i++) { motorfroz = new Motorcycle(abs(sf), A_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(f[1]); i++) { motorfroz = new Motorcycle(abs(sf), B_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(f[2]); i++) { motorfroz = new Motorcycle(abs(sf), C_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(f[3]); i++) { motorfroz = new Motorcycle(abs(sf), D_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
						
	for (int i = 0; i < abs(v[0]); i++) { motorvip = new Motorcycle(abs(sv), A_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(v[1]); i++) { motorvip = new Motorcycle(abs(sv), B_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(v[2]); i++) { motorvip = new Motorcycle(abs(sv), C_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(v[3]); i++) { motorvip = new Motorcycle(abs(sv), D_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}

	Event* pArrive;		CancelationEvent* pCancel;		PromotionEvent* pPromote;
	
	for (int m = 0; m < abs(NmberEvent); m++) {
		
		char EventDecide;
		
		fileIN >> EventDecide;
		
		if (toupper(EventDecide) == 'R') {
			
			int ts, id, dist;	double money;	char type, region;
			
			fileIN >> ts >> type >> id >> dist >> money >> region;
			
			if (toupper(type) == 'N' && toupper(region) == 'A') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_NRM, A_REG, abs(money));
			else if (toupper(type) == 'N' && toupper(region) == 'B') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_NRM, B_REG, abs(money));
			else if (toupper(type) == 'N' && toupper(region) == 'C') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_NRM, C_REG, abs(money));
			else if (toupper(type) == 'N' && toupper(region) == 'D') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_NRM, D_REG, abs(money));
					 																					 
			else if (toupper(type) == 'F' && toupper(region) == 'A') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_FROZ, A_REG, abs(money));
			else if (toupper(type) == 'F' && toupper(region) == 'B') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_FROZ, B_REG, abs(money));
			else if (toupper(type) == 'F' && toupper(region) == 'C') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_FROZ, C_REG, abs(money));
			else if (toupper(type) == 'F' && toupper(region) == 'D') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_FROZ, D_REG, abs(money));
					 						 															 
			else if (toupper(type) == 'V' && toupper(region) == 'A') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_VIP, A_REG, abs(money));
			else if (toupper(type) == 'V' && toupper(region) == 'B') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_VIP, B_REG, abs(money));
			else if (toupper(type) == 'V' && toupper(region) == 'C') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_VIP, C_REG, abs(money));
			else if (toupper(type) == 'V' && toupper(region) == 'D') pArrive = new ArrivalEvent(abs(ts), abs(id), TYPE_VIP, D_REG, abs(money));
														   
			pRest->AddEvent(pArrive);

		}
		else if (toupper(EventDecide) == 'X') {
			int ts, id;
			fileIN >> ts >> id;
			pCancel = new CancelationEvent(abs(ts), abs(id));
			pRest->AddEvent(pCancel);
		}
		else if (toupper(EventDecide) == 'P') {
			int ts, id; double exMoney;
			fileIN >> ts >> id >> exMoney;
			pPromote = new PromotionEvent(abs(ts), abs(id), abs(exMoney));
			pRest->AddEvent(pPromote);
		}
	}
	//fileIN.close();
}

void Io::print(){
	//this function will print the final results in the file format given, but needed in phase2 only
}

void Io::PrintStatusBar(int vA ,int vB ,int vC ,int vD , int fA ,int fB ,int fC ,int fD,int nA ,int nB ,int nC ,int nD )
{
	pGUI->PrintMessage("Region A -> VIP orders: "+to_string(vA) +", Frozen orders: "+to_string(fA) +", Normal orders: "+to_string(nA)+", VIP motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(0))+", Frozen motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(1))+", NORMALmotorcycles: "+to_string(pRest->GetInitialNumOfMOTR(2))   )  ;
	pGUI->PrintMessage2("Region B -> VIP orders: "+to_string(vB) +", Frozen orders: "+to_string(fB) +", Normal orders: "+to_string(nB)+", VIP motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(3))+", Frozen motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(4))+", NORMALmotorcycles: "+to_string(pRest->GetInitialNumOfMOTR(5))   )  ;
	pGUI->PrintMessage3("Region C -> VIP orders: "+to_string(vC) +", Frozen orders: "+to_string(fC) +", Normal orders: "+to_string(nC)+", VIP motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(6))+", Frozen motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(7))+", NORMALmotorcycles: "+to_string(pRest->GetInitialNumOfMOTR(8))   )  ;
	pGUI->PrintMessage4("Region D -> VIP orders: "+to_string(vD) +", Frozen orders: "+to_string(fD) +", Normal orders: "+to_string(nD)+", VIP motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(9))+", Frozen motorcycles: "+to_string(pRest->GetInitialNumOfMOTR(10))+", NORMALmotorcycles: "+to_string(pRest->GetInitialNumOfMOTR(11)) )  ;	

}

int Io::getEventsNum(){
	return NmberEvent;
}


Io::~Io(){}
