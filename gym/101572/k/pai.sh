g++ k1.cpp -o my -std=c++17
g++ kk.cpp -o std -std=c++17 -O2
while true
do
python3 rand.py > rand.in
./my < rand.in > my.out
./std < rand.in > std.out
if diff std.out my.out
then
printf AC
else
echo WA
cat rand.in
exit 0
fi
done
