#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int num;
	Node **next_arr;
	Node(int, int);
};

Node::Node(int num, int layer)
{
	this->num = num;

	next_arr = new Node*[layer + 1];

	memset(next_arr, 0, sizeof(Node*)*(layer+1));
};

class SkipList
{
	int upper_layer;
	int num_of_layers;
	float num_of_ptrs;
	int layer;
	Node *head;

public:
	SkipList(int, float);
	int random_layer();
	Node* intiate_node(int, int);
	int Insert(int);
	int Search(int);
	void Delete(int);
	int get_max();
	int getLayers();
	void printLayer(int);
};

SkipList::SkipList(int upper_layer, float num_of_ptrs)
{
	this->upper_layer = upper_layer;
	this->num_of_ptrs = num_of_ptrs;
	layer = 0;
	num_of_layers = upper_layer + 1;
	head = new Node(-1, upper_layer);
};

int SkipList::random_layer()
{
  	float random_head = (float)rand()/RAND_MAX;
	int layer_num = 0;
	while (random_head < num_of_ptrs && layer_num < upper_layer)
	{
		random_head = (float)rand()/RAND_MAX;
        layer_num++;
	}
	return layer_num;
};

Node* SkipList::intiate_node(int num, int layer)
{
	Node *node = new Node(num, layer);
	return node;
};

int SkipList::Insert(int num)
{
	Node *current = head;
	Node *neww[upper_layer + 1];
	memset(neww, 0, sizeof(Node*)*(upper_layer + 1));

	for (int i = layer; i >= 0; i--)
	{
		while (current->next_arr[i] != NULL && current->next_arr[i]->num < num)
        {
            current = current->next_arr[i];
        }
		neww[i] = current;
	}
	current = current->next_arr[0];

	if (current == NULL || current->num != num)
	{
		int rLayer = random_layer();

		if (rLayer > layer)
		{
			for (int i = layer + 1; i < rLayer + 1; i++)
            {
				neww[i] = head;
			}
            layer = rLayer;
		}

		Node* n = intiate_node(num, rLayer);
		for (int i=0; i <= rLayer ;i++)
		{
			n->next_arr[i] = neww[i]->next_arr[i];
			neww[i]->next_arr[i] = n;
		}
	}
	return num;
};

int SkipList::Search(int num)
{
    int maxm = get_max();
    int flag = 0;
    Node *current = head;
    Node *cur;

    for(int i = layer; i >= 0; i--)
    {
        while(current->next_arr[i] != NULL && current->next_arr[i]->num < num)
        {
            current = current->next_arr[i];
            flag++;
        }
    }

    cur = current;
    current = current->next_arr[0];

    if(num > maxm)
    {
        return -1;
    }
    if(current->num == num)
    {
        return flag;
    }
    else
    {
        return -1;
    }

};

void SkipList::Delete(int num)
{
    Node *current = head;
    Node *neww[upper_layer + 1];
    memset(neww, 0, sizeof(Node*)*(upper_layer + 1));

    for(int i = layer; i >= 0; i--)
    {
        while(current->next_arr[i] != NULL  && current->next_arr[i]->num < num){
            current = current->next_arr[i];
        }
        neww[i] = current;
    }
    current = current->next_arr[0];

    if(current != NULL && current->num == num)
    {
        for(int i = 0; i <= layer; i++)
        {

            if(neww[i]->next_arr[i] != current)
            {
                break;
            }
            neww[i]->next_arr[i] = current->next_arr[i];
        }

        while(layer > 0 && head->next_arr[layer] == 0){
            layer--;
            }
         cout<< "key:"<< num << " is deleted"<<endl<<endl;
    }
};

int SkipList::get_max()
{
    int maxm = 0;
    Node *current = head;

    for(int i = layer; i >= 0; i--)
    {
        while(current->next_arr[i] != NULL)
        {
            current = current->next_arr[i];
            if (current->num > maxm)
            {
                maxm = current->num;
            }
        }
    }

    return maxm;

};

int SkipList::getLayers()
{
    return num_of_layers;
};

void SkipList::printLayer(int layerNum)
{
    if(layerNum < num_of_layers)
    {
        cout << "L" << layerNum << " : ";
        Node *node = head->next_arr[layerNum];
        while (node != NULL)
        {
            cout << node->num<<" ";
            node = node->next_arr[layerNum];
        }
        cout<<endl<<endl;
    }
    else
    {
        cout<<"layer not found"<<endl;
    }
};

int main()
{
    srand((unsigned)time(0));
    int choice;
    int listSize;
    int elem;
    int maxLayer;

    cout<<endl<<"please enter number of the upper layer"<<endl;
    cin>> maxLayer;
    cout<<endl<<"please enter number of elements to insert"<<endl;
            cin>> listSize;
            SkipList skipList(maxLayer,0.5);
            cout<<"please insert elements "<<endl;

            for(int i = 0; i < listSize; i++)
            {
                cin>> elem;
                skipList.Insert(elem);
            }

    do{
        cout<<"please enter a choice from 1 to 6"<<endl<<endl;
        cout<<"1- search element"<<endl;
        cout<<"2- delete element"<<endl;
        cout<<"3- print elements of certain layer"<<endl;
        cout<<"4- print number of layers"<<endl;
        cout<<"5- exit"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            srand((unsigned)time(0));
            cout<<"enter the element you want to search for"<<endl;
            cin>> elem;
            if (skipList.Search(elem) == -1)
            {
                cout<<"element doesn't exist in the list"<<endl;
            }
            else
            {
                cout<<"element exists in the list"<<endl;
            }
            cout<< "Number of search steps for element "<< elem << " is: " << skipList.Search(elem)<<endl;
        }

        else if(choice == 2)
        {
            cout<<"please enter the element you want to delete"<<endl;
            cin>> elem;
            if (skipList.Search(elem) == -1)
            {
                cout<<"element doesn't exist in the list"<<endl;
            }
            else
            {
                skipList.Delete(elem);
            }
        }

        else if(choice == 3)
        {
            srand((unsigned)time(0));
            cout<<"please enter the number of layer you want to print"<<endl;
            cin>> elem;
            skipList.printLayer(elem);
        }

        else if(choice == 4)
        {
            cout<< "Number of layers = "<< skipList.getLayers()<<endl;
        }

    }while(choice!=5);

/*	SkipList skipList(4,0.5);
	skipList.Insert(2);
	skipList.Insert(10);
	skipList.Insert(15);
	skipList.Insert(16);
	skipList.Insert(31);
	skipList.Insert(71);
	skipList.Insert(86);
	skipList.Insert(89);
	skipList.Insert(91);
	skipList.Insert(96);

    skipList.Delete(86);

	cout<< "Number of search steps is: "<< skipList.Search(86)<<endl;
	/*cout<< "Number of search steps is: "<< skipList.Search(16)<<endl;
	cout<< "Number of search steps is: "<< skipList.Search(160)<<endl;

	cout<< "Number of layers = "<< skipList.getLayers()<<endl;

	skipList.printLayer(1);
	skipList.printLayer(4);
	skipList.printLayer(0);*/

	return 0;
}
