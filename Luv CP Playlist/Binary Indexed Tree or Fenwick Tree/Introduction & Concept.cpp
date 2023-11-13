#include <bits/stdc++.h>
using namespace std;

/*
any binary number except Zero can be written as : a1b
where a is the left part of rightmost set bit & b is the right part of the rightmost set bit
1 is the rightmost set bit
as 1 is the rightmost setbit that means b is all 0 part
, b = 000000....
x = a1b
-x = 2's complement of x
   = (x)' + 1
   = (a1b)' + 1
   = a'0(1111) + 1
   = a'1b


   x = a  1 b
& -x = a' 1 b
(x & (-x)) = (0000)1(0000) -- it becomes a number where only right most bit is set for x , now if we want to remove the rightmost bit of x we can subtract this number from x

(x - (x & (-x))) = a0b

so now we can define the binary indexed trees

here the value present at each index i stores the sum of the original array from index (j + 1) to (i)

where j is the number formed by removing the last set bit of i

j = i - (i & (-i));

so the formula becomes sum upto bit[ind] = bit[ind] + bit[ind1] + bit[ind2] + ... until indk > 0

here,
ind1 = number formed by removing the last set bit of ind
ind2 = number formed by removing the last set but of ind1
and so on ,...
*/

// always use 1 based indexing in bit
const int N = 1e5 + 10;
int bit[N]; // binary indexed tree array , intially all values are Zero

/*
 This function provides me the prefix sum from indexes 1 to ind
 max bit we can remove is all , when all bits are set
 any number can have atmost log n bits -- so its worst case time complexity becomes log n
*/

int sum(int ind)
{
    int ans = 0;

    for (; ind > 0; ind = (ind - (ind & (-ind))))
    {
        ans += bit[ind];
    }

    return ans;
}

/*
    to update the bit array we need to add a number at all the positions on whose range it comes
    we know every number stores the range but the upper bit of any range is number itself -- that means he current index ind can occur again in range of other indexes which are greater than it .
    now the indexes in whose range the index ind involves can be found by just adding the a number to the index ind who just has set its right bit as ind , all other bits should be zero
    so ind1 = ind + (ind & (-ind))
    ind2 = ind1 + (ind1 & (-ind1))
    ans so on ,until it reaches the size of the array
*/

/* we want to add value x to the existing value of bit[ind] , this is called if we add value x to index ind in array arr*/
void update(int ind, int x)
{
    for (; ind <= N; ind = (ind + (ind & (-ind))))
    {
        bit[ind] += x;
    }
}

int main()
{
    int arr[100] = {0};

    for (int i = 1; i < 100; i++)
    {
        arr[i] = i;
        update(i, arr[i]);
    }

    // for any query that wants sum from l to r
    // we can simply do it by

    int l = 10, r = 20;
    int _sum = sum(r) - sum(l - 1);
    cout << _sum << endl;

    int ind = 13, x = 3;
    arr[ind] += x;

    update(ind, x);
    _sum = sum(r) - sum(l - 1);
    cout << _sum << endl;

    return 0;
}