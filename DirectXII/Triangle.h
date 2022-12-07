#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "DXUT.h"
#include <D3DCompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
using namespace DirectX;

struct Vertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};

class Triangle : public App
{
private:
    ID3D12RootSignature* rootSignature;
    ID3D12PipelineState* pipelineState;
    Mesh* triangle1;
    Mesh* triangle2;

public:
    void Init();
    void Update();
    void Display();
    void Finalize();

    void BuildTriangle(Vertex vertices[3], Mesh* mesh);
    void BuildRootSignature();
    void BuildPipelineState();    
};

#endif