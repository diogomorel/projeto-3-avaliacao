#include "sculptor.h"
#include "vector"
#include <cmath>
#include <iostream>
#include "mainwindow.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;
    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }
    v = new Voxel**[nx];

    if(v == nullptr){
        exit(0);
    }

    v[0] = new Voxel*[nx*ny];

    if(v[0] == nullptr){
        exit(0);
    }

    v[0][0] = new Voxel[nx*ny*nz];

    if(v[0][0] = nullptr){
        exit(0);
    }
    for(int i=0; i< nx; i++)
    {
        if (i<(nx-1))
        {
            v[i+1] = v[i]+ny;
        }
        for(int j=1; j< ny; j++)
        {
            v[i][j] = v[i][j-1]+nz;
            if(j==ny-1 && i!=(nx-1))
            {
                v[i+1][0] = v[i][j]+nz;
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;

}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
     _r = r; _g = g; _b = b; _a = alpha;

}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = _r;
    v[x][y][z].g = _g;
    v[x][y][z].b = _b;
    v[x][y][z].a = _a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j< ycenter+ry; j++)
        {
            for(int k=zcenter - rz; k< zcenter + rz; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0)
                {
                   putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j< ycenter+ry; j++)
        {
            for(int k=zcenter - rz; k< zcenter + rz; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

vector<vector<Voxel> > Sculptor::getPlano(int dim , int plano)
{
        vector< vector<Voxel> > retorno;
        vector<Voxel> linha;
        if(plano == XY){
            linha.resize(ny);
            for(int i =0;i<nx;i++){
                for(int j = 0;j<ny;j++){
                    linha[j].r = v[i][j][dim].r;
                    linha[j].g = v[i][j][dim].g;
                    linha[j].b = v[i][j][dim].b;
                    linha[j].a = v[i][j][dim].a;
                    linha[j].isOn = v[i][j][dim].isOn;

                }
                retorno.push_back(linha);
            }
        }
        if(plano == ZX){
            linha.resize(nx);
            for(int i =0;i<nz;i++){
                for(int j = 0;j<nx;j++){
                    linha[j].r = v[j][dim][i].r;
                    linha[j].g = v[j][dim][i].g;
                    linha[j].b = v[j][dim][i].b;
                    linha[j].a = v[j][dim][i].a;
                    linha[j].isOn = v[j][dim][i].isOn;

                }
                retorno.push_back(linha);
            }
        }
        if(plano == YZ){
            linha.resize(nz);
            for(int i =0;i<ny;i++){
                for(int j = 0;j<nz;j++){
                    linha[j].r = v[dim][i][j].r;
                    linha[j].g = v[dim][i][j].g;
                    linha[j].b = v[dim][i][j].b;
                    linha[j].a = v[dim][i][j].a;
                    linha[j].isOn = v[dim][i][j].isOn;

                }
                retorno.push_back(linha);
            }
        }
        linha.clear();
        return retorno;

}
