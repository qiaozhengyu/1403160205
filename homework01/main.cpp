#include <QCoreApplication>
#include <QDebug>
#include <QList>    //头文件

typedef qint32 word;
typedef qint8 byte;
#define WORD_LLO(xxx) ((byte) ((word)(xxx) & 255))  //取最低8位
#define WORD_LHO(xxx) ((byte) ((word)(xxx) >> 8))  //取次低8位
#define WORD_HLI(xxx) ((byte) ((word)(xxx) >> 16))  //取次高8位
#define WORD_HHI(xxx) ((byte) ((word)(xxx) >> 24))  //取最高8位

#define MAX(x,y) ( (x)>(y) ? (x):(y) )  //取最大值
#define MIN(x,y) ( (x)<(y) ? (x):(y) )  //取最小值

int main(int argc, char *argv[])
{
    qint32 i=0x12345678;
    qDebug()<<"原值0x12345678="<<i;      //输出原值及各个8位
    qDebug()<<"0x12="<<WORD_HHI(i);
    qDebug()<<"0x34="<<WORD_HLI(i);
    qDebug()<<"0x56="<<WORD_LHO(i);
    qDebug()<<"0x78="<<WORD_LLO(i);

    QList<qint8> values;
     values<<WORD_HHI(i)<<WORD_HLI(i)
          <<WORD_LHO(i)<<WORD_LLO(i); //将各个8位存入values

    qDebug("最高位与次高位的最大值：0x%x(%d)",
           (MAX(WORD_HHI(i),WORD_HLI(i))),
           (MAX(WORD_HHI(i),WORD_HLI(i))));  //比较最大值的十进制与十六进制输出
    qDebug("最低位与次低位的最小值：0x%x(%d)",
           (MIN(WORD_LHO(i),WORD_LLO(i))),
           (MIN(WORD_LHO(i),WORD_LLO(i))));  //比较最小值的十进制与十六进制输出
    qDebug("重新组合后数值：0x%x(%d)",
           ((WORD_HHI(i) << 16)+WORD_HLI(i)
            +(WORD_LHO(i) << 24)+(WORD_LLO(i) << 8)),
            (((WORD_HHI(i) << 16)+WORD_HLI(i)
            +(WORD_LHO(i) << 24)+(WORD_LLO(i) << 8)))); //按要求重新组合
    qDebug()<<"排序前"<<values;
    std::sort(values.begin(),values.end(),
              std::greater<qint8>());     //从大到小排序
    qDebug()<<"排序后"<<values;

    QCoreApplication a(argc, argv);

    return a.exec();



}
