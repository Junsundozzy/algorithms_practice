//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length < 0) {
            return;
        }
        int i = 0;
        int spacecum = 0;
        int oldlength = 0;
        while (str[i] != '\0') {
            
            if (str[i] == ' ') {
                spacecum++;
            }
            i++;
        }
        
        int newlength = length + 2*spacecum;
        int oldindex = length - 1;
        int newindex = newlength - 1;
        for (;oldindex >= 0 && newindex > oldindex; oldindex--) {
            if (str[oldindex] == ' ') {
                str[newindex--] = '0';
                str[newindex--] = '2';
                str[newindex--] = '%';
            }
            else {
                str[newindex--] = str[oldindex];
            }
        }
	}
};