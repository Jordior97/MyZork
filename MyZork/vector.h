#ifndef _vector_
#define _vector_

#include<assert.h>


typedef unsigned int uint;

template<class TYPE>
class Vector
{
private:

	TYPE *vector = nullptr;
	uint max_size = 10;
	uint n_elements = 0;

public:

	/*---CONSTRUCTORS-DESTRUCTOR---*/
	Vector()
	{
		vector = new TYPE[max_size];
	}

	Vector(const Vector &other)
	{
		max_size = other.n_elements;
		vector = new TYPE[max_size];
		if (other.n_elements > 0)
		{
			n_elements = other.n_elements;
			for (int i = 0; i < n_elements; i++)
			{
				*(vector + i) = *(other.vector + i);
			}
		}
	}


	/*---MEMBER FUNCTIONS---*/

	void push_back(const TYPE &element)
	{

		if (max_size == n_elements)
		{
			TYPE *temp = nullptr;
			max_size += 5;
			temp = new TYPE[max_size];

			for (int i = 0; i < n_elements; i++)
			{
				*(temp + i) = *(vector + i);
			}
			delete[] vector;
			vector = temp;
		}
		*(vector + n_elements++) = element;
	}

	void push_front(const TYPE &element)
	{

		if (max_size == n_elements)
		{
			TYPE *temp = nullptr;
			max_size += 5;
			temp = new TYPE[max_size];

			for (int i = 0; i < n_elements; i++)
			{
				*(temp + i) = *(vector + i);
			}
			delete[] vector;
			vector = temp;
		}

		for (int i = n_elements - 1; i >= 0; i--)
		{
			*(vector + i + 1) = *(vector + i);
		}

		*(vector) = element;
		n_elements++;
	}

	~Vector()
	{
		delete[] vector;
	}

	TYPE &operator[](uint index) const
	{
		assert(index >= 0 && index < n_elements);
		return vector[index];
	}


	TYPE &operator[](uint index) 
	{
		assert(index >= 0 && index < n_elements);
		return vector[index];
	}

	bool empty() const
	{
		return n_elements == 0;
	}

	void clear()
	{
		n_elements = 0;
	}

	uint size() const
	{
		return n_elements;
	}

	uint capacity()const
	{
		return max_size;
	}

	void shrink_to_fit()
	{
		if (max_size != n_elements)
		{
			TYPE *temp = nullptr;
			max_size = n_elements;
			temp = new TYPE[max_size];
			for (int i = 0; i < max_size; i++)
			{
				temp[i] = vector[i];
			}
			delete[]vector;
			vector = temp;
		}
	}

	void pop_back()
	{
		if (n_elements > 0)
		{
			n_elements--;
		}
	}

	bool erase(uint index)
	{
		if (index < n_elements)
		{
			for (int i = index; i < n_elements; i++)
			{
				vector[i] = vector[i + 1];
			}
			n_elements--;

			return true;
		}
		return false;
	}

};


#endif