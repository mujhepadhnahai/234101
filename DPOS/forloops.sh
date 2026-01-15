#read -p "enter a no " n
# echo "n=: $n"

# if [ $n -eq 10 ]
# then 
#    echo "equal"
# else
#    echo "not"
# fi

# x=10
# sum=0
# while [ $x -gt 0 ]
# do
#    sum=$((sum+x))
#    x=$((x-1))
# done
# echo "sum= ${sum}"

# for((i=1;i<4;i++))
# do
#   echo $i 
# done

read -p "Enter a number (1–3): " n

case $n in
  1) echo "One" ;;
  2) echo "Two" ;;
  3) echo "Three" ;;
  *) echo "Invalid choice" ;;
esac