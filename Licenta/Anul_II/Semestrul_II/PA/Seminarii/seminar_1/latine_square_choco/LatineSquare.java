import java.util.*;
public class LatineSquare{
    public static int NR = 0;
    public static int SOLS = 0;
    public static int REST;
    public static int START;
    public static boolean STOP = false;

    private static boolean check(int[][] vals)
    {
        for (int i = 0; i < NR; i ++)
        {
            for (int j = 0; j < NR-1; j++)
            {
                for(int k = j+1; k<NR; k++)
                {
                    if(vals[i][j] == vals[i][k])
                        return false;
                }
            }
        }

        for (int i = 0; i < NR-1; i ++)
        {
            for (int j = 0; j < NR; j++)
            {
                for(int k = i+1; k<NR; k++)
                {
                    if(vals[i][j] == vals[k][j])
                        return false;
                }
            }
        }

        return true;
    }

    public static boolean solutie(int[][] vals)
    {
        SOLS += 1 ;
        for (int i = 0; i < NR; i++)
        {
            for (int j = 0; j < NR; j++)
            {
                int aux = START + vals[i][j];
				System.out.print(" " + Character.toString((char)aux) + " ");
            }
            System.out.println();
        }
        System.out.println();


        if(SOLS > REST-1)
        {
            STOP = true;
        }
        return true;
    }

    public static int cauta(int[][] vals, int x, int y)
    {
        for(int i=0; i<NR; i++){
            if(STOP)
            {
                return 0;
            }
            vals[x][y] = i;

            if(check(vals))
            {
                solutie(vals);
            }

            if(x+1 == NR)
            {
                if(y+1 == NR)
                {
                    // finalul matrici
                }
                else
                {
                    cauta(vals, 0, y+1);
                }
            }
            else
            {
                cauta(vals, x+1, y);
            }
        }
        return 0;
    }

	public static void main(String args[]) {
        String limba;
        if (args.length < 3)
        {
            System.out.println("[n: size of the square] [symbols: latin or greek] [max: nr max shown]");
			NR = 3;
			limba = "latin";
        }else
		{
			NR = Integer.parseInt(args[0]);
			limba = args[1];
            REST = Integer.parseInt(args[2]);
		}
        if(!limba.equals("greek") && !limba.equals("latin"))
        {
            System.out.println("Argumentul pentru limba " + limba + " este invalid.");
            System.out.println("[n: size of the square] [symbols: latin or greek]");
            System.exit(1);
        }

		switch(limba)
		{
		case  "greek":
			START = 0x03B1; 
			break;

		case  "latin":
			START = 97;
			break;
		}
        SOLS = 0;
        int[][] vals = new int[NR][NR];

        for (int i = 0; i < NR; i++)
            for (int j = 0; j < NR; j++)
                vals[i][j] = 0;

        cauta(vals, 0, 0);
	}
}
