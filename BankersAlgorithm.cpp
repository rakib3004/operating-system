#include<bits/stdc++.h>
using namespace std;



int main()
{
    int i,j;
    i=0;
    j=0;



    int m,n;

    cout<<"Enter Number of Threads: ";
    cin>>n;

    cout<<"Enter Number of Resources: ";
    cin>>m;

    int Allocation[n][m]= {0};
    int Need[n][m]= {0};
    int Available[m]= {0};
    int Max[n][m]= {0};
    int Process[n]={0};
    int Resource[m]= {0};
    int processId=0;

    cout<<"Resource:"<<endl;

    for(i=0; i<m; i++)
    {
        cin>>Resource[i];
    }

    int totalAlloc[m]= {0};


    cout<<"Allocation:"<<endl;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>Allocation[i][j];
            totalAlloc[j]=totalAlloc[j]+Allocation[i][j];
        }
    }



    cout<<"Max:"<<endl;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>Max[i][j];
        }
    }



    for(j=0; j<m; j++)
    {
        Available[j]=Resource[j]-totalAlloc[j];
    }


    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            Need[i][j] = Max[i][j]-Allocation[i][j];
        }
    }




    bool Finish[n];
    int Work[m]= {0};


    for(i=0; i<n; i++)
    {
        Finish[i]=false;
    }


//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<m; j++)
//        {
//            Available[i][j] = Available[i][j]-Work[j];
//            Allocation[i][j]= Allocation[i][j]+Work[j];
//            Max[i][j]=Max[i][j]-Work[j];
//
//        }
//    }

    bool isNotWork=false;

    for(int k=0; k<n; k++)
    {

        for(i=0; i<n; i++)
        {


            if(Finish[i]==false)
            {
                isNotWork=false;
                for(j=0; j<m; j++)
                {

                    if(Need[i][j]>Available[j])
                    {

                        isNotWork=true;
                        break;

                    }

                }

                if(isNotWork==false)
                {

                    //resource sequence
                    Process[processId++]=i;
                   // processId++;

                    for(j=0; j<m; j++)
                    {
                        Available[j]+=Allocation[i][j];
                    }
                    Finish[i]=true;
                }
            }

        }

    }




    cout<<"Process Sequence is: "<<endl;
    for(i=0; i<n; i++)
    {
cout<<"Process_"<<Process[i]<<endl;
    }

    return 0;

}
/*

Resource:10 5 7

Allocation:

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Max:

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3


Available:
3 2 2


*/
