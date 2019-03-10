//공통조상 20190310 분할정복 디버깅없이품 개인적으로 제일 맘에듬 킼키ㅡ킼키키킼
#include<iostream>
using namespace std;
 
struct list {
    int data;
    int left;
    int right;
    int pred;
};
 
struct list arr[10001];
int v, e, first, second;
 
void addlist(int first_data,int second_data)
{
    if (!arr[first_data].left)arr[first_data].left = second_data;
    else arr[first_data].right = second_data;
    arr[second_data].pred = first_data;
}
 
int divide(int cur)
{
    int ret = 1;
    if (arr[cur].left)ret += divide(arr[cur].left);
    if (arr[cur].right)ret += divide(arr[cur].right);
    return ret;
}
 
int find(int cur)
{
    arr[cur].data++;
    if (arr[cur].data == 2)return cur;
    if (arr[cur].pred)find(arr[cur].pred);
}
 
int find_head(int fir,int sec)
{
    int ret;
    if (arr[fir].pred)ret = find(arr[fir].pred);
    if (arr[sec].pred)ret = find(arr[sec].pred);
    return ret;
}
 
int main()
{
    int t,a,b,result,head;
    cin >> t;
     
    for (int test = 1; test <= t; test++)
    {
        cout << "#" << test << " ";
        cin >> v >> e >> first >> second;
        for (int i = 1; i <= v; i++)arr[i].data = arr[i].left = arr[i].right = arr[i].pred = 0;
        arr[first].data = 1;
        arr[second].data = 1;
        for (int inp = 0; inp < e; inp++)
        {
            cin >> a >> b;
            addlist(a, b);
        }
        head = find_head(first, second);
        result = divide(head);
        cout << head << " " << result << "\n";
    }
 
}
