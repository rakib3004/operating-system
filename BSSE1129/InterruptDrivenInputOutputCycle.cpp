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

struct interruption
{
    int interruptionState;
    void (*interruptionHandler)();

};

struct interruption interruptionVectorObject[totalInterruptionNumbers];





void divideError()
{
    interruptionVectorObject[0].interruptionState=0;
        cout<<"Division Error"<<endl;


}


void  debugException()
{
    interruptionVectorObject[1].interruptionState=0;
    cout<<"Debug Exception"<<endl;

}


void  nullInterrupt()
{

    interruptionVectorObject[2].interruptionState=0;
    cout<<"Null Interruption"<<endl;

}

void  breakPoint()
{
    interruptionVectorObject[3].interruptionState=0;
    cout<<"Break Point"<<endl;
}

void  intoDetectedOverflow()
{
    interruptionVectorObject[4].interruptionState=0;
    cout<<"INTO Detected Overflow"<<endl;
}


void  boundRangeException()
{
    interruptionVectorObject[5].interruptionState=0;
    cout<<"Bound Range Exception"<<endl;
}


void  invalidOpcode()
{
    interruptionVectorObject[6].interruptionState=0;
    cout<<"Invalid Opcode"<<endl;
}


void  deviceNotAvailable()
{
    interruptionVectorObject[7].interruptionState=0;
    cout<<"Device not Available"<<endl;
}


void  doubleFault()
{
    interruptionVectorObject[8].interruptionState=0;
    cout<<"Double Fault"<<endl;
}



void  coprocessorSegmentOverrun()
{
    interruptionVectorObject[9].interruptionState=0;
    cout<<"Co-Processor Segment Overrun"<<endl;
}


void  invalidTaskStateSegment()
{
    interruptionVectorObject[10].interruptionState=0;
    cout<<"Invalid Task State Segment"<<endl;
}


void  stackFault()
{
    interruptionVectorObject[11].interruptionState=0;
    cout<<"Stack Fault"<<endl;

}


void  generalProtection()
{
    interruptionVectorObject[12].interruptionState=0;
    cout<<"General Protection"<<endl;
}


void  pageFault()
{
    interruptionVectorObject[13].interruptionState=0;
    cout<<"Page Fault"<<endl;

}


void  intelReserved()
{
    interruptionVectorObject[14].interruptionState=0;
    cout<<"Intel Reserved"<<endl;
}


void  floatingPointError()
{
    interruptionVectorObject[15].interruptionState=0;
    cout<<"Floating Point Error"<<endl;
}


void  alignmentCheck()
{
    interruptionVectorObject[16].interruptionState=0;
    cout<<"Alignment Check"<<endl;
}


void  machineCheck()
{
    interruptionVectorObject[17].interruptionState=0;
    cout<<"Machine Check"<<endl;

}


void  hardwareReserved()
{
    interruptionVectorObject[18].interruptionState=0;
    cout<<"Hardware Reserved"<<endl;

}


void  maskableInterrupt()
{
    interruptionVectorObject[19].interruptionState=0;
    cout<<"Mask-able Interrupt"<<endl;

}



void setInterruptVactorTableValue()
{


    for(int i=0; i<totalInterruptionNumbers; i++)
    {
        interruptionVectorObject[i].interruptionState=0;


    }

    interruptionVectorObject[0].interruptionHandler = divideError;
    interruptionVectorObject[1].interruptionHandler = debugException;
    interruptionVectorObject[2].interruptionHandler = nullInterrupt;
    interruptionVectorObject[3].interruptionHandler = breakPoint;
    interruptionVectorObject[4].interruptionHandler = intoDetectedOverflow;
    interruptionVectorObject[5].interruptionHandler = boundRangeException;
    interruptionVectorObject[6].interruptionHandler = invalidOpcode;
    interruptionVectorObject[7].interruptionHandler = deviceNotAvailable;
    interruptionVectorObject[8].interruptionHandler = doubleFault;
    interruptionVectorObject[9].interruptionHandler = coprocessorSegmentOverrun;
    interruptionVectorObject[10].interruptionHandler = invalidTaskStateSegment;
    interruptionVectorObject[11].interruptionHandler = stackFault;
    interruptionVectorObject[12].interruptionHandler = generalProtection;
    interruptionVectorObject[13].interruptionHandler = pageFault;
    interruptionVectorObject[14].interruptionHandler = intelReserved;
    interruptionVectorObject[15].interruptionHandler = floatingPointError;
    interruptionVectorObject[16].interruptionHandler = alignmentCheck;
    interruptionVectorObject[17].interruptionHandler = machineCheck;
    interruptionVectorObject[18].interruptionHandler = hardwareReserved;
    interruptionVectorObject[19].interruptionHandler = maskableInterrupt;

}


