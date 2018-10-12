#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include<QVector>

class student
{
public:
    int num;
    QString name;
    int tech1;
    int tech2;
};                          //定义一个学生类

bool operator1(const student &s1,const student &s2)
{
    return s1.name<s2.name;
}
bool operator2(const student &s1,const student &s2)
{
    return s1.tech1>s2.tech1;
}
bool operator3(const student &s1,const student &s2)
{
    return s1.tech2>s2.tech2;
}                                                   //对sort进行自定义排序

int main()
{
    student s[4];
    s[0].num=1403130209;
    s[0].name="鲁智深";
    s[0].tech1=80;
    s[0].tech2=72;
    s[1].num=1403140101;
    s[1].name="林冲";
    s[1].tech1=82;
    s[1].tech2=76;
    s[2].num=1403140102;
    s[2].name="宋江";
    s[2].tech1=76;
    s[2].tech2=85;
    s[3].num=1403140103;
    s[3].name="武松";
    s[3].tech1=88;
    s[3].tech2=80;        //输入学生信息


    QList<student> value;
     value<<s[0]<<s[1]<<s[2]<<s[3];
    qDebug()<<"原始学生信息：";
    for(int i=0;i<4;i++)
    {
    qDebug()<<value.at(i).num<< value.at(i).name<<
              value.at(i).tech1<<value.at(i).tech2<<"\n";
    }                                   //将所有原始学生信息连接

    qDebug()<<"---------------------------------\n"<<"姓名排序后：";
    std::sort(value.begin(),value.end(),operator1);
    for(int i=0;i<4;i++)
    {
    qDebug()<<value.at(i).num<< value.at(i).name<<
              value.at(i).tech1<<value.at(i).tech2<<"\n";
    }

    qDebug()<<"---------------------------------\n"<<"成绩1排序后：";
    std::sort(value.begin(),value.end(),operator2);
    for(int i=0;i<4;i++)
    {
    qDebug()<<value.at(i).num<< value.at(i).name<<
              value.at(i).tech1<<value.at(i).tech2<<"\n";
    }
    //按成绩1由大到小排序

    qDebug()<<"---------------------------------\n"<<"成绩2排序后：";
    std::sort(value.begin(),value.end(),operator3);
    for(int i=0;i<4;i++)
    {
    qDebug()<<value.at(i).num<< value.at(i).name<<
              value.at(i).tech1<<value.at(i).tech2<<"\n";
    }
    //按成绩2由大到小排序


}
