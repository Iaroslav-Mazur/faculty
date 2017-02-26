import java.util.Vector;
import java.util.Enumeration;
import java.io.Serializable;

public class Aeroport implements Help, Serializable
{
    private String name;
    protected String type;
    protected Vector<BaseContainerAeronava> items;

    public Aeroport(String name)
    {
        this.name = name;
        this.type = "Aeroport";
        this.items = new Vector<BaseContainerAeronava>();
    }

    public String getName()
    {
        return this.name;
    }

    public String getType()
    {
        return this.type;
    }

    public BaseContainerAeronava getItem()
    {
        return this.items.firstElement();
    }

    public void addItem(BaseContainerAeronava item)
    {
        this.items.addElement(item);
    }

    public void printHelp(String paddingLeft)
    {
        System.out.print(paddingLeft);
        System.out.println("Type:" + this.type + "  Name: " + this.name);
        for(int i = 0; i < this.items.size(); i++)
        {
            this.items.get(i).printHelp(paddingLeft);
        }
    }

    public void printHelp()
    {
        this.printHelp(" ");
    }
}
