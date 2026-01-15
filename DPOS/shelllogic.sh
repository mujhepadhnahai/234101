#!/bin/bash
----------------factorial--------------------
read -p "Enter number: " n
f=1

for ((i=1; i<=n; i++))
do
  f=$((f * i))
done

echo "Factorial = $f"

------------prime check------------------
#!/bin/bash

read -p "Enter number: " n
c=0

for ((i=1; i<=n; i++))
do
  if [ $((n % i)) -eq 0 ]
  then
    c=$((c + 1))
  fi
done

if [ $c -eq 2 ]
then
  echo "Prime"
else
  echo "Not Prime"
fi

-------------------palendrom----------------
#!/bin/bash

read -p "Enter number: " n
t=$n
r=0

while [ $n -gt 0 ]
do
  d=$((n % 10))
  r=$((r * 10 + d))
  n=$((n / 10))
done

if [ $t -eq $r ]
then
  echo "Palindrome"
else
  echo "Not Palindrome"
fi

--------------sum of digits------------------
#!/bin/bash

read -p "Enter number: " n
s=0

while [ $n -gt 0 ]
do
  d=$((n % 10))
  s=$((s + d))
  n=$((n / 10))
done

echo "Sum = $s"

----------------fibonacci series----------------
#!/bin/bash

read -p "Enter limit: " n
a=0
b=1

for ((i=1; i<=n; i++))
do
  echo -n "$a "
  c=$((a + b))
  a=$b
  b=$c
done
echo
------------switch case----------------------
read -p "Enter a: " a
read -p "Enter b: " b
read -p "Enter op (+ - * /): " op

case $op in
  +) echo $((a+b)) ;;
  -) echo $((a-b)) ;;
  \*) echo $((a*b)) ;;
  /) echo $((a/b)) ;;
esac


