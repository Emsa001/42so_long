check_wrong=1
check_correct=0

if (( check_wrong == 1 )); then
    for ((i=1; i<=40; i++))
    do
        echo "$(tput setaf 2)Checking wrong map $i$(tput sgr0)"
        leaks --atExit -- ./so_long ./maps/wrong/$i.ber
        echo " "
    done
fi

if (( check_correct == 1 )); then
    for ((i=1; i<=20; i++))
    do
        echo "$(tput setaf 2)Checking map $i$(tput sgr0)"
        leaks --atExit -- ./so_long ./maps/correct/$i.ber
        echo " "
    done
fi