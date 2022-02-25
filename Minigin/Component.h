#pragma once
class Component
{
public:
	//Component(dae::GameObject* pGO):pGameObject{pGO}{};
	Component() = default;
	virtual ~Component() = default;

	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() const = 0;

	Component(const Component& other) = delete;
	Component(Component&& other) = delete;
	Component& operator=(const Component& other) = delete;
	Component& operator=(Component&& other) = delete;
private:
protected:
	//dae::GameObject* pGameObject = nullptr;
};

