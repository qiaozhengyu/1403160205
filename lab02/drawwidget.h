#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include <common.h>
#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>

class DrawWidget : public QWidget//绘图区窗口类
{
    Q_OBJECT

public:
    explicit DrawWidget(QWidget *parent = 0);
    ~DrawWidget();

    void setShapeType(ST::ShapeType type);//设置绘图类型
    ST::ShapeType shapeType();//绘制形状的枚举变量,返回当前绘图类型
    void setDrawnText(QString text);

protected:
    void mousePressEvent (QMouseEvent *e);//处理鼠标点击事件
    void mouseMoveEvent (QMouseEvent *e);//处理鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);//处理按键释放事件
    void paintEvent (QPaintEvent *);//处理绘图事件
    void resizeEvent (QResizeEvent *);//处理窗口大小变化时的resize事件
    //根据起始点、结束点和绘图类型进行绘图
    void drawShape(const QPointF ptStart,const QPointF ptEnd,const ST::ShapeType drawType);
    //计算绘制文本时所需要的最佳矩形大小
    QRectF textRect(const QPointF ptStart, const QPointF ptEnd, QString displayText, QFontMetrics fm);

public slots:
    void setStyle(int);//接收用户选定的画笔风格
    void setWidth(int);//接收用户选定的画笔宽度值
    void setColor(QColor);//接收用户选定的画笔颜色值
    void clear();
    void drawpicture();

private :
    QPixmap *pix;//定义一个画板指针
    QPoint startpos;//绘图起始点
    QPoint endpos;//绘图终点
    bool canDraw; //绘图标志：true:绘制， false:不绘制
    int style; //绘图时使用的画笔风格
    int weight;//绘图时的画笔线宽
    QColor color;//绘图时的画笔颜色
    ST::ShapeType drawType;
    QString drawnText;
};

#endif // DRAWWIDGET_H

