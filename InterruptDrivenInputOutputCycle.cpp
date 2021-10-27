#include<bits/stdc++.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define  totalThreadNumbers 20
#define  totalInterruptionNumbers 20
using namespace std;
void CPU();

struct interruption{
int interruptionState;
void (*interruptionHandler)();

};

struct interruption interruptionVectorObject[totalInterruptionNumbers];



void interruptionVectorStates()
{

    pthread_t threads[totalThreadNumbers];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    time_t t;
    srand(time(&t));



}

// Input Output Controller Section !!!!!!!!!!!!

void initiateIO()
{
    cout<<"---------------------------"<<endl;
    cout<<"1.1 Initiate I/O"<<endl;
    cout<<"---------------------------"<<endl<<endl<<endl;     sleep(2);

}

void getInterruptSignals()
{
    cout<<"---------------------------------------"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"1.2 Get Interrupt Signals"<<endl;
    cout<<"   3 Basic Interrupt Signals: \n\n";
    cout<<"i.Input Signal (which is ready)\n";
    cout<<"ii.Output Signal (which is complete)\n";
    cout<<"iii.Error Signal (which is generate)\n";

    cout<<"Visualize Interruption ==>"<<endl<<endl;     sleep(2);
    interruptionVectorStates();

    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl<<endl<<endl;     sleep(2);


}

void InputOutputController()
{

    printf("---------------------------------\n");
    printf("======== I/O Controller ==========\n");
    printf("----------------------------------\n\n\n");

    initiateIO();
    getInterruptSignals();

    return;

}



void initiateDeviceDriverIO()
{
    cout<<"----------------------------------------------"<<endl;
    cout<<"1. Device Driver Initiates Input Output at CPU"<<endl;
    cout<<"-----------------------------------------------"<<endl<<endl<<endl;     sleep(2);

    cout<<"---------------------------------"<<endl;
    cout<<"1.a. Go to I/O Controller  -----> "<<endl;
    cout<<"---------------------------------"<<endl<<endl<<endl;     sleep(2);


    InputOutputController();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"1.b. I/O Controller's action is finished !!!!!!  -----> "<<endl;
    cout<<"======================================================="<<endl<<endl<<endl;     sleep(2);

    return;

}


void receivingInterrupt()
{
    cout<<"-----------------------------------"<<endl;
    cout<<"2.CPU receive all interrupt signals"<<endl;
    cout<<"I/O Controller ->O  ->O ->O ->O ->O CPU"<<endl;
    cout<<"[O means data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;     sleep(2);

    cout<<"-----------------------------------"<<endl;
    cout<<"2.a. Transfer Control to Interrupt Handler"<<endl;
    cout<<"CPU Controller ->O  ->O ->O ->O ->O Interrupt Handler"<<endl;
    cout<<"[O means data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;     sleep(2);



}


void processData()
{

    cout<<"-----------------------------------"<<endl;
    cout<<"3. Interrupt Handler Process Data!!"<<endl;
    cout<<"->O ->O ===> -># -># -># "<<endl;
    cout<<"[# means processed data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;     sleep(2);


    cout<<"-----------------------------------"<<endl;
    cout<<"3.a. Return to I/O Controller (Interrupts)"<<endl;
    cout<<"Interrupt Handler -># -># -># -># -># I/O Controller (Interrupts) "<<endl;
    cout<<"[# means processed data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;     sleep(2);


}

void resumesCpuInterruptedTask()
{

    cout<<"-----------------------------------"<<endl;
    cout<<"4.Restart CPU's remaining and new interrupt task"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;     sleep(2);

}




void CPU()
{

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


    for(i=0; i<1; i++)
    {
        CPU();
    }




}
