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

// KMP algorithm to find a pattern in a string
vector<int> findPattern(string pattern, string text){
    vector <int>  positions;
    vector <int> lps = prefix_function(pattern);
    int i = 0, j = 0;
    while (i < text.size()){
        if ( pattern[j] == text[i]){
            i++;
            j++;
        }
        if (j == pattern.size()){
            positions.push_back(i - pattern.size());
            j = lps[j - 1];
        }
        else if (i < text.size() && text[i] != pattern[j]){
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return positions;
}
