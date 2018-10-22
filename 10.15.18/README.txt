big O notation for double gridpi() is n-squared because there's not one but TWO for loops in the function!!

Here are times: 
10:     0.045s
100:    0.047s
1000:   0.284s
10000: 23.871s

In the 10,000 run, the time went up by a factor of 100 which is in alignment with O(n^2) model. When we increase n by 10, time should incraese by a factor of 10^2. 


Ooh! When I compile the code with constexpr gridpi2(), it takes much longer to *calculate* pi than gridpi(). For example, I tried gridpi2 for 100 and it took .579 seconds to compile, which is .082 seconds longer than the compile time for just gridpi. This means that the constexpr version for 100 takes nearly twice as long to calculate pis than gridpi! But when it runs, it is much quicker! I see why this is helpful. If I am selling compiled code, I don't care how long I have to wait for it to compile since my users will have quick, already calculated constants. 


Here are run times for gridpi2:
10:    0.053s
100:   0.053s
1000:  0.047s
10000: too long to compile

The runtimes are all the same because all the math was done at compile time! The time it takes to compile is all that changes! It takes longer to do the calculation overall, but runtime is quicker.
