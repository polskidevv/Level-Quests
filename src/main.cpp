#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(InfoLayerMy, LevelInfoLayer) {
	void onButton(CCObject* target) {
		auto scene = reinterpret_cast<CCNode*>(CCScene::get());
		auto questsMenu = ChallengesPage::create();
		questsMenu->setZOrder(1);
		questsMenu->draw();
		questsMenu->setVisible(true);
		questsMenu->setID("quests");
		scene->addChild(questsMenu);
	}

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
			return false;

		if (Mod::get()->getSettingValue<bool>("active")) {
			auto buttonSpr = CCSprite::create("challengeButton_01.png"_spr);
			auto buttonSprAlt = CCSprite::create("challengeButton_02.png"_spr);
			auto sprite = buttonSpr;

			/*if (Mod::get()->getSettingValue<bool>("location")) {					temporarily disabled until proper nodeids for the garage menu releases
				if(auto menu = this->getChildByID("garage-menu")) {
					menu->setLayout(
						RowLayout::create()
							->setGrowCrossAxis(true)
							->setAxisReverse(true)
					);
					auto button = CCMenuItemSpriteExtra::create(
						sprite, this, menu_selector(InfoLayerMy::onButton)
					);
					sprite->setPositionY(35.250f);
					button->setSizeMult(1);
					button->m_animationType = MenuAnimationType::Move;
					button->m_startPosition = button->getPosition();
					button->m_offset = ccp(0, -8.f);
					button->setID("quests-button");
					menu->setContentSize({ 200.f, 0.f });
					menu->addChild(button);
					menu->setPositionX(464.0f);
					menu->updateLayout();
				}
			}
			else {*/
				if(auto menu = this->getChildByID("left-side-menu")) {
					sprite = buttonSprAlt;
					auto button = CCMenuItemSpriteExtra::create(
						sprite, this, menu_selector(InfoLayerMy::onButton)
					);
					button->setID("quests-button");
					menu->addChild(button);
					menu->updateLayout();
				}
			//}
		}
		return true;
	} 
};
