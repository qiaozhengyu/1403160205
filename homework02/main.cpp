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
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

typedef struct{
    QStringList stud;
} studData;

QDebug operator<< (QDebug d, const studData &data)
{
    for(int i=0;i<data.stud.size();i++)
           d.noquote().nospace()<<QString(data.stud.at(i))<<"\t" ;
    // 运算符重载函数，使其可以直接输出studData结构
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
    //排序自定义，从第二列姓名排序开始
    return d1.stud.at(currentColumn+1)>d2.stud.at(currentColumn+1);
}

//排序
class ScoreSorter
{
    public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
     QString File;
     studData ltitle;//标题
     QList<studData> data;//内部数据结构
};
//构造函数分配资源
ScoreSorter::ScoreSorter(QString dataFile)
{
  File=dataFile;
}
void ScoreSorter::readFile()
{
    QFile file(this->File);   //只读方式打开文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件%1打开失败"<<endl;
    }
    //读取表头并按空格 split '  '.  //https://blog.csdn.net/jack_bro/article/details/70160718
    QString titile(file.readLine());
    ltitle.stud= titile.split(" ", QString::SkipEmptyParts);
    // 除去末尾的'\n'
    if((ltitle.stud).last() == "\n")
        ltitle.stud.removeLast();
    // 按行读取
    studData perdata;
    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QString str(line);
        perdata.stud= str.split(" ", QString::SkipEmptyParts);
        //去末尾'\n'  如果是空 qlist()  则摒弃,否则添加到 data
        if((perdata.stud).last() == "\n") perdata.stud.removeLast();
        if(perdata.stud.size()==0) continue;
        //将几个块数据存入data
        data.append(perdata);
    }
    file.close();
}
//排序函数
void ScoreSorter::doSort()
{
    for(int i=0;i<ltitle.stud.size()-1;i++)
    {
        //https://blog.csdn.net/maverick1990/article/details/37738601   声明比较规则类
        myCmp cmp(i);    //初始化排序规则对象
        std::sort(data.begin(),data.end() , cmp );  //排序
        //标题输出
        qDebug() << '\t'<< (ltitle);
        //qDebug重载输出
        for(int i=0;i<data.size();i++)
        qDebug() << data.at(i);
        qDebug()<<"-----------------------------------------------------------------------\n";

    }
}
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

        // 输出信息至文件中（读写、追加形式）
        QFile file("C:/homework/build-text3-Desktop-Debug/sorted_data.txt");
        file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
        QTextStream origin(&file);
        origin << msg << endl;
        file.flush();
        file.close();
        QTextStream sortout(stdout);
        sortout << msg <<endl;
        file.flush();
        file.close();
}


int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "C:/homework/build-text3-Desktop-Debug/data.txt";

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
