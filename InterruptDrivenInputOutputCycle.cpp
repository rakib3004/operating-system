#include<bits/stdc++.h>
using namespace std;
void CPU();



// Input Output Controller Section !!!!!!!!!!!!

void initiateIO(){
cout<<"---------------------------"<<endl;
cout<<"1.1 Initiate I/O"<<endl;
cout<<"---------------------------"<<endl;

}

void getInterruptSignals(){
cout<<"---------------------------"<<endl;
cout<<"1.2 Get Interrupt Signals"<<endl;
cout<<"   3 Basic Interrupt Signals: \n\n";
cout<<"i.Input Signal (which is ready)\n";
cout<<"ii.Output Signal (which is complete)\n";
cout<<"iii.Error Signal (which is generate)\n";
cout<<"---------------------------"<<endl;


}

void InputOutputController(){

printf("---------------------------------\n");
printf("======== I/O Controller ==========\n");
printf("----------------------------------\n\n\n");

initiateIO();
getInterruptSignals();

return;

}



void initiateDeviceDriverIO(){
cout<<"---------------------------"<<endl;
cout<<"1. Device Driver Initiates Input Output at CPU"<<endl;
cout<<"---------------------------"<<endl;

cout<<"---------------------------"<<endl;
cout<<"1.a. Go to I/O Controller  -----> "<<endl;
cout<<"---------------------------"<<endl;


InputOutputController();

cout<<"1.b. I/O Controller's action is finished !!!!!!  -----> "<<endl;
cout<<"---------------------------"<<endl;
cout<<"---------------------------"<<endl;

return;

}


void receivingInterrupt(){

cout<<"CPU receive all interrupt signals"<<endl<<endl;
cout<<"I/O Controller ->O  ->O ->O ->O ->O CPU"<<endl<<endl;
cout<<"Transfer Control to Interrupt Handler"<<endl<<endl;
cout<<"CPU Controller ->O  ->O ->O ->O ->O Interrupt Handler"<<endl<<endl;


}


void processData(){


cout<<"Interrupt Handler Process Data!!"<<endl;

cout<<"->O ->O ===> -># -># -># "<<endl;

cout<<"Return to I/O Controller (Interrupts)"<<endl;

cout<<"Interrupt Handler -># -># -># -># -># I/O Controller (Interrupts) "<<endl;

}

void resumesCpuInterruptedTask(){


cout<<"Restart CPU's remaining and new interrupt task"<<endl;


}




void CPU(){

printf("---------------------------------\n");
printf("============ CPU ================\n");
printf("----------------------------------\n\n\n");
time_t now = time(0);

   char* dt = ctime(&now);

   cout <<dt<< endl;

initiateDeviceDriverIO();
receivingInterrupt();

 processData();

 resumesCpuInterruptedTask();



return;

}





int main()
{


printf("---- Welcome to the Interrupt I/O Cycle -----\n");
printf("\n");
printf("\n");

int i;


for(i=0;i<1;i++){
  CPU();
}




}
