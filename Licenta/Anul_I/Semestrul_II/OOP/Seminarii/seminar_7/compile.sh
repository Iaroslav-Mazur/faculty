#!/usr/bin/env bash

EDITOR="nvim"
ERR_FILE="file.err"

function iesi(){
    echo ""
    echo "  Bye !";
    echo ""
    exit 0;
}

function informatii(){

    echo ""

    echo "  1) Editeaza"
    echo "  2) Compileaza"
    echo "  3) Ruleaza"
    echo "  4) Afiseaza erori"
    echo "  5) Bye"

    echo ""
}

function afisea_erori(){
    if [[ -f "$ERR_FILE" ]]; then
        echo ""
        echo "  Erorile :"
        echo ""
        cat "$ERR_FILE"
        echo ""
    else
        echo ""
        echo "  Nu exista un fisier cu erori !"
        echo ""
    fi
    main;
}

function ruleaza(){
    baseName=$(basename "$fileName" .cpp);

    if [[ -x "$baseName" ]]; then
        echo ""
        echo "  Rulam :"
        echo ""
        "./$baseName"
        echo ""
    else
        if [[ -f "$ERR_FILE" ]]; then
            echo ""
            echo "  Nu am gasit executabilul, dar exista un fisier cu errori !"
            echo ""
        else
            echo ""
            echo "  Nu am gasit executabilul !"
            echo ""
        fi
    fi
    main;
}

function compile(){
    baseName=$(basename "$fileName" .cpp);

    if [[ -f "$baseName" ]]; then
        rm "$baseName";
    fi
    if [[ -f "$ERR_FILE" ]]; then
        rm "$ERR_FILE";
    fi

    g++ "$fileName" -o "$baseName" 2> $ERR_FILE;

    if [[ -s "$ERR_FILE" ]]; then
        echo ""
        echo "  Am avut o eroare !!!"
        echo ""
    else
        echo ""
        echo "  Am compilat cu succes !"
        echo ""
    fi
    main;
}

function editeaza(){
    $EDITOR $fileName;
    main;
}



function main(){
    informatii;
    echo ""
    echo -n "Valoare :"
    read opt
    case "$opt" in
        "1" ) editeaza;
            ;;
        "2" ) compile;
            ;;
        "3" ) ruleaza;
            ;;
        "4" ) afisea_erori;
            ;;
        "5" ) iesi;
            ;;
        * ) echo "  Asta nu e o valoare valida!";
            main;
            ;;
    esac
}

if [[ $# -lt 1 ]]; then
    echo "  Nu am primit nici un parametru !"
else
    fileName="$1"
    main;
fi
