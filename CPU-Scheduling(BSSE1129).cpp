

#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int arrival;
    int priority;
    int burst;

    Process(int index, int arrivalTime, int Processpriority, int burstTime)
    {
        id = index;
        arrival = arrivalTime;
        priority = Processpriority;
        burst = burstTime;
    }
};


bool sortedBySecond(const pair<int,int> &process1,
               const pair<int,int> &process2)
{
    return (process1.second < process2.second);
}


bool sortbyarrival(Process process1, Process process2)
{
    return (process1.arrival < process2.arrival);
}

bool sortedByBurstTime(Process process1, Process process2)
{
    return (process1.burst < process2.burst);
}

bool sortedByPriorityBased(Process process1, Process process2)
{
    return (process1.priority < process2.priority);
}

int main()
{
    int n=6;
//    cout << "Enter number of process: ";
//    cin >> n;

    int priority[n], burst[n], arrival[n];
    int trunaround[n], wait[n];
//
//    cout << "Enter priorities: ";
//    for(int i=0; i<n; ++i)

//        cin >> priority[i];
//
//    cout << "Enter burst time: ";
//    for(int i=0; i<n; ++i)
//        cin >> burst[i];
//
//    cout << "Enter arrival time: ";
//    for(int i=0; i<n; ++i)
//        cin >> arrival[i];




        priority[0]=8;
        priority[1]=3;
        priority[2]=4;
        priority[3]=4;
        priority[4]=5;
        priority[5]=5;

        burst[0]=15;
        burst[1]=20;
        burst[2]=20;
        burst[3]=20;
        burst[4]=5;
        burst[5]=15;

        arrival[0]=0;
        arrival[1]=0;
        arrival[2]=20;
        arrival[3]=25;
        arrival[4]=45;
        arrival[5]=55;



    for(int i=0; i<n; ++i)
    {
        trunaround[i] = 0;
        wait[i] = 0;
    }

    //FCFS
    int time = 0, sum_wait = 0, sum_turn = 0;
    double avg_turn = 0.0, avg_wait = 0.0;

    vector < pair <int, int> > vec;
    vector <int> job_list;

    for(int i=0; i<n; ++i)
        vec.push_back(make_pair(i, arrival[i]));

    sort(vec.begin(), vec.end(), sortedBySecond);

    for(int i=0; i<n; ++i)
    {
        job_list.push_back(vec[i].first);

        if(vec[i].second >= time)
        {
            wait[vec[i].first] = 0;
            trunaround[vec[i].first] = burst[vec[i].first];
            time = vec[i].second + burst[vec[i].first];
        }
        else
        {
            wait[vec[i].first] = time - vec[i].second;
            trunaround[vec[i].first] = wait[vec[i].first] + burst[vec[i].first];
            time += burst[vec[i].first];
        }
    }

    cout << "\nFCFS\njob no\tarrival\tturn\twait\n";
    for(int i=0; i<n; ++i)
    {
        cout << job_list[i] << '\t' << arrival[job_list[i]] << '\t' << trunaround[job_list[i]] << "\t" << wait[job_list[i]] << endl;
        sum_turn += trunaround[job_list[i]];
        sum_wait += wait[job_list[i]];
    }

    avg_turn = (double) sum_turn / (double) n;
    avg_wait = (double) sum_wait / (double) n;

    cout <<endl<<"Average waiting time: " << avg_wait << endl;
    cout <<endl<<"Average turnaround time: " << avg_turn << endl;
    //FCFS....end

    //clear array
    for(int i=0; i<n; ++i)
    {
        trunaround[i] = 0;
        wait[i] = 0;
    }

    //clear vector
    vec.clear();
    job_list.clear();

    //reset variables
    time = 0, sum_wait = 0, sum_turn = 0;
    avg_turn = 0.0, avg_wait = 0.0;

    //priority
    vector<Process> compund_vector;

    for(int i=0; i<n; ++i)
    {
        compund_vector.push_back(Process(i, arrival[i], priority[i], burst[i]));
    }

    sort(compund_vector.begin(), compund_vector.end(), sortedByPriorityBased);
    sort(compund_vector.begin(), compund_vector.end(), sortbyarrival);

    for(int i=0; i<n; ++i)
    {
        vec.push_back(make_pair(compund_vector[i].id, compund_vector[i].priority));
    }

    for(int i=0; i<n; ++i)
    {
        job_list.push_back(vec[i].first);

        if(arrival[vec[i].first] >= time)
        {
            wait[vec[i].first] = 0;
            trunaround[vec[i].first] = burst[vec[i].first];
            time = arrival[vec[i].first] + burst[vec[i].first];
        }
        else
        {
            wait[vec[i].first] = time - arrival[vec[i].first];
            trunaround[vec[i].first] = wait[vec[i].first] + burst[vec[i].first];
            time += burst[vec[i].first];
        }
    }

    cout << "\nPriority"<<endl<<"job no\tarrival\tturn\twait\n";
    for(int i=0; i<n; ++i)
    {
        cout << job_list[i] << '\t' << arrival[job_list[i]] << '\t' << trunaround[job_list[i]] << "\t" << wait[job_list[i]] << endl;
        sum_turn += trunaround[job_list[i]];
        sum_wait += wait[job_list[i]];
    }

    avg_turn = (double) sum_turn / (double) n;
    avg_wait = (double) sum_wait / (double) n;

    cout <<endl<<"Average waiting time: " << avg_wait << endl;
    cout <<"Average turnaround time: " << avg_turn << endl;

    //priority.....end

    //clear array
    for(int i=0; i<n; ++i)
    {
        trunaround[i] = 0;
        wait[i] = 0;
    }

    //clear vector
    vec.clear();
    job_list.clear();

    //reset variables
    time = 0, sum_wait = 0, sum_turn = 0;
    avg_turn = 0.0, avg_wait = 0.0;


    return 0;
}

