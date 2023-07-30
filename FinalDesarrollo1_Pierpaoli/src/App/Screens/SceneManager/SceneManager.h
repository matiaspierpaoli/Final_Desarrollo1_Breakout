#pragma once
namespace BreakoutGame
{
	enum class Scene { MENU, GAMEPLAY, RULES, CREDITS, EXIT };

	class SceneManager
	{
	private:
		Scene scene;
	public:
		SceneManager();
		~SceneManager();
		Scene getScene();
		void setScene(Scene scene);
	};
}