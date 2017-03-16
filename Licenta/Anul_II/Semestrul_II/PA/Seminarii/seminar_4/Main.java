import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        ArrayList<Command> commands = new ArrayList<Command>();
        // commands.add(new)
        /* main 
         * - are o lista cu commands 
         * - apeleaza fiecare comanda in functie de cum prefix
         * */
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
                    try{
                        cmd.run(inp);
                    }
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
