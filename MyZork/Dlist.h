#ifndef _DLIST_
#define _DLIST_

typedef unsigned int uint;

template<class TYPE>
class DList
{
public:

	struct DNode
	{
		TYPE data;
		DNode* next = nullptr;
		DNode* prev = nullptr;

		DNode(const TYPE& data) :data(data){}
		~DNode(){}
	};

	DNode* first = nullptr;

public:
	DList(){};
	~DList(){};

	bool empty() const
	{
		return first == nullptr;
	}

	uint size() const
	{
		uint n_elements = 0;
		DNode* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			n_elements++;
		}
		return n_elements;
	}

	DNode* end() const
	{
		DNode* temp = first;

		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE& data)
	{
		DNode* temp = first;
		DNode* new_node = new DNode(data);

		if (temp == nullptr)
		{
			first = new_node;
		}

		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
	}

	void push_front(const TYPE& data)
	{
		DNode* new_node = new DNode(data);

		if (first == nullptr)
		{
			first = new_node;
		}

		else
		{
			new_node->next = first;
			first->prev = new_node;
			first = new_node;
		}
	}

	bool pop_back()
	{
		if (first != nullptr) //size != 0
		{
			if (first->next != nullptr) //size > 1
			{
				DNode* temp = first;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->prev->next = nullptr;
				delete temp;
			}
			else //size = 1
			{
				DNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	bool pop_front()
	{
		if (first != nullptr) //size != 0
		{
			if (first->next != nullptr)
			{
				DNode* temp = first;
				first = temp->next;
				first->prev = nullptr;
				delete temp;
			}
			else
			{
				DNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	void erase(DNode* toerase)
	{
		if (size() > 1)
		{
			if (toerase->prev == nullptr)
			{
				first = toerase->next;
				first->prev = nullptr;
			}
			else if (toerase->next == nullptr)
			{
				toerase->prev->next = nullptr;
			}
			else
			{
				toerase->prev->next = toerase->next;
				toerase->next->prev = toerase->prev;
			}
			delete toerase;
		}
		else
		{
			first = nullptr;
			delete toerase;
		}
	}

	void insert(DNode* toinsert, const TYPE& data)
	{
		DNode* new_node = new DNode(data);
		if (first != nullptr)
		{
			if (toinsert->prev == nullptr)
			{
				new_node->next = toinsert;
				toinsert->prev = new_node;
				first = new_node;
			}

			else
			{
				new_node->next = toinsert;
				toinsert->prev->next = new_node;
				new_node->prev = toinsert->prev;
				toinsert->prev = new_node;
			}
		}

		else
		{
			first = new_node;
		}
	}

	void clear()
	{
		DNode* n = first;
		DNode* next;
		while (n != nullptr)
		{
			next = n->next;
			delete n;
			n = next;
		}
		first = nullptr;
	}

};

#endif