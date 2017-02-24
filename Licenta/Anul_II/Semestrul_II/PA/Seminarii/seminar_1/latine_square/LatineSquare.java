import java.util.*;
public class LatineSquare{
	public static void main(String args[]) {
        int N ;
        String limba;
        if (args.length < 2)
        {
            System.out.println("[n: size of the square] [symbols: latin or greek]");
			N = 3;
			limba = "latin";
        }else
		{
			N = Integer.parseInt(args[0]);
			limba = args[1];
		}
        if(!limba.equals("greek") && !limba.equals("latin"))
        {
            System.out.println("Argumentul pentru limba " + limba + " este invalid.");
            System.out.println("[n: size of the square] [symbols: latin or greek]");
            System.exit(1);
        }

		int start = 0;
		switch(limba)
		{
		case  "greek":
			start = 0x03B1;
			break;

		case  "latin":
			start = 97;
			break;
		}
		for (int i=0; i<N;i++)
		{
			for (int j=0; j<N;j++)
			{
				int aux = start + i + j;
				if(aux >= start + N ){
				aux = (aux) % (start + N - 1) + start - 1;
				}
				System.out.print( Character.toString((char)aux));
			}
			System.out.println();
		}
	}
}
