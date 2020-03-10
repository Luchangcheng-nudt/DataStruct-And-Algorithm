#ifndef SIMULATION
#define SIMULATION

#include <stdio.h>
#include <stdlib.h>
#include "event.h"
typedef Event DataType;       /* elements are Event objects */

#include "apqueue.h"

/* Structure for Teller Info */
struct tellerStats
{
    int finishService;      /* when teller available */
    int totalCustomerCount; /* total of customers serviced */
    int totalCustomerWait;  /* total customer waiting time */
    int totalService;       /* total time servicing customers */
};
typedef struct tellerStats TellerStats;

struct simulation
{/* data used to run the simulation */
	int simulationLength;        /* simulation length */
	int numTellers;              /* number of tellers */
	int nextCustomer;            /* next customer ID */
	int arrivalLow, arrivalHigh; /* next arrival range */
	int serviceLow, serviceHigh; /* service range */
	TellerStats tstat[11];       /* max 10 tellers */
	PQueue pq;                   /* priority queue */
};
typedef struct simulation Simulation;

int NextArrivalTime(Simulation *s);
int Get_ServiceTime(Simulation *);
int NextAvailableTeller(Simulation *s);
void InitSimulation(Simulation *s);
void RunSimulation(Simulation *s);/* execute study */
void PrintSimulationResults(Simulation *s);/* print stats */

/* initializes simulation data and prompts client for simulation parameters */
void InitSimulation(Simulation *s)
{
    int i;
    Event *firstevent=(Event *)malloc(sizeof(Event));
    
	/* Initialize Teller Information Parameters */
    for(i = 1; i <= 10; i++)
    {
        s->tstat[i].finishService = 0; 
        s->tstat[i].totalService = 0;
        s->tstat[i].totalCustomerWait = 0;
        s->tstat[i].totalCustomerCount = 0;
    }
	s->nextCustomer = 1;

    /* reads client input for the study */
    printf("Enter the simulation time in minutes: ");
    scanf("%d", &s->simulationLength);
    printf("Enter the number of bank tellers: ");
    scanf("%d", &s->numTellers);
	printf("Enter the range of arrival times in minutes: ");
	scanf("%d%d", &s->arrivalLow, &s->arrivalHigh);
    printf("Enter the range of service times in minutes: ");
	scanf("%d%d", &s->serviceLow, &s->serviceHigh);

    /* generate first arrival event
       teller#/waittime/servicetime not used for arrival */
	InitEvent(firstevent,0,arrival,1,0,0,0);
	InitPQueue(&(s->pq));
    PQInsert(&(s->pq), *firstevent);
}

/* determine random time of next arrival */
int NextArrivalTime(Simulation *s)
{
    return s->arrivalLow+rand()%(s->arrivalHigh-s->arrivalLow+1);
}

/* determine random time for customer service */
int Get_ServiceTime(Simulation *s)
{
    return s->serviceLow+rand()%(s->serviceHigh-s->serviceLow+1);
}

/* return first available teller */
int TellerWaitCount[11] = {0};
int NextAvailableTeller(Simulation *s)                                                  //Change point 1
{
    /*                                                                                  //Version of refering the finish Time of service
    int mininum = INT_MAX;
    int List[10] = {0};
    int index = 0;
    int i = 1;

    for (i; i <= s->numTellers; i++)
    {
        if (s->tstat[i].finishService < mininum)
        {
            mininum = s->tstat[i].finishService;
            index = 0;
            List[index++] = i;
        }
        else
        {
            if (s->tstat[i].finishService == mininum)
                List[index++] = i;
        }
    }

    return List[rand() % index];
    */

    int mininum = INT_MAX;                                                              //Version of referring to the number of queue
    int i = 1;
    int List[10] = {0};
    int index = 0;
    for (i; i <= s->numTellers; i++)
    {
        if (TellerWaitCount[i] < mininum)
        {
            mininum = TellerWaitCount[i];
            index = 0;
            List[index++] = i;
        }
        else
        {
            if (TellerWaitCount[i] == mininum)
                List[index++] = i;
        }
    }
    return List[rand() % index];
}

