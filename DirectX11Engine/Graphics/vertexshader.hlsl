cbuffer myCbuffer : register(b0)
{
    float xOffset;
    float yOffset;
};

struct VS_INPUT
{
    float3 pos : POSITION;
    float2 texCoord : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 pos : SV_POSITION;
    float2 texCoord : TEXCOORD;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;
    input.pos.x += xOffset;
    input.pos.y += yOffset;
    output.pos = float4(input.pos, 1.0f);
    output.texCoord = input.texCoord;
    return output;
}
