g++ a.cpp -o my
g++ lyj.cpp -o std
while true
do
python3 rand.py > rand.in
./my < rand.in > my.out
./std < rand.in > std.out
if diff my.out std.out
then
printf AC
else
echo WA
exit 0
fi
done
