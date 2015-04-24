/*#include <iostream>
#include <random>
#include <ctime>
#include <functional>

using namespace std;
 
int main()
{
  //  mt19937 mt_rand(time(0));
    mt19937::result_type seed = time(0);
    auto n=bind(uniform_int_distribution<int>(0,1),mt19937(seed));
        int i;
        for(i=0;i<100;i++){
            n=uniform_int_distribution<int>(0,100);
            cout << n << endl;
        }
             
                return 0;
}
*/

#include <chrono>
#include <random>
#include <iostream>
using namespace std;

int main() {
    int i, N=100,n1;

    float x, y;

    for(i=0;i<N;i++){
  /*          uniform_int_distribution<int> unif(0,i+1);
        n1=unif(eng);
            cout << n1 << '\n';*/
        mt19937 eng(chrono::high_resolution_clock::now()
                    .time_since_epoch().count()+1);
        uniform_real_distribution<float> unif(-1, 1);
        x=unif(eng);
        y=unif(eng);
        cout<<x<<" "<<y<<endl;
        
    }

}