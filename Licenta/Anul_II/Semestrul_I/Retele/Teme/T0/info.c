    ## client 
        if(strncmp(buff, GET, strlen(GET)) == 0 && found == false){
            req[41];
            bzero(req, sizeof(req));
            req[0] = 'g'
            strncpy(req[1], buff[1], 20);
            strncpy(req[21], buff[21], 20);
            // g a.html     t.html
            // get 
            write(sd, req, sizeof(req));
            primeste(buf[21], sd);
        }

    daca vrem sa trimitem
    trimite(param_1, sd);

//g____________________

# server
# ai facut login
# login = 1

char* list()
{
    char buff[255];
    bzero(buff, 255);

    list
}

if(login=1)
{
    req[41];
    bzero(req, sizeof(req));
    while(req[0] != 'q')
    {
        read(client, req, sizeof(req));
        switch(req[0])
        {
            case('l'):
                // despachetare 
                char param_1[20]. param_2[20];
                strncpy(param_1, req[1], 20);
                strncpy(param_2, req[21], 20);
    
                char files[255] = list();

                write(client, htoni(strlen(files)), sizeof(int));
                break;
            case('g'):
                char param_1[20]. param_2[20];
                strncpy(param_1, req[1], 20);
                strncpy(param_2, req[21], 20);

                trimite(param_1, client);
                break;
            case('a'):
                char param_1[20]. param_2[20];
                strncpy(param_1, req[1], 20);
                strncpy(param_2, req[21], 20);

                primire(param_2, client);
                break;
            case('d'):
                char param_1[20]. param_2[20];
                strncpy(param_1, req[1], 20);
                strncpy(param_2, req[21], 20);

                remove(param_1);
                // 
                break;

        }
    }

}

# client
conecsiune facuta => ai sd
while(1)
{
    char param_1[20], param_2[20];
    bzero(param_1, sizeof(param_1));
    ... 
    read(opt, 1);
    char req[41];
    bzero(req, sizeof(req));
    req[0] = opt;
    switch(opt)
    {
        case('l'):
            int size;
            write(sd, req, sizeo(req));

            read(sd, &size, sizeof(size));
            size = ntohi(size);

            char buff[size];
            read(sd, buff, size);
            printf("Lista : %s \n",buff );
            fflush(stdout);
            break;        
        case('a'):
            scanf("%s", &param_1);
            scanf("%s", &param_2);
            strncpy(req[1], param_1, 20);
            strncpy(req[21], param_2, 20);

            // trimiti ca vrei sa adaugi din local param_1 in remote param_2
            write(sd, req, sizeo(req));
            trimite(param_1, sd);
            break;        

        case('g'):
            scanf("%s", &param_1);
            scanf("%s", &param_2);
            strncpy(req[1], param_1, 20);
            strncpy(req[21], param_2, 20);

            // trimiti mesaju ca vrei sa primesti din remote  param_1 in locam parma_2
            write(sd, req, sizeo(req));
            primeste(param_2, sd);
            break;        

        case('d'):
            scanf("%s", &param_1);
            strncpy(req[1], param_1, 20);

            // trimiti ca vrei sa deletezi param_1
            write(sd, req, sizeo(req));


            break;        
    }
}





## path

/home/mmicu/test
- a.txt -> /home/mmicu/test/a.txt
- b.txt

