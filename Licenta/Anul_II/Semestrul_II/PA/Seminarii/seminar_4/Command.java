abstract class Command
{
    public String prefix;
    Command(String prefix)
    {
        this.prefix = prefix;
    }

    abstract public void run(String info);
    /* TODO(mmicu): va arunca o excettie custom in functie de eroare intalnita */
}
