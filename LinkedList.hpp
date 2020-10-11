#pragma once 
template <class T>
class LinkedList
{
private:
	template <class T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node<T>* head;
public:
	LinkedList()
	{
		this->size = 0;
		head = nullptr;
	}
	LinkedList(T* items, int count)
	{
		//if (count < 0)
		//	throw std::exception("The size cannot be < 0");
		this->size = count;
		this->head = nullptr;
		T ptemp;
		for (size_t i = 0; i < count; i++)
		{
			ptemp = items;
			if (head == nullptr)
			{
				head = new Node<T>(ptemp);
			}
			else
			{
				Node<T>* temp = head;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = new Node<T>(ptemp);
			}
		}
	}
	LinkedList(LinkedList<T>& other)
	{
		this.head = nullptr;
		this.size = other.Getsize();
		for (size_t i = 0; i < other.Getsize(); i++)
		{
			this.Prepend(other.Get(i));
		}
	}
public:
	T& operator[](const int index)
	{
		//if (index < 0 || index >= this->size)
			//throw std::exception("undefined index");
		int count = 0;
		Node<T>* temp = this->head;
		while (temp != nullptr)
		{
			if (count == index)
			{
				return temp->data;
			}
			temp = temp->next;
			count++;
		}
	}
	T Get(const int index)
	{

		//if (index < 0 || index >= this->size)
			//throw std::exception("undefined index");
		int count = 0;
		Node<T>* temp = this->head;
		while (temp != nullptr)
		{
			if (count == index)
			{
				return temp->data;
			}
			temp = temp->next;
			count++;
		}
	}
	T GetFirst()
	{
		return Get(0);
	}
	T GetLast()
	{
		return Get(this->size - 1);
	}
	int Getsize()
	{
		return this->size;
	}
	void Prepend(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Node<T>(data);
		}
		this->size++;
	}
	void Apend(T data)
	{
		this->head = new Node<T>(data, head);
		this->size++;
	}
	void InsertAt(T data, const int index)
	{
		//if (index < 0 || index >= this->size)
		//	throw std::exception("undefined index ");
		if (index == 0)
		{
			Apend(data);
		}
		else
		{
			Node<T>* last = this->head;

			for (size_t i = 0; i < index - 1; i++)
			{
				last = last->next;
			}
			Node<T>* newNode = new  Node<T>(data, last->next);
			last->next = newNode;
		}
		this->size++;
	}
	void PopFront()
	{

		Node<T>* temp = this->head;
		this->head = this->head->next;

		delete temp;

		this->size--;


	}
	void Remove(const int index)
	{
		//if (index < 0 || index >= this->size)
			//throw std::exception("undefined index ");
		if (index == 0)
		{
			PopFront();
		}
		else
		{
			Node<T>* last = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				last = last->next;
			}
			Node<T>* ToDelete = last->next;
			last->next = ToDelete->next;

			delete ToDelete;
			this->size--;
		}
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		//if (startIndex >= this->size || endIndex >= this->size)
			//throw std::exception("undefined index");
		T* arrtemp = new T[endIndex - startIndex + 1];
		LinkedList<T>* Sublist;
		Sublist = new LinkedList<T>();
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			arrtemp[i] = this->Get(startIndex + i);
		}
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			Sublist->Prepend(arrtemp[i]);
		}
		return Sublist;
	}

	~LinkedList()
	{
		while (this->size)
		{
			PopFront();
		}
	}
};