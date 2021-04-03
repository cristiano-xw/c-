typedef unsigned long Item;

class stack
{
	private:
		enum {MAX=10};
		Item items[MAX];
		int top;
	
	public:
		stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item &item);
		bool pop(Item & item);
};

stack::stack()
{
	top=0;
}

bool stack::isempty() const
{
	return top==0;   //≈–∂œ «∑Ò «ø’’ª 
}

bool stack::isfull() const
{
	return top==MAX;//≈–∂œ «∑Ò¬˙’ª 
}

bool stack::push(const Item &item)
{
	if(top<MAX)
	{
		items[top++]=item;
		return true;
	}
	
	else 
		return false;
} 

bool stack::pop(Item & item)
{
	if(top>0)
	{
		item=items[--top];
		return true;
	}
	else
		return false;
}

