#pragma once
#include "GameObject.h"
#include "Component.h"

namespace dae {
    class Texture final: public Component
    {
    public:
        Texture();
        ~Texture() override;

        Texture(const Texture& other) = delete;
        Texture(Texture&& other) = delete;
        Texture& operator=(const Texture& other) = delete;
        Texture& operator=(Texture&& other) = delete;

        void Update() override;
        void FixedUpdate() override;
        void Render() const override;

        void SetTexture(const std::string& filename);
        void SetPosition(float x, float y);

    private:
        Transform m_Transform;
        std::shared_ptr<Texture2D> m_Texture{};
    };
}
