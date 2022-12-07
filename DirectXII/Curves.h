#ifndef _CURVES_H
#define _CURVES

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

class Curves : public App
{
private:
    ID3D12RootSignature* rootSignature;
    ID3D12PipelineState* pipelineState;
    Mesh* line;

    static const uint maxVertives = 1024;
    Vertex vertices[maxVertives];
    uint index;

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();

    void BuildRootSignature();
    void BuildPipelineState();

    void BuildLine();
    void setPoint(float x, float y);
    void resetPoints();
    void Subdivision();
};
#endif 
