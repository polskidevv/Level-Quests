#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LQInfoLayer, LevelInfoLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
			return false;

		if (Mod::get()->getSettingValue<bool>("active")) {
			auto buttonSpr = CCSprite::create("challengeButton_01.png"_spr);
			auto buttonSprAlt = CCSprite::create("challengeButton_02.png"_spr);
			auto sprite = buttonSpr;

			if (Mod::get()->getSettingValue<bool>("location")) {
				if(auto menu = this->getChildByID("garage-menu")) {
					menu->setLayout(RowLayout::create());
					auto button = CCMenuItemSpriteExtra::create(
						sprite, this, menu_selector(CreatorLayer::onChallenge)
					);

					sprite->setPositionY(35.250f);
					button->setSizeMult(1);
					button->m_animationType = MenuAnimationType::Move;
					button->m_startPosition = sprite->getPosition();
					button->m_offset = ccp(button->getPositionX(), -8.f);
					button->setID("quests-button");
					button->m_duration = 0.2f;
					button->m_unselectedDuration = 0.2f;
					menu->setContentSize({ 200.f, 0.f });
					menu->addChild(button);
					if(menu->getChildrenCount() > 1) { menu->setPositionX(menu->getPositionX() - 10.f); } else { menu->setPositionX(menu->getPositionX() - 25.f); }
					menu->updateLayout();
				}
			}
			else {
				if(auto menu = this->getChildByID("left-side-menu")) {
					sprite = buttonSprAlt;
					auto button = CCMenuItemSpriteExtra::create(
						sprite, this, menu_selector(CreatorLayer::onChallenge)
					);
					button->setID("quests-button");
					menu->addChild(button);
					menu->updateLayout();
				}
			}
		}
		return true;
	} 
};