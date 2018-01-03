#include <iostream>
#include <vector>
using namespace std;
bool search(int page, vector<int>& frames);
int predict(const int *pg, vector<int>& frames, int pn, int index);
void optimalPage(int pg[], int pn, int fn);
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
    optimalPage(reference, str_length, n_frames);
    return 0;
}
bool search(int page, vector<int>& frames){  //Checks whether the give page value exist in frames or not.
    for (auto &&  item:frames ) {
        cout<<item<<" ";
    }printf("\n");
    for (int i = 0; i < frames.size(); i++){
        if (frames[i] == page){
            return true;
        }
    }
    return false;
}
int predict(const int *pg, vector<int>& frames, int pn, int index){ //finds the value in frames to be replaced by forward reference.
    int res = -1, farthest = index;
    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (frames[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}
void optimalPage(int pg[], int pn, int fn)
{    vector<int> frames;
    int hit = 0;

    for (int i = 0; i < pn; i++) {
        // hit
        if (search(pg[i], frames)) {
            hit++;
            continue;
        }
        if (frames.size() < fn) //first n frames.
            frames.push_back(pg[i]);
        else {
            int j = predict(pg, frames, pn, i + 1); //select which frame to be replaced.
            frames[j] = pg[i];

        }

    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}
