#pragma once
#include "TextObject.h"
namespace dae {
    class FpsCounter final: public TextObject
    {
    public: 
        explicit FpsCounter(const std::shared_ptr<Font>& font);
        explicit FpsCounter();
        virtual ~FpsCounter() = default;

        FpsCounter(const FpsCounter& other) = delete;
        FpsCounter(FpsCounter&& other) = delete;
        FpsCounter& operator=(const FpsCounter& other) = delete;
        FpsCounter& operator=(FpsCounter&& other) = delete;
        void Update() override;
        void FixedUpdate() override;
    private:
        int prevFps;
    };
}

