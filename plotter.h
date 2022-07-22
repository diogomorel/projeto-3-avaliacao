#ifndef PLOTTER_H
#define PLOTTER_H
#include <iostream>
#include <QWidget>
#include <QWidget>
#include "sculptor.h"
#include "vector"

/**
 * @brief Classe responsavel pelos desenhos e cores
 *
 */

class Plotter : public QWidget
{
    Q_OBJECT

    //float amplitude = 1.0,frequencia = 1,velocidade = 0.0,angulo = 0.0;
    //int timerId;
    //QColor background;
    //QAction *actionOpcao;
public:
    /**
     * @brief Construtor
     *
     */
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    Sculptor *s;

    int dim,plano; /**< valores da dimensão e plano *///Dimensao e plano
    int r,g,b,a; /**< valores das cores vermelho, verde, azul e transparencia */ //cores que serao modificadas
    int xx,yy,zz; /**< medidas do plano *///Medidas do PLano
    int raio,rx,ry,rz; /**< valores de raios */
    int x,y,z;//variaveis auxiliares

    //void timerEvent(QTimerEvent *event);
    //void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void contextMenuEvent(QContextMenuEvent *event);
private:
    vector<vector<Voxel>> e;
signals:
    //void moveX(int);
    //void moveY(int);

public slots:
    //void setTamanho(int _nlinhas, int _ncolunas);
    /*void mudaDimX(int size);
    void mudaDimY(int size);
    void mudaDimZ(int size);
    void mudaRx(int _rx);
    void mudaRy(int _ry);
    void mudaRz(int _rz);
    void mudaR(int vermelho);
    void mudaG(int verde);
    void mudaB(int azul);
    void mudaAlpha(int a);
    //void setVelocidade(int _velocidade);
    //void mudacor(void);
*/

};

#endif // PLOTTER_H
