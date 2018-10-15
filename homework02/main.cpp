#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

namespace SK
{
enum SortKind
{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
};
}

typedef struct
{
    QString num;
    QString name;
    QVector<int> scores;
    // 结构定义
} studData;

QDebug operator<< (QDebug d, const studData &data)
{
    QDebugStateSaver saver(d);
          d.nospace()<<data.num<<data.name<<data.scores;

    // 请补全运算符重载函数，使其可以直接输出studData结构
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn)
    {
    case SK::col01:
        d1.num<d2.num;
        break;
    case SK::col02:
        d1.name<d2.name;
        break;
    case SK::col03:
    case SK::col04:
    case SK::col05:
    case SK::col06:
    case SK::col07:
    case SK::col08:
        d1.scores<d2.scores;
        break;

    // 请补全运算符重载函数

    }
    return result;
}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    // ...
    // 请补全该类，使其实现上述要求
    // ...
}

// 请补全
ScoreSorter::ScoreSorter(QString dataFile){
}


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 自定义qDebug
}



int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
