// ***
//
// Design an algorithm to encode a list of strings to a string.
// The encoded string is then sent over the network and is decoded back to the original list of strings.
//
// Machine 1 (sender) has the function:
//
// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:
//
// string encoded_string = encode(strs);
// and Machine 2 does:
//
// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.
//
// Implement the encode and decode methods.
//
// Note:
// The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be
// generalized enough to work on any possible characters. Do not use class member/global/static variables to store
// states. Your encode and decode algorithms should be stateless. Do not rely on any library method such as eval or
// serialize methods. You should implement your own encode/decode algorithm.
//
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
//
// ***
//
// To encode, add size-slash in front of every word in the vector.
// For example, [i love you] -> 1/i4/love3/you
// You may repalce '/' with whatever character you want.
// You are guaranteed when decode you will get the original string back.
// Just read the code and you'll understand.

class Codec {
public:
    string encode(vector<string>& strs) {
        string encoded;

        for (string& word : strs) {
            encoded += to_string(word.size()) + '/' + word;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        // Starting position of number which stores each string length.
        int numStart = 0;

        while (numStart < s.size()) {
            int slashPos = s.find_first_of('/', numStart);
            int wordLen = stoi(s.substr(numStart, slashPos - numStart));
            decoded.push_back(s.substr(slashPos + 1, wordLen));

            // slashPos + 1 is where the string starts
            // slashPos + 1 + wordLen is where the number which stores the size of next string starts.
            numStart = slashPos + 1 + wordLen;
        }

        return decoded;
    }
};

