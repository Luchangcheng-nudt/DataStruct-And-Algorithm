/* specifies the two kinds of events */
enum eventType {arrival, departure};
typedef enum eventType EventType;

struct event
{
	/* members that identify both customer and teller, as
	   well as maintain information on time of the event,
	   the event type, the length of service required by
	   the customer, and the amount of time customer is
	   forced to wait for service */
	int time;
    EventType etype;
    int customerID;     /* customers numbered 1, 2, 3,... */
    int tellerID;       /* tellers numbered 1, 2, 3,... */
    int waittime;
    int servicetime;
};
typedef struct event Event;

void InitEvent(Event *e, int t, EventType et, int cn, int tn, int wt,int st);
/* methods to retrieve private data */
int GetTime(Event *e);
EventType GetEventType(Event *e);
int GetCustomerID(Event *e);
int GetTellerID(Event *e);
int GetWaitTime(Event *e);
int GetServiceTime(Event *e);

/* initializes all data members of the event */
void InitEvent(Event *e, int t,EventType et,int cn,int tn, int wt,int st)
{
	e->time=t;
	e->etype=et;
	e->customerID=cn;
	e->tellerID=tn;
	e->waittime=wt;
	e->servicetime=st; 
}

/* return the time the event occurs */
int GetTime(Event *e)
{
	return e->time;
}
 
/* return the type of event (arrival, departure) */
EventType GetEventType(Event *e)
{
	return e->etype;
}

/* return the customer number */
int GetCustomerID(Event *e)
{
	return e->customerID;
}
    
/* return the teller number */
int GetTellerID(Event *e)
{
    return e->tellerID;
}

/* return the time the customer waits for service */
int GetWaitTime(Event *e)
{
	return e->waittime;
}

/* return the amount of teller time needed by customer */
int GetServiceTime(Event *e)
{
	return e->servicetime;
}

/* compare two Event objects using the time at
   which the events occur. needed for the priority queue */
int CompareEvent(Event * e1, Event * e2)
{
	return GetTime(e1) < GetTime(e2);
}