class Encrypter {
    unordered_map<char, string> kv;
    unordered_map<string,int> dict;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i = 0; i < n; ++i) {
            kv[keys[i]] = values[i];
        }

        for(string s: dictionary) {
            dict[encrypt(s)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        
        for(auto c: word1) {
            ans += kv[c];
        }
        
        return ans;
    }
    
    int decrypt(string word2) {
        return dict[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */