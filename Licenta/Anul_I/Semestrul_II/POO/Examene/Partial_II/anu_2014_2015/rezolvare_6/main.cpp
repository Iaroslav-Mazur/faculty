void main()
{
	Deplasare d;
	d.AddCommand('l', 2);
	d.AddCommand('b', 2);
	d.AddCommand('l', 4);
	d.AddCommand('t', 6);
	d.AddCommand('r', 10);
	cout << d.AddCommand('p', 10) << ", " << d.AddCommand('l', 0) << endl;  // 0, 0
	cout << d.GetCommandsCount() << endl;  // 5
	
	d.Execute(1); // coordonatele o sa fie (-2,0)
	d.Execute(2); // se ruleaza 2 comenzi - prima data Bottom(2) si apoi Left(4) -> punctul final va fi la (-6,-2)
	d.Execute(1); // se ruleaza o comanda Top(6) - punctul va fi la (-6,4)
	cout << d.Execute(4) << endl; // returneaza false
	int x,y;
	d.GetCoord(x,y);
	cout << "X=" << x << ",Y=" << y << endl; // afiseaza "X=4,Y=4"
	d.Reset();
	cout << d.GetRemainingCommands() << endl; // afiseaza 5
}