#include "IO.h"
#include<ctime>
int Io::sum(int * x, int size){
	int sum = 0;
	for (int i = 0; i < size; i++) { sum += x[i]; }
	return sum;
}
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
	
	int sn, sf, sv, autolimit;
	Motorcycle*motornorm, *motorfroz, *motorvip;
	fileIN >> sn >> sf >> sv; //speed of each type of motorcycle

	//Number of motorcycles or each type for the 4 regions
	fileIN >> nM[0] >> fM[0] >> vM[0]; 
	fileIN >> nM[1] >> fM[1] >> vM[1];
	fileIN >> nM[2] >> fM[2] >> vM[2];
	fileIN >> nM[3] >> fM[3] >> vM[3];

	pRest->SetInitialNumOfMOTR(vM[0],fM[0],nM[0],vM[1],fM[1],nM[1],vM[2],fM[2],nM[2],vM[3],fM[3],nM[3]);

	fileIN >> autolimit;	//Auto-promotion time limit(the max time for order to stay in the waiting list)
	fileIN >> NmberEvent; //Number of expected lines coming after that(it corresponding to number of events
	pRest->SetAutoPromTime(abs(autolimit));
	
	for (int i = 0; i < abs(nM[0]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(nM[1]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(nM[2]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
	for (int i = 0; i < abs(nM[3]); i++) {motornorm = new Motorcycle(abs(sn), A_REG); pRest->AddMototrcycle(motornorm); motornorm = NULL;}
						
	for (int i = 0; i < abs(fM[0]); i++) { motorfroz = new Motorcycle(abs(sf), A_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(fM[1]); i++) { motorfroz = new Motorcycle(abs(sf), B_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(fM[2]); i++) { motorfroz = new Motorcycle(abs(sf), C_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
	for (int i = 0; i < abs(fM[3]); i++) { motorfroz = new Motorcycle(abs(sf), D_REG); pRest->AddMototrcycle(motorfroz); motorfroz = NULL;}
						
	for (int i = 0; i < abs(vM[0]); i++) { motorvip = new Motorcycle(abs(sv), A_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(vM[1]); i++) { motorvip = new Motorcycle(abs(sv), B_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(vM[2]); i++) { motorvip = new Motorcycle(abs(sv), C_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}
	for (int i = 0; i < abs(vM[3]); i++) { motorvip = new Motorcycle(abs(sv), D_REG); pRest->AddMototrcycle(motorvip); motorvip = NULL;}

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

void Io::print(int VIPOA, int VIPOB, int VIPOC, int VIPOD, int FrozOA, int FrozOB, int FrozOC, int FrozOD, int NormOA, int NormOB, int NormOC, int NormOD){
	nO[0] = NormOA;	nO[1] = NormOB;	nO[2] = NormOC;	nO[3] = NormOD;
	fO[0] = FrozOA;	fO[1] = FrozOB;	fO[2] = FrozOC;	fO[3] = FrozOD;
	vO[0] = VIPOA;	vO[1] = VIPOB;	vO[2] = VIPOC;	vO[3] = VIPOD;
	srand(time(0));
	int x = rand()%101;
	fileOUT.open("OutputFile"+to_string(x)+".txt");
	fileOUT << "FT ID AT WT ST" << endl;
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			fileOUT << "Region A:" << endl;
			break;
		case 1:
			fileOUT << "Region B:" << endl;
			break;
		case 2:
			fileOUT << "Region C:" << endl;
			break;
		case 3:
			fileOUT << "Region D:" << endl;
			break;
		}
		fileOUT << "Orders: " << (nO[i] + fO[i] + vO[i]) << " " << "[Norm:" << nO[i] << ", Froz:" << fO[i] << ", VIP:" << vO[i] << "]" << endl;
		fileOUT << "MotorC: " << (nM[i] + fM[i] + vM[i]) << " " << "[Norm:" << nM[i] << ", Froz:" << fM[i] << ", VIP:" << vM[i] << "]" << endl;
		fileOUT << "Avg Wait = 111" << ", Avg Serv = 111" << endl; // this will be modified
	}
	int totalNormal = sum(nO, 4), totalFrozen = sum(fO, 4), totalVIP = sum(vO, 4);
	int totalNMotor = sum(nM, 4), totalFMototr = sum(fM, 4), totalVMototr = sum(vM, 4);
	fileOUT << "For Whole Resturant:" << endl;
	fileOUT<<"Orders: "<<(totalNormal+totalFrozen+totalVIP)<<" "<< "[Norm:" << totalNormal << ", Froz:" << totalFrozen << ", VIP:" << totalVIP << "]" << endl;
	fileOUT<< "MotorC: " << (totalFMototr+totalNMotor+totalVMototr) << " " << "[Norm:" << totalNMotor << ", Froz:" << totalFMototr << ", VIP:" << totalVMototr << "]" << endl;
	fileOUT << "Avg Wait = 111" << ", Avg Serv = 111"; // this will be modified
	fileOUT.close();
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
