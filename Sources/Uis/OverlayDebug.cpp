﻿#include "OverlayDebug.hpp"

#include <Maths/Visual/DriverConstant.hpp>
#include <Scenes/Scenes.hpp>
#include <Guis/Gui.hpp>

namespace test
{
	OverlayDebug::OverlayDebug(UiObject *parent) :
		UiObject(parent, UiBound(Vector2(0.5f, 0.5f), "Centre", true, true, Vector2(1.0f, 1.0f))),
		m_textInfo(CreateStatus("Build: d0.0.1", 0.002f, 0.002f, JUSTIFY_LEFT)),
		m_textFps(CreateStatus("FPS: 0", 0.002f, 0.022f, JUSTIFY_LEFT)),
		m_textUps(CreateStatus("UPS: 0", 0.002f, 0.042f, JUSTIFY_LEFT)),
		m_textPosition(CreateStatus("POSITION: 0.0, 0.0, 0.0", 0.002f, 0.062f, JUSTIFY_LEFT)),
		m_timerUpdate(Timer(0.333f))
	{
	}

	OverlayDebug::~OverlayDebug()
	{
		delete m_textInfo;
		delete m_textFps;
		delete m_textUps;
		delete m_textPosition;
	}

	void OverlayDebug::UpdateObject()
	{
		if (m_timerUpdate.IsPassedTime())
		{
			m_timerUpdate.ResetStartTime();

			if (Scenes::Get()->GetCamera() != nullptr)
			{
				Vector3 cameraPosition = Scenes::Get()->GetCamera()->GetPosition();
				m_textPosition->SetString("POS: " + std::to_string(static_cast<int>(cameraPosition.m_x)) + ", " +
					std::to_string(static_cast<int>(cameraPosition.m_y)) + ", " +
					std::to_string(static_cast<int>(cameraPosition.m_z)));
			}

			m_textFps->SetString("FPS: " + std::to_string(static_cast<int>(1.0f / Engine::Get()->GetDeltaRender())));
			m_textUps->SetString("UPS: " + std::to_string(static_cast<int>(1.0f / Engine::Get()->GetDelta())));
		}
	}

	Text *OverlayDebug::CreateStatus(const std::string &content, const float &positionX, const float &positionY, const TextJustify &justify)
	{
		Text *result = new Text(this, UiBound(Vector2(positionX, positionY), "BottomLeft", true), 1.1f, content, FontType::Resource("Fonts/ProximaNova", "Regular"), justify);
		result->SetTextColour(Colour(1.0f, 1.0f, 1.0f));
		result->SetBorderColour(Colour(0.15f, 0.15f, 0.15f));
		result->SetBorderDriver<DriverConstant>(0.04f);
		return result;
	}
}