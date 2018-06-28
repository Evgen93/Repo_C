#include <iostream>
#include <ctime>

using namespace std;

template<typename dataType>
class queueList
{
private:
	struct node
	{
		dataType data;
		node* right;
		node* left;

		node(dataType newData, node* curTail)
		{
			data = newData;
			right = nullptr;
			left = curTail;
		}
	};
	unsigned size;
	node* head;
	node* tail;
public:
	queueList();
	queueList(dataType* mas, unsigned sizeMas);
	~queueList();
	bool pushBack(dataType var, unsigned priority = 0);
	bool popFront(dataType & var);
	bool Back(dataType & var) const;
	bool Front(dataType & var) const;
	bool printQueue() const;
	bool printRevers() const;
private:
	void AddWithPriority(unsigned p, node* temp);
};
template<typename dataType>
queueList<dataType>::queueList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename dataType>
queueList<dataType>::~queueList()
{
	dataType i;
	while (popFront(i));
}
template<typename dataType>
queueList<dataType>::queueList(dataType* mas, unsigned sizeMas)
{
	for (size_t i = 0; i < sizeMas; i++)
	{
		pushBack(mas[i]);
	}
}
template<typename dataType>
bool queueList<dataType>::pushBack(dataType var, unsigned priority)
{
	node* temp = new node(var, tail);
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		if (priority == 0)
		{
			temp->left = tail;
			tail->right = temp;
			tail = temp;
		}
		else
		{
			AddWithPriority(priority, temp);
		}
	}
	size++;
	return true;
}
template<typename dataType>
bool queueList<dataType>::popFront(dataType & var)
{
	if (head != nullptr)
	{
		var = head->data;
		node* temp = head;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head->right;
			head->left = nullptr;
		}
		size--;
		delete temp;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename dataType>
bool queueList<dataType>::Back(dataType & var) const
{
	if (tail != nullptr)
	{
		var = tail->data;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename dataType>
bool queueList<dataType>::Front(dataType & var) const
{
	if (head != nullptr)
	{
		var = head->data;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename dataType>
bool queueList<dataType>::printQueue() const
{
	node* temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << endl << "end queue" << endl;
	return true;
}
template<typename dataType>
bool queueList<dataType>::printRevers() const
{
	node* temp = tail;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->left;
	}
	cout << endl << "end queue" << endl;
	return true;
}
template<typename dataType>
void queueList<dataType>::AddWithPriority(unsigned p, node* t)
{
	node* temp = tail;
	if (p < size)
	{
		for (size_t i = 1; i < p; i++)
		{
			temp = temp->left;
		}
		t->left = temp->left;
		t->right = temp;
		temp->left->right = t;
		//temp->right = t;
		temp->left = t;
		//temp = t;
	}
	else
	{
		t->right = head;
		head->left = t;
		head = t;
	}
}

class client
{
private:
	int Snumber;
	int priority;
	int num;
public:
	client() : client(10) {}
	client(int num)
	{
		priority = rand() % 10;
		Snumber = rand();
		this->num = num;
	}

	void Print()
	{
		cout << num << " ";
		cout << Snumber << endl;
	}

	client& operator=(client & const obj)
	{
		this->num = obj.num;
		this->priority = obj.priority;
		this->Snumber = obj.Snumber;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const client & obj);

	void cleanPriority()
	{
		this->priority = 0;
	}

	int GetPriority()
	{
		return this->priority;
	}
};

ostream& operator<<(ostream& out, const client & obj)
{
	out << obj.num << " " << obj.Snumber << endl;
	return out;
}

void PrinterQueue(queueList<client>& arr, queueList<client>& statArr)
{	
	client _temp(0);
	int size = rand() % 30;
	cout << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		client temp(i + 1);
		arr.pushBack(temp, temp.GetPriority());
		temp.cleanPriority();
		statArr.pushBack(temp);
	}

	//arr.printQueue();

	for (size_t i = 0; i < size; i++)
	{
		arr.popFront(_temp);
		_temp.Print();
	}
	cout << "end print" << endl;
}

void main()
{
	FILE* f;
	srand(time(nullptr));
	
	client* masClient = nullptr;
	queueList<client> queueClient(masClient, 0);
	queueList<client> queueClientStat(masClient, 0);

	PrinterQueue(queueClient, queueClientStat);
	cout << " ";
	queueClientStat.printQueue();

	system("pause");
	return;
}