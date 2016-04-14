void main(void)
{
	Tree t;
	Node *r = t.CreateRoot(100);
	for (int tr=0;tr<10;tr++)
		r->AddNode(Node(tr));
	r = r->Get(3);
	for (int tr=20;tr<30;tr++)
		r->AddNode(Node(tr));
	t.Show();		
}