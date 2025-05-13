#pragma once
#include "Polygon.h"
#include <vector>

class Camera;

enum class ObjectType {
    kCircle,//円
    kLine,//直線
    kTriangle,//正三角形
    kQuad,//正方形
    kCustom//カスタム
};

class Object : public Polygon {
public:
    /// <summary>
	/// 32*32の四角形を作成する
    /// </summary>
    Object();

    /// <summary>
    /// Objectを作成する
    /// </summary>
    /// <param name="size">Objectの外枠</param>
    /// <param name="fillMode">内側を埋めるかどうか</param>
    /// <param name="type">プリセットを使用しない場合はcustom</param>
    /// <param name="localPositions">customの場合は各点の座標(時計回りで、-1~1の範囲)、それ以外は{}を入力</param>
    Object(const Vector2& size, FillMode fillMode = kFillModeSolid, ObjectType type = ObjectType::kQuad, const std::vector<Vector2>& localPositions = {});
    virtual ~Object() = default;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="textureHandle"></param>
    /// <param name="textureSize">画像サイズ</param>
    void SetTextureHandle(int textureHandle, IVector2 textureSize);
    void SetTexturePos(IVector2 texturePos);

    void Ready(const Camera& camera, int bright = 255);

    virtual void Draw() const;

protected:
    std::vector<Vector2> npos_;         // 正規化されたローカル座標
    std::vector<Vector2> spos_;         // 変換されたスクリーン座標
    Vector2 smidPos_;                   // スクリーン上の中心位置

    IVector2 textureSize_;
    IVector2 texturePos_;
    int textureHandle_ = 0;

	ObjectType type_;                   // オブジェクトの形状
	FillMode fillMode_;                 // 塗りつぶしの有無
	BlendMode blendMode_;               // ブレンドモード

    unsigned int sColor_;               //スクリーンに描画する用の色

private:
    void Initialize(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions);
};
