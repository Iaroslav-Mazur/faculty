void main()
{
	Translate t;
	t.AddTranslate("are","has");
	t.AddTranslate("mere","apples");
	cout << "Cuvinte = " << t.GetCount() << ", mere =" << t.GetTranslate("mere") << endl;
	string s = t.Translate("Ana are mere");
	cout << s << endl; // afiseaza "Ana has apples"
	t.ReverseTranslate();
	s = t.Translate("Ana has apples");
	cout << s << endl; // afiseaza "Ana are mere"
}