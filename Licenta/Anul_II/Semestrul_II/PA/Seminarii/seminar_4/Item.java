abstract class Item
{
    static public String type;
    private String name;
    private String path;
    Item(String name, String path)
    {
        /*
         * TODO(mmicu): Aici ar trebui verificat path-ul in caz contrar se arunca o exceptie custom
         */
        this.name = name;
        this.path = path;

    }

    /* To implement :
     * getName
     * setName
     * getPath
     * */

    abstract public void display();
}
