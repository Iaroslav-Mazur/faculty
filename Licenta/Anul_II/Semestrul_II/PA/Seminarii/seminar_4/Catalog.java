import java.util.*;
class Catalog 
{
    private ArrayList<Item> items;
    Catalog()
    {
        this.items = new ArrayList<Item>();
    }

    public void  addItem(Item i)
    {
        this.items.add(i);
    }

     public void removeItem(Item i)
     {
         this.items.remove(i);
     }

     public void show(String itemName)
     {
         boolean found = false;
         // Search for the item
         for(Item i: this.items)
         {
             if(i.getName().equals(itemName))
             {
                 found = true;
                 i.display();
             }
         }

         if(!found)
         {
             System.out.println("Nu s-a gasit nici un item cu numele "+itemName);
         }
     }

     public ArrayList<Item> getItems()
     {
         return new ArrayList<Item>(this.items);
     }


    /* To implement :
     * save(path)
     * report # genereaza reportul html, xml, json
     */

}
