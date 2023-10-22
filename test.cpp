#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <unordered_map>
using namespace std;


bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int prev =0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < leftChild.size(); i++) {
            if(i > 0 && leftChild[i - 1] != -1 && leftChild[i] != -1) {
                prev = leftChild[i- 1];
                if(prev > leftChild[i] && i > leftChild[i]) return false;
            }
            if(i > 0 && rightChild[i - 1] != -1 && rightChild[i] != -1) {
                prev = rightChild[i- 1];
                if(prev > rightChild[i] &&  i > rightChild[i]) return false;
            }
            mp[leftChild[i]].push_back(i);
            mp[rightChild[i]].push_back(i);
        }
        vector<int> x;
        for (auto it : mp) {
            if (it.second.size() > 1 && it.first != -1) return false;  
            else{
                
                x = mp.at(-1);
            } 
        }

        int k = leftChild.size() - 1;
        for(int i = x.size() - 1; i>=0; i--){
            while(k == x.back()) x.pop_back();
            k--;
            if(k != x.back()) break;
        }
        if(x.empty()) return true;
        int count;
        for(auto s : x) cout<<s<<" ";
        int left = 0 ; 
        int right = 1;
        while(right < x.size()){
            if(x[left] == x[right]){
                count++;
            }
            left++;
            right++;
        
        }
        if(count >= 2) return false;
        return true;
}

int main() {
    vector<int> left =  {1,2,16,13,7,15,108,99,14,23,11,32,17,25,27,21,26,19,54,31,48,87,474,24,30,-1,52,28,308,256,46,70,103,74,68,37,40,58,224,155,111,-1,49,175,57,51,63,94,64,193,226,159,126,431,60,62,-1,121,71,169,65,72,114,343,79,118,141,216,78,98,81,82,107,83,138,-1,91,97,428,-1,494,200,100,164,86,160,142,153,-1,-1,-1,-1,430,112,102,104,324,116,165,105,396,-1,117,140,234,119,205,419,123,171,236,230,131,-1,349,-1,-1,120,386,128,149,302,135,251,-1,137,-1,237,287,265,-1,-1,-1,218,219,173,139,222,-1,241,282,242,-1,253,207,233,485,187,170,184,-1,248,177,-1,344,335,-1,356,362,-1,166,168,-1,182,-1,278,303,-1,176,334,-1,208,-1,-1,220,291,-1,441,206,378,-1,243,213,-1,-1,445,-1,306,204,299,-1,-1,322,-1,319,-1,-1,297,354,-1,-1,202,-1,238,473,397,-1,355,292,-1,-1,239,-1,-1,491,-1,-1,-1,-1,332,-1,442,432,284,387,326,231,-1,429,-1,-1,327,276,261,-1,-1,339,271,-1,394,-1,-1,-1,275,-1,257,254,273,-1,-1,492,329,286,304,414,258,359,-1,-1,-1,-1,370,-1,295,-1,345,-1,358,-1,-1,447,-1,-1,-1,-1,423,-1,294,450,390,438,-1,-1,-1,296,310,288,-1,446,-1,-1,309,372,-1,-1,338,-1,-1,455,352,404,348,-1,-1,-1,382,-1,-1,-1,380,440,-1,457,-1,-1,471,-1,-1,-1,341,-1,-1,-1,-1,-1,330,-1,-1,-1,-1,361,-1,466,342,-1,360,-1,-1,-1,-1,-1,-1,363,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,461,377,-1,-1,379,-1,-1,-1,-1,-1,-1,-1,469,-1,407,-1,-1,-1,-1,-1,-1,412,-1,-1,-1,-1,-1,433,-1,-1,-1,400,-1,-1,-1,-1,-1,401,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,483,453,463,-1,-1,-1,-1,-1,-1,-1,467,452,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,490,-1,481,-1,-1,-1,488,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,497,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,493,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    vector<int> right =   {4,12,3,6,5,10,9,8,33,113,95,34,43,196,18,-1,22,39,20,92,42,199,110,35,41,29,36,101,38,45,69,67,-1,44,157,456,90,55,191,47,50,192,53,80,162,374,122,56,300,336,252,76,59,89,66,84,127,77,61,201,415,-1,-1,-1,96,73,125,367,88,109,229,136,75,85,424,214,277,132,-1,260,-1,143,398,-1,151,93,312,194,150,-1,-1,255,124,106,158,468,188,-1,274,211,267,227,266,130,133,185,209,-1,190,-1,167,145,115,427,-1,269,223,197,146,134,437,161,129,156,189,172,147,144,246,435,152,195,-1,-1,212,148,-1,301,-1,181,365,316,174,183,313,-1,-1,228,203,-1,-1,154,270,-1,-1,210,180,245,350,221,-1,-1,163,-1,-1,388,346,-1,-1,-1,470,179,-1,178,225,272,247,347,232,422,281,198,186,215,413,268,-1,476,-1,-1,-1,279,484,351,392,-1,305,328,323,-1,283,298,-1,448,289,375,-1,357,315,217,307,498,240,250,285,321,409,-1,-1,-1,-1,-1,-1,235,402,-1,-1,-1,-1,410,-1,244,-1,-1,-1,249,-1,-1,318,259,373,264,487,-1,384,-1,314,263,-1,459,393,-1,340,-1,399,-1,262,293,-1,-1,311,-1,-1,-1,280,-1,-1,403,-1,411,-1,434,-1,-1,416,395,-1,-1,-1,-1,-1,-1,290,331,-1,-1,486,-1,-1,-1,-1,-1,-1,325,-1,-1,-1,-1,320,-1,-1,-1,317,371,364,-1,472,-1,337,-1,454,-1,-1,368,333,444,-1,-1,-1,443,353,-1,-1,-1,425,383,376,-1,-1,-1,-1,-1,-1,-1,-1,369,-1,-1,418,366,-1,-1,-1,-1,-1,-1,389,-1,417,475,-1,-1,-1,-1,460,480,-1,-1,-1,-1,-1,-1,-1,-1,-1,421,-1,408,426,-1,405,385,-1,-1,391,-1,-1,-1,381,-1,-1,-1,-1,-1,-1,-1,439,406,449,-1,-1,477,-1,-1,-1,-1,420,-1,-1,-1,-1,-1,479,464,-1,-1,-1,-1,465,-1,451,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,482,-1,-1,436,-1,-1,-1,-1,-1,499,-1,462,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,496,-1,-1,-1,-1,489,-1,458,-1,-1,-1,478,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,495,-1,-1,-1,-1,-1,-1,-1,-1};
    cout<< validateBinaryTreeNodes(6 , left , right);
    return 0;
}