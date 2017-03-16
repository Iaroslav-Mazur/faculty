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
    }
}
