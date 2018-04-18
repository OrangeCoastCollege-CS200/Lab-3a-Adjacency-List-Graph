#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string>					
using namespace std;

class Node
{
public:
	Node() : link(nullptr) {}
	Node(string theInfo, Node *theLink) : info(theInfo), link(theLink) {}
	Node *getLink() const { return link; }
	string getInfo() const { return info; }
	void setInfo(string theInfo) { info = theInfo; }
	void setLink(Node *theLink) { link = theLink; }
	~Node() {}
private:
	string info;
	Node *link;
};


class AnyList
{
	friend ostream& operator<<(ostream& out, const AnyList& theList);

public:
	AnyList();	

	void insertFront(const string&  newInfo);
	void insertBack(const string& newInfo);

	int getCount() const;		

	AnyList& operator=(const AnyList& otherList);

	void destroyList();
	~AnyList();

private:
	Node *first; 
	int count;	      
};

#endif