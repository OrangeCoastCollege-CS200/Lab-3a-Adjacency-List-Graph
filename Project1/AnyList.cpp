#include "AnyList.h"

ostream& operator<<(ostream& out, const AnyList& theList)
{
	Node *current = theList.first;
	while (current != nullptr)
	{
		out << current->getInfo() << " ";
		current = current->getLink();
	}
	return out;
}

AnyList::AnyList()
{
	first = nullptr;
	count = 0;
}

void AnyList::insertFront(const string&  newInfo)
{
	first = new Node(newInfo, first);
	++count;
}

void AnyList::insertBack(const string& newInfo)
{
	if (first == nullptr)
		first = new Node(newInfo, nullptr);
	else
	{
		Node *current = first;
		while (current->getLink() != nullptr)
			current = current->getLink();
		current->setLink(new Node(newInfo, nullptr));
	}
	++count;
}

int AnyList::getCount() const
{
	return count;
}

AnyList& AnyList::operator=(const AnyList &otherList)
{
	if (this != &otherList)
	{
		destroyList();
		Node *current = otherList.first;
		while (current != nullptr)
		{
			insertBack(current->getInfo());
			current = current->getLink();
		}
	}
	else
		cerr << "Attempted assignment to self";

	return *this;
}

void AnyList::destroyList()
{ 
	Node  *temp = first;
	
	while (first != nullptr)
    {
		first = first->getLink();
        delete temp;
		temp = first;
    }

	count = 0;
}

AnyList::~AnyList()
{
	destroyList();
}