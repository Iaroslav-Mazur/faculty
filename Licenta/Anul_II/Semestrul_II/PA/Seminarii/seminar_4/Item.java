import java.nio.file.*;
abstract class Item
{
    static public String type;
    private String name;
    private String path;
    Item(String name, String path)
    {
        this.name = name;
        this.path = path;

    }

    public static void checkPath(String path) throws BrokenPathException
    {
        Path p = Paths.get(path);
        if(Files.exists(p))
        {
            throw new BrokenPathException("File " + path + " nu exista!");
        }

    }

    public String getPath()
    {
        return this.path;
    }

    public String getName()
    {
        return this.name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    abstract public void display();
}