/* implements the simulation */
void RunSimulation(Simulation *s)
{
    Event *e = (Event *)malloc(sizeof(Event));
	Event *newevent = (Event *) malloc (sizeof(Event));
    int nexttime;
    int tellerID;
    int servicetime;
    int waittime;
        
    /* run till priority queue is empty */
    while (!PQEmpty(&(s->pq)))
    {
        /* get next event (time measures the priority) */
        *e = PQDelete(&(s->pq));
        
        /* handle an arrival event */
        if (GetEventType(e) == arrival)
        {
            /* compute time for next arrival. */
            nexttime = GetTime(e) + NextArrivalTime(s);
            
            if (nexttime > s->simulationLength)
                /* process events but don't generate any more */
                continue;
            else
            {
                /* generate arrival for next customer. put in queue */
                s->nextCustomer++;
                InitEvent(newevent, nexttime, arrival, s->nextCustomer, 0, 0, 0);
                PQInsert(&(s->pq), *newevent);
            }
            
            printf("Time: %2d\tarrival of customer %d\n", GetTime(e), GetCustomerID(e));
                
            /* generate departure event for current customer */
            /* time the customer takes */
            servicetime = Get_ServiceTime(s);
            /* teller who services customer */
            tellerID = NextAvailableTeller(s);                                              

            /* if teller free, update sign to current time */
            if (s->tstat[tellerID].finishService == 0)
                s->tstat[tellerID].finishService = GetTime(e);
        
            /* compute time customer waits by subtracting the
               current time from time on the teller's sign */
            waittime = s->tstat[tellerID].finishService - GetTime(e);
    
            /* update teller statistics */
            s->tstat[tellerID].totalCustomerWait += waittime;
            s->tstat[tellerID].totalCustomerCount++;
            s->tstat[tellerID].totalService += servicetime;
            s->tstat[tellerID].finishService += servicetime;
            
            TellerWaitCount[tellerID]++;                                                        //Change point 2

            /* create a departure event and put in the queue */
            InitEvent(newevent, s->tstat[tellerID].finishService,
                        departure,GetCustomerID(e),tellerID,
                        waittime,servicetime);
            PQInsert(&(s->pq), *newevent);
        }
        /* handle a departure event */
        else
        {
            printf("Time: %2d\tdeparture of customer %d\n", GetTime(e), GetCustomerID(e));
            printf("\tTeller %d\tWait %d\tService %d\n",GetTellerID(e), GetWaitTime(e), GetServiceTime(e));
            tellerID = GetTellerID(e);
            /* if nobody waiting for teller, mark teller free */
            if (GetTime(e) == s->tstat[tellerID].finishService)
                s->tstat[tellerID].finishService = 0;

            TellerWaitCount[tellerID]--;                                                        //Change Point 3
        }
    }
    
    /* adjust simulation to account for overtime by tellers */
    s->simulationLength = (GetTime(e) <= s->simulationLength)
                        ? s->simulationLength : GetTime(e);
}

/* summarize the simulation results */
void PrintSimulationResults(Simulation *s)
{
    int cumCustomers = 0, cumWait = 0, i;
    int avgCustWait, tellerWorkPercent;
    float tellerWork;

    for (i = 1; i <= s->numTellers; i++)
    {
        cumCustomers += s->tstat[i].totalCustomerCount;
        cumWait += s->tstat[i].totalCustomerWait;
    }

    printf("\n");
    printf("******** Simulation Summary ********\n");
    printf("Simulation of %d minutes\n", s->simulationLength);
    printf("\tNo. of Customers: %d\n", cumCustomers);
    printf("\tAverage Customer Wait: ");
    
    avgCustWait = (int)((float)cumWait/cumCustomers + 0.5);
    printf("%d minutes\n", avgCustWait);
    for(i=1;i <= s->numTellers;i++)
    {
        printf("\tTeller #%d\tWorking ", i);
        /* display percent rounded to nearest integer value */
        tellerWork = (float)(s->tstat[i].totalService)/s->simulationLength;
        tellerWorkPercent = (int) (tellerWork * 100.0 + 0.5);
        printf("%d\n", tellerWorkPercent);
    }
}

#endif  /* SIMULATION */