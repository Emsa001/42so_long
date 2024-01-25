for ((i=1; i<=40; i++))
do
    echo "$(tput setaf 2)Checking map $i$(tput sgr0)"
    ./so_long ./maps/wrong/$i.ber
    echo " "
done
