g++ h.cpp -o my -O2
g++ djk.cpp -o std -O2
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
