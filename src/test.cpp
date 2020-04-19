//
// Created by kolane on 2020/4/19.
//

//#include<iostream>
//#include<set>
//using namespace std;
////set插入元素操作
//int main()
//{
//    //定义一个int型集合对象s,当前没有任何元素.由www.169it.com搜集整理
//    set<int> s;
//    s.insert((1,2));  //第一次插入8，可以插入
//    s.insert((2,3));
//    s.insert((3,4));
//    s.insert((4,5));
//    s.insert((1,2));   //第二次插入8，重复元素，不会插入
//    set<int>::iterator it; //定义前向迭代器
//    //中序遍历集合中的所有元素
//    for(it=s.begin();it!=s.end();it++)
//        cout<<*it<<endl;
//    return 0;
//}

//#include<iostream>
//#include<set>
//#include <string>
//using namespace std;
////set插入元素操作
//int main()
//{
//    int a  = 1;
//    int b = 2;
//
//    cout << to_string(a) + to_string(b)<< endl;
//    cout << (to_string(a) + to_string(b))[0]<< endl;
//    cout << (to_string(a) + to_string(b))[1]<< endl;
//
//    return 0;
//}


#include<iostream>
#include<set>
#include <cstdlib>
#include <string>
using namespace std;
//set插入元素操作
int main()
{
    string s = "12";
    int a = std::atoi(s.c_str());
    int b = a/10;
    int c = a%10;
    cout << s << "==" << a << "==" << b << "==" << c <<  endl;
     return 0;
}