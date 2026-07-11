/**
 * 題目：1108. Defanging an IP Address
 * 難度：簡單 (Easy)
 * 描述：將 IPv4 位址中的所有的句點 "." 替換為 "[.]"。
 * * 優化重點：
 * 1. 介面精準：完美區分了 append (處理字串) 與 push_back (處理字元) 的使用時機。
 * 2. 空間配置：直接建構新字串返回，未更動原字串。
 */

class Solution {
public:
    string defangIPaddr(string address) {
        string defang;
        for(const char& c : address) {
            if(c == '.') {
                defang.append("[.]");
            } else {
                defang.push_back(c);
            }
        }
        return defang;
    }
};
