//Program by Luchangcheng 2019/12/5
//Compiler: MSVC 14.23   tested on Visual Studio Community 2019
template<class T>
class PriorityQueue
{
private:
	struct Node
	{
		T data;
		Node* next;
		int priority;
	};
	Node* head;
	Node* tail;
	int length;
	int HighestPriority;
public:
	PriorityQueue();
	~PriorityQueue();
	void EnterQueue(T data, int priority);
	T LeaveQueue();
	bool isEmpty();
	int size();
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
	this->head = this->tail = new Node;
	this->length = 0;
	this->HighestPriority = 0;
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{

}

template<class T>
inline void PriorityQueue<T>::EnterQueue(T data, int priority)
{
	Node* node = new Node;
	node->data = data;
	node->priority = priority;

	if (priority > this->HighestPriority)
		this->HighestPriority = priority;

	node->next = NULL;
	tail->next = node;
	tail = node;
	if (this->length == 0)
		this->head = this->head->next;
	this->length++;
}

template<class T>
inline T PriorityQueue<T>::LeaveQueue()
{
	Node* temp = this->head;
	Node* preNode = NULL;
	T ans = -1;
	int SecondPriority = 0;
	while (temp != NULL && temp->priority < this->HighestPriority)
	{
		if (temp->priority > SecondPriority)
			SecondPriority = temp->priority;
		preNode = temp;
		temp = temp->next;
	}
	ans = temp->data;
	Node* behind = temp->next;
	if (temp == this->head)
	{
		Node* tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}
	else
	{
		preNode->next = temp->next;
		delete temp;
	}
	temp = behind;
	while (temp != NULL)
	{
		if (temp->priority > SecondPriority)
			SecondPriority = temp->priority;
		temp = temp->next;
	}
	this->HighestPriority = SecondPriority;
	return ans;
}

template<class T>
inline bool PriorityQueue<T>::isEmpty()
{
	if (this->length == 0)
		return true;
	else
		return false;
}

template<class T>
inline int PriorityQueue<T>::size()
{
	return this->size;
}