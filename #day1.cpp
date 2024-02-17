#include<bits/stdc++.h>
using namespace std;
// int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//     int ans=0;
//     int i;
//     for( i=0;i<heights.size()-1;i++)
//     {
//         int diff=heights[i+1]-heights[i];
//         if(bricks<diff && ladders==0)
//         {
          
//           return i;
//         }
//        if(heights[i+1]>=heights[i])
//        {
//          if(bricks!=0 && bricks>=diff)
//          {
//           bricks=bricks-diff;
//          }t
//          else if(ladders!=0)
//          {
//             ladders=ladders-1;
//          }

//        }
//     }
//     return i;
// }
// we can use another approach by using priority queue for finding maximum difference between heights
// 
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int i=0,diff=0;
        priority_queue<int>p;
        for(i=0;i<heights.size()-1;i++)
        {
            diff=heights[i+1]-heights[i];
            if(diff<=0)
            {
                continue;
            }
            bricks-=diff;
            p.push(diff);
            if(bricks<0)
            {
                bricks+=p.top();
                p.pop();
                ladders--;
            }
            if(ladders<0)
              break;

        }
        return i;
    }
int main()
{
    vector<int>h={14,3,19,3};
    int b=17;
    int l=0;
    int ans=furthestBuilding(h,b,l);
    cout<<ans<<endl;
}