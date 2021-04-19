#include<bits/stdc++.h>
using namespace std;

struct process
{
    int arrival,burst,priority, pid;
    int passed=0;
};
process processes[6];
bool vis[7] = {false};
//int n = 6;
process findMinSize(int n, int ttime)
{
    process ret;
    ret.burst=INT_MAX;
    ret.pid= -1;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==false && processes[i].burst<ret.burst && processes[i].arrival<=ttime)
            ret = processes[i];
    }
    vis[ret.pid-1]=true;
    return ret;
}

bool foo(process x, process y)
{
    if(x.arrival==y.arrival)
    {
        if(x.priority==y.priority)
        {
            return x.burst<y.burst;
        }
        else
            return x.priority>y.priority;
    }
    else
        return x.arrival<y.arrival;
}

void waitingFunction(int burst[],int arrival[], int waitingTime[], int totalWaitingTime, int n)
{
    waitingTime[0]=0;
    int service[n]= {0};
    for(int i=1; i<n; i++)
    {
        service[i] = service[i-1]+burst[i-1];
        waitingTime[i]=service[i]-arrival[i];
        if(waitingTime[i]<0) waitingTime[i] = 0;
    }
}

void turnAroundFunction(int burst[], int arrival[], int turnAroundTime[], int waitingTime[], int totalTurnAroundTime, int n)
{
    for(int i=0; i<n; i++)
    {
        turnAroundTime[i] = burst[i] + waitingTime[i];
    }
}

void solutionwithFCFS(int priority[], int burst[], int arrival[], int n)
{
    cout<< "\n..............FCFS.............\n"<<endl;
    int waitingTime[n], turnAroundTime[n], totalWaitingTime = 0, totalTurnAroundTime = 0;

    waitingFunction(burst,arrival,waitingTime,totalWaitingTime,n);
    turnAroundFunction(burst,arrival,turnAroundTime,waitingTime, totalTurnAroundTime,n);
    cout<< "Processes  BurstTime  WaitingTime ArrivalTime TurnAroundTime Priority"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<< "p"<< processes[i].pid<< "        "<< processes[i].burst<< "            "<< waitingTime[i]<< "          "<< processes[i].arrival<< "               " <<turnAroundTime[i]<<"             "<<processes[i].priority<<endl;
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }
    float avgWaitingTime = float(totalWaitingTime)/float(n);
    cout<< "Average Waiting Time : "<< avgWaitingTime <<endl;
    float avgTurnAroundTime = float(totalTurnAroundTime)/float(n);
    cout<< "Average Turn Around Time : "<< avgTurnAroundTime <<endl;

}

void sjfnonpreemp(int n)
{
    cout<< "\n\n........SJF(non preemp).......\n"<<endl;
    cout<< "Order: ";
    int time=0;
    int wait[n]= {0},turn[n]= {0};
    process minariv;
    minariv.arrival=INT_MAX;
    deque<process> dq;

    for(int i=0; i<n; i++)
    {
        if(processes[i].arrival<minariv.arrival)
        {
            minariv=processes[i];
        }
    }
    dq.push_back(minariv);
    vis[minariv.pid-1]=true;
    int counter =0;
    while(!dq.empty())
    {
        process tem = dq.back();
        dq.pop_back();
        cout<< tem.pid<< " ";
        wait[tem.pid-1] = time - tem.arrival;
        if(wait[tem.pid-1]<0) wait[tem.pid-1]=0;
        time+=tem.burst;
        process mini = findMinSize(n,time);
        if(mini.pid!=-1)
            dq.push_back(mini);
    }
    cout<< endl;
    int tw=0, tt=0, ta[n]= {0};
    for(int i=0; i<n; i++)
    {
        tw+=wait[i];
        ta[i]=processes[i].burst+wait[i];
        tt+=ta[i];
    }
    cout<< "Avg Waiting Time: "<< (float) tw/ (float)n<<endl;
    cout<< "Avg TurnAround Time: "<< (float) tt/ (float)n<<endl;

}

