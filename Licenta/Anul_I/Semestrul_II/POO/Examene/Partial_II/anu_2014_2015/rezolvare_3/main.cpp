void main()
{
	Graph g;

	g.AddNode(10,10,100);
	g.AddNode(10,20,200);
	g.AddNode(20,20,300);
	g.AddEdge(0,1);
	g.AddEdge(1,2);
	printf("Node 1 value is %d\n",g.GetNode(1)->Value);
	g.AddNode(0,0,200);
	printf("Nodes = %d, Edges=%d, Conex=%d\n",g.GetNodesCount(),g.GetEdgesCount(),g.IsConex());
}
