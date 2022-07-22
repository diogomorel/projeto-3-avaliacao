#include "plotter.h"
#include "sculptor.h"
#include <iostream>
#include <QPainter>
#include <QBrush>
#include <QPen>


Plotter::Plotter(QWidget *parent) : QWidget(parent)
{






    //inicia um timer que e repetido a cada 100 ms
    /*timerId = startTimer(100);
    //killTimer para matar o TImer
    //habilita o rastreio da posicao do mouse
    setMouseTracking(true);
    background = QColor(255,255,0);
    actionOpcao = new QAction(this);
    actionOpcao->setText("Muda Cor");
    connect(actionOpcao,SIGNAL(triggered(bool)),this,
            SLOT(mudacor()));
*/

}
/*void Plotter::timerEvent(QTimerEvent *event)
{
    angulo = angulo + velocidade;
    if(angulo > 2*PI){
        angulo = 0;
    }
    repaint();
}
void Plotter::mousePressEvent(QMouseEvent *event)
{
    emit mudouX(event->x());
    emit mudouY(event->y());
}
void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    emit mudouX(event->x());
    emit mudouY(event->y());
}
void Plotter::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(actionOpcao);
    menu.exec(event->globalPos());
}
*/
void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);// Tela
    QBrush brush;//Preenchimento da tela
    QPen pen;// caneta do contorno da tela
    //int x1,y1,x2,y2;

    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
    painter.setPen(pen);
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);


    e = s->getPlano(dim,plano);
    //painter.setBrush(Qt::BDiagPattern);

    // Tela preenchida com a cor amarela e uma superficie solida
    //brush.setColor(QColor(255,255,100));
    //brush.setColor(background);
    //brush.setStyle(Qt::SolidPattern);

    //HORIZONTAL
    pen.setColor(Qt::black);
    //Largura do contorno (2 PIXELS)
    pen.setWidth(2);

    //painter.setBrush(brush);
    painter.setPen(pen);
    //Desenha um retangulo abrangendo toda a extensão do componente
    painter.drawRect(0,0,width(),height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,height()/2,width(),height()/2);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,height()/4,width(),height()/4);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,height()/8,width(),height()/8);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,3*height()/4,width(),3*height()/4);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,5*height()/8,width(),5*height()/8);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,3*height()/8,width(),3*height()/8);

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0,7*height()/8,width(),7*height()/8);

    //VERTICAL
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(width()/2,0,width()/2,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(width()/4,0,width()/4,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(width()/8,0,width()/8,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(3*width()/4,0,3*width()/4,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(3*width()/8,0,3*width()/8,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(5*width()/8,0,5*width()/8,height());

    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(7*width()/8,0,7*width()/8,height());


    /*e = s->getPlano(dim,plano);
    int dim1 = width()/e[0].size();
    int dim2 = height()/e.size();
    for(int i=0;i<e.size();i++){
        for(int j=0;j<e[0].size();j++){
            if(e[i][j].isOn ){
                brush.setColor(QColor(e[i][j].r,e[i][j].g,e[i][j].b,e[i][j].a));
                brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);
                /*qDebug() << e[i][j].r <<e[i][j].g <<e[i][j].b;
                int xcenter =i*dim1;
                int ycenter =j*dim2;*/
            //}

        }
    //painter.setRenderHint(QPainter::Antialiasing);






    /*pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
*/
    //Linha com a cor laranja
    //pen.setColor(QColor(255,180,0));
    //informa ao pintor qual a caneta (pen) atual
    //painter.setPen(pen);
    //Desenha uma linha no meio da tela


    //Desenha o seno na tela
    /*x1 = 0;
    y1 = height()/2;
    //Desenha o seno na tela
    pen.setColor(QColor(0,0,255));
    painter.setPen(pen);
    for(int i=1;i<width();i++){
        x2 = i;
        y2 = height()/2 * (1 - amplitude*sin(2*PI*frequencia*x2/width()*angulo));
        painter.drawLine(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }
}
void Plotter::setAmplitude(int _amplitude)
{
    amplitude = _amplitude/99.0;
    repaint();
}
void Plotter::setFrequencia(int _frequencia)
{
    frequencia = _frequencia;
    repaint();
}
void Plotter::setVelocidade(int _velocidade)
{
    velocidade= _velocidade/99.0;
    repaint();
}
void Plotter::mudacor()
{
    background = QColor(0,255,255);
    repaint();
}
*/
