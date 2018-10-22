big O notation for double gridpi() is n-squared because there's not one but TWO for loops in the function!!

Here are times: 
10:     0.045s
100:    0.047s
1000:   0.284s
10000: 23.871s

In the 10,000 run, the time went up by a factor of 100 which is in alignment with O(n^2) model. When we increase n by 10, time should incraese by a factor of 10^2. 
