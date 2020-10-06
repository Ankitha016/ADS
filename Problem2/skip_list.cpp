#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int key;
		Node **forward;
		Node(int, int);
};
Node::Node(int key, int level)
{
	this->key = key;
	forward = new Node*[level+1];
	memset(forward, 0, sizeof(Node*)*(level+1));
};
class SkipList
{
	int MaxLvl;
	float p;
	int level;
	Node *head;
	public:
		SkipList(int, float);
		int randomLevel();
		Node* createNode(int, int);
		void insert(int);
		void delete_ele(int);
		void search(int);
		void display();
		
};
SkipList::SkipList(int MaxLvl, float p)
{
	this->MaxLvl = MaxLvl;
	this->p = p;
	level = 0;
	head = new Node(-1, MaxLvl);
};

int SkipList::randomLevel()
{
	float r = (float)rand()/RAND_MAX;
	int l = 0;
	while(r<p && l<MaxLvl)
	{
		l++;
		r = (float)rand()/RAND_MAX;
	}
	return l;
}

Node* SkipList::createNode(int key, int level)
{
	Node *newn = new Node(key, level);
	return newn;
};

void SkipList::insert(int key)
{
	Node *curr = head;
	Node *update[MaxLvl+1];
	memset(update, 0, sizeof(Node*)*(MaxLvl+1));
	for(int i = level; i>=0; i--)
	{
		while(curr->forward[i]!=NULL && curr->forward[i]->key < key)
		{
			curr = curr->forward[i];
		}
		update[i] = curr;
	}
	curr = curr->forward[0];
	if(curr == NULL || curr->key != key)
	{
		int rlvl = randomLevel();
		if(rlvl > level)
		{
			for(int i=level+1; i<rlvl+1; i++)
			{
				update[i] = head;
			}
			level = rlvl;
		}
		Node *newn = createNode(key, rlvl);
		for(int i=0; i<=rlvl; i++)
		{
			newn->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = newn;
		}
	}
};

void SkipList::delete_ele(int key)
{
	Node *curr = head;
	Node *update[MaxLvl+1];
	memset(update, 0, sizeof(Node*)*(MaxLvl+1));
	for(int i = level; i>=0; i--)
	{
		while(curr->forward[i]!=NULL && curr->forward[i]->key < key)
		{
			curr = curr->forward[i];
		}
		update[i] = curr;
	}
	curr = curr->forward[0];
	if(curr != NULL || curr->key == key)
	{
		for(int i=0;i<=level;i++)
		{
			if(update[i]->forward[i] != curr)
				break;
			update[i]->forward[i] = curr->forward[i];
		}
		while(level>0 && head->forward[level] == 0)
			level--;
	}
};

void SkipList::search(int key)
{
	Node *curr = head;
	for(int i=level; i>=0; i--)
	{
		while(curr->forward[i]!=NULL && curr->forward[i]->key < key)
		{
			curr = curr->forward[i];
		}
	}
	curr = curr->forward[0];
	if(curr != NULL && curr->key == key)
		cout<<"Found "<<key<<endl;
	else{
		cout<<"Not found"<<endl;
	}
};
	

void SkipList::display()
{
	cout<<"The list is"<<endl;
	for(int i=0; i<=level; i++)
	{
		Node *node = head->forward[i];
		cout<<"Level "<<i<<": ";
		while(node!=NULL)
		{
			cout<<node->key<<" ";
			node = node->forward[i];
		}
		cout<<endl;
	}
};

int main()
{
	srand((unsigned)time(0));
	SkipList list(3, 0.5);
	int n,ele,key,ch;
	cout<<"Enter the number of elements to be inserted"<<endl;
 	cin>>n;
        cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		list.insert(ele);
	}
	cout<<"After insertion"<<endl;
	list.display();
	cout<<"Enter 1 to delete 2 to search a element 0 to exit"<<endl;
	cin>>ch;
	
	while(ch!=0)
	{
	cout<<"enter the element"<<endl;
	cin>>key;
	switch(ch)
	{
		case 1:	list.delete_ele(key);
			cout<<"after deletion";
			list.display();
			break;
		case 2: list.search(key);
			break;
		default: break;
	}
	cout<<"Enter 1 to delete 2 to search a element 0 to exit"<<endl;
	cin>>ch;
	}
	return 0;
}



