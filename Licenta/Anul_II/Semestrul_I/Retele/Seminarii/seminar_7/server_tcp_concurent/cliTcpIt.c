/* cliTCPIt.c - Exemplu de client TCP
   Trimite un nume la server; primeste de la server "Hello nume".
         
   Autor: Lenuta Alboaie  <adria@infoiasi.ro> (c)2009
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* portul de conectare la server*/
int port;

struct i{
    int nr1, nr2;
    char operator;
};

int main (int argc, char *argv[])
{
  int sd;			// descriptorul de socket
  struct sockaddr_in server;	// structura folosita pentru conectare 
  int msg;
  struct i info;
  /* exista toate argumentele in linia de comanda? */
  if (argc != 3)
    {
      printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
      return -1;
    }

  /* stabilim portul */
  port = atoi (argv[2]);

  /* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET;
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr(argv[1]);
  /* portul de conectare */
  server.sin_port = htons (port);
  
  /* ne conectam la server */
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }

  /* citirea mesajului */
  struct info;
  bzero (&info, sizeof(info));

  // close the server
  if(info.nr1 != -1){
      for(; ;){

        bzero (&info, sizeof(info));
        printf ("[client]Primul numar: ");
        fflush (stdout);
        scanf("%d",&info.nr1);

        printf ("[client]Al doilea numar: ");
        fflush (stdout);
        scanf("%d",&info.nr2);

        printf ("[client]Semnul numar: ");
        fflush (stdout);
        read (0, &info.operator, sizeof(info.operator));
        printf("[client]Mesaj %d  %c  %d \n", info.nr1, info.operator, info.nr2);

        /* trimiterea mesajului la server */
        if (write (sd, &info, sizeof(info)) <= 0)

            {
            perror ("[client]Eroare la write() spre server.\n");
            return errno;
            }

        /* citirea raspunsului dat de server 
            (apel blocant pina cind serverul raspunde) */
        if (read (sd, &msg, sizeof(msg)) < 0)
            {
            perror ("[client]Eroare la read() de la server.\n");
            return errno;
            }
        /* afisam mesajul primit */
        printf ("[client]Mesajul primit este: %d\n", msg);
      }
  }
  /* inchidem conexiunea, am terminat */
  close (sd);
}
