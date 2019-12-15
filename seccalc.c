#include"calc.c"

pList seccalc(pList list)//not sure >> noname list making
{
	pList = makeList();//noname list create
	struct node* head = NULL;
	pNode front = list->head;
	char temp;
	while(front!=NULL){
		if(isdigit(list -> data) || list -> data == '.'){
			insertBack(pList,makeNode(front->data));
		}
		else if(list->data == ' '){
			int *temp = &head;// in pointer, head address save
			push(&head,head_node->next) // in stack, saving this linked list's address of next node
			pList = makeList(); // new List
		}
		else if(list->data == '+' || list->data == '-' || list->data == '*'){


			temp = pop(&head);//address of next node from n1
			pList a = makeList();
			while()//while current node != \0
			{
				insertBack(a,makeNode(temp));
				node = node->next;
				temp = node->data;
			}

			temp = pop(&head);
			pList b = makeList();
			while()//same
			{
				insertBack(b,makeNode(temp));
				node = node->next;
				temp = node->data;
			}


			if(list->data == '+')
			{
				add( a, b);//add func
				//return
				freeList(a);
				freeList(b);
				push(&head,head_node->next);//saving this list's next node address
			}
			else if(list->data =='-')
			{
				minus( a, b);//minus func
				//return
				freeList(a);
				freeList(b);
				push(&head,head_node->next);//same
			}
			else if(list->data = '*')
			{
				multiply( a, b);
				//return
				freeList(a);
				freeList(b);
				push(&head,head_node->next);//same
			}
		}
		list = list->next;
		display(head);//checking
	}
	//return list
	//char?
	pList clist = makeList();
	while()//current node != \0
	{
		inserBack(clist,makeNOde(temp));
		node = node->next;
		temp = node->data;
	}
	return clist;
}

int main(void)
{
	printList(seccalc(list));
	freelist(clist);
}


			


			
		
