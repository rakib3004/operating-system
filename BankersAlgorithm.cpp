#include<bits/stdc++.h>
using namespace std;



int main()
{


    int m,n;

    cout<<"Enter Number of Threads: ";
    cin>>n;

    cout<<"Enter Number of Resources: ";
    cin>>m;

    int Allocation[n][m]= {0};
    int Need[n][m]= {0};
    int Available[n][m]= {0};
    int Max[n][m]= {0};

    int i,j;
    i=0;
    j=0;

    cout<<"Allocation:";

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>Allocation[i][j];
        }
    }


    cout<<"Max:";

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>Max[i][j];
        }
    }


    cout<<"Available:";
    for(j=0; j<m; j++)
    {
        cin>>Available[0][j];
    }


    bool Finish[n];
    int Work[m]= {0};

    for(j=0; j<m; j++)
    {
        Work[j]=Available[0][j];
    }

    for(i=0; i<n; i++)
    {
        Finish[i]=false;
    }


    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        Available[i][j] = Available[i][j]-Work[j];
        Allocation[i][j]= Allocation[i][j]+Work[j];
        Max[i][j]=Max[i][j]-Work[j];

        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {

            if(Finish[i]==false&&Allocation[i][j]<=Work[j])
            {

                Finish[i]==true;

            }
            else{
Work[j]+=Allocation[i][j];
            }

        }
    }




       for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
    cout<<Max[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}
/*

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
