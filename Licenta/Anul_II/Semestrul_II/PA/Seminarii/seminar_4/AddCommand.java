import java.util.*;
class AddCommand extends Command
{
    AddCommand(Catalog catalog)
    {
        super("add", catalog);
    }

    public void run(String info) throws CommandError
    {
        // TODO(mmicu):
        // Comanda ca fi de forma
        // `add book 'path' 'nume' 'autor'`
        // `add song 'path' 'nume' 'autor'`
        // TREBUIE:
        //  - implementat un Item de tip Book
        //  - parsat al doilea parametru `book`, 'song' etc
        //  - implemetata crearea si adaugarea itemului la catalog

	String temp=info;
	String[] tokens = temp.split(" ");
	int start = 0;
	int position = 0;
	String name;
	String path;
	if (tokens[start].equals(" "))
		start = 1;
	if (tokens[start].equals("'book'"))
		//adaugam o carte
		position = start + 1;
		name = tokens[position];
		path = tokens[position+1];
		catalog.addItem(new Book(name.substring(1,name.length()-2), path.substring(1,path.length()-2)));
	
	if (tokens[start].equals("'song'"))
		//adaugam un cantec
		position = start + 1;
		name = tokens[position];
		path = tokens[position+1];
		catalog.addItem(new Song(name.substring(1,name.length()-2), path.substring(1,path.length()-2)));
	
    }
}
