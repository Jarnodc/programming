#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "Component.h"

namespace dae
{
	class Texture2D;

	// todo: this should become final.
	class GameObject final : public SceneObject
	{
	public:
		void Update() override;
		void FixedUpdate() override;
		void Render() const override;

		void SetPosition(float x, float y); 
		
		//Update Component 
		template <typename T> std::shared_ptr<T> AddComponent();
		template <typename T> std::shared_ptr<T> GetComponent() const;
		template <typename T> void RemoveComponent();

		//Update Parent 
		void SetParent(const std::shared_ptr<GameObject>& parent);
		std::shared_ptr<GameObject> GetParent() const;

		//Update Child 
		size_t GetChildCount() const;
		std::shared_ptr<GameObject> GetChildAt(int index) const;
		void RemoveChild(int index);
		void AddChild(const std::shared_ptr<GameObject>& go);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform;
		std::vector<std::shared_ptr<Component>> m_pComponents{};
		std::vector<std::shared_ptr<GameObject>> m_pChilds{};
		std::shared_ptr<GameObject> m_pParent{ nullptr };
	};
	
	template<typename T>
	inline std::shared_ptr<T> GameObject::AddComponent()
	{
		const auto pComp{ std::make_shared<T>() };
		m_pComponents.push_back(pComp);
		return pComp;
	}

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent() const
	{
		for (auto& comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
				return std::static_pointer_cast<T>(comp);
		}
		return nullptr;
	}

	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		auto it = std::find_if(m_pComponents.begin(), m_pComponents.end(), [](auto comp) {
			return typeid(*comp) == typeid(T);
			});
		if (it == m_pComponents.end())
			return;

		m_pComponents.erase(std::remove_if(m_pComponents.begin(), m_pComponents.end(), [](auto comp) {
			return typeid(*comp) == typeid(T);
			}));
	}
}
