#include<bits/stdc++.h>
using namespace std;

/*
we use priority queue rather than queue to compute the minimum path to a vertex first then by exploring all paths
*/

// intution of priority queue
/*
 psuedo code of Dijkstra's Algorithm

 while(!priorityqueue)
 {
    auto it = .top() // log(heap size)

    for(child) // no of edges of each node
    {
        condition
        .push // log(heap size)
    }
 }

  complexity is : O(v * (log(heap) + e * log(heap)))
  O(v * (log(heap) * (e + 1))) // worst case sinareo every vertex has v-1 edges --> e = v-1
  O(v * (log(heap) * v)) == (v^2 * log(heap))
  heap size = v;
  v^2 * log(v) --> in worst case v2 is equal to E
  E*log(V) is the worst case complexity

*/


int main()
{
    
    return 0;
}