void solutionwithPriority(int n)
{
    cout<< "\n\n.........Priority.......\n\n";
    int waitingTime[n]= {0};
    int turnAroundTime[n]= {0};
    int service[n]= {0};
    int totalWaitingTime = 0, totalTurnAroundTime =0;
    int totalBurst =0;
    for(int i=0; i<n; i++)
    {
        waitingTime[i]= totalBurst-processes[i].arrival;
        totalBurst+=processes[i].burst;
        turnAroundTime[i]=waitingTime[i]+processes[i].burst;

    }
    cout<< "Order: "<<endl;
    cout<< "Processes  BurstTime  WaitingTime ArrivalTime TurnAroundTime Priority"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<< "p"<< processes[i].pid<< "        "<< processes[i].burst<< "            "<< waitingTime[i]<< "          "<< processes[i].arrival<< "               " <<turnAroundTime[i]<<"             "<<processes[i].priority<<endl;
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }
    cout<<endl;
    cout<< "Avg waiting: "<< (float) totalWaitingTime/(float)n<<endl;
    cout<< "Avg turnAround: "<< (float)totalTurnAroundTime/(float)n<<endl;
}

void solutionwithRoundRobin(int priority[], int burst[], int arrival[], int n)
{
    cout<< "\n\n.......Round Robin.....\n\n";
    int quantam = 10;
    int totalWaitingTime = 0, totalTurnAroundTime =0;
    int waitingTime[n] = {0}, turnAroundTime[n]= {0}, temp[10];
    int total =0, cc2=0;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        temp[i]=burst[i];
    }
    queue<process> q;
    vector<int> res;
    int  wait=0;
    int wt=0,tt=0;
    process minArivProcess;
    minArivProcess.arrival=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(processes[i].arrival<minArivProcess.arrival)
        {
            minArivProcess = processes[i];
        }
    }
    q.push(minArivProcess);
    int counter2=0;
    //cout<< "size"<< q.size()<<endl;
    while(!q.empty())
    {
        process tem = q.front();
        q.pop();
        res.push_back(tem.pid);
        //q.pop();
        if(tem.burst<=quantam&&tem.burst>0)
        {
            //cout<< "1"<<endl;
            total +=  tem.burst;
            tem.burst=0;
            flag=true;
        }
        else if(tem.burst>0)
        {
            //cout<< "2"<<endl;
            total += quantam;
            tem.burst -= quantam;
        }
        if(tem.burst==0 && flag==true)
        {
            cc2++;
            waitingTime[counter2++] = total-tem.arrival-temp[tem.pid-1];
            if(waitingTime[counter2-1]<0) waitingTime[counter2-1]=0;
            wt+=waitingTime[counter2-1];
            turnAroundTime[counter2-1] = total - tem.arrival;
            tt+=turnAroundTime[counter2-1];
            totalTurnAroundTime = totalTurnAroundTime + total - tem.arrival;
        }
        for(int i=0; i<n; i++)
        {
            if(processes[i].pid==tem.pid)
            {
                processes[i].burst=tem.burst;
            }
        }
        int ii=tem.pid;
        if(ii==n) ii=0;

        int counter = 0;
        //cout<< ii<< endl;
        while(counter++<n)
        {
            if(processes[ii].arrival<=total&&processes[ii].pid!=tem.pid && processes[ii].burst>0)
            {
                q.push(processes[ii]);
                ii++;
                break;
            }
            ii++;
            if(ii==n) ii=0;
        }

        if(cc2==n)
        {
            break;
        }

    }
    cout<< "Order: ";
    for(int i=0; i<res.size(); i++)
    {
        cout<< res[i]<< " ";
    }
    cout<< endl;
    //cout<<wt<<endl;
    cout<< "Avg Waiting Time : "<< (float) wt/ (float)n<<endl;
    cout<< "Avg TurnAround Time : "<< (float) tt/ (float)n<<endl;
}


bool done[7] = {false};


bool foo2(process x, process y)
{
    if(x.arrival==y.arrival)
    {
        return x.burst<y.burst;
    }
    else
        return x.arrival<y.arrival;
}

process findNextProcess(int ttime, int id, int n, int bt)
{
    process ret;
    ret.burst=INT_MAX;
    ret.pid=-1;
    //cout<< "bairer time: "<< ttime<<endl;
    for(int i=0; i<n; i++)
    {
        if(bt!=0)
        {
            if(processes[i].burst<processes[id-1].burst&&processes[i].burst>0&&processes[i].pid!=id&&done[processes[i].pid-1]!=true&&processes[i].arrival<=ttime)
            {
                // cout<< "time1: "<< ttime<<"  arri: "<< processes[i].arrival<<endl;
                ret = processes[i];
            }
        }
        else
        {
            if(processes[i].burst<ret.burst&&processes[i].burst>0&&processes[i].pid!=id&&done[processes[i].pid-1]!=true&&processes[i].arrival<=ttime)
            {
                // cout<< "time2: "<< ttime<<"  arri: "<< processes[i].arrival<<endl;
                ret = processes[i];
            }
        }
    }
    return ret;
}

