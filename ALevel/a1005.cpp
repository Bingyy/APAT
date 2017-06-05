#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char,int> digHash = { 
                            {'0',0},
                            {'1',1},
                            {'2',2},
                            {'3',3},
                            {'4',4},
                            {'5',5},
                            {'6',6},
                            {'7',7},
                            {'8',8},
                            {'9',9},
                          };

map<int,string> ha;
void constructMap()
{
    int digits[10] = {0,1,2,3,4,5,6,7,8,9};
    string words[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i < 10; i++)
    {
        ha.insert(pair<int,string>(digits[i],words[i]));
    }
}

int main()
{
    constructMap();
    vector<int> digits;
    // num很大，超过了int的表示范围，需要用string来接收
    string num;
    cin >> num;
    int cnt = num.size();
    for(int i = 0; i < cnt; i++)
    {
        digits.push_back(digHash[num[i]]); // 存储数位
    }

    int sum = 0;
    // 求和
    for(auto it = digits.begin(); it != digits.end(); it++)
    {
        sum += *it;
    }

    if(sum == 0)
    {
        cout << "zero" << endl;
    }

    else
    {
        digits = {}; //清空digits数组，这样不必另外再开一个
        while(sum)
        {
            int digit = sum % 10;
            digits.push_back(digit);
            sum /= 10;
        }
    
   
        //借助map输出英文描述
        for(auto it = digits.rbegin();it != digits.rend() - 1; it++)
        {
            cout << ha[*it] << " ";
        }
        cout << ha[digits[0]] << endl;
    }
        
    return 0;
}
