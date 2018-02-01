#include <iostream>
#include <string>

//解题思路:
//1.通过字符串数组保存单词,下标与词义对应
//2.递归打印sum,打印时输出与其对应的单词

using namespace std;

//单词数组
const char *words[] = { 
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
};

void _printByWords(int num)
{
    if (num) {
        _printByWords(num / 10);
        cout << words[num % 10] << " ";
    }
}

//以单词形式打印num
void printByWords(int num)
{
    //这样调用仅仅为了控制格式
    _printByWords(num / 10);
    cout << words[num % 10];
}

int main()
{
    string num;
    int sum = 0;

    cin >> num;
    //累加每一个数的和
    for (const auto x : num) {
        sum += x - '0';
    }

    printByWords(sum);
    cout << endl;

    return 0;
}
