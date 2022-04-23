class Solution {
    unordered_map<string,string> store;
    string generate() {
        string code;
        do {
            code = "";
            for(int i = 0; i < 6; ++i) {
                code += getChar(rand()%62);
            }
        } while(store.find(code) != store.end());
        return code;
    }
    
    char getChar(int i) {
        if(i < 10) {
            return '0' + i;
        }
        if(i < 36) {
            return 'a' + i - 10;
        }
        return 'A' + i - 36;
    }
    
public:
    Solution() {
        srand(time(0));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string prefix = "http://tinyurl.com/";
        string shorted = generate();
        store[shorted] = longUrl;
        return prefix + shorted;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(19);
        return store[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));