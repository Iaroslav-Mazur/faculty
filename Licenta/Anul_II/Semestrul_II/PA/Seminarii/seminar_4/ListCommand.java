import java.util.*;
class ListCommand extends Command
{
    ListCommand(Catalog catalog)
    {
        super("list", catalog);
    }

    public void run(String info) throws CommandError
    {
        ArrayList<Item> items = this.catalog.getItems();
        System.out.println("Lista :");
        for(Item i : items)
        {
            System.out.println(i);
        }
    }
}
