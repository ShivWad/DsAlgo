//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code
            int j = 0, maxLen = 0;

        unordered_map<char, int> tempMap;

        while (j < S.size())
        {
            if (tempMap.count(S[j]))
                tempMap.clear();

            tempMap.insert(pair<char, int>(S[j], 1));

            if (maxLen < tempMap.size())
                maxLen = tempMap.size();
            j++;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}
// } Driver Code Ends


   bool isValid(string s) {
        for(int i=0; i<s.length()-1;i+=2){
            if((int(s[i+1])-int(s[i]))<=2){
                return false;
            }
        }
        return true;
    }