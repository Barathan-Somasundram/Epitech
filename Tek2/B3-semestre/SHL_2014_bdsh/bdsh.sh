#!/bin/sh

is_k=0
df_file="./sh.db"
file=""
val=""
key=""

msg_error()
{
    if [ $1 = 1 ]; then
	echo "Usage: ./bdsh.sh [-k] [-f <db_file>] (put (<clef> | $<clef>) (<valeur> | $<clef>) |" 1>&2
	echo "                                      del (<clef> | $<clef>) [<valeur> | $<clef>] |" 1>&2
        echo "                                      select [<expr> | $<clef>] |" 1>&2
	echo "                                      flush" 1>&2
    elif [ $1 = 2 ]; then
	echo "Syntax Error" 1>&2
    elif [ $1 = 3 ]; then
	echo "Error: too many parameters" 1>&2
    elif [ $1 = 4 ]; then
	echo "Error: too few parameters" 1>&2
    elif [ $1 = 5 ]; then
	echo "Error" 1>&2
    fi
}

verif()
{
    if [[ $1 > 6 ]]; then
	msg_error 3
	msg_error 1
	exit 1
    elif [[ $1 = 0 ]]; then
	msg_error 4
	msg_error 1
	exit 1
    fi
    if [ "$file" = "" ]; then
	if [ ! -e $df_file ]; then
	    echo "Error: No such file (data base)"
	    exit 1
	fi
    fi
}

init_args()
{
    for i in $@
    do
	if [ $i = "-k" ]; then
	    is_k=1
	fi
    done
    for i in $@
    do
	if [ $i = "-f" ]; then
	    is_f=1
	elif [ $is_f = 1 ]; then
	    file=$i
	fi
    done
}

flush()
{
    echo -n "" > "sh.db"
}

put_db()
{
    echo ""
}

select_db()
{
    echo ""
}

del_db()
{
    echo ""
}

echo "$#"

verif $#
init_args $*
if [ $is_f = 1 ]; then
    if [ ! -e $file ]; then
	echo "Error: No such file (data base)"
	exit 1
	fi
else
    file=$df_file
fi

echo "is_k = $is_k"
echo "-f = $file"
exit 0
