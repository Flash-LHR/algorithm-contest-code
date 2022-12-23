g++ b.cpp -o my
g++ bao.cpp -o std
while true
do
python3 gen.py > rand.in
./my < rand.in > my.out
./std < rand.in > std.out
if diff my.out std.out
then
printf AC
else 
echo WA
cat rand.in
exit 0
fi
done
