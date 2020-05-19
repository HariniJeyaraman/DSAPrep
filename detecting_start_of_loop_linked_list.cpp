//Detecting the start of the loop or cycle in a linked list

//function that returns the node where the slow pointer and fast pointer coincide
node* check_loop(node* head)
{
    node *p=head;
    node *q=head;
    while(p && q && q->next)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
            return p;
    }
    return NULL;
}

//Essentially, the distance from the start of the loop from head is same as that from the node p(returned from the previous function)
node* start_loop(node* p, node* head)
{
    node *q=head;
    while(p!=q)
    {
        p=p->next;
        q=q->next;
    }
    return p; 
}