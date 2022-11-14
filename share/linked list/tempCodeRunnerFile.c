int main()
{
	struct node *head=NULL;
	while(1)
	{
	int ch;
	printf("\n PRESS 1 TO CREATE:");
	printf("\n PRESS 2 TO DISPLAY:");
	printf("\n PRESS 3 TO INSERT:");
	printf("\n PRESS 5 TO Exit:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		head=append(head);
		break;
		case 2:
		display(head);
		break;
		case 3:
		head=insert(head);
		break;
		case 5:
		exit(0);	
	}
}
return 0;
}
