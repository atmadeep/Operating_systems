#include <iostream>
#include <vector>
using namespace std;
bool search(int page, vector<int>& frames);
int predict(const int *pg, vector<int>& frames,int index);
void LRU(int pg[], int pn, int fn);
int main()
{
    int str_length,n_frames;
    printf("enter length of input string");
    cin>>str_length;
    int reference[str_length];
    printf("\ninput string\n");
    for (int i = 0; i <str_length ; ++i) {
        cin>>reference[i];
    }
    printf("enter no of frames\n");
    cin>>n_frames;
    LRU(reference, str_length, n_frames);
    return 0;
}
bool search(int page, vector<int>& frames){  //Checks whether the give page value exist in frames or not.

    for (int i = 0; i < frames.size(); i++){
        if (frames[i] == page){
            return true;
        }
    }
    return false;
}
int predict(const int *pg, vector<int>& frames, int index){   //finds the value in frames to be rep
// laced by backward reference.
    int least_page=index-1,res=-1,i,j;
    for ( i = 0; i < frames.size(); ++i) {
        for ( j = index-1; j > 0  ; --j) {
            if(pg[j]==frames[i]){
                if(least_page > j){
                    least_page=j;
                    res=i;
                }
                break;
            }
        }
        if(j==0)
            return i;
    }
    return (res==-1)?0:res;
}
void LRU(int pg[], int pn, int fn)
{    vector<int> frames;
    int hit = 0,sl=0;

    for (int i = 0; i <= pn; i++) {
        cout<<sl++<<"# ";
        for (auto &&  val:frames )
            cout<<val<<" ";
        printf("\n");
         if (search(pg[i], frames)) {
            hit++;
            continue;
        }
        if (frames.size() < fn) //first n frames.
            frames.push_back(pg[i]);
        else {
            int j = predict(pg, frames,i ); //select which frame to be replaced.
            frames[j] = pg[i];

        }
//        printf("%d \b",sl++);


    }


    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}
