import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Catalog catalog = new Catalog();
        ArrayList<Command> commands = new ArrayList<Command>();
        commands.add(new ListCommand(catalog));
        commands.add(new AddCommand(catalog));

        String inp = "";
        Scanner sc = new Scanner(System.in);
        while(!inp.equals("q"))
        {
            System.out.print(">> ");
            inp = sc.nextLine();
            boolean found = false;

            for(Command cmd : commands)
            {
                if(inp.startsWith(cmd.getPrefix()))
                {
                    found = true;
                    String aux;
                    aux = inp.substring(cmd.getPrefix().length());
                    try{
                        cmd.run(aux);
                    }
                    // NOTE(mmicu): poate ar fi mai okay sa prindem 
                    // doar CommandError si nu toata exceptia de baza 
                    catch(BaseException exp)
                    {
                        System.out.println("Exception: " + exp.toString());
                    }
                }
            }

            if(!found && !inp.equals("q"))
            {
                System.out.println("Command '" + inp + "' not found!");
            }
        }
    }
}
