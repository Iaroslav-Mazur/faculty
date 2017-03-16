abstract class Command
{
    protected String prefix;
    protected Catalog catalog;
    Command(String prefix, Catalog catalog)
    {
        this.prefix = prefix;
        this.catalog = catalog;
    }

    public String getPrefix()
    {
        return this.prefix;
    }

    abstract public void run(String info) throws CommandError;
    /* TODO(mmicu): va arunca o excettie custom in functie de eroare intalnita */
}
