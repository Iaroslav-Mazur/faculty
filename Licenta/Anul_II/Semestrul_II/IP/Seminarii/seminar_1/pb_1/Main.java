import java.io.*;
public class Main 
{
    public static void generate()
    {
        System.out.println("Start !");
        Aeroport aeroport = new Aeroport("aeroport-1");

        Avion a1 = new Avion("a-1");
        Avion a2 = new Avion("a-2");
        Avion a3 = new Avion("a-3");
        Avion a4 = new Avion("a-4");

        Elicopter e1 = new Elicopter("e-1");
        Elicopter e2 = new Elicopter("e-2");
        Elicopter e3 = new Elicopter("e-3");
        Elicopter e4 = new Elicopter("e-4");

        Pista p1 = new Pista("Pista-1");

        Hangar h1 = new Hangar("Hangar-1");
        Hangar h2 = new Hangar("Hangar-2");

        p1.addItem(a1);
        p1.addItem(e1);

        h1.addItem(a2);
        h1.addItem(a3);
        h1.addItem(a4);

        h2.addItem(e2);
        h2.addItem(e3);
        h2.addItem(e4);

        aeroport.addItem(p1);
        aeroport.addItem(h1);
        aeroport.addItem(h2);

        aeroport.printHelp("");

        try {
         FileOutputStream fileOut = new FileOutputStream("data.ser");
         ObjectOutputStream out = new ObjectOutputStream(fileOut);
         out.writeObject(aeroport);
         out.close();
         fileOut.close();
         System.out.println("Serializare reuista in fisierul `data.ser`");
      }catch(IOException i) {
         System.out.println("Serializare esuata");
         i.printStackTrace();
      }

    }

    public static void read()
    {
      Aeroport aeroport = null;
      try {
         FileInputStream fileIn = new FileInputStream("data.ser");
         ObjectInputStream in = new ObjectInputStream(fileIn);
         aeroport = (Aeroport) in.readObject();
         in.close();
         fileIn.close();
      }catch(IOException i) {
         i.printStackTrace();
         return;
      }catch(ClassNotFoundException c) {
         System.out.println("Nu am gasit clasa.");
         c.printStackTrace();
         return;
      }
      aeroport.printHelp();
    }
    public static void main(String args[])
    {
        /*
         * -d pentru deserializare din fisierul cu numele `data.ser`
         * -g pentru generarea (serializarea) structuri in fisierul
         *    cu numele `data.ser`
         *
         */
        if (args.length < 1)
        {
            System.out.println("Nici un argument -d/-g");
            System.exit(1);
        }
        String opt = args[0];

        switch (opt)
        {
            case "-d":
                read();
                break;
            case "-g":
                generate();
                break;  
        }
    }
}