void *creatingInterruption(void *args) {

    int limitStraem = 10;
    while (limitStraem--) {
        sleep(1);
            srand(time(0));
        interruptionVectorObject[rand() % totalInterruptionNumbers].interruptionState = 1;
    }
    pthread_exit(NULL);
}

void checkInterruption() {
    for (int i = 0; i < totalInterruptionNumbers; i++) {
        if (interruptionVectorObject[i].interruptionState) {
            interruptionVectorObject[i].interruptionHandler();
        }
    }
}

void interruptionVectorStates()
{

    pthread_t threads[totalThreadNumbers];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    srand(time(0));

    setInterruptVactorTableValue();

    int i;

    for (i = 0; i < totalThreadNumbers; i++) {
        if (pthread_create(&threads[i], &attr, creatingInterruption, NULL)) {

        }
    }

    int keyboardStreamCount = 29;
    while (keyboardStreamCount--) {
        printf("%c  ----> is a keyboard input\n", (rand() % 90)+65);
        sleep(1);
        checkInterruption();
    }

    for (i = 0; i < totalThreadNumbers; i++) {
        pthread_join(threads[i], NULL);
    }

}

// Input Output Controller Section !!!!!!!!!!!!

void initiateIO()
{
    cout<<"---------------------------"<<endl;
    cout<<"1.1 Initiate I/O"<<endl;
    cout<<"---------------------------"<<endl<<endl<<endl;
    sleep(1);

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

    cout<<"Visualize Interruption ==>"<<endl<<endl;
        cout<<"|||||||||||||||||||||||||||||"<<endl;
        cout<<"|||||||||||||||||||||||||||||"<<endl<<endl;



    sleep(1);
    interruptionVectorStates();

     cout<<"|||||||||||||||||||||||||||||"<<endl;
    cout<<"|||||||||||||||||||||||||||||"<<endl<<endl;

    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl<<endl<<endl;
    sleep(1);


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
    cout<<"-----------------------------------------------"<<endl<<endl<<endl;
    sleep(1);

    cout<<"---------------------------------"<<endl;
    cout<<"1.a. Go to I/O Controller  -----> "<<endl;
    cout<<"---------------------------------"<<endl<<endl<<endl;
    sleep(1);


    InputOutputController();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"1.b. I/O Controller's action is finished !!!!!!  -----> "<<endl;
    cout<<"======================================================="<<endl<<endl<<endl;
    sleep(1);

    return;

}


void receivingInterrupt()
{
    cout<<"-----------------------------------"<<endl;
    cout<<"2.CPU receive all interrupt signals"<<endl;
    cout<<"I/O Controller ->O  ->O ->O ->O ->O CPU"<<endl;
    cout<<"[O means data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;
    sleep(1);

    cout<<"-----------------------------------"<<endl;
    cout<<"2.a. Transfer Control to Interrupt Handler"<<endl;
    cout<<"CPU Controller ->O  ->O ->O ->O ->O Interrupt Handler"<<endl;
    cout<<"[O means data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;
    sleep(1);



}


void processData()
{

    cout<<"-----------------------------------"<<endl;
    cout<<"3. Interrupt Handler Process Data!!"<<endl;
    cout<<"->O ->O ===> -># -># -># "<<endl;
    cout<<"[# means processed data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;
    sleep(1);


    cout<<"-----------------------------------"<<endl;
    cout<<"3.a. Return to I/O Controller (Interrupts)"<<endl;
    cout<<"Interrupt Handler -># -># -># -># -># I/O Controller (Interrupts) "<<endl;
    cout<<"[# means processed data steam]"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;
    sleep(1);


}

void resumesCpuInterruptedTask()
{

    cout<<"-----------------------------------"<<endl;
    cout<<"4.Restart CPU's remaining and new interrupt task"<<endl;
    cout<<"-----------------------------------"<<endl<<endl<<endl;
    sleep(1);

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
