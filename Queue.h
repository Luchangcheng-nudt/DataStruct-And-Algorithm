template<class T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int length;
public:
	Queue();
	~Queue();
	void EnterQueue(T data);
	T LeaveQueue();
	bool isEmpty();
	int size();
};

template<class T>
Queue<T>::Queue()
{
	this->head = this->tail = new Node;
	this->length = 0;
}

template<class T>
Queue<T>::~Queue()
{

}

template<class T>
void Queue<T>::EnterQueue(T data)
{
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	tail->next = node;
	tail = node;
	if (this->length == 0)
		this->head = this->head->next;
	this->length++;
}

template<class T>
T Queue<T>::LeaveQueue()
{
	T ans = this->head->data;
	if (--this->length == 0)
	{
		Queue();
		return ans;
	}
	Node* temp = this->head;
	this->head = this->head->next;
	delete temp;

	return ans;
}

template<class T>
bool Queue<T>::isEmpty()
{
	if (this->length == 0)
		return true;
	else
		return false;
}

template<class T>
int Queue<T>::size()
{
	return this->size;
}