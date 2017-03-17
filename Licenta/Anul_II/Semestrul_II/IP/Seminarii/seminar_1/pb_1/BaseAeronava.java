import java.io.Serializable;
public abstract class BaseAeronava implements Help, Serializable
{
    private String name;
    protected String type;
    public BaseAeronava(String name)
    {
        this.name = name; 
        this.type = "base_aeronava";
    }

    public String getName()
    {
        return this.name;
    }

    public String getType()
    {
        return this.type;
    }

    public void printHelp(String paddingLeft)
    {
        System.out.print(paddingLeft);
        System.out.println("Type:" + this.type + "  Name: " + this.name);
    }
}