void sjfPreemp(int n)
{
    cout<< "\n\n.........SJF(preemptive).......\n\n"<<endl;
    vector<int> res;
    sort(processes, processes+n, foo2);
    int time = 0, totalWaitingTime = 0, totalTurnAroundTime = 0;
    int waitingTime[n] = {0}, turnAroundTime[n] = {0};
    deque<process> dq;
    dq.push_back(processes[0]);
    res.push_back(processes[0].pid);
    int counter = 0;
    int cc=0;
    int ttt = 0;
    int cpy[n];
    for(int i=0; i<n; i++)
    {
        ttt+=processes[i].burst;
        cpy[i]=processes[i].burst;
    }
    while(!dq.empty())
    {

        process tem = dq.back();
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            if(done[i]==false)
                flag=true;
        }

        int timer = 0;
        process nextProcess = findNextProcess(time,tem.pid,n,tem.burst);
        //cout<< nextProcess.pid<<endl;

        if(nextProcess.pid==-1)
        {
            while(tem.burst<=nextProcess.burst&&nextProcess.pid==-1)
            {
                // cout<< "dhuksi22222"<<endl;
                time++;
                tem.burst--;
                if(time == ttt)
                {
                    waitingTime[counter++]= time-cpy[tem.pid-1];
                    totalWaitingTime+=waitingTime[counter-1];
                    totalTurnAroundTime+=cpy[tem.pid-1]+waitingTime[counter-1];
                    cout<< "Order: ";
                    for(auto a: res)
                    {
                        cout<< a<< " ";
                    }
                    cout<<endl;
                    cout<< "Avg Waiting: "<< (float)totalWaitingTime/(float)n<<endl;
                    cout<< "Avg TurnAround: "<< (float)totalTurnAroundTime/(float)n<<endl;
                    return;
                }
                for(int i=0; i<n; i++)
                {
                    if(tem.pid==processes[i].pid)
                    {
                        processes[i].burst--;
                    }
                }
                if(tem.burst==0)
                {
                    done[tem.pid-1]=true;
                    waitingTime[counter]=time-tem.arrival-cpy[tem.pid-1];
                    turnAroundTime[counter]=cpy[tem.pid-1]+waitingTime[counter];
                    totalTurnAroundTime+=turnAroundTime[counter];
                    totalWaitingTime+=waitingTime[counter];
                    counter++;
                    //cout<< "Counter: "<<counter<<endl;
                }
                nextProcess = findNextProcess(time,tem.pid,n,tem.burst);
                if(nextProcess.pid!=-1)
                {
                    dq.pop_back();
                    // cout<< "popped: " <<tem.pid<<endl;
                    dq.push_back(nextProcess);
                    // cout<<"pushed: "<<nextProcess.pid<<endl;
                    res.push_back(nextProcess.pid);
                }
            }
        }
        else
        {
            dq.pop_back();
            //cout<< "popped: " <<tem.pid<<endl;
            dq.push_back(nextProcess);
            // cout<<"pushed: "<<nextProcess.pid<<endl;
            res.push_back(nextProcess.pid);
        }

    }
}

int main()
{
    int priority[] = {8,3,4,4,5,5};
    int brust[] = {15,20,20,20,5,15};
    int arrival[] = {0,0,20,25,45,55};
    int n = sizeof(priority)/sizeof(int);
    for(int i=0; i<n; i++)
    {
        processes[i].arrival=arrival[i];
        processes[i].burst = brust[i];
        processes[i].priority=priority[i];
        processes[i].pid=i+1;
    }
    solutionwithFCFS(priority,brust,arrival,n);
    sjfnonpreemp(n);
    sort(processes,processes+n,foo);
    solutionwithPriority(n);
    solutionwithRoundRobin(priority,brust,arrival,n);
    for(int i=0; i<n; i++)
    {
        processes[i].arrival=arrival[i];
        processes[i].burst = brust[i];
        processes[i].priority=priority[i];
        processes[i].pid=i+1;
    }
    sjfPreemp(n);
}
