void main ()
{
	Punct **points=(Punct**)malloc(4*sizeof(Punct*));
	Figure **figs=(Figure**)malloc(5*sizeof(Figure*));
	int puncte[4][2]={{10,2},{12,0},{14,13},{6,13}};
	int i;

	for (i=0;i<4;i++)
	    points[i]=new Punct(puncte[i][0],puncte[i][1]);

	figs[0]=(Figure*)new Cerc(points[0],5);
	figs[1]=(Figure*)new Patrat(points[2],4);
	figs[2]=(Figure*)new Patrat(points[3],5);
	figs[3]=(Figure*)new Triunghi(points[0],points[1],points[3]);
      
	// Cream un vector de figuri geometrice

	vector <Figure*> vfig;
	for (i=0;i<4;i++)
	    vfig.push_back(figs[i]);

        //[3p] Sortam vectorul crescator in functie de perimetru
   
        
        //[3p] Sortam vectorul descrescator in functie de arie
}