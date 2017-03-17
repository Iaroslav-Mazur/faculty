import java.util.*;
class RemoveCommand extends Command
{
	private ArrayList<Item> items;

	RemoveCommand(Catalog catalog)
	{
	super("remove", catalog);
	}

	public void run(String info) throws CommandError
	{
	String temp=info;
	int start = 0;
	if (temp.charAt[start] == ' ')
		start++;
	String name = temp.substring(start);
	items = catalog.getItems();
	Item found;
	for(Item i : items)
        {
            if (i.getName() == name)
		found = i;
        }
	catalog.removeItem(found);

	}

}
