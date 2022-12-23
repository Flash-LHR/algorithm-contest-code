g++ b.cpp -o my -O2
g++ bb.cpp -o std -O2
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
exit 1
fi
done
