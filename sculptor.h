#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <iostream>
#include "vector"

using namespace std;

/**
 * @brief Estutura do voxel
 *
 */
struct Voxel{
    float r,g,b,a;
    bool isOn;
};

enum {XY,ZX,YZ};//Identifica o plano

class Sculptor
{
private:
    Voxel ***v; /**< criação do voxel */
    int nx,ny,nz; /**< dimensões */
    float _r,_g,_b,_a; /**< valores das cores */

public:
    /**
     * @brief Construtor da matriz 3D
     *
     * @param tam de X do Sculptor
     * @param tam de Y do Sculptor
     * @param tam de Z do Sculptor
     */
    Sculptor(int _nx=0,int _ny=0,int _nz=0);
    /**
     * @brief Destrutor da matriz 3D
     */
    ~Sculptor();
    /**
     * @brief Funcao que seta as cores e transparencia do voxel
     *
     * @param valor do componente em Vermelho
     * @param valor do componente em Verde
     * @param valor do componente em Azul
     * @param valor do componente para Transparencia
     */
    void setColor(float r,float g,float b,float alpha);
    /**
     * @brief Funcao que cria o Voxel
     *
     * @param posicao X do Voxel
     * @param posicao Y do Voxel
     * @param posicao Z do Voxel
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief Funcao que remove o Voxel
     *
     * @param posicao X do Voxel
     * @param posicao Y do Voxel
     * @param posicao Z do Voxel
     */
    void cutVoxel(int x,int y,int z);
    /**
     * @brief Funcao que cria uma Box
     *
     * @param posicao X inical da caixa
     * @param posicao X final da caixa
     * @param posicao Y inical da caixa
     * @param posicao Y final da caixa
     * @param posicao Z inical da caixa
     * @param posicao z final da caixa
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Funcao que remove uma Box
     *
     * @param posicao X inical da caixa
     * @param posicao X final da caixa
     * @param posicao Y inical da caixa
     * @param posicao Y final da caixa
     * @param posicao Z inical da caixa
     * @param posicao z final da caixa
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Funcao que cria uma Esfera
     *
     * @param posicao X do centro da esfera
     * @param posicao Y do centro da esfera
     * @param posicao Z do centro da esfera
     * @param tamanho do raio da esfera
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int raio);
    /**
     * @brief Funcao que remove uma Esfera
     *
     * @param posicao X do centro da esfera
     * @param posicao Y do centro da esfera
     * @param posicao Z do centro da esfera
     * @param tamanho do raio da esfera
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int raio);
    /**
     * @brief Funcao que cria uma Elipsoide
     *
     * @param posicao X do centro da Elipsoide
     * @param posicao Y do centro da Elipsoide
     * @param posicao Z do centro da Elipsoide
     * @param tamanho do raio X da Elipsoide
     * @param tamanho do raio Y da Elipsoide
     * @param tamanho do raio Z da Elipsoide
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief Funcao que remove uma Elipsoide
     *
     * @param posicao X do centro da Elipsoide
     * @param posicao Y do centro da Elipsoide
     * @param posicao Z do centro da Elipsoide
     * @param tamanho do raio X da Elipsoide
     * @param tamanho do raio Y da Elipsoide
     * @param tamanho do raio Z da Elipsoide
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief matriz 2D representando um plano da matriz 3D
     *
     * @param dimensao a ser visualizada
     * @param plano atual
     * @return Matriz 2D plotada
     */
    vector< vector<Voxel> > getPlano(int dim =0, int plano = XY);
};

#endif // SCULPTOR_H
