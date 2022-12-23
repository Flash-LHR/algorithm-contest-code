g++ g.cpp -o my
g++ std.cpp -o std
g++ rand.cpp -o rand
while true
do
./rand > rand.in
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
