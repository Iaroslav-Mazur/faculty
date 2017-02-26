import java.util.Vector;
import java.io.Serializable;

public abstract class BaseContainerAeronava implements Help, Serializable
{
    private String name;
    protected String type;
    protected Vector<BaseAeronava> items;

    public BaseContainerAeronava(String name)
    {
        this.name = name;
        this.type = "base_container";
        this.items = new Vector<BaseAeronava>();
    }

    public String getName()
    {
        return this.name;
    }

    public String getType()
    {
        return this.type;
    }

    public BaseAeronava getItem()
    {
        return this.items.firstElement();
    }

    public void addItem(BaseAeronava item)
    {
        this.items.addElement(item);
    }

    public void printHelp(String paddingLeft)
    {
        System.out.print(paddingLeft);
        System.out.println("Type:" + this.type + "  Name: " + this.name);
        paddingLeft += "  ";

        for(int i = 0; i < this.items.size(); i++)
        {
            this.items.get(i).printHelp(paddingLeft);
        }
    }
}
