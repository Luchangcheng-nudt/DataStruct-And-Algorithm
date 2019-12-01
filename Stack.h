//Program by Luchangcheng 2019/12/1
//Compiler:MSVC 14.23  Visual Studio Community 2019
template <class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int num;
public:
	Stack();
	~Stack();
	void push_stack(T data);
	T pop_stack();
	bool isEmpty();
	int size();
	T top();
};

template<class T>
Stack<T>::Stack()
{
	this->head = this->tail = new Node;
	this->num = 0;
}

template<class T>
Stack<T>::~Stack()
{

}

template <class T>
inline void Stack<T>::push_stack(T data)
{
	this->num++;
	Node* node = new Node;
	node->data = data;
	node->next = this->head;
	if (this->head->next == NULL)
		node->next = NULL;
	this->head = node;
}

template<class T>
inline T Stack<T>::pop_stack()
{
	this->num--;
	T ans = this->head->data;
	Node* temp = this->head;
	this->head = this->head->next;
	delete temp;
	return ans;
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	if (this->num == 0)
		return true;
	else
		return false;
}

template<class T>
inline int Stack<T>::size()
{
	return this->num;
}

template<class T>
inline T Stack<T>::top()
{
	return this->head->data;
}
