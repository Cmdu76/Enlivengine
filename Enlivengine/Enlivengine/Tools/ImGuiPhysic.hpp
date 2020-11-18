#pragma once

#include <Enlivengine/Config.hpp>

#ifdef ENLIVE_MODULE_TOOLS
#ifdef ENLIVE_ENABLE_IMGUI

#include <Enlivengine/Tools/ImGuiTool.hpp>

namespace en
{

class ImGuiPhysic : public ImGuiTool
{
	ENLIVE_SINGLETON(ImGuiPhysic);

public:
	ImGuiToolTab GetTab() const override;
	const char* GetName() const override;
	const char* GetSaveName() const override;

	void Display() override;
};

} // namespace en

#endif // ENLIVE_ENABLE_IMGUI
#endif // ENLIVE_MODULE_TOOLS