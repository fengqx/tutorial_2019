#include"longest.h"

string longestCommon(vector<string>& str)
{
	//??????????
	int m = sizeof(str[0]);	//m?????????
    for (auto v : str) {
		if (sizeof(v) < m) {
			m = sizeof(v);
		}
	}
	//?????????
    string ans;		//??????
    char temp;		//???????i???
    for (int i = 0; i < m ; i++) {		
        temp = str[0][str[0].length() - i - 1];	
        for (auto v : str) {
			if (temp != v[v.length() - i - 1])	
				return ans;		//???????ans
		}
		string t; t += temp;	
		ans.insert(0, t);		//?str?????????ans???temp
    }
	return ans;
}

