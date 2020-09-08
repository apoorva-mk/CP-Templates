vector<int> prefix_function(string s){
    vector<int> lps(s.size());
    for (int i = 1; i < s.size(); i++){
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}
