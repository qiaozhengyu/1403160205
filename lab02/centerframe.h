#ifndef CENTERFRAME_H
#define CENTERFRAME_H
#include <QFrame>
#include <common.h>

class QVBoxLayout;
class QHBoxLayout;
class DrawWidget;
class QGroupBox;
class QPushButton;
class QLineEdit;

class CenterFrame : public QFrame//用户绘图框架类
{
    Q_OBJECT

public:
    explicit CenterFrame(QWidget *parent=0);//创建用户区中心窗口
     DrawWidget* insideWidget() const;//获取绘图区绘图对象的指针

protected:
    void createUserCommandArea();//创建绘图框的用户命令区
    void createUI();//创建用户界面
    void updateButtonStatus();//更新按键状态

    void drawpicture();//画图片

public slots:
    void setPenStyle(int penStyle);//改变画笔风格
    void setPenWidth(int width=1);//改变画笔宽度
    void setPenColor(QColor color);//改变画笔颜色
    void clearPaint();//清除当前绘图



protected slots:
    void on_btnRectClicked();//绘制矩形按键响应槽函数
    void on_btnEllipseClicked();//绘制圆形按键响应槽函数
    void on_btnLineClicked();//绘制直线按键响应槽函数
    void on_btnTriangleClicked();//绘制三角形按键响应槽函数
    void on_btnDiamondClicked();//绘制菱形按键响应槽函数
    void on_btnTextClicked();//绘制文本按键响应槽函数
    void on_edtTextEdited(const QString &text);//输入文本响应槽函数
    void on_btnDrawpictureClicked();//绘制图片按键响应槽函数

private:
    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    DrawWidget* drawWidget;
    QGroupBox* group;
    QPushButton* btnRect;
    QPushButton* btnEllipse;
    QPushButton* btnLine;
    QPushButton* btnTriangle;
    QPushButton* btnDiamond;
    QPushButton* btnText;
    QLineEdit* edtText;
    QPushButton* btndrawpicture;
};

#endif // CENTERFRAME_H
