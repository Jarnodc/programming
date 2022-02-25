#pragma once
#include "Component.h"
#include "Transform.h"
#include "Font.h"
#include "Texture2D.h"

namespace dae
{
	class TextObject : public Component
	{
	public:
		virtual void Update() override;
		virtual void FixedUpdate() override;
		virtual void Render() const override;

		void SetText(const std::string& text);
		void SetFont(const std::shared_ptr<Font>& font);
		void SetColor(const SDL_Color& color);
		void SetPosition(float x, float y);

		explicit TextObject(const std::string& text, const std::shared_ptr<Font>& font);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	protected:
		bool m_NeedsUpdate;
		std::string m_Text;
		Transform m_Transform;
		std::shared_ptr<Font> m_Font;
		SDL_Color m_Color = { 255,255,255 };
		std::shared_ptr<Texture2D> m_TextTexture;
	};
}